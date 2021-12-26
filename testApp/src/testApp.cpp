#include <wsylog.hpp>
#include <wsyassert.hpp>

#include <wsyapp.hpp>
#include <wisaya/core/main.hpp>

class TestbedApp : public Wisaya::AppDelegate
{
public:
protected:
    TestbedApp() { WSY_INFO("Created TestbedApp!"); }
    ~TestbedApp() { WSY_INFO("Deleted TestbedApp!"); }
private:
    friend Wisaya::AppDelegate* Wisaya::ApplicationCreate();
};

Wisaya::AppDelegate* Wisaya::ApplicationCreate() {
    return new TestbedApp();
}
