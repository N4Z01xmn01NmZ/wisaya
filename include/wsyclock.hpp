#ifndef WSYCLOCK_H
#define WSYCLOCK_H

#pragma once

#include <type/wsyBasicType.hpp>

namespace Wisaya {

    /**
     * @brief Data structure for a clock
     */
    typedef struct wisaya_clock
    {
        wsyFloat64 start_time;
        wsyFloat64 elapsed;
    } wisaya_clock;

    // TODO Implement platform specific update, start, and stop clock function before use
    // The function below serves as a reference
    // Actual use are deprecated

    // Updates the provided clock
    // void wclock_update(wisaya_clock* clock) {
    //     if (clock->start_time != 0)
    //         clock->elapsed = platform_absolute_time() - clock->start_time;
    // }

    // Starts the provided clock and resets elapsed time.
    // void wclock_start(wisaya_clock* clock) {
    //     clock->start_time = platform_absolute_time();
    //     clock->elapsed = 0;
    // }

    // Stops and refreshes the provided clock.
    // void wclock_stop(wisaya_clock* clock) {
    //     clock->start_tim = 0;
    // }

} // namespace Wisaya


#endif // WSYCLOCK_H