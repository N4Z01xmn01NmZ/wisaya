#include "appdelegate.hpp"

#include <wsylog.hpp>
#include <wsyassert.hpp>

namespace Wisaya {

    AppDelegate* AppDelegate::s_Instance = nullptr;

    AppDelegate::AppDelegate() {
        if (s_Instance) {
            WSY_CORE_ERROR("ApplicationCreate called more than once.");
            // throw std::logic_error("Application instance already exist.");
            return;
        }
        
        WSY_CORE_TRACE("Initializing application instance...");
        s_Instance = this;
        m_Running = true;
        m_Suspended = false;
    }

    AppDelegate::~AppDelegate() {
        Shutdown();
    }

    void AppDelegate::Initialize() {

    }

    void AppDelegate::Shutdown() {
        WSY_CORE_TRACE("Shutting down application...");
    }

    void AppDelegate::Run() {
        // try {
        //     /* code */
        // }
        // catch(const std::exception& e) {
        //     WSY_CORE_CRITICAL();
        //     // std::cerr << e.what() << '\n';
        // }
        
        // if (!Initialize()) {
        //     WSY_CORE_CRITICAL("Failed to start application.");
        //     return;
        // }

        // while (m_Running) {  
            
        // }
        WSY_CORE_INFO("Task executed succesfully!");
    }

} // namespace Wisaya
