#ifndef WSYMOUSECODE_H
#define WSYMOUSECODE_H

#pragma once

#include <type/wsyBasicType.hpp>


namespace Wisaya
{

    using wsyMouseCode = wsyInt16;
    typedef enum Mouse : wsyMouseCode {
        // Taken from glfw3.h
        Button0         = 0,
        Button1         = 1,
        Button2         = 2,
        Button3         = 3,
        Button4         = 4,
        Button5         = 5,
        Button6         = 6,
        Button7         = 7,

        ButtonLast      = Button7,
        ButtonLeft      = Button0,
        ButtonRight     = Button1,
        ButtonMiddle    = Button2
    } Mouse;

} // namespace Wisaya


#endif // WSYMOUSECODE_H
