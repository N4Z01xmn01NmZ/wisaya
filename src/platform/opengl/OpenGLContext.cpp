#include <Wisaya_pch.hpp>
#include <platform/opengl/OpenGLContext.hpp>

#include <GLFW/glfw3.h>

namespace Wisaya { namespace Platform { namespace OpenGL {

        OpenGLContext::OpenGLContext(void* windowHandle)
            : m_WindowHandle(windowHandle) {
            WSY_CORE_ASSERT(windowHandle, "Context window is null!");
        }

        wsyBool OpenGLContext::Initialize() {
            glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_WindowHandle));
            // TODO Add glad library
            // int status = gladLoadGLLoader((GLADLoadProc)glfwGetProcAddress);
            // WSY_CORE_ASSERT(status, "Failed to initialize glad!");
        }

        void OpenGLContext::SwapBuffers() {
            glfwSwapBuffers(static_cast<GLFWwindow*>(m_WindowHandle));
        }


}}} // namespace Wisaya::Platform::OpenGL
