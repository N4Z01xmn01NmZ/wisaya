#ifndef WSYKEYEVENT_H
#define WSYKEYEVENT_H

#pragma once

#include <event/wsyEvent.hpp>
#include <input/wsyKeyCode.hpp>
#include <type/wsyBasicType.hpp>

#include <sstream>

namespace Wisaya
{

    class WisayaKeyEvent : public WisayaEvent
    {
    public:
        wsyKeyCode GetKeyCode() const { return m_KeyCode; }

        SYSTEM_EVENT_CATEGORY(SECatKeyboard | SECatInput)
    protected:
        WisayaKeyEvent(const wsyKeyCode keycode) : m_KeyCode(keycode) {}

        wsyKeyCode m_KeyCode;
    };

    class WisayaKeyPressedEvent : public WisayaKeyEvent
    {
    public:
        WisayaKeyPressedEvent(const wsyKeyCode keycode, const wsyUInt16 repeatCount)
            : WisayaKeyEvent(keycode), m_RepeatCount(repeatCount) {}

        wsyUInt16 GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        SYSTEM_EVENT_CODE(KEY_PRESSED);
    private:
        wsyUInt16 m_RepeatCount;
    };

    class WisayaKeyReleasedEvent : public WisayaKeyEvent
    {
    public:
        WisayaKeyReleasedEvent(const wsyKeyCode keycode) : WisayaKeyEvent(keycode) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        SYSTEM_EVENT_CODE(KEY_RELEASED);
    };

    class WisayaKeyTypedEvent : public WisayaKeyEvent
    {
    public:
        WisayaKeyTypedEvent(const wsyKeyCode keycode) : WisayaKeyEvent(keycode) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        SYSTEM_EVENT_CODE(KEY_TYPED);
    };

} // namespace Wisaya


#endif // WSYKEYEVENT_H