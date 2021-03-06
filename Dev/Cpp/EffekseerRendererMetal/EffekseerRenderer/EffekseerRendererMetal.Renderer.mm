#include "EffekseerRendererMetal.Renderer.h"
#include "../EffekseerRendererMetal.RendererImplemented.h"

#include "../../EffekseerRendererLLGI/EffekseerRendererLLGI.Shader.h"
#include "../../EffekseerRendererLLGI/EffekseerRendererLLGI.VertexBuffer.h"

#include "../../3rdParty/LLGI/src/Metal/LLGI.CommandListMetal.h"
#include "../../3rdParty/LLGI/src/Metal/LLGI.GraphicsMetal.h"

#include "../../3rdParty/LLGI/src/Metal/LLGI.CommandListMetal.h"
#include "../../3rdParty/LLGI/src/Metal/LLGI.GraphicsMetal.h"
#include "../../3rdParty/LLGI/src/Metal/LLGI.RenderPassMetal.h"
#include "../../3rdParty/LLGI/src/Metal/LLGI.Metal_Impl.h"

#include "Shaders.h"

namespace EffekseerRendererMetal
{

::EffekseerRenderer::Renderer* Create(int32_t squareMaxCount,
                                      MTLPixelFormat renderTargetFormat,
                                      MTLPixelFormat depthStencilFormat,
									  bool isReversedDepth)
{
	auto graphics = new LLGI::GraphicsMetal();
    graphics->Initialize(nullptr);
    
    RendererImplemented* renderer = new RendererImplemented(squareMaxCount);

    auto allocate_ = [](std::vector<LLGI::DataStructure>& ds, const char* data, int32_t size) -> void {
        ds.resize(1);
        ds[0].Size = size;
        ds[0].Data = data;
        return;
    };
    
    const char* sources[] = {
        g_sprite_vs_src, g_sprite_distortion_vs_src, g_model_lighting_vs_src, g_model_texture_vs_src, g_model_distortion_vs_src,
        g_sprite_fs_texture_src, g_sprite_fs_texture_distortion_src, g_model_lighting_fs_src, g_model_texture_fs_src, g_model_distortion_fs_src
    };
    
    std::vector<LLGI::DataStructure>* dest = &renderer->fixedShader_.StandardTexture_VS;

    for (int i = 0; i < 10; ++i)
    {
        allocate_(dest[i], sources[i], sizeof(sources[i]));
    }

    auto pipelineState = graphics->CreateRenderPassPipelineState(renderTargetFormat, depthStencilFormat).get();

    if (renderer->Initialize(graphics, pipelineState, isReversedDepth))
    {
        ES_SAFE_RELEASE(graphics);
        ES_SAFE_RELEASE(pipelineState);
        return renderer;
    }

    ES_SAFE_RELEASE(graphics);
    ES_SAFE_RELEASE(pipelineState);

    ES_SAFE_DELETE(renderer);

    return nullptr;
}

Effekseer::TextureData* CreateTextureData(::EffekseerRenderer::Renderer* renderer, id<MTLTexture> texture)
{
	auto r = static_cast<::EffekseerRendererLLGI::RendererImplemented*>(renderer);
	auto g = static_cast<LLGI::GraphicsMetal*>(r->GetGraphics());
	auto texture_ = g->CreateTexture((uint64_t)texture);

	auto textureData = new Effekseer::TextureData();
	textureData->UserPtr = texture_;
	textureData->UserID = 0;
	textureData->TextureFormat = Effekseer::TextureFormatType::ABGR8;
	textureData->Width = 0;
	textureData->Height = 0;
	return textureData;
}

void DeleteTextureData(::EffekseerRenderer::Renderer* renderer, Effekseer::TextureData* textureData)
{
	auto texture = (LLGI::Texture*)textureData->UserPtr;
	texture->Release();
	delete textureData;
}

void FlushAndWait(::EffekseerRenderer::Renderer* renderer)
{
	auto r = static_cast<::EffekseerRendererLLGI::RendererImplemented*>(renderer);
	auto g = static_cast<LLGI::GraphicsMetal*>(r->GetGraphics());
	g->WaitFinish();
}

EffekseerRenderer::CommandList* CreateCommandList(::EffekseerRenderer::Renderer* renderer,
												  ::EffekseerRenderer::SingleFrameMemoryPool* memoryPool)
{
	auto r = static_cast<::EffekseerRendererLLGI::RendererImplemented*>(renderer);
	auto g = static_cast<LLGI::GraphicsMetal*>(r->GetGraphics());
	auto mp = static_cast<::EffekseerRendererLLGI::SingleFrameMemoryPool*>(memoryPool);
	auto commandList = g->CreateCommandList(mp->GetInternal());
	auto ret = new EffekseerRendererLLGI::CommandList(g, commandList, mp->GetInternal());
	ES_SAFE_RELEASE(commandList);
	return ret;
}

EffekseerRenderer::SingleFrameMemoryPool* CreateSingleFrameMemoryPool(::EffekseerRenderer::Renderer* renderer)
{
	auto r = static_cast<::EffekseerRendererLLGI::RendererImplemented*>(renderer);
	auto g = static_cast<LLGI::GraphicsMetal*>(r->GetGraphics());
	auto mp = g->CreateSingleFrameMemoryPool(1024 * 1024 * 8, 128);
	auto ret = new EffekseerRendererLLGI::SingleFrameMemoryPool(mp);
	ES_SAFE_RELEASE(mp);
	return ret;
}
/*
void BeginCommandList(EffekseerRenderer::CommandList* commandList, id<MTLCommandBuffer> commandBuffer)
{
	assert(commandList != nullptr);

	LLGI::PlatformContextDX12 context;
	context.commandList = dx12CommandList;

	auto c = static_cast<EffekseerRendererLLGI::CommandList*>(commandList);
	c->GetInternal()->BeginWithPlatform(&context);
}

void EndCommandList(EffekseerRenderer::CommandList* commandList)
{
	assert(commandList != nullptr);
	auto c = static_cast<EffekseerRendererLLGI::CommandList*>(commandList);
	c->GetInternal()->EndWithPlatform();
}
*/
void RendererImplemented::SetExternalCommandBuffer(id<MTLCommandBuffer> extCommandBuffer)
{
    if (commandList_ != nullptr)
    {
        auto clm = static_cast<LLGI::CommandListMetal*>(GetCurrentCommandList());
        clm->GetImpl()->commandBuffer = extCommandBuffer;
    }
}
    
void RendererImplemented::SetExternalRenderEncoder(id<MTLRenderCommandEncoder> extRenderEncoder)
{
    if (commandList_ != nullptr)
    {
        auto clm = static_cast<LLGI::CommandListMetal*>(GetCurrentCommandList());
        clm->GetImpl()->renderEncoder = extRenderEncoder;
    }
}

bool RendererImplemented::BeginRendering()
{
    assert(graphics_ != NULL);

    ::Effekseer::Matrix44::Mul(m_cameraProj, m_camera, m_proj);

    // initialize states
    m_renderState->GetActiveState().Reset();
    m_renderState->Update(true);

    if (commandList_ != nullptr)
    {
#ifdef __EFFEKSEER_RENDERERMETAL_INTERNAL_COMMAND_BUFFER__
        GetCurrentCommandList()->Begin();
#else
        GetCurrentCommandList()->CommandList::Begin();
#endif
#ifdef __EFFEKSEER_RENDERERMETAL_INTERNAL_RENDER_PASS__
        auto g = static_cast<LLGI::GraphicsMetal*>(graphics_);
        GetCurrentCommandList()->BeginRenderPass(g->GetRenderPass());
#else
        GetCurrentCommandList()->CommandList::BeginRenderPass(nullptr);
#endif
    }

    // reset renderer
    m_standardRenderer->ResetAndRenderingIfRequired();

    return true;
}

bool RendererImplemented::EndRendering()
{
    assert(graphics_ != NULL);

    // reset renderer
    m_standardRenderer->ResetAndRenderingIfRequired();

    if (commandList_ != nullptr)
    {
#ifdef __EFFEKSEER_RENDERERMETAL_INTERNAL_RENDER_PASS__
        GetCurrentCommandList()->EndRenderPass();
#endif
#ifdef __EFFEKSEER_RENDERERMETAL_INTERNAL_COMMAND_BUFFER__
        GetCurrentCommandList()->End();
        graphics_->Execute(GetCurrentCommandList());
#endif
    }
    return true;
}

} // namespace EffekseerRendererMetal
