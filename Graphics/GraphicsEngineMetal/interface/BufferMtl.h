/*
 *  Copyright 2019-2021 Diligent Graphics LLC
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
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
/// Definition of the Diligent::IBufferMtl interface

#include "../../GraphicsEngine/interface/Buffer.h"

DILIGENT_BEGIN_NAMESPACE(Diligent)

// {F8A1A3AC-923A-419D-AB9D-FE9E35DC654B}
static const INTERFACE_ID IID_BufferMtl =
    {0xf8a1a3ac, 0x923a, 0x419d, {0xab, 0x9d, 0xfe, 0x9e, 0x35, 0xdc, 0x65, 0x4b}};

#define DILIGENT_INTERFACE_NAME IBufferMtl
#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/DefineInterfaceHelperMacros.h"

#define IBufferMtlInclusiveMethods \
    IBufferInclusiveMethods;       \
    IBufferMtlMethods BufferMtl

// clang-format off

/// Exposes Metal-specific functionality of a buffer object.
DILIGENT_BEGIN_INTERFACE(IBufferMtl, IBuffer)
{
    /// Returns a pointer to a Metal buffer object.
    VIRTUAL id<MTLBuffer> METHOD(GetMtlResource)(THIS) CONST PURE;
};
DILIGENT_END_INTERFACE

#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/UndefInterfaceHelperMacros.h"

#if DILIGENT_C_INTERFACE

#    define IBufferMtl_GetMtlResource(This) CALL_IFACE_METHOD(BufferMtl, GetMtlResource, This)

#endif

DILIGENT_END_NAMESPACE // namespace Diligent
