//Reference: https://minkukel.com/en/various/calculating-moon-phase/

#include <ctime>
#include "MoonPhase.h"

namespace MoonPhase
{

const int lunar_const = 29.53058770576 * 24 * 60 * 60;

const int new_moon2000 { 947182440 };

MoonPhase::Moon_Phase calc(std::time_t time)
{
  double phase_f = (double)((time - new_moon2000) % lunar_const) / lunar_const;

  if ((phase_f >= 0 && phase_f < 0.033863193308711) || (phase_f >= 0.966136806691289 && phase_f <= 1))
    return MoonPhase::NEW_MOON;

  if (phase_f >= 0.033863193308711 && phase_f < 0.216136806691289)
    return MoonPhase::WAXING_CRESCENT;

  if (phase_f >= 0.216136806691289 && phase_f < 0.283863193308711)
    return MoonPhase::FIRST_QUARTER;

  if (phase_f >= 0.283863193308711 && phase_f < 0.466136806691289)
    return MoonPhase::WAXING_GIBBOUS;

  if (phase_f >= 0.466136806691289 && phase_f < 0.533863193308711)
    return MoonPhase::FULL_MOON;

  if (phase_f >= 0.533863193308711 && phase_f < 0.716136806691289)
    return MoonPhase::WANING_GIBBOUS;

  if (phase_f >= 0.716136806691289 && phase_f < 0.783863193308711)
    return MoonPhase::LAST_QUARTER;

  if (phase_f >= 0.783863193308711 && phase_f < 0.966136806691289)
    return MoonPhase::WANING_CRESCENT;
}

}