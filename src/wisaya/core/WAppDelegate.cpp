#include <Wisaya_pch.hpp>
#include <wisaya/core/WAppDelegate.hpp>

#include <wsyclock.hpp>
#include <event/WisayaApplicationEvent.hpp>

namespace Wisaya {

    WAppDelegate* WAppDelegate::s_Instance = nullptr;

    WAppDelegate* WAppDelegate::GetInstance() {
        return s_Instance;
    }

    void WAppDelegate::ReleaseInstance() {
        if (s_Instance != nullptr)
            delete s_Instance;
        s_Instance = nullptr;
    }

    WAppDelegate::WAppDelegate() {       
        WSY_CORE_TRACE("Creating application instance...");
        s_Instance = this;
        m_Running = true;
        m_Suspended = false;
        m_LastFrameTime = 0.0f;

        m_Window = nullptr;
    }

    WAppDelegate::~WAppDelegate() {
        
    }

    wsyBool WAppDelegate::Initialize() {
        WSY_CORE_TRACE("Initializing application instance...");

        m_Window = wsyCreateWindow();
        if (m_Window->Initialize() == WSY_FALSE)
            return WSY_FALSE;

        return WSY_TRUE;
    }

    void WAppDelegate::Shutdown() {
        WSY_CORE_TRACE("Shutting down application...");
    }

    void WAppDelegate::Run() {
        while (m_Running) {
            wsyFloat64 currentTime = m_Window->GetTimeMillis();
            wsyFloat64 deltaTime = currentTime - m_LastFrameTime;
            m_LastFrameTime = currentTime;
            WSY_CORE_TRACE("{0}", deltaTime);
            m_Window->OnUpdate();
        }
        WSY_CORE_INFO("Task executed succesfully!");

        Shutdown();
        WAppDelegate::ReleaseInstance();
    }

    void WAppDelegate::OnEvent(WisayaEvent& evt) {
        
    }

} // namespace Wisaya
