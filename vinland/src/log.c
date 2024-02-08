#include "log.h"
#include <stdio.h>
#include <time.h>

static enum LogLevel currentLevel;
static FILE *fileSink;

void v_Log(const char *f, const int lvl, const int l, 
           const char *msg) {
  if (currentLevel > l) {
    return;
  }

  const char *lvlStr = lvl == DEBUG     ? "DEBUG"
                       : lvl == INFO    ? "INFO"
                       : lvl == WARNING ? "WARNING"
                       : lvl == ERROR   ? "ERROR"
                                        : "FATAL";
  char now[24];
  time_t raw_now;
  time(&raw_now);
  struct tm *tz;
  tz = localtime(&raw_now);
  strftime(now, 24, "%H:%M:%S", tz);

  printf("[%s %s %s:%d] %s", now, lvlStr, f, l, msg);

  if (!fileSink) {
    return;
  }
  fprintf(fileSink, "[%s %s %s:%d] %s", now, lvlStr, f, l, msg);
}
