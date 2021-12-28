#ifndef WSYMEMORY_H
#define WSYMEMORY_H

#pragma once

#include <wsydef.hpp>

#include <memory>
#include <memory.h>

// TODO Create alocator

namespace Wisaya {

    template<typename T>
    using scoped_ptr = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr scoped_ptr<T> create_scoped(Args&& ... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using reference_ptr = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr reference_ptr<T> create_reference(Args&& ... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

} // namespace Wisaya

#endif // WSYMEMORY_H
