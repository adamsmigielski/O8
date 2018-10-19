/** License
*
* Copyright (c) 2015 Adam �migielski
*
*
*  Permission is hereby granted, free of charge, to any person obtaining a
*      copy of this software and associated documentation files (the
*      "Software"), to deal in the Software without restriction, including
*      without limitation the rights to use, copy, modify, merge, publish,
*      distribute, sublicense, and/or sell copies of the Software, and to
*      permit persons to whom the Software is furnished to do so, subject to
*      the following conditions: The above copyright notice and this permission
*      notice shall be included in all copies or substantial portions of the
*      Software.
*
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
*      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*      MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
*      CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
*      TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
*      SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
**/

/**
* @author Adam �migielski
* @file main.cpp
**/

#include "PCH.hpp"

#include <string>
#include <iostream>
#include <vector>

#include <Platform\Platform.hpp>

#include <Utilities\basic\Assert.hpp>
#include <Utilities\basic\BreakToDebug.hpp>
#include <Utilities\basic\CallConvention.hpp>
#include <Utilities\basic\ErrorCodes.hpp>
#include <Utilities\basic\Log.hpp>

//#include <O8\GI\Loader.hpp>
//#include <O8\GI\Presentation.hpp>
//#include <O8\GI\RI.hpp>

#include <O8\Thread\Factory.hpp>

#include <O8\WS\ErrorCodes.hpp>
#include <O8\WS\Manager.hpp>
#include <O8\WS\Window.hpp>
#include <O8\WS\Window_event_handler.hpp>

#include <vulkan\vulkan.h>

#include <Vulkan\Loader.hpp>
#include <Vulkan\Implementation.hpp>
#include <Vulkan\Instance.hpp>

class Event_handler : public O8::WS::Window_event_handler
{
public:
    void Init(O8::WS::Manager * manager)
    {
        m_manager = manager;
    }

    virtual Platform::int32 On_close(
        O8::WS::Window * window,
        bool & should_window_close)
    {
        should_window_close = true;

        return 0;
    }

    virtual void On_release(
        O8::WS::Window * window)
    {
        m_manager->Stop_event_processing();
    }

private:
    O8::WS::Manager * m_manager;
};


