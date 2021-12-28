#include <wsylog.hpp>
#include <wsyassert.hpp>

#include <wsyapp.hpp>
#include <wisaya/core/WAppMain.hpp>

class TestbedApp : public Wisaya::WAppDelegate
{
public:
protected:
    TestbedApp() { WSY_TRACE("Starting TestbedApp..."); }
    ~TestbedApp() { WSY_INFO("Deleted TestbedApp!"); }
private:
    friend Wisaya::WAppDelegate* Wisaya::ApplicationCreate();
};

Wisaya::WAppDelegate* Wisaya::ApplicationCreate() {
    return new TestbedApp();
}
