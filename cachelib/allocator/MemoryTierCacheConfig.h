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

struct MemoryTierCacheConfig {
    static MemoryTierCacheConfig fromAnonymousMemory(int numa = -1);
    static MemoryTierCacheConfig fromDirectory(std::string directory);

    // set size ratio of this memory tier (1.0 by default)
    // ALTERNATIVELY: specify absolute size (this would require changing/removing
    // global setCacheSize() or require user to properly split the size)
    MemoryTierCacheConfig& setRatio(double ratio);

    // TODO:
    // setBaseAddr() (from enableCachePersistence)
    // enableMmemoryMonitor()

private:
    MemoryTierCacheConfig() = default;

    int numa = -1;
    std::string directory;
    double ratio = 1.0;
};

}

}
