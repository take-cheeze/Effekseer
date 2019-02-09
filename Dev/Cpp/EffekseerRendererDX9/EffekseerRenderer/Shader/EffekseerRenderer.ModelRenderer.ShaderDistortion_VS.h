#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tvs_2_0 /EVS /Fh
//    Shader/EffekseerRenderer.ModelRenderer.ShaderDistortion_VS.h
//    Shader/model_renderer_distortion_VS.fx
//
//
// Parameters:
//
//   float4 fModelColor[40];
//   float4 fUV[40];
//   float4x4 mCameraProj;
//   float4x4 mModel[40];
//   float4 mUVInversed;
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   mCameraProj  c0       4
//   mModel       c4     160
//   fUV          c164    40
//   fModelColor  c204    40
//   mUVInversed  c247     1
//

    vs_2_0
    def c244, 4, 0, 0, 0
    dcl_position v0
    dcl_normal v1
    dcl_normal1 v2
    dcl_normal2 v3
    dcl_texcoord v4
    dcl_blendindices v5
    mova a0.x, v5.x
    mad oT0.x, v4.x, c164[a0.x].z, c164[a0.x].x
    mov r0.xyz, v0
    add r1.xyz, r0, v1
    mul r0.w, v5.x, c244.x
    mova a0.y, r0.w
    mul r2, r1.y, c5[a0.y]
    mad r2, c4[a0.y], r1.x, r2
    mad r1, c6[a0.y], r1.z, r2
    add r1, r1, c7[a0.y]
    mul r2, v0.y, c5[a0.y]
    mad r2, c4[a0.y], v0.x, r2
    mad r2, c6[a0.y], v0.z, r2
    add r2, r2, c7[a0.y]
    add r3, r1, -r2
    dp4 r0.w, r3, r3
    rsq r0.w, r0.w
    lrp r3, r0.w, r1, r2
    mul r1, r3.y, c1
    mad r1, c0, r3.x, r1
    mad r1, c2, r3.z, r1
    mad oT1, c3, r3.w, r1
    add r1.xyz, r0, v2
    mul r3, r1.y, c5[a0.y]
    mad r3, c4[a0.y], r1.x, r3
    mad r1, c6[a0.y], r1.z, r3
    add r1, r1, c7[a0.y]
    add r3, -r2, r1
    dp4 r0.w, r3, r3
    rsq r0.w, r0.w
    lrp r3, r0.w, r1, r2
    mul r1, r3.y, c1
    mad r1, c0, r3.x, r1
    mad r1, c2, r3.z, r1
    mad oT2, c3, r3.w, r1
    add r0.xyz, r0, v3
    mul r1, r0.y, c5[a0.y]
    mad r1, c4[a0.y], r0.x, r1
    mad r0, c6[a0.y], r0.z, r1
    add r0, r0, c7[a0.y]
    add r1, -r2, r0
    dp4 r1.x, r1, r1
    rsq r1.x, r1.x
    lrp r3, r1.x, r0, r2
    mul r0, r3.y, c1
    mad r0, c0, r3.x, r0
    mad r0, c2, r3.z, r0
    mad oT3, c3, r3.w, r0
    mad r0.x, v4.y, c164[a0.x].w, c164[a0.x].y
    mov oD0, c204[a0.x]
    mad oT0.y, c247.y, r0.x, c247.x
    mul r0, r2.y, c1
    mad r0, c0, r2.x, r0
    mad r0, c2, r2.z, r0
    mad r0, c3, r2.w, r0
    mov oPos, r0
    mov oT4, r0

// approximately 57 instruction slots used
#endif

