#include <wisaya/core/appdelegate.hpp>

#include <wsylog.hpp>
#include <wsyassert.hpp>

#include <event/wsyApplicationEvent.hpp>

namespace Wisaya {

    AppDelegate* AppDelegate::s_Instance = nullptr;

    AppDelegate* AppDelegate::GetInstance() {
        return s_Instance;
    }

    void AppDelegate::ReleaseInstance() {
        if (s_Instance != nullptr)
            delete s_Instance;
        s_Instance = nullptr;
    }

    AppDelegate::AppDelegate() {       
        WSY_CORE_TRACE("Creating application instance...");
        s_Instance = this;
        m_Running = true;
        m_Suspended = false;
    }

    AppDelegate::~AppDelegate() {
        
    }

    wsyBool AppDelegate::Initialize() {
        WSY_CORE_TRACE("Initializing application instance...");
        return WSY_TRUE;
    }

    void AppDelegate::Shutdown() {
        WSY_CORE_TRACE("Shutting down application...");
    }

    void AppDelegate::Run() {
        // while (m_Running) {  
            
        // }
        WSY_CORE_INFO("Task executed succesfully!");

        Shutdown();
        AppDelegate::ReleaseInstance();
    }

} // namespace Wisaya
