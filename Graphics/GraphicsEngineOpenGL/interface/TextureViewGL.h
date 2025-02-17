/*
 *  Copyright 2019-2021 Diligent Graphics LLC
 *  Copyright 2015-2019 Egor Yusov
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *      http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#pragma once

/// \file
/// Definition of the Diligent::ITextureViewGL interface

#include "../../GraphicsEngine/interface/TextureView.h"

DILIGENT_BEGIN_NAMESPACE(Diligent)

// {15F93272-6135-414F-AB10-53FF9A5004AD}
static const INTERFACE_ID IID_TextureViewGL =
    {0x15f93272, 0x6135, 0x414f, {0xab, 0x10, 0x53, 0xff, 0x9a, 0x50, 0x4, 0xad}};

#define DILIGENT_INTERFACE_NAME ITextureViewGL
#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/DefineInterfaceHelperMacros.h"

#define ITextureViewGLInclusiveMethods \
    ITextureViewInclusiveMethods
//ITextureViewGLMethods TextureViewGL

#if DILIGENT_CPP_INTERFACE

/// Exposes OpenGL-specific functionality of a texture view object.
DILIGENT_BEGIN_INTERFACE(ITextureViewGL, ITextureView) //
{
    //const GLObjectWrappers::GLTextureObj& GetHandle();
    //GLenum GetBindTarget();
};
DILIGENT_END_INTERFACE

#endif

#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/UndefInterfaceHelperMacros.h"

#if DILIGENT_C_INTERFACE

typedef struct ITextureViewGLVtbl
{
    ITextureViewGLInclusiveMethods;
} ITextureViewGLVtbl;

typedef struct ITextureViewGL
{
    struct ITextureViewGLVtbl* pVtbl;
} ITextureViewGL;

#endif

DILIGENT_END_NAMESPACE // namespace Diligent
