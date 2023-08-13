
#include "ff/logger.h"

#include <stdio.h>

const char * const ffLogLevelStr[] = {
  "fatal error", "error", "warn", "info", "debg", "verb"
};


void ff_log(ffLogLevel level, const char* fmt, va_list arglist) {
  FILE * std = level < INFO ? stderr : stdout;

  char buf[1012]; // -12
  vsprintf(buf, fmt, arglist);

  if (level < INFO) {
    fprintf(std, "%s %s %s%s", TCOL(BLD,RED,BLK), ffLogLevelStr[level], buf, FRST);
    return;
  }
  fprintf(std, "%s%s%s: %s", TCOL(RST,BLU,BLK), ffLogLevelStr[level], FRST, buf);
}

void ff_fatal(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  ff_log(FATAL, fmt, args);
  va_end(args);
}

void ff_error(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  ff_log(ERROR, fmt, args);
  va_end(args);
}

void ff_warn(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  ff_log(WARN, fmt, args);
  va_end(args);
}

void ff_info(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  ff_log(INFO, fmt, args);
  va_end(args);
}

void ff_debug(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  ff_log(DEBUG, fmt, args);
  va_end(args);
}

void ff_verb(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  ff_log(VERBOSE, fmt, args);
  va_end(args);
}
