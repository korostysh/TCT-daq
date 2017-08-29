#include "instruments/include/standa_types.h"
#include <cmath>
#include <iostream>

template <typename T> T clamp(const T &value, const T &max, const T &min)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

goto_data::goto_data(int destination, int speed, int div, bool def_dir, bool loft_en,
                     bool sl_start, bool w_sync, bool sync_out, bool force_loft)
{
    int realspeed = clamp(speed, 5000, 16);
    std::cout<<"real speed is"<<realspeed<<std::endl;
    double dec = floor(1000000.0 / realspeed + 0.5);
    std::cout<<"dec is "<<dec<<std::endl;
    __uint16_t timerperiod = 65536 - floor(1000000.0/double(realspeed) + 0.5);
    std::cout<<"timeperiod is"<<timerperiod<<std::endl;

    if (div == 1){
        this->stepsizeM1 = 0;
        this->stepsizeM2 = 0;
    }
    else if (div == 2){
        this->stepsizeM1 = 1;
        this->stepsizeM2 = 0;
    }
    else if (div == 4){
        this->stepsizeM1 = 0;
        this->stepsizeM2 = 1;
    }
    else {
        this->stepsizeM1 = 1;
        this->stepsizeM2 = 1;
    }

    this->destination = destination*8;
    this->timerperiod = ((timerperiod&0xFF00) >> 8) | ((timerperiod&0x00FF) << 8);
    this->defaultDirection = def_dir?1:0;
    this->antiloft = loft_en?1:0;
    this->slowstart = sl_start?1:0;
    this->waitSynchro = w_sync?1:0;
    this->resetSynchro = sync_out?1:0;
    this->forceLoft = force_loft?1:0;
}

__uint16_t goto_data::upperWord()
{
    return *reinterpret_cast<__uint16_t*>(&(this->destination));
}

__uint16_t goto_data::lowerWord()
{
    return *(reinterpret_cast<__uint16_t*>(&(this->destination))+1);
}
