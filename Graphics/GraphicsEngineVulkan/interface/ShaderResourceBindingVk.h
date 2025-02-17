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
/// Definition of the Diligent::IShaderResourceBindingVk interface and related data structures

#include "../../GraphicsEngine/interface/ShaderResourceBinding.h"

DILIGENT_BEGIN_NAMESPACE(Diligent)

// {1E8C82DC-5B3A-47D5-8AE9-197CAE8DB71F}
static const INTERFACE_ID IID_ShaderResourceBindingVk =
    {0x1e8c82dc, 0x5b3a, 0x47d5, {0x8a, 0xe9, 0x19, 0x7c, 0xae, 0x8d, 0xb7, 0x1f}};

#define DILIGENT_INTERFACE_NAME IShaderResourceBindingVk
#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/DefineInterfaceHelperMacros.h"

#define IShaderResourceBindingVkInclusiveMethods \
    IShaderResourceBindingInclusiveMethods
//IShaderResourceBindingVkMethods ShaderResourceBindingVk

#if DILIGENT_CPP_INTERFACE

/// Exposes Vulkan-specific functionality of a shader resource binding object.
DILIGENT_BEGIN_INTERFACE(IShaderResourceBindingVk, IShaderResourceBinding){};
DILIGENT_END_INTERFACE

#endif

#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/UndefInterfaceHelperMacros.h"

#if DILIGENT_C_INTERFACE

typedef struct IShaderResourceBindingVkVtbl
{
    IShaderResourceBindingVkInclusiveMethods;
} IShaderResourceBindingVkVtbl;

#endif

DILIGENT_END_NAMESPACE // namespace Diligent
