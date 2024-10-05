#pragma once
#include "Config.h"

namespace BB {
  typedef struct {
    float Lifetime;
  } Timer;

  extern void StartTimer(Timer* time, float lifeTime);
  extern void UpdateTimer(Timer* time);
  extern bool TimerDone(Timer* time);
}
