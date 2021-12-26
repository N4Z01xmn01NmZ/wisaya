#ifndef WAPPWINDOW_H
#define WAPPWINDOW_H

#pragma once

#include <type/wsyBasicType.hpp>

#include <string>

namespace Wisaya
{

    typedef struct window_properties
    {
        std::string Title;
        wsyUInt32 Width;
        wsyUInt32 Height;

        window_properties(
            const std::string& title = "Wisaya Engine",
            wsyUInt32 width = 1280,
            wsyUInt32 height = 720
            ) : Title(title), Width(width), Height(height) {}
    };

    class WSYAPI WAppWindow
    {
    public:
        
    };

} // namespace Wisaya


#endif // WAPPWINDOW_H
