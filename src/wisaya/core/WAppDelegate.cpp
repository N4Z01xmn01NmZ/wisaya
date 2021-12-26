#include <Wisaya_pch.hpp>
#include <wisaya/core/WAppDelegate.hpp>

#include <wsylog.hpp>
#include <wsyassert.hpp>

#include <event/wsyApplicationEvent.hpp>

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
    }

    WAppDelegate::~WAppDelegate() {
        
    }

    wsyBool WAppDelegate::Initialize() {
        WSY_CORE_TRACE("Initializing application instance...");
        return WSY_TRUE;
    }

    void WAppDelegate::Shutdown() {
        WSY_CORE_TRACE("Shutting down application...");
    }

    void WAppDelegate::Run() {
        // while (m_Running) {  
            
        // }
        WSY_CORE_INFO("Task executed succesfully!");

        Shutdown();
        WAppDelegate::ReleaseInstance();
    }

} // namespace Wisaya
