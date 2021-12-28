#ifndef WSYMOUSEEVENT_H
#define WSYMOUSEEVENT_H

#pragma once

#include <event/WisayaEvent.hpp>
#include <input/WisayaMouseCode.hpp>

#include <type/wsyBasicType.hpp>
#include <type/wsyStringType.hpp>

namespace Wisaya
{
    
    class WisayaMouseMovedEvent : public WisayaEvent
    {
    public:
        WisayaMouseMovedEvent(const wsyFloat32 mouseX, const wsyFloat32 mouseY)
            : m_MouseX(mouseX), m_MouseY(mouseY) {}

        wsyFloat32 GetMouseX() const { return m_MouseX; }
        wsyFloat32 GetMouseY() const { return m_MouseY; }

        wsy_string ToString() const override
        {
            wsy_sstream ss;
            ss << "MouseMovedEvent: " << GetMouseX() << ", " << GetMouseY();
            return ss.str();
        }

        EVENT_CLASS_TYPE(WSY_MOUSE_MOVED)
        EVENT_CLASS_CATEGORY(SECatMouse | SECatInput)
    private:
        wsyFloat32 m_MouseX, m_MouseY;
    };

    class WisayaMouseScrolledEvent : public WisayaEvent
    {
    public:
        WisayaMouseScrolledEvent(const wsyFloat32 offsetX, const wsyFloat32 offsetY)
            : m_OffsetX(offsetX), m_OffsetY(offsetY) {}

        wsyFloat32 GetOffsetX() const { return m_OffsetX; }
        wsyFloat32 GetOffsetY() const { return m_OffsetY; }

        wsy_string ToString() const override
        {
            wsy_sstream ss;
            ss << "MouseScrolledEvent: " << GetOffsetX() << ", " << GetOffsetY();
            return ss.str();
        }

        EVENT_CLASS_TYPE(WSY_MOUSE_SCROLLED)
        EVENT_CLASS_CATEGORY(SECatMouse | SECatInput)
    private:
        wsyFloat32 m_OffsetX, m_OffsetY;
    };

    class WisayaMouseButtonEvent : public WisayaEvent
    {
    public:
        wsyMouseCode GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(SECatMouseButton | SECatMouse | SECatInput)
    protected:
        WisayaMouseButtonEvent(const wsyMouseCode button)
            : m_Button(button) {}

        wsyMouseCode m_Button;
    };

    class WisayaMouseButtonPressedEvent : public WisayaMouseButtonEvent
    {
    public:
        WisayaMouseButtonPressedEvent(const wsyMouseCode button)
            : WisayaMouseButtonEvent(button) {}

        wsy_string ToString() const override
        {
            wsy_sstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WSY_MOUSE_BUTTON_PRESSED)
    };

    class WisayaMouseButtonReleasedEvent : public WisayaMouseButtonEvent
    {
    public:
        WisayaMouseButtonReleasedEvent(const wsyMouseCode button)
            : WisayaMouseButtonEvent(button) {}

        wsy_string ToString() const override
        {
            wsy_string ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WSY_MOUSE_BUTTON_RELEASED)
    };

} // namespace Wisaya

#endif // WSYMOUSEEVENT_H
