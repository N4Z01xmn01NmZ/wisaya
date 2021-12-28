#ifndef PLATFORM_WINDOWS_WINDOW_H
#define PLATFORM_WINDOWS_WINDOW_H

#pragma once

#include <wisaya/core/WAppWindow.hpp>
#include <wisaya/rendering/WisayaContext.hpp>

namespace Wisaya { namespace Platform { namespace Windows {

    class WSYAPI WindowsWindow : public ::Wisaya::WAppWindow
    {
    public:
        virtual void* GetNativeWindow() const override { return m_Window; }

        WindowsWindow(const window_properties& properties);
        virtual ~WindowsWindow();

        WindowsWindow(const WindowsWindow&) = delete;
        WindowsWindow& operator=(const WindowsWindow&) = delete;

        virtual void OnUpdate() override;

        virtual wsyUInt32 GetWidth() const override { return m_Data.Width; }
        virtual wsyUInt32 GetHeight() const override { return m_Data.Height; }

        virtual void ClockUpdate() override;
        virtual void ClockStart() override;
        virtual void ClockStop() override;
        virtual wsyFloat64 ClockGetStartTime() override { return m_Clock.start_time; }
        virtual wsyFloat64 ClockGetElapsedTime() override { return m_Clock.elapsed; }
        virtual wsyFloat64 GetTime() override { return GetPlatformAbsoluteTime(); }
        virtual wsyFloat64 GetTimeMillis() override { return GetPlatformAbsoluteTime() * 1000; }

        virtual void SetEventCallback(const event_callback_fn& callback) const override;
        virtual void SetVSync(wsyBool enable) override;
        virtual wsyBool IsVSync() const override;

        virtual wsyBool Initialize() override;
    private:
        virtual void Release();
        static wsyFloat64 GetPlatformAbsoluteTime();
    private:
        void* m_Window;
        wisaya_clock m_Clock;
        scoped_ptr<WisayaContext> m_Context;

        typedef struct WindowData
        {
            wsy_string Title;
            wsyUInt32 Width, Height;
            wsyBool VSync;

            event_callback_fn EventCallback;
        } WindowData;
        
        WindowData m_Data;
    };

}}} // namespace Wisaya::Platform::Windows


#endif // PLATFORM_WINDOWS_WINDOW_H