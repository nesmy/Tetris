#include "GTime.h"

namespace BB {
  void StartTimer(Timer *time, float lifetime) {
  if (time != NULL)
    time->Lifetime = lifetime;
}

void UpdateTimer(Timer *time) {
  // sub this frame from the timer if its not allready expired
  if (time != NULL && time->Lifetime > 0)
    time->Lifetime -= GetFrameTime();
}

bool TimerDone(Timer *time) {
  if (time != NULL)
    return time->Lifetime <= 0;

  return (bool)NULL;
}
}
