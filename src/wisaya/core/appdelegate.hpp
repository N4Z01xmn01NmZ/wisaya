#pragma once

#include <type/wsyBasicType.h>

#include <wsydef.h>

int main(void);

namespace Wisaya {

    class WSYAPI AppDelegate
    {
    public:
        static AppDelegate& GetInstance() { return *s_Instance; }

        AppDelegate(const AppDelegate&) = delete;
    protected:
        AppDelegate();
        virtual ~AppDelegate();
    private:
        void Initialize();
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

    AppDelegate* ApplicationCreate(AppDelegate*&);

} // namespace Wisaya
