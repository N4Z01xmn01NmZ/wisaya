#include <wisaya/core/logger.hpp>

#ifdef WSY_PLATFORM_WINDOWS

int main(void) {
    Wisaya::Logger::Initialize();
    WSY_CORE_INFO("Initialized Logger!");

    WSY_INFO("Test message");

    Wisaya::Logger::Shutdown();
    return 0;
}

#endif