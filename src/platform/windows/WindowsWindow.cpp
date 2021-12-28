#include <Wisaya_pch.hpp>
#include <platform/windows/WindowsWindow.hpp>

#include <GLFW/glfw3.h>

namespace Wisaya { namespace Platform { namespace Windows {

    static wsyUInt8 s_GLFWWindowCount = 0;

    static void GLFWErrorCallback(wsyInt32 error, wsy_cstr description) {
        WSY_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    WindowsWindow::WindowsWindow(const window_properties& properties) {
        m_Clock.start_time = 0.0f;
        m_Clock.elapsed = 0.0f;
        m_Data.Title = properties.Title;
        m_Data.Width = properties.Width;
        m_Data.Height = properties.Height;
    }

    WindowsWindow::~WindowsWindow() {
        Release();
    }

    void WindowsWindow::OnUpdate() {

        glfwPollEvents();
        m_Context->SwapBuffers();
    }

    void WindowsWindow::ClockUpdate() {
        if (m_Clock.start_time != 0)
            m_Clock.elapsed = WindowsWindow::GetPlatformAbsoluteTime() - m_Clock.start_time;
    }

    void WindowsWindow::ClockStart() {
        m_Clock.start_time = WindowsWindow::GetPlatformAbsoluteTime();
        m_Clock.elapsed = 0;
    }
    
    void WindowsWindow::ClockStop() {
        m_Clock.start_time = 0;
    }

    void WindowsWindow::SetEventCallback(const event_callback_fn& callback) const {
    
    }

    void WindowsWindow::SetVSync(wsyBool enable) {
        glfwSwapInterval(enable ? GL_TRUE : GL_FALSE);
        m_Data.VSync = enable;
    }

    wsyBool WindowsWindow::IsVSync() const {
        return m_Data.VSync;
    }


    wsyBool WindowsWindow::Initialize() {
        if (s_GLFWWindowCount == 0) {
            int success = glfwInit();
            WSY_CORE_ASSERT(success, "Could not initialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
        }
        
        #ifdef GLFW_INCLUDE_VULKAN
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        #endif

        {
        #ifdef WSY_CONFIG_DEBUG
            
        #endif
            m_Window = glfwCreateWindow(
                (int)m_Data.Width,
                (int)m_Data.Height,
                m_Data.Title.c_str(),
                nullptr,
                nullptr
            );
            ++s_GLFWWindowCount;
        }

        WSY_CORE_INFO(
            "Created window {0} ({1}, {2})",
            m_Data.Title,
            m_Data.Width,
            m_Data.Height
        );

        m_Context = wsyMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(static_cast<GLFWwindow*>(m_Window), &m_Data);
        SetVSync(false);
        return WSY_TRUE;
    }

    void WindowsWindow::Release() {
        glfwDestroyWindow(static_cast<GLFWwindow*>(m_Window));
        --s_GLFWWindowCount;

        if (s_GLFWWindowCount == 0)
            glfwTerminate();
    }

    wsyFloat64 WindowsWindow::GetPlatformAbsoluteTime() {
        return static_cast<wsyFloat64>(glfwGetTime());
    }

}}} // namespace Wisaya
