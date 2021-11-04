#pragma once

#include <memory>

namespace Wisaya {

    template<typename T>
    using scoped = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr scoped<T> createScope(Args&& ... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using reference = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr reference<T> createRefs(Args&& ... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

} // namespace Wisaya
