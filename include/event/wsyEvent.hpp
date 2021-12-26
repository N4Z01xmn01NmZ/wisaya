#ifndef WSYEVENT_H
#define WSYEVENT_H

#pragma once

#include <wsydef.hpp>

#include <string>
#include <functional>

// #define WSY_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Wisaya {

    // Internal system event code 0-255.
    typedef enum class SystemEventCode {
        NONE = 0,
        WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_LOST_FOCUS, WINDOW_MOVED,
        KEY_PRESSED, KEY_RELEASED, KEY_TYPED,
        MOUSE_MOVED, MOUSE_SCROLLED, MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED,
        INTERNAL_SECODE_MAX = 0xFF
    } SystemEventCode;

    typedef enum SystemEventCategory {
        NONE = 0,
        SECatApplication    = WSY_BV(0),
        SECatInput          = WSY_BV(1),
        SECatKeyboard       = WSY_BV(2),
        SECatMouse          = WSY_BV(3),
        SECatMouseButton    = WSY_BV(4)
    } SystemEventCategory;

    #define SYSTEM_EVENT_CATEGORY(category) virtual int GetSECategoryFlags() const override { return category; }

    #define SYSTEM_EVENT_CODE(code) static SystemEventCode GetStaticCode() { return SystemEventCode::code; }\
                                    virtual SystemEventCode GetSECode() const override { return GetStaticCode(); }\
                                    virtual const char* GetName() const override { return #code; }

    class WisayaEvent {
    public:
        virtual ~WisayaEvent() = default;

        virtual SystemEventCode GetSECode() const = 0;
        wsyBool SECodeEquals(SystemEventCode code) { return GetSECode() == code; }
        wsyBool operator==(SystemEventCode code) { return SECodeEquals(code); }

        virtual int GetSECategoryFlags() const = 0;
        wsyBool SECategoryEquals(SystemEventCategory category) { return GetSECategoryFlags() & category; }
        wsyBool operator==(SystemEventCategory category) { return SECategoryEquals(category); }

        virtual const char* GetName() const = 0;
        virtual std::string ToString() const { return GetName(); }

        wsyBool isHandled = false;
    };

    class WisayaEventDispatcher {

    };

    std::ostream& operator<<(std::ostream& os, const WisayaEvent& evt) { return os << evt.ToString(); }


} // namespace Wisaya

#endif // WSYEVENT_H