int main()
{
    Event_handler handler;

    /* Load dlls */
    std::auto_ptr<Vulkan::Loader> vulkan_loader(Vulkan::Create_loader());
    vulkan_loader->Init("vulkan-1.dll");
    std::auto_ptr<Vulkan::Version_1_0_0::Implementation> vulkan_implementation(new Vulkan::Version_1_0_0::Implementation);
    vulkan_implementation->Init(*vulkan_loader.get());

    std::vector<VkLayerProperties> layers;
    vulkan_implementation->Enumerate_layers(layers);

    std::vector<VkExtensionProperties> implementation_extensions;
    vulkan_implementation->Enumerate_implementation_extensions(implementation_extensions);

    std::vector<std::string> extensions_to_enable;
    std::vector<std::string> extensions_to_request;
    std::vector<std::string> layers_to_enable;
    std::vector<std::string> layers_to_request;

    extensions_to_request.push_back(Vulkan::Version_1_0_0::Instance::VK_EXT_debug_report_name);
    layers_to_request.push_back(Vulkan::Version_1_0_0::Instance::VK_LAYER_LUNARG_standard_validation_name);

    vulkan_implementation->Select_extensions(extensions_to_request, implementation_extensions, extensions_to_enable);
    vulkan_implementation->Select_layers    (layers_to_request,     layers,                    layers_to_enable);

    std::vector<std::string> empty;
    auto vulkan_instance = vulkan_implementation->Create_instance(
        "Demo_vulkan",
        VK_MAKE_VERSION(1, 0, 0),
        "Red oxygen",
        VK_MAKE_VERSION(1, 0, 0),
        VK_MAKE_VERSION(1, 0, 0),
        layers_to_enable,
        extensions_to_enable);


    /* Prepare window */
    auto thread_factory = O8::Thread::Create_factory();
    auto ws_manager     = O8::WS::Create_manager(thread_factory);
    handler.Init(ws_manager);

    auto ws_window = ws_manager->Create_window();
    ws_window->Init(&handler, 16, 16, 256, 256, "O8_demo_vulkan");

#if 0
    uint32_t n_phy_dev = 0;
    result = vkEnumeratePhysicalDevices(
        vulkan_instance,
        &n_phy_dev,
        nullptr);
    if (VK_SUCCESS != result)
    {
        ERRLOG("Failed to get number of physical devices: " << result);
        return result;
    }

    LOG("There are physical devices: " << n_phy_dev);
    std::vector<VkPhysicalDevice> phy_dev;
    phy_dev.resize(n_phy_dev);
    result = vkEnumeratePhysicalDevices(
        vulkan_instance,
        &n_phy_dev,
        phy_dev.data());
    if (VK_SUCCESS != result)
    {
        ERRLOG("Failed to enumerate physical devices: " << result);
        return result;
    }

    for (auto dev : phy_dev)
    {
        VkPhysicalDeviceProperties properties;
        vkGetPhysicalDeviceProperties(dev, &properties);
        LOG("Physical device"
         << "\n\tapiVersion: "                                         << properties.apiVersion
         << "\n\tdriverVersion: "                                      << properties.driverVersion
         << "\n\tvendorID: "                                           << properties.vendorID
         << "\n\tdeviceID: "                                           << properties.deviceID
         << "\n\tdeviceType: "                                         << properties.deviceType
         << "\n\tdeviceName: "                                         << properties.deviceName
         << "\n\tpipelineCacheUUID: "                                  << properties.pipelineCacheUUID
         << "\n\tlimits"
         << "\n\t\t.maxImageDimension1D: "                             << properties.limits.maxImageDimension1D
         << "\n\t\t.maxImageDimension2D: "                             << properties.limits.maxImageDimension2D
         << "\n\t\t.maxImageDimension3D: "                             << properties.limits.maxImageDimension3D
         << "\n\t\t.maxImageDimensionCube: "                           << properties.limits.maxImageDimensionCube
         << "\n\t\t.maxImageArrayLayers: "                             << properties.limits.maxImageArrayLayers
         << "\n\t\t.maxTexelBufferElements: "                          << properties.limits.maxTexelBufferElements
         << "\n\t\t.maxUniformBufferRange: "                           << properties.limits.maxUniformBufferRange
         << "\n\t\t.maxStorageBufferRange: "                           << properties.limits.maxStorageBufferRange
         << "\n\t\t.maxPushConstantsSize: "                            << properties.limits.maxPushConstantsSize
         << "\n\t\t.maxMemoryAllocationCount: "                        << properties.limits.maxMemoryAllocationCount
         << "\n\t\t.maxSamplerAllocationCount: "                       << properties.limits.maxSamplerAllocationCount
         << "\n\t\t.bufferImageGranularity: "                          << properties.limits.bufferImageGranularity
         << "\n\t\t.sparseAddressSpaceSize: "                          << properties.limits.sparseAddressSpaceSize
         << "\n\t\t.maxBoundDescriptorSets: "                          << properties.limits.maxBoundDescriptorSets
         << "\n\t\t.maxPerStageDescriptorSamplers: "                   << properties.limits.maxPerStageDescriptorSamplers
         << "\n\t\t.maxPerStageDescriptorUniformBuffers: "             << properties.limits.maxPerStageDescriptorUniformBuffers
         << "\n\t\t.maxPerStageDescriptorStorageBuffers: "             << properties.limits.maxPerStageDescriptorStorageBuffers
         << "\n\t\t.maxPerStageDescriptorSampledImages: "              << properties.limits.maxPerStageDescriptorSampledImages
         << "\n\t\t.maxPerStageDescriptorStorageImages: "              << properties.limits.maxPerStageDescriptorStorageImages
         << "\n\t\t.maxPerStageDescriptorInputAttachments: "           << properties.limits.maxPerStageDescriptorInputAttachments
         << "\n\t\t.maxPerStageResources: "                            << properties.limits.maxPerStageResources
         << "\n\t\t.maxDescriptorSetSamplers: "                        << properties.limits.maxDescriptorSetSamplers
         << "\n\t\t.maxDescriptorSetUniformBuffers: "                  << properties.limits.maxDescriptorSetUniformBuffers
         << "\n\t\t.maxDescriptorSetUniformBuffersDynamic: "           << properties.limits.maxDescriptorSetUniformBuffersDynamic
         << "\n\t\t.maxDescriptorSetStorageBuffers: "                  << properties.limits.maxDescriptorSetStorageBuffers
         << "\n\t\t.maxDescriptorSetStorageBuffersDynamic: "           << properties.limits.maxDescriptorSetStorageBuffersDynamic
         << "\n\t\t.maxDescriptorSetSampledImages: "                   << properties.limits.maxDescriptorSetSampledImages
         << "\n\t\t.maxDescriptorSetStorageImages: "                   << properties.limits.maxDescriptorSetStorageImages
         << "\n\t\t.maxDescriptorSetInputAttachments: "                << properties.limits.maxDescriptorSetInputAttachments
         << "\n\t\t.maxVertexInputAttributes: "                        << properties.limits.maxVertexInputAttributes
         << "\n\t\t.maxVertexInputBindings: "                          << properties.limits.maxVertexInputBindings
         << "\n\t\t.maxVertexInputAttributeOffset: "                   << properties.limits.maxVertexInputAttributeOffset
         << "\n\t\t.maxVertexInputBindingStride: "                     << properties.limits.maxVertexInputBindingStride
         << "\n\t\t.maxVertexOutputComponents: "                       << properties.limits.maxVertexOutputComponents
         << "\n\t\t.maxTessellationGenerationLevel: "                  << properties.limits.maxTessellationGenerationLevel
         << "\n\t\t.maxTessellationPatchSize: "                        << properties.limits.maxTessellationPatchSize
         << "\n\t\t.maxTessellationControlPerVertexInputComponents: "  << properties.limits.maxTessellationControlPerVertexInputComponents
         << "\n\t\t.maxTessellationControlPerVertexOutputComponents: " << properties.limits.maxTessellationControlPerVertexOutputComponents
         << "\n\t\t.maxTessellationControlPerPatchOutputComponents: "  << properties.limits.maxTessellationControlPerPatchOutputComponents
         << "\n\t\t.maxTessellationControlTotalOutputComponents: "     << properties.limits.maxTessellationControlTotalOutputComponents
         << "\n\t\t.maxTessellationEvaluationInputComponents: "        << properties.limits.maxTessellationEvaluationInputComponents
         << "\n\t\t.maxTessellationEvaluationOutputComponents: "       << properties.limits.maxTessellationEvaluationOutputComponents
         << "\n\t\t.maxGeometryShaderInvocations: "                    << properties.limits.maxGeometryShaderInvocations
         << "\n\t\t.maxGeometryInputComponents: "                      << properties.limits.maxGeometryInputComponents
         << "\n\t\t.maxGeometryOutputComponents: "                     << properties.limits.maxGeometryOutputComponents
         << "\n\t\t.maxGeometryOutputVertices: "                       << properties.limits.maxGeometryOutputVertices
         << "\n\t\t.maxGeometryTotalOutputComponents: "                << properties.limits.maxGeometryTotalOutputComponents
         << "\n\t\t.maxFragmentInputComponents: "                      << properties.limits.maxFragmentInputComponents
         << "\n\t\t.maxFragmentOutputAttachments: "                    << properties.limits.maxFragmentOutputAttachments
         << "\n\t\t.maxFragmentDualSrcAttachments: "                   << properties.limits.maxFragmentDualSrcAttachments
         << "\n\t\t.maxFragmentCombinedOutputResources: "              << properties.limits.maxFragmentCombinedOutputResources
         << "\n\t\t.maxComputeSharedMemorySize: "                      << properties.limits.maxComputeSharedMemorySize
         << "\n\t\t.maxComputeWorkGroupCount[0]: "                     << properties.limits.maxComputeWorkGroupCount[0]
         << "\n\t\t.maxComputeWorkGroupCount[1]: "                     << properties.limits.maxComputeWorkGroupCount[1]
         << "\n\t\t.maxComputeWorkGroupCount[2]: "                     << properties.limits.maxComputeWorkGroupCount[2]
         << "\n\t\t.maxComputeWorkGroupInvocations: "                  << properties.limits.maxComputeWorkGroupInvocations
         << "\n\t\t.maxComputeWorkGroupSize[0]: "                      << properties.limits.maxComputeWorkGroupSize[0]
         << "\n\t\t.maxComputeWorkGroupSize[1]: "                      << properties.limits.maxComputeWorkGroupSize[1]
         << "\n\t\t.maxComputeWorkGroupSize[2]: "                      << properties.limits.maxComputeWorkGroupSize[2]
         << "\n\t\t.subPixelPrecisionBits: "                           << properties.limits.subPixelPrecisionBits
         << "\n\t\t.subTexelPrecisionBits: "                           << properties.limits.subTexelPrecisionBits
         << "\n\t\t.mipmapPrecisionBits: "                             << properties.limits.mipmapPrecisionBits
         << "\n\t\t.maxDrawIndexedIndexValue: "                        << properties.limits.maxDrawIndexedIndexValue
         << "\n\t\t.maxDrawIndirectCount: "                            << properties.limits.maxDrawIndirectCount
         << "\n\t\t.maxSamplerLodBias: "                               << properties.limits.maxSamplerLodBias
         << "\n\t\t.maxSamplerAnisotropy: "                            << properties.limits.maxSamplerAnisotropy
         << "\n\t\t.maxViewports: "                                    << properties.limits.maxViewports
         << "\n\t\t.maxViewportDimensions[0]: "                        << properties.limits.maxViewportDimensions[0]
         << "\n\t\t.maxViewportDimensions[1]: "                        << properties.limits.maxViewportDimensions[1]
         << "\n\t\t.viewportBoundsRange[0]: "                          << properties.limits.viewportBoundsRange[0]
         << "\n\t\t.viewportBoundsRange[1]: "                          << properties.limits.viewportBoundsRange[1]
         << "\n\t\t.viewportSubPixelBits: "                            << properties.limits.viewportSubPixelBits
         << "\n\t\t.minMemoryMapAlignment: "                           << properties.limits.minMemoryMapAlignment
         << "\n\t\t.minTexelBufferOffsetAlignment: "                   << properties.limits.minTexelBufferOffsetAlignment
         << "\n\t\t.minUniformBufferOffsetAlignment: "                 << properties.limits.minUniformBufferOffsetAlignment
         << "\n\t\t.minStorageBufferOffsetAlignment: "                 << properties.limits.minStorageBufferOffsetAlignment
         << "\n\t\t.minTexelOffset: "                                  << properties.limits.minTexelOffset
         << "\n\t\t.maxTexelOffset: "                                  << properties.limits.maxTexelOffset
         << "\n\t\t.minTexelGatherOffset: "                            << properties.limits.minTexelGatherOffset
         << "\n\t\t.maxTexelGatherOffset: "                            << properties.limits.maxTexelGatherOffset
         << "\n\t\t.minInterpolationOffset: "                          << properties.limits.minInterpolationOffset
         << "\n\t\t.maxInterpolationOffset: "                          << properties.limits.maxInterpolationOffset
         << "\n\t\t.subPixelInterpolationOffsetBits: "                 << properties.limits.subPixelInterpolationOffsetBits
         << "\n\t\t.maxFramebufferWidth: "                             << properties.limits.maxFramebufferWidth
         << "\n\t\t.maxFramebufferHeight: "                            << properties.limits.maxFramebufferHeight
         << "\n\t\t.maxFramebufferLayers: "                            << properties.limits.maxFramebufferLayers
         << "\n\t\t.framebufferColorSampleCounts: "                    << properties.limits.framebufferColorSampleCounts
         << "\n\t\t.framebufferDepthSampleCounts: "                    << properties.limits.framebufferDepthSampleCounts
         << "\n\t\t.framebufferStencilSampleCounts: "                  << properties.limits.framebufferStencilSampleCounts
         << "\n\t\t.framebufferNoAttachmentsSampleCounts: "            << properties.limits.framebufferNoAttachmentsSampleCounts
         << "\n\t\t.maxColorAttachments: "                             << properties.limits.maxColorAttachments
         << "\n\t\t.sampledImageColorSampleCounts: "                   << properties.limits.sampledImageColorSampleCounts
         << "\n\t\t.sampledImageIntegerSampleCounts: "                 << properties.limits.sampledImageIntegerSampleCounts
         << "\n\t\t.sampledImageDepthSampleCounts: "                   << properties.limits.sampledImageDepthSampleCounts
         << "\n\t\t.sampledImageStencilSampleCounts: "                 << properties.limits.sampledImageStencilSampleCounts
         << "\n\t\t.storageImageSampleCounts: "                        << properties.limits.storageImageSampleCounts
         << "\n\t\t.maxSampleMaskWords: "                              << properties.limits.maxSampleMaskWords
         << "\n\t\t.timestampComputeAndGraphics: "                     << properties.limits.timestampComputeAndGraphics
         << "\n\t\t.timestampPeriod: "                                 << properties.limits.timestampPeriod
         << "\n\t\t.maxClipDistances: "                                << properties.limits.maxClipDistances
         << "\n\t\t.maxCullDistances: "                                << properties.limits.maxCullDistances
         << "\n\t\t.maxCombinedClipAndCullDistances: "                 << properties.limits.maxCombinedClipAndCullDistances
         << "\n\t\t.discreteQueuePriorities: "                         << properties.limits.discreteQueuePriorities
         << "\n\t\t.pointSizeRange[0]: "                               << properties.limits.pointSizeRange[0]
         << "\n\t\t.pointSizeRange[1]: "                               << properties.limits.pointSizeRange[1]
         << "\n\t\t.lineWidthRange[0]: "                               << properties.limits.lineWidthRange[0]
         << "\n\t\t.lineWidthRange[1]: "                               << properties.limits.lineWidthRange[1]
         << "\n\t\t.pointSizeGranularity: "                            << properties.limits.pointSizeGranularity
         << "\n\t\t.lineWidthGranularity: "                            << properties.limits.lineWidthGranularity
         << "\n\t\t.strictLines: "                                     << properties.limits.strictLines
         << "\n\t\t.standardSampleLocations: "                         << properties.limits.standardSampleLocations
         << "\n\t\t.optimalBufferCopyOffsetAlignment: "                << properties.limits.optimalBufferCopyOffsetAlignment
         << "\n\t\t.optimalBufferCopyRowPitchAlignment: "              << properties.limits.optimalBufferCopyRowPitchAlignment
         << "\n\t\t.nonCoherentAtomSize: "                             << properties.limits.nonCoherentAtomSize
         << "\n\tsparseProperties"
         << "\n\t\t.residencyStandard2DBlockShape: "                   << properties.sparseProperties.residencyStandard2DBlockShape
         << "\n\t\t.residencyStandard2DMultisampleBlockShape: "        << properties.sparseProperties.residencyStandard2DMultisampleBlockShape
         << "\n\t\t.residencyStandard3DBlockShape: "                   << properties.sparseProperties.residencyStandard3DBlockShape
         << "\n\t\t.residencyAlignedMipSize: "                         << properties.sparseProperties.residencyAlignedMipSize
         << "\n\t\t.residencyNonResidentStrict: "                      << properties.sparseProperties.residencyNonResidentStrict);
    }
    VkPhysicalDevice dev = phy_dev[0];

    uint32_t n_queue = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(dev, &n_queue, nullptr);
    uint32_t queue_idx = 0;
    std::vector<VkQueueFamilyProperties> queue_prop;
    queue_prop.resize(n_queue);
    vkGetPhysicalDeviceQueueFamilyProperties(dev, &n_queue, queue_prop.data());
    for (auto prop : queue_prop)
    {
        if ((0 != prop.queueCount) &&
            (0 != (VK_QUEUE_GRAPHICS_BIT & prop.queueFlags)))
        {
            break;
        }
        queue_idx += 1;
    }

    float queue_priority = 1.0f;
    VkDeviceQueueCreateInfo queue_create_info = {
        VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO /* VkStructureType             sType; */,
        nullptr                                    /* const void*                 pNext; */,
        0                                          /* VkDeviceQueueCreateFlags    flags; */,
        queue_idx                                  /* uint32_t                    queueFamilyIndex; */,
        1                                          /* uint32_t                    queueCount; */,
        &queue_priority                            /* const float*                pQueuePriorities; */
    };

    VkDeviceCreateInfo device_create_info = {
        VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO /* VkStructureType                    sType; */,
        nullptr                              /* const void*                        pNext; */,
        0                                    /* VkDeviceCreateFlags                flags; */,
        1                                    /* uint32_t                           queueCreateInfoCount; */,
        &queue_create_info                   /* const VkDeviceQueueCreateInfo*     pQueueCreateInfos; */,
        0                                    /* uint32_t                           enabledLayerCount; */,
        nullptr                              /* const char* const*                 ppEnabledLayerNames; */,
        0                                    /* uint32_t                           enabledExtensionCount; */,
        nullptr                              /* const char* const*                 ppEnabledExtensionNames; */,
        nullptr                              /* const VkPhysicalDeviceFeatures*    pEnabledFeatures; */
    };

    VkDevice vulkan_device;
    result = vkCreateDevice(
        dev,
        &device_create_info,
        nullptr /* const VkAllocationCallbacks* pAllocator */,
        &vulkan_device);
    if (VK_SUCCESS != result)
    {
        ERRLOG("Failed to create device: " << result);
        return result;
    }

    VkQueue queue;
    vkGetDeviceQueue(vulkan_device, queue_idx, 0, &queue);
#endif

    /* Prepare graphics interface */
    //O8::GI::GI * gi = O8::GI::Create_GI();
    //gi->Init();
    //auto ri = gi->Create_rendering_interface(gi->First());
    //auto presentation = ri->Create_presentation_for_window(ws_window->Get_native());
    //ws_window->Set_user_data(presentation);

    /* Start window events processing */
    ws_manager->Start_event_processing();
    /* Event processing loop has finished */

    /* Release graphics interface */
    //delete presentation;
    //delete ri;
    //delete gi;
#if 0
    vkDestroyDevice(vulkan_device, nullptr);
#endif

    /* Release window */
    delete ws_window;
    delete ws_manager;

    /* Done */
    return 0;
}