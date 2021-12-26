#pragma once

#include <type/wsyBasicType.hpp>

#include <wsydef.hpp>

int main(void);

namespace Wisaya {

    class WSYAPI AppDelegate
    {
    public:
        // static AppDelegate& GetInstance() { return *s_Instance; }
        static AppDelegate* GetInstance();
        static void ReleaseInstance();

        AppDelegate(const AppDelegate&) = delete;
    protected:
        AppDelegate();
        virtual ~AppDelegate();
    private:
        wsyBool Initialize();
        void Shutdown();
        void Run();
    private:
        wsyBool m_Running;
        wsyBool m_Suspended;
    private:
        friend int ::main(void);
        friend AppDelegate* ApplicationCreate();
        static AppDelegate* s_Instance;
    };

    extern AppDelegate* ApplicationCreate();

} // namespace Wisaya
