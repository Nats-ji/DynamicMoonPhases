#pragma once

#include "pch.h"
#include <ctime>

namespace MoonPhase
{

enum Moon_Phase
{
  NEW_MOON,
  WAXING_CRESCENT,
  FIRST_QUARTER,
  WAXING_GIBBOUS,
  FULL_MOON,
  WANING_GIBBOUS,
  LAST_QUARTER,
  WANING_CRESCENT
};

extern const int lunar_const;

extern const int new_moon2000;

MoonPhase::Moon_Phase calc(std::time_t time);

}