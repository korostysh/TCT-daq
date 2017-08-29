#ifndef STANDA_TYPES_H
#define STANDA_TYPES_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


template<typename T> bool getBit(const T &N, int bit = 0);
char tobyte(const bool *bits);
void byte2bits(const char &byte, bool *bits);

struct goto_data{
    __uint32_t destination;
    __uint16_t timerperiod;
   bool stepsizeM1: 1;
   bool stepsizeM2: 1;
   bool defaultDirection: 1;
   bool antiloft: 1;
   bool slowstart: 1;
   bool waitSynchro: 1;
   bool resetSynchro: 1;
   bool forceLoft: 1;

   goto_data(int destination, int speed, int div = 0, bool def_dir = false, bool loft_en = false, bool sl_start = false, bool w_sync = false, bool sync_out = false, bool force_loft = false);

   __uint16_t upperWord();
   __uint16_t lowerWord();
};

template<typename T> T clamp(const T &value, const T& max, const T& min);

#endif // STANDA_TYPES_H
