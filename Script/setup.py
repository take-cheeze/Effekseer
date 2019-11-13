import shutil
import os
import platform

os.chdir(os.path.dirname(os.path.abspath(__file__)))

shutil.rmtree('../Dev/release/resources/fonts', ignore_errors=True)
shutil.copytree('../ResourceData/tool/resources/fonts', '../Dev/release/resources/fonts')

pf = platform.system()
if pf == 'Windows':
    shutil.copyfile("../ResourceData/tool/tools/win/fbxToEffekseerModelConverter.exe", "../Dev/release/tools/fbxToEffekseerModelConverter.exe")

if pf == 'Darwin':
    shutil.copyfile("../ResourceData/tool/tools/mac/fbxToEffekseerModelConverter", "../Dev/release/tools/fbxToEffekseerModelConverter")
    shutil.copyfile("../ResourceData/tool/tools/mac/libfbxsdk.dylib", "../Dev/release/tools/libfbxsdk.dylib")

    