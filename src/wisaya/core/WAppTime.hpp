#ifndef WAPPTIME_H
#define WAPPTIME_H

#pragma once

#include <type/wsyBasicType.hpp>

namespace Wisaya
{

    class WAppTime
    {
    public:
        WAppTime();

        static wsyFloat64 UpdateTime();
        static wsyFloat64 GetDeltaTime();
    private:
        static wsyFloat64 s_CurrentTime; 
        static wsyFloat64 s_LastFrameTime; 
        static wsyFloat64 s_DeltaTime; 
    };

} // namespace Wisaya


#endif // WAPPTIME_H