#include <type/wsyBasicType.h>

#include <wsydef.h>
#include <wsylog.hpp>
#include <wsyassert.hpp>

#include <wisaya/core/appdelegate.hpp>

#ifdef WSY_PLATFORM_WINDOWS

extern Wisaya::AppDelegate* Wisaya::ApplicationCreate();

int main(void) {
    Wisaya::Logger::Initialize();
    WSY_CORE_INFO("Initialized Logger!");

    Wisaya::AppDelegate* app = Wisaya::ApplicationCreate();
    app->Run();
    delete app;

    Wisaya::Logger::Shutdown();
    return 0;
}

#endif