/* Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "vulkan_helpers/structs.h"

#include <utility>

static_assert(VK_VERSION_1_0 == 1 && VK_HEADER_VERSION == 203,
              "review the following to make sure that all enumerant values are "
              "covered after updating vulkan.h");

namespace vulkan {

containers::vector<::VkFormat> AllVkFormats(containers::Allocator* allocator) {
  containers::vector<::VkFormat> formats(allocator);
  //                       0: VK_FORMAT_UNDEFINED
  //          1 -        184: assigned
  // 1000054000 - 1000054007: assigned
  // 1000066000 - 1000066013: assigned
  // 1000156000 - 1000156033: assigned
  // 1000340000 - 1000340001: assigned
  // These are due to BEGIN_RANGE, END_RANGE, RANGE_SIZE removed in 1.2.140
  const uint64_t VK_FORMAT_BEGIN_RANGE = VK_FORMAT_UNDEFINED;
  const uint64_t VK_FORMAT_END_RANGE = VK_FORMAT_ASTC_12x12_SRGB_BLOCK;
  const uint64_t VK_FORMAT_RANGE_SIZE =
      (VK_FORMAT_ASTC_12x12_SRGB_BLOCK - VK_FORMAT_UNDEFINED + 1);
  formats.reserve(VK_FORMAT_RANGE_SIZE + 8 + 14 + 34 + 2);
  for (uint64_t i = VK_FORMAT_BEGIN_RANGE; i <= VK_FORMAT_END_RANGE; ++i) {
    formats.push_back(static_cast<::VkFormat>(i));
  }
  for (uint64_t i = 1000054000ul; i <= 1000054007ul; ++i) {
    formats.push_back(static_cast<::VkFormat>(i));
  }
  for (uint64_t i = 1000066000ul; i <= 1000066013ul; ++i) {
    formats.push_back(static_cast<::VkFormat>(i));
  }
  for (uint64_t i = 1000156000ul; i <= 1000156033ul; ++i) {
    formats.push_back(static_cast<::VkFormat>(i));
  }
  for (uint64_t i = 1000340000ul; i <= 1000340001ul; ++i) {
    formats.push_back(static_cast<::VkFormat>(i));
  }

  return std::move(formats);
}

containers::vector<::VkImageType> AllVkImageTypes(
    containers::Allocator* allocator) {
  containers::vector<::VkImageType> types(allocator);
  // These are due to BEGIN_RANGE, END_RANGE, RANGE_SIZE removed in 1.2.140
  const uint64_t VK_IMAGE_TYPE_BEGIN_RANGE = VK_IMAGE_TYPE_1D;
  const uint64_t VK_IMAGE_TYPE_END_RANGE = VK_IMAGE_TYPE_3D;
  const uint64_t VK_IMAGE_TYPE_RANGE_SIZE =
      (VK_IMAGE_TYPE_3D - VK_IMAGE_TYPE_1D + 1);
  types.reserve(VK_IMAGE_TYPE_RANGE_SIZE);
  for (uint64_t i = VK_IMAGE_TYPE_BEGIN_RANGE; i <= VK_IMAGE_TYPE_END_RANGE;
       ++i) {
    types.push_back(static_cast<::VkImageType>(i));
  }
  return std::move(types);
}

containers::vector<::VkImageTiling> AllVkImageTilings(
    containers::Allocator* allocator) {
  containers::vector<::VkImageTiling> tilings(allocator);
  // These are due to BEGIN_RANGE, END_RANGE, RANGE_SIZE removed in 1.2.140
  const uint64_t VK_IMAGE_TILING_BEGIN_RANGE = VK_IMAGE_TILING_OPTIMAL;
  const uint64_t VK_IMAGE_TILING_END_RANGE = VK_IMAGE_TILING_LINEAR;
  const uint64_t VK_IMAGE_TILING_RANGE_SIZE =
      (VK_IMAGE_TILING_LINEAR - VK_IMAGE_TILING_OPTIMAL + 1);
  tilings.reserve(VK_IMAGE_TILING_RANGE_SIZE);
  for (uint64_t i = VK_IMAGE_TILING_BEGIN_RANGE; i <= VK_IMAGE_TILING_END_RANGE;
       ++i) {
    tilings.push_back(static_cast<::VkImageTiling>(i));
  }
  return std::move(tilings);
}

containers::vector<::VkImageUsageFlags> AllVkImageUsageFlagCombinations(
    containers::Allocator* allocator) {
  containers::vector<::VkImageUsageFlags> flags(allocator);
  const uint64_t min = VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
  const uint64_t max = VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT << 1;
  flags.reserve(max - 1);
  for (uint64_t i = min; i < max; ++i) {
    flags.push_back(static_cast<::VkImageUsageFlags>(i));
  }
  return std::move(flags);
}

containers::vector<::VkImageCreateFlags> AllVkImageCreateFlagCombinations(
    containers::Allocator* allocator) {
  containers::vector<::VkImageCreateFlags> flags(allocator);
  const uint64_t min = VK_IMAGE_CREATE_SPARSE_BINDING_BIT;
  const uint64_t max = VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT << 1;
  flags.reserve(max - 1);
  for (uint64_t i = min; i < max; ++i) {
    flags.push_back(static_cast<::VkImageCreateFlags>(i));
  }
  return std::move(flags);
}

containers::vector<::VkSampleCountFlagBits> DecomposeVkSmapleCountFlagBits(
    const ::VkSampleCountFlags flags, containers::Allocator* allocator) {
  containers::vector<::VkSampleCountFlagBits> bits(allocator);
  bits.reserve(7u);  // We have 7 possible sample count flag bits till now.
  for (uint64_t i = VK_SAMPLE_COUNT_1_BIT; i <= VK_SAMPLE_COUNT_64_BIT;
       i <<= 1) {
    if (flags & i) bits.push_back(static_cast<::VkSampleCountFlagBits>(i));
  }
  return std::move(bits);
}

containers::vector<::VkCommandBufferLevel> AllVkCommandBufferLevels(
    containers::Allocator* allocator) {
  containers::vector<::VkCommandBufferLevel> levels(allocator);
  // These are due to BEGIN_RANGE, END_RANGE, RANGE_SIZE removed in 1.2.140
  const uint64_t VK_COMMAND_BUFFER_LEVEL_BEGIN_RANGE =
      VK_COMMAND_BUFFER_LEVEL_PRIMARY;
  const uint64_t VK_COMMAND_BUFFER_LEVEL_END_RANGE =
      VK_COMMAND_BUFFER_LEVEL_SECONDARY;
  const uint64_t VK_COMMAND_BUFFER_LEVEL_RANGE_SIZE =
      (VK_COMMAND_BUFFER_LEVEL_SECONDARY - VK_COMMAND_BUFFER_LEVEL_PRIMARY + 1);
  levels.reserve(VK_COMMAND_BUFFER_LEVEL_RANGE_SIZE);
  for (uint64_t i = VK_COMMAND_BUFFER_LEVEL_BEGIN_RANGE;
       i <= VK_COMMAND_BUFFER_LEVEL_END_RANGE; ++i) {
    levels.push_back(static_cast<::VkCommandBufferLevel>(i));
  }
  return std::move(levels);
}

containers::vector<::VkCommandBufferResetFlags>
AllVkCommandBufferResetFlagCombinations(containers::Allocator* allocator) {
  containers::vector<::VkCommandBufferResetFlags> flags(allocator);
  const uint64_t min = 0;
  const uint64_t max = VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT << 1;
  flags.reserve(max);
  for (uint64_t i = min; i < max; ++i) {
    flags.push_back(static_cast<::VkCommandBufferResetFlags>(i));
  }
  return std::move(flags);
}

}  // namespace vulkan