const BYTE g_vs20_VS[] =
{
      0,   2, 254, 255, 254, 255, 
     79,   0,  67,  84,  65,  66, 
     28,   0,   0,   0,   7,   1, 
      0,   0,   0,   2, 254, 255, 
      5,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
      0,   1,   0,   0, 128,   0, 
      0,   0,   2,   0, 204,   0, 
     40,   0,  50,   3, 140,   0, 
      0,   0,   0,   0,   0,   0, 
    156,   0,   0,   0,   2,   0, 
    164,   0,  40,   0, 146,   2, 
    160,   0,   0,   0,   0,   0, 
      0,   0, 176,   0,   0,   0, 
      2,   0,   0,   0,   4,   0, 
      2,   0, 188,   0,   0,   0, 
      0,   0,   0,   0, 204,   0, 
      0,   0,   2,   0,   4,   0, 
    160,   0,  18,   0, 212,   0, 
      0,   0,   0,   0,   0,   0, 
    228,   0,   0,   0,   2,   0, 
    247,   0,   1,   0, 222,   3, 
    240,   0,   0,   0,   0,   0, 
      0,   0, 102,  77, 111, 100, 
    101, 108,  67, 111, 108, 111, 
    114,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,  40,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  85,  86,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
     40,   0,   0,   0,   0,   0, 
      0,   0, 109,  67,  97, 109, 
    101, 114,  97,  80, 114, 111, 
    106,   0,   3,   0,   3,   0, 
      4,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    109,  77, 111, 100, 101, 108, 
      0, 171,   3,   0,   3,   0, 
      4,   0,   4,   0,  40,   0, 
      0,   0,   0,   0,   0,   0, 
    109,  85,  86,  73, 110, 118, 
    101, 114, 115, 101, 100,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 118, 115, 
     95,  50,  95,  48,   0,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  32,  40,  82,  41, 
     32,  72,  76,  83,  76,  32, 
     83, 104,  97, 100, 101, 114, 
     32,  67, 111, 109, 112, 105, 
    108, 101, 114,  32,  57,  46, 
     50,  57,  46,  57,  53,  50, 
     46,  51,  49,  49,  49,   0, 
     81,   0,   0,   5, 244,   0, 
     15, 160,   0,   0, 128,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   0,   0,  15, 144, 
     31,   0,   0,   2,   3,   0, 
      0, 128,   1,   0,  15, 144, 
     31,   0,   0,   2,   3,   0, 
      1, 128,   2,   0,  15, 144, 
     31,   0,   0,   2,   3,   0, 
      2, 128,   3,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   4,   0,  15, 144, 
     31,   0,   0,   2,   2,   0, 
      0, 128,   5,   0,  15, 144, 
     46,   0,   0,   2,   0,   0, 
      1, 176,   5,   0,   0, 144, 
      4,   0,   0,   6,   0,   0, 
      1, 224,   4,   0,   0, 144, 
    164,  32, 170, 160,   0,   0, 
      0, 176, 164,  32,   0, 160, 
      0,   0,   0, 176,   1,   0, 
      0,   2,   0,   0,   7, 128, 
      0,   0, 228, 144,   2,   0, 
      0,   3,   1,   0,   7, 128, 
      0,   0, 228, 128,   1,   0, 
    228, 144,   5,   0,   0,   3, 
      0,   0,   8, 128,   5,   0, 
      0, 144, 244,   0,   0, 160, 
     46,   0,   0,   2,   0,   0, 
      2, 176,   0,   0, 255, 128, 
      5,   0,   0,   4,   2,   0, 
     15, 128,   1,   0,  85, 128, 
      5,  32, 228, 160,   0,   0, 
     85, 176,   4,   0,   0,   5, 
      2,   0,  15, 128,   4,  32, 
    228, 160,   0,   0,  85, 176, 
      1,   0,   0, 128,   2,   0, 
    228, 128,   4,   0,   0,   5, 
      1,   0,  15, 128,   6,  32, 
    228, 160,   0,   0,  85, 176, 
      1,   0, 170, 128,   2,   0, 
    228, 128,   2,   0,   0,   4, 
      1,   0,  15, 128,   1,   0, 
    228, 128,   7,  32, 228, 160, 
      0,   0,  85, 176,   5,   0, 
      0,   4,   2,   0,  15, 128, 
      0,   0,  85, 144,   5,  32, 
    228, 160,   0,   0,  85, 176, 
      4,   0,   0,   5,   2,   0, 
     15, 128,   4,  32, 228, 160, 
      0,   0,  85, 176,   0,   0, 
      0, 144,   2,   0, 228, 128, 
      4,   0,   0,   5,   2,   0, 
     15, 128,   6,  32, 228, 160, 
      0,   0,  85, 176,   0,   0, 
    170, 144,   2,   0, 228, 128, 
      2,   0,   0,   4,   2,   0, 
     15, 128,   2,   0, 228, 128, 
      7,  32, 228, 160,   0,   0, 
     85, 176,   2,   0,   0,   3, 
      3,   0,  15, 128,   1,   0, 
    228, 128,   2,   0, 228, 129, 
      9,   0,   0,   3,   0,   0, 
      8, 128,   3,   0, 228, 128, 
      3,   0, 228, 128,   7,   0, 
      0,   2,   0,   0,   8, 128, 
      0,   0, 255, 128,  18,   0, 
      0,   4,   3,   0,  15, 128, 
      0,   0, 255, 128,   1,   0, 
    228, 128,   2,   0, 228, 128, 
      5,   0,   0,   3,   1,   0, 
     15, 128,   3,   0,  85, 128, 
      1,   0, 228, 160,   4,   0, 
      0,   4,   1,   0,  15, 128, 
      0,   0, 228, 160,   3,   0, 
      0, 128,   1,   0, 228, 128, 
      4,   0,   0,   4,   1,   0, 
     15, 128,   2,   0, 228, 160, 
      3,   0, 170, 128,   1,   0, 
    228, 128,   4,   0,   0,   4, 
      1,   0,  15, 224,   3,   0, 
    228, 160,   3,   0, 255, 128, 
      1,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,   7, 128, 
      0,   0, 228, 128,   2,   0, 
    228, 144,   5,   0,   0,   4, 
      3,   0,  15, 128,   1,   0, 
     85, 128,   5,  32, 228, 160, 
      0,   0,  85, 176,   4,   0, 
      0,   5,   3,   0,  15, 128, 
      4,  32, 228, 160,   0,   0, 
     85, 176,   1,   0,   0, 128, 
      3,   0, 228, 128,   4,   0, 
      0,   5,   1,   0,  15, 128, 
      6,  32, 228, 160,   0,   0, 
     85, 176,   1,   0, 170, 128, 
      3,   0, 228, 128,   2,   0, 
      0,   4,   1,   0,  15, 128, 
      1,   0, 228, 128,   7,  32, 
    228, 160,   0,   0,  85, 176, 
      2,   0,   0,   3,   3,   0, 
     15, 128,   2,   0, 228, 129, 
      1,   0, 228, 128,   9,   0, 
      0,   3,   0,   0,   8, 128, 
      3,   0, 228, 128,   3,   0, 
    228, 128,   7,   0,   0,   2, 
      0,   0,   8, 128,   0,   0, 
    255, 128,  18,   0,   0,   4, 
      3,   0,  15, 128,   0,   0, 
    255, 128,   1,   0, 228, 128, 
      2,   0, 228, 128,   5,   0, 
      0,   3,   1,   0,  15, 128, 
      3,   0,  85, 128,   1,   0, 
    228, 160,   4,   0,   0,   4, 
      1,   0,  15, 128,   0,   0, 
    228, 160,   3,   0,   0, 128, 
      1,   0, 228, 128,   4,   0, 
      0,   4,   1,   0,  15, 128, 
      2,   0, 228, 160,   3,   0, 
    170, 128,   1,   0, 228, 128, 
      4,   0,   0,   4,   2,   0, 
     15, 224,   3,   0, 228, 160, 
      3,   0, 255, 128,   1,   0, 
    228, 128,   2,   0,   0,   3, 
      0,   0,   7, 128,   0,   0, 
    228, 128,   3,   0, 228, 144, 
      5,   0,   0,   4,   1,   0, 
     15, 128,   0,   0,  85, 128, 
      5,  32, 228, 160,   0,   0, 
     85, 176,   4,   0,   0,   5, 
      1,   0,  15, 128,   4,  32, 
    228, 160,   0,   0,  85, 176, 
      0,   0,   0, 128,   1,   0, 
    228, 128,   4,   0,   0,   5, 
      0,   0,  15, 128,   6,  32, 
    228, 160,   0,   0,  85, 176, 
      0,   0, 170, 128,   1,   0, 
    228, 128,   2,   0,   0,   4, 
      0,   0,  15, 128,   0,   0, 
    228, 128,   7,  32, 228, 160, 
      0,   0,  85, 176,   2,   0, 
      0,   3,   1,   0,  15, 128, 
      2,   0, 228, 129,   0,   0, 
    228, 128,   9,   0,   0,   3, 
      1,   0,   1, 128,   1,   0, 
    228, 128,   1,   0, 228, 128, 
      7,   0,   0,   2,   1,   0, 
      1, 128,   1,   0,   0, 128, 
     18,   0,   0,   4,   3,   0, 
     15, 128,   1,   0,   0, 128, 
      0,   0, 228, 128,   2,   0, 
    228, 128,   5,   0,   0,   3, 
      0,   0,  15, 128,   3,   0, 
     85, 128,   1,   0, 228, 160, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   0,   0, 228, 160, 
      3,   0,   0, 128,   0,   0, 
    228, 128,   4,   0,   0,   4, 
      0,   0,  15, 128,   2,   0, 
    228, 160,   3,   0, 170, 128, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   3,   0,  15, 224, 
      3,   0, 228, 160,   3,   0, 
    255, 128,   0,   0, 228, 128, 
      4,   0,   0,   6,   0,   0, 
      1, 128,   4,   0,  85, 144, 
    164,  32, 255, 160,   0,   0, 
      0, 176, 164,  32,  85, 160, 
      0,   0,   0, 176,   1,   0, 
      0,   3,   0,   0,  15, 208, 
    204,  32, 228, 160,   0,   0, 
      0, 176,   4,   0,   0,   4, 
      0,   0,   2, 224, 247,   0, 
     85, 160,   0,   0,   0, 128, 
    247,   0,   0, 160,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      2,   0,  85, 128,   1,   0, 
    228, 160,   4,   0,   0,   4, 
      0,   0,  15, 128,   0,   0, 
    228, 160,   2,   0,   0, 128, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      2,   0, 228, 160,   2,   0, 
    170, 128,   0,   0, 228, 128, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   3,   0, 228, 160, 
      2,   0, 255, 128,   0,   0, 
    228, 128,   1,   0,   0,   2, 
      0,   0,  15, 192,   0,   0, 
    228, 128,   1,   0,   0,   2, 
      4,   0,  15, 224,   0,   0, 
    228, 128, 255, 255,   0,   0
};
