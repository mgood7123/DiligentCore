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
/// Definition of the Diligent::IQueryMtl interface

#include "../../GraphicsEngine/interface/Query.h"

DILIGENT_BEGIN_NAMESPACE(Diligent)

// {514BAE55-C3E9-4D78-A013-63522FD595DA}
static const INTERFACE_ID IID_QueryMtl =
    {0x514bae55, 0xc3e9, 0x4d78, {0xa0, 0x13, 0x63, 0x52, 0x2f, 0xd5, 0x95, 0xda}};

#define DILIGENT_INTERFACE_NAME IQueryMtl
#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/DefineInterfaceHelperMacros.h"

#define IQueryMtlInclusiveMethods \
    IQueryInclusiveMethods
//IQueryMtlMethods QueryMtl

#if DILIGENT_CPP_INTERFACE

/// Exposes Metal-specific functionality of a Query object.
DILIGENT_BEGIN_INTERFACE(IQueryMtl, IQuery){};
DILIGENT_END_INTERFACE

#endif

#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/UndefInterfaceHelperMacros.h"

#if DILIGENT_C_INTERFACE

typedef struct IQueryMtlVtbl
{
    IQueryMtlInclusiveMethods;
} IQueryMtlVtbl;

typedef struct IQueryMtl
{
    struct IQueryMtlVtbl* pVtbl;
} IQueryMtl;

#endif

DILIGENT_END_NAMESPACE // namespace Diligent
