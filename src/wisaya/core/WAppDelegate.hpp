#ifndef WAPPDELEGATE_H
#define WAPPDELEGATE_H

#pragma once

#include <wsydef.hpp>
#include <type/wsyBasicType.hpp>

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
    private:
        wsyBool m_Running;
        wsyBool m_Suspended;
    private:
        friend int ::main(void);
        friend WAppDelegate* ApplicationCreate();
        static WAppDelegate* s_Instance;
    };

    extern WAppDelegate* ApplicationCreate();

} // namespace Wisaya

#endif // WAPPDELEGATE_H
