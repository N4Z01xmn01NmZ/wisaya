#ifndef WISAYACONTEXT_H
#define WISAYACONTEXT_H

#pragma once

#include <wsymemory.hpp>

namespace Wisaya {

    class WisayaContext
    {
    public:
        ~WisayaContext() = default;

        virtual wsyBool Initialize() = 0;
        virtual void SwapBuffers() = 0;

        static scoped_ptr<WisayaContext> Create(void* window);
    };

    static scoped_ptr<WisayaContext> wsyMakeContextCurrent(void* window) {
        return WisayaContext::Create(std::forward<void*>(window));
    }

} // namespace Wisaya


#endif // WISAYACONTEXT_H