#ifndef WAPPMAIN_H
#define WAPPMAIN_H

#pragma once

#include <wsydef.hpp>
#include <wsylog.hpp>
#include <wsyassert.hpp>

#include <type/wsyBasicType.hpp>

#include <wisaya/core/WAppDelegate.hpp>

#ifdef WSY_PLATFORM_WINDOWS

extern Wisaya::WAppDelegate* Wisaya::ApplicationCreate();

int main(void) {
    Wisaya::WAppLog::Initialize();
    WSY_CORE_INFO("Initialized Logger!");

    Wisaya::WAppDelegate* app = Wisaya::ApplicationCreate();
    if (app->Initialize() == WSY_FALSE) {
        WSY_CORE_CRITICAL("Failed to start application.");
        return 1;
    }
    app->Run();

    Wisaya::WAppLog::Shutdown();
    return 0;
}

#endif // WSY_PLATFORM_WINDOWS

#endif // WAPPMAIN_H