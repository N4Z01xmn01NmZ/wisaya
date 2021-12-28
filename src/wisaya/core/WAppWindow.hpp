#ifndef WAPPWINDOW_H
#define WAPPWINDOW_H

#pragma once

#include <wsymemory.hpp>
#include <wsyclock.hpp>
#include <type/wsyBasicType.hpp>
#include <event/WisayaEvent.hpp>

#include <type/wsyStringType.hpp>

namespace Wisaya
{

    typedef struct window_properties
    {
        wsy_string Title;
        wsyUInt32 Width;
        wsyUInt32 Height;

        window_properties(
            const wsy_string& title = "Wisaya Engine",
            wsyUInt32 width = 1280,
            wsyUInt32 height = 720
            ) : Title(title), Width(width), Height(height) {}
    } window_properties;

    class WSYAPI WAppWindow
    {
    public:
        using event_callback_fn = std::function<void(WisayaEvent&)>;

        virtual void* GetNativeWindow() const = 0;

        virtual ~WAppWindow() = default;

        virtual void OnUpdate() = 0;

        virtual wsyUInt32 GetWidth() const = 0;
        virtual wsyUInt32 GetHeight() const = 0;

        virtual void ClockUpdate() = 0;
        virtual void ClockStart() = 0;
        virtual void ClockStop() = 0;
        virtual wsyFloat64 ClockGetStartTime() = 0;
        virtual wsyFloat64 ClockGetElapsedTime() = 0;
        virtual wsyFloat64 GetTime() = 0;
        virtual wsyFloat64 GetTimeMillis() = 0;

        virtual void SetEventCallback(const event_callback_fn& callback) const = 0;
        virtual void SetVSync(wsyBool enable) = 0;
        virtual wsyBool IsVSync() const = 0;

        virtual wsyBool Initialize() = 0;
        
        static scoped_ptr<WAppWindow> Create(const window_properties& properties = window_properties());
        static scoped_ptr<WAppWindow> Create(wsyUInt16 width, wsyUInt16 height, wsy_string title);
    };

    template<typename ... Args>
    static scoped_ptr<WAppWindow> wsyCreateWindow(Args&& ... args) {
        return WAppWindow::Create(std::forward<Args>(args)...);
    }

} // namespace Wisaya


#endif // WAPPWINDOW_H
