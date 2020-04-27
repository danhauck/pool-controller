#include "Timer.hpp"

/**
 *
 */
tm getCurrentDateTime() {

  TimeChangeRule *tcr = NULL;
  time_t     t        = getTimeFor(0, &tcr);
  struct tm timeinfo  = *localtime(&t);

  return timeinfo;
}

tm getStartTime(TimerSetting timerSetting) {
  tm startTime      = getCurrentDateTime();
  startTime.tm_hour = timerSetting.timerStartHour;
  startTime.tm_min  = timerSetting.timerStartMinutes;
  startTime.tm_sec  = 0;

  return startTime;
}

tm getEndTime(TimerSetting timerSetting) {
  tm endTime      = getCurrentDateTime();
  endTime.tm_hour = timerSetting.timerEndHour;
  endTime.tm_min  = timerSetting.timerEndMinutes;
  endTime.tm_sec  = 0;

  return endTime;
}

bool isInTimeRange(tm currentTime, TimerSetting timerSetting) {
  bool retval;

  time_t cTime   = mktime(&currentTime);
  time_t startTm = mktime(&getStartTime(timerSetting));
  time_t endTm   = mktime(&getEndTime(timerSetting));

  if (difftime(cTime, startTm) >= 0 && difftime(cTime, endTm) <= 0) {
    retval = true;

  } else {
    retval = false;
  }

  return retval;
}


