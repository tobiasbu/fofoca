
#ifndef _FF_LOGGER_H_
#define _FF_LOGGER_H_

#include "ff/macros.h"

#include <stdarg.h>

/**
 * Get terminal color representation
 * @param attr Attribute
 * @param fg Foreground
 * @param bg Background
 * @return Ansi color
*/
#define TCOL(attr, fg, bg) SUM(fg,30)

// "\x1B["
//  STRINGER(fg + 30) ";" STRINGER(bg + 40) "m"
// "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
//  ";"

// Fully resets any modifiers
#define FRST "\x1B[0m" // Full Reset

/// Attributes

#define RST 0 // Reset
#define BLD 1 // Bold/Bright
#define DIM 2 // Dim
#define UND 3 // Underscore
#define BIK 4 // Blink
#define RVS 7 // Reverse
#define HID 8 // Hidden

/// Colors

#define BLK 0 // Black
#define RED 1 // Red
#define GRN 2 // Green
#define YLW 3 // Yellow
#define BLU 4 // Blue
#define MAG 5 // Magenta
#define CYN 6 // Cyan
#define WHT 7 // White

typedef enum
{
  FATAL = 0,
  ERROR,
  WARN,
  INFO,
  DEBUG,
  VERBOSE
} ffLogLevel;

void ff_log(ffLogLevel level, const char *fmt, va_list arglist);

void ff_fatal(const char *fmt, ...);
void ff_error(const char *fmt, ...);
void ff_warn(const char *fmt, ...);
void ff_info(const char *fmt, ...);
void ff_debug(const char *fmt, ...);
void ff_verb(const char *fmt, ...);

#endif /* _FF_LOGGER_H_ */
