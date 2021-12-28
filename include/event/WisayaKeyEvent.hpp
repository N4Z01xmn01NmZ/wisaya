#ifndef WSYKEYEVENT_H
#define WSYKEYEVENT_H

#pragma once

#include <event/WisayaEvent.hpp>
#include <input/WisayaKeyCode.hpp>

#include <type/wsyBasicType.hpp>
#include <type/wsyStringType.hpp>


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

        wsy_string ToString() const override {
            wsy_sstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        SYSTEM_EVENT_CODE(WSY_KEY_PRESSED);
    private:
        wsyUInt16 m_RepeatCount;
    };

    class WisayaKeyReleasedEvent : public WisayaKeyEvent
    {
    public:
        WisayaKeyReleasedEvent(const wsyKeyCode keycode) : WisayaKeyEvent(keycode) {}

        wsy_string ToString() const override {
            wsy_sstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        SYSTEM_EVENT_CODE(WSY_KEY_RELEASED);
    };

    class WisayaKeyTypedEvent : public WisayaKeyEvent
    {
    public:
        WisayaKeyTypedEvent(const wsyKeyCode keycode) : WisayaKeyEvent(keycode) {}

        wsy_string ToString() const override {
            wsy_sstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        SYSTEM_EVENT_CODE(WSY_KEY_TYPED);
    };

} // namespace Wisaya


#endif // WSYKEYEVENT_H