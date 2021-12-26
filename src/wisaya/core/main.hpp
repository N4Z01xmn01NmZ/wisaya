#include <wsydef.hpp>
#include <wsylog.hpp>
#include <wsyassert.hpp>

#include <type/wsyBasicType.hpp>

#include <wisaya/core/appdelegate.hpp>

#ifdef WSY_PLATFORM_WINDOWS

extern Wisaya::AppDelegate* Wisaya::ApplicationCreate();

int main(void) {
    Wisaya::Logger::Initialize();
    WSY_CORE_INFO("Initialized Logger!");

    Wisaya::AppDelegate* app = Wisaya::ApplicationCreate();
    if (app->Initialize() == WSY_FALSE) {
        WSY_CORE_CRITICAL("Failed to start application.");
        return 1;
    }
    app->Run();

    Wisaya::Logger::Shutdown();
    return 0;
}

#endif