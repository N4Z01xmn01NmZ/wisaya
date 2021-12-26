#ifndef WSYMEMORY_H
#define WSYMEMORY_H

#pragma once

#include <wsydef.hpp>

#include <memory>
#include <memory.h>

// TODO Create alocator
// FIXME test

namespace Wisaya {

    template<typename T>
    using unique_ptr = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr unique_ptr<T> makeUnique(Args&& ... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using shared_ptr = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr shared_ptr<T> makeShared(Args&& ... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

} // namespace Wisaya

#endif // WSYMEMORY_H
