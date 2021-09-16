/*
 * Copyright (c) Intel Corporation
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

#pragma once

#include <string>

namespace facebook {

namespace cachelib {

struct MemoryTierCacheConfigBase {
    MemoryTierCacheConfig& setRatio(size_t ratio = 1) {
        this->ratio = ratio;
        return *this;
    }

    size_t ratio;
};

// TODO - alternatively, jus have one MemoryTierCacheConfig class
// with setDirectory and setNumaNode functions.

struct DramCacheConfig : public MemoryTierCacheConfigBase {
    // Empty.
};

struct FsDaxCacheConfig : public MemoryTierCacheConfigBase {
    FsDaxCacheConfig& setDirectory(std::string directory) {
        this->directory = directory;
        return *this;
    }

    std::string directory;
};

struct NumaNodeCacheConfig : public MemoryTierCacheConfigBase {
    NumaNodeCacheConfig& setNumaNode(size_t numaNode) {
        this->numaNode = numaNode;
        return *this;
    }

    // TODO - add support for autodetection?

    size_t numaNode;
};

using MemoryTierCacheConfig = std::variant<DramCacheConfig, FsDaxCacheConfig, NumaNodeCacheConfig>;

}

}
