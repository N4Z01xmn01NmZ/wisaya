#ifndef WSYEVENT_H
#define WSYEVENT_H

#pragma once

#include <wsydef.hpp>

#include <type/wsyStringType.hpp>
#include <functional>

#define WSY_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Wisaya {

    // Internal system event code 0-255.
    typedef enum class SystemEventCode {
        NONE = 0,
        WSY_WINDOW_CLOSE, WSY_WINDOW_RESIZE, WSY_WINDOW_FOCUS, WSY_WINDOW_LOST_FOCUS, WSY_WINDOW_MOVED,
        WSY_KEY_PRESSED, WSY_KEY_RELEASED, WSY_KEY_TYPED,
        WSY_MOUSE_MOVED, WSY_MOUSE_SCROLLED, WSY_MOUSE_BUTTON_PRESSED, WSY_MOUSE_BUTTON_RELEASED,
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
                                    virtual wsy_cstr GetName() const override { return #code; }

    class WisayaEvent {
    public:
        virtual ~WisayaEvent() = default;

        virtual SystemEventCode GetSECode() const = 0;
        wsyBool SECodeEquals(SystemEventCode code) { return GetSECode() == code; }
        wsyBool operator==(SystemEventCode code) { return SECodeEquals(code); }

        virtual int GetSECategoryFlags() const = 0;
        wsyBool SECategoryEquals(SystemEventCategory category) { return GetSECategoryFlags() & category; }
        wsyBool operator==(SystemEventCategory category) { return SECategoryEquals(category); }

        virtual wsy_cstr GetName() const = 0;
        virtual wsy_string ToString() const { return GetName(); }

        wsyBool isHandled = false;
    };

    class WisayaEventDispatcher {

    };

    inline std::ostream& operator<<(std::ostream& os, const WisayaEvent& evt) { return os << evt.ToString(); }


} // namespace Wisaya

#endif // WSYEVENT_H
