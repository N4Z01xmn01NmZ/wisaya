#ifndef WSYAPPLICATIONEVENT_H
#define WSYAPPLICATIONEVENT_H

#pragma once

#include <event/wsyEvent.hpp>
#include <type/wsyBasicType.hpp>

namespace Wisaya
{

    class WisayaWindowCloseEvent : public WisayaEvent
    {
    public:
        WisayaWindowCloseEvent() = default;

        SYSTEM_EVENT_CODE(WSY_WINDOW_CLOSE)
        SYSTEM_EVENT_CATEGORY(SECatApplication)
    };

    class WisayaWindowResizeEvent : public WisayaEvent
    {
    public:
        WisayaWindowResizeEvent(wsyUInt32 width, wsyUInt32 height)
            : m_Width(width), m_Height(height) {}

        wsyUInt32 GetWidth() const { return m_Width; }
        wsyUInt32 GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        SYSTEM_EVENT_CODE(WSY_WINDOW_RESIZE)
        SYSTEM_EVENT_CATEGORY(SECatApplication)
    private:
        wsyUInt32 m_Width, m_Height;
    };

} // namespace Wisaya


#endif // WSYAPPLICATIONEVENT_H
