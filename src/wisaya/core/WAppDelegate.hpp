#ifndef WAPPDELEGATE_H
#define WAPPDELEGATE_H

#pragma once

#include <wsydef.hpp>
#include <type/wsyBasicType.hpp>
#include <event/WisayaEvent.hpp>

#include <wisaya/core/WAppWindow.hpp>

int main(void);

namespace Wisaya {

    class WSYAPI WAppDelegate
    {
    public:
        // static AppDelegate& GetInstance() { return *s_Instance; }
        static WAppDelegate* GetInstance();
        static void ReleaseInstance();

        WAppDelegate(const WAppDelegate&) = delete;
    protected:
        WAppDelegate();
        virtual ~WAppDelegate();
    private:
        wsyBool Initialize();
        void Shutdown();
        void Run();

        void OnEvent(WisayaEvent& evt);
    private:
        scoped_ptr<WAppWindow> m_Window;
        wsyBool m_Running;
        wsyBool m_Suspended;
        wsyFloat64 m_LastFrameTime;
    private:
        friend int ::main(void);
        friend WAppDelegate* ApplicationCreate();
        static WAppDelegate* s_Instance;
    };

    extern WAppDelegate* ApplicationCreate();

} // namespace Wisaya

#endif // WAPPDELEGATE_H
