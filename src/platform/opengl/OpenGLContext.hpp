#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H

#pragma once

#include <wisaya/rendering/WisayaContext.hpp>

namespace Wisaya { namespace Platform { namespace OpenGL {

    class OpenGLContext : public WisayaContext
    {
    public:
        OpenGLContext(void* windowHandle);

        virtual wsyBool Initialize() override;
        virtual void SwapBuffers() override;
    private:
        void* m_WindowHandle;
    };

}}} // namespace Wisaya::Platform::OpenGL

#endif // OPENGL_CONTEXT_H