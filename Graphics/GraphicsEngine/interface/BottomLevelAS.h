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
/// Definition of the Diligent::IBottomLevelAS interface and related data structures

#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/Object.h"
#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/FlagEnum.h"
#include "GraphicsTypes.h"
#include "Constants.h"
#include "Buffer.h"

DILIGENT_BEGIN_NAMESPACE(Diligent)

// {E56F5755-FE5E-496C-BFA7-BCD535360FF7}
static const INTERFACE_ID IID_BottomLevelAS =
    {0xe56f5755, 0xfe5e, 0x496c, {0xbf, 0xa7, 0xbc, 0xd5, 0x35, 0x36, 0xf, 0xf7}};

// clang-format off

static const Uint32 INVALID_INDEX = ~0u;


/// Defines bottom level acceleration structure triangles description.

/// Triangle geometry description.
struct BLASTriangleDesc
{
    /// Geometry name.
    /// The name is used to map triangle data (BLASBuildTriangleData) to this geometry.
    const char*               GeometryName          DEFAULT_INITIALIZER(nullptr);

    /// The maximum vertex count in this geometry.
    /// Current number of vertices is defined in BLASBuildTriangleData::VertexCount.
    Uint32                    MaxVertexCount        DEFAULT_INITIALIZER(0);

    /// The type of vertices in this geometry, see Diligent::VALUE_TYPE.
    /// 
    /// \remarks Only the following values are allowed: VT_FLOAT32, VT_FLOAT16, VT_INT16.
    ///          VT_INT16 defines 16-bit signed normalized vertex components.
    VALUE_TYPE                VertexValueType       DEFAULT_INITIALIZER(VT_UNDEFINED);

    /// The number of components in the vertex.
    /// 
    /// \remarks Only 2 or 3 are allowed values. For 2-component formats, the third component is assumed 0.
    Uint8                     VertexComponentCount  DEFAULT_INITIALIZER(0);

    /// The maximum primitive count in this geometry.
    /// The current number of primitives is defined in BLASBuildTriangleData::PrimitiveCount.
    Uint32                    MaxPrimitiveCount     DEFAULT_INITIALIZER(0);

    /// Index type of this geometry, see Diligent::VALUE_TYPE.
    /// Must be VT_UINT16, VT_UINT32 or VT_UNDEFINED.
    /// If not defined then vertex array is used instead of indexed vertices.
    VALUE_TYPE                IndexType             DEFAULT_INITIALIZER(VT_UNDEFINED);

    /// Vulkan only, allows to use transformations in BLASBuildTriangleData.
    Bool                      AllowsTransforms      DEFAULT_INITIALIZER(False);
    
#if DILIGENT_CPP_INTERFACE
    BLASTriangleDesc() noexcept {}
#endif
};
typedef struct BLASTriangleDesc BLASTriangleDesc;


/// Defines bottom level acceleration structure axis-aligned bounding boxes description.

/// AABB geometry description.
struct BLASBoundingBoxDesc
{
    /// Geometry name.
    /// The name is used to map AABB data (BLASBuildBoundingBoxData) to this geometry.
    const char*               GeometryName  DEFAULT_INITIALIZER(nullptr);
    
    /// The maximum AABB count.
    /// Current number of AABBs is defined in BLASBuildBoundingBoxData::BoxCount. 
    Uint32                    MaxBoxCount   DEFAULT_INITIALIZER(0);
    
#if DILIGENT_CPP_INTERFACE
    BLASBoundingBoxDesc() noexcept {}
#endif
};
typedef struct BLASBoundingBoxDesc BLASBoundingBoxDesc;


/// Defines acceleration structures build flags.
DILIGENT_TYPED_ENUM(RAYTRACING_BUILD_AS_FLAGS, Uint8)
{
    RAYTRACING_BUILD_AS_NONE              = 0,

    /// Indicates that the specified acceleration structure can be updated
    /// via IDeviceContext::BuildBLAS() or IDeviceContext::BuildTLAS().
    /// With this flag, the acceleration structure may allocate more memory and take more time to build.
    RAYTRACING_BUILD_AS_ALLOW_UPDATE      = 0x01,

    /// Indicates that the specified acceleration structure can act as the source for
    /// a copy acceleration structure command IDeviceContext::CopyBLAS() or IDeviceContext::CopyTLAS()
    /// with COPY_AS_MODE_COMPACT mode to produce a compacted acceleration structure.
    /// With this flag acculeration structure may allocate more memory and take more time on build.
    RAYTRACING_BUILD_AS_ALLOW_COMPACTION  = 0x02,

    /// Indicates that the given acceleration structure build should prioritize trace performance over build time.
    RAYTRACING_BUILD_AS_PREFER_FAST_TRACE = 0x04,

    /// Indicates that the given acceleration structure build should prioritize build time over trace performance.
    RAYTRACING_BUILD_AS_PREFER_FAST_BUILD = 0x08,

    /// Indicates that this acceleration structure should minimize the size of the scratch memory and the final
    /// result build, potentially at the expense of build time or trace performance.
    RAYTRACING_BUILD_AS_LOW_MEMORY        = 0x10,

    RAYTRACING_BUILD_AS_FLAGS_LAST        = RAYTRACING_BUILD_AS_LOW_MEMORY
};
DEFINE_FLAG_ENUM_OPERATORS(RAYTRACING_BUILD_AS_FLAGS)


/// Bottom-level AS description.
struct BottomLevelASDesc DILIGENT_DERIVE(DeviceObjectAttribs)

    /// Array of triangle geometry descriptions.
    const BLASTriangleDesc*    pTriangles       DEFAULT_INITIALIZER(nullptr);

    /// The number of triangle geometries in pTriangles array.
    Uint32                     TriangleCount    DEFAULT_INITIALIZER(0);

    /// Array of AABB geometry descriptions.
    const BLASBoundingBoxDesc* pBoxes           DEFAULT_INITIALIZER(nullptr);

    /// The number of AABB geometries in pBoxes array.
    Uint32                     BoxCount         DEFAULT_INITIALIZER(0);

    /// Ray tracing build flags, see Diligent::RAYTRACING_BUILD_AS_FLAGS.
    RAYTRACING_BUILD_AS_FLAGS  Flags            DEFAULT_INITIALIZER(RAYTRACING_BUILD_AS_NONE);

    /// Size from the result of IDeviceContext::WriteBLASCompactedSize() if this acceleration structure
    /// is going to be the target of a compacting copy (IDeviceContext::CopyBLAS() with COPY_AS_MODE_COMPACT).
    Uint32                     CompactedSize    DEFAULT_INITIALIZER(0);

    /// Defines which immediate contexts are allowed to execute commands that use this BLAS.

    /// When ImmediateContextMask contains a bit at position n, the acceleration structure may be
    /// used in the immediate context with index n directly (see DeviceContextDesc::ContextId).
    /// It may also be used in a command list recorded by a deferred context that will be executed
    /// through that immediate context.
    ///
    /// \remarks    Only specify these bits that will indicate those immediate contexts where the BLAS
    ///             will actually be used. Do not set unncessary bits as this will result in extra overhead.
    Uint64                     ImmediateContextMask    DEFAULT_INITIALIZER(1);

#if DILIGENT_CPP_INTERFACE
    BottomLevelASDesc() noexcept {}
#endif
};
typedef struct BottomLevelASDesc BottomLevelASDesc;


/// Defines the scratch buffer info for acceleration structure.
struct ScratchBufferSizes
{
    /// Scratch buffer size for acceleration structure building,
    /// see IDeviceContext::BuildBLAS(), IDeviceContext::BuildTLAS().
    /// May be zero if the acceleration structure was created with non-zero CompactedSize.
    Uint32 Build  DEFAULT_INITIALIZER(0);
    
    /// Scratch buffer size for acceleration structure updating,
    /// see IDeviceContext::BuildBLAS(), IDeviceContext::BuildTLAS().
    /// May be zero if acceleration structure was created without RAYTRACING_BUILD_AS_ALLOW_UPDATE flag.
    /// May be zero if acceleration structure was created with non-zero CompactedSize.
    Uint32 Update DEFAULT_INITIALIZER(0);
    
#if DILIGENT_CPP_INTERFACE
    ScratchBufferSizes() noexcept {}
#endif
};
typedef struct ScratchBufferSizes ScratchBufferSizes;


#define DILIGENT_INTERFACE_NAME IBottomLevelAS
#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/DefineInterfaceHelperMacros.h"

#define IBottomLevelASInclusiveMethods     \
    IDeviceObjectInclusiveMethods;         \
    IBottomLevelASMethods BottomLevelAS

