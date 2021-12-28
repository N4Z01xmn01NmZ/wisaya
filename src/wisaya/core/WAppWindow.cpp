#include <Wisaya_pch.hpp>
#include <wisaya/core/WAppWindow.hpp>

#ifdef WSY_PLATFORM_WINDOWS
    #include <platform/windows/WindowsWindow.hpp>
#endif

namespace Wisaya
{
    scoped_ptr<WAppWindow> WAppWindow::Create(const window_properties& properties) {
        #ifdef WSY_PLATFORM_WINDOWS
            return create_scoped<Platform::Windows::WindowsWindow>(properties);
        #else
            WSY_CORE_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }

    scoped_ptr<WAppWindow> WAppWindow::Create(wsyUInt16 width, wsyUInt16 height, wsy_string title) {
        return WAppWindow::Create(window_properties { title, width, height });
    }

} // namespace Wisaya

