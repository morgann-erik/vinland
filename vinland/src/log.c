#include "vinland/log.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static enum LogLevel currentLevel;
static FILE *fileSink;

void v_SetLogLevel(enum LogLevel value) { currentLevel = value; }

void v_Log(const char *f, const enum LogLevel lvl, const int l,
           const char *msg) {
  if (currentLevel > lvl) {
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

  printf("[%s %s %s:%d] %s\n", now, lvlStr, f, l, msg);

  if (!fileSink) {
    return;
  }
  fprintf(fileSink, "[%s %s %s:%d] %s\n", now, lvlStr, f, l, msg);
  fflush(fileSink);
}

void v_InitFileSink() {
  fileSink = fopen("log.txt", "a");
  if (!fileSink) {
    perror("Failed to initialise file sink");
    exit(EXIT_FAILURE);
  }
}
void v_CleanUpFileSink() {
  if (fileSink) {
    fclose(fileSink);
    fileSink = NULL;
  }
}