/// Bottom-level AS interface

/// Defines the methods to manipulate a BLAS object
DILIGENT_BEGIN_INTERFACE(IBottomLevelAS, IDeviceObject)
{
#if DILIGENT_CPP_INTERFACE
    /// Returns the bottom level AS description used to create the object
    virtual const BottomLevelASDesc& DILIGENT_CALL_TYPE GetDesc() const override = 0;
#endif

    /// Returns the geometry description index in BottomLevelASDesc::pTriangles or BottomLevelASDesc::pBoxes.

    /// \param [in] Name - Geometry name that is specified in BLASTriangleDesc or BLASBoundingBoxDesc.
    /// \return Geometry index or INVALID_INDEX if geometry does not exist.
    /// 
    /// \note Access to the BLAS must be externally synchronized.
    VIRTUAL Uint32 METHOD(GetGeometryDescIndex)(THIS_
                                                const char* Name) CONST PURE;


    /// Returns the geometry index that can be used in a shader binding table.
    
    /// \param [in] Name - Geometry name that is specified in BLASTriangleDesc or BLASBoundingBoxDesc.
    /// \return Geometry index or INVALID_INDEX if geometry does not exist.
    /// 
    /// \note Access to the BLAS must be externally synchronized.
    VIRTUAL Uint32 METHOD(GetGeometryIndex)(THIS_
                                            const char* Name) CONST PURE;


    /// Returns the geometry count that was used to build AS.
    /// Same as BuildBLASAttribs::TriangleDataCount or BuildBLASAttribs::BoxDataCount.

    /// \return The number of geometries that was used to build AS.
    /// 
    /// \note Access to the BLAS must be externally synchronized.
    VIRTUAL Uint32 METHOD(GetActualGeometryCount)(THIS) CONST PURE;


    /// Returns the scratch buffer info for the current acceleration structure.
    
    /// \return ScratchBufferSizes object, see Diligent::ScratchBufferSizes.
    VIRTUAL ScratchBufferSizes METHOD(GetScratchBufferSizes)(THIS) CONST PURE;


    /// Returns the native acceleration structure handle specific to the underlying graphics API

    /// \return pointer to ID3D12Resource interface, for D3D12 implementation\n
    ///         VkAccelerationStructure handle, for Vulkan implementation
    VIRTUAL void* METHOD(GetNativeHandle)(THIS) PURE;


    /// Sets the acceleration structure usage state.

    /// \note This method does not perform state transition, but
    ///       resets the internal acceleration structure state to the given value.
    ///       This method should be used after the application finished
    ///       manually managing the acceleration structure state and wants to hand over
    ///       state management back to the engine.
    VIRTUAL void METHOD(SetState)(THIS_
                                  RESOURCE_STATE State) PURE;


    /// Returns the internal acceleration structure state
    VIRTUAL RESOURCE_STATE METHOD(GetState)(THIS) CONST PURE;
};
DILIGENT_END_INTERFACE

#include "../../../../../MultiTouch/DiligentLog/Primitives/interface/UndefInterfaceHelperMacros.h"

#if DILIGENT_C_INTERFACE

// clang-format off

#    define IBottomLevelAS_GetGeometryDescIndex(This, ...)  CALL_IFACE_METHOD(BottomLevelAS, GetGeometryDescIndex,   This, __VA_ARGS__)
#    define IBottomLevelAS_GetGeometryIndex(This, ...)      CALL_IFACE_METHOD(BottomLevelAS, GetGeometryIndex,       This, __VA_ARGS__)
#    define IBottomLevelAS_GetActualGeometryCount(This)     CALL_IFACE_METHOD(BottomLevelAS, GetActualGeometryCount, This)
#    define IBottomLevelAS_GetScratchBufferSizes(This)      CALL_IFACE_METHOD(BottomLevelAS, GetScratchBufferSizes,  This)
#    define IBottomLevelAS_GetNativeHandle(This)            CALL_IFACE_METHOD(BottomLevelAS, GetNativeHandle,        This)
#    define IBottomLevelAS_SetState(This, ...)              CALL_IFACE_METHOD(BottomLevelAS, SetState,               This, __VA_ARGS__)
#    define IBottomLevelAS_GetState(This)                   CALL_IFACE_METHOD(BottomLevelAS, GetState,               This)

// clang-format on

#endif

DILIGENT_END_NAMESPACE // namespace Diligent
