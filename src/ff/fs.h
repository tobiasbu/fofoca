
#ifndef _FF_FS_H_
#define _FF_FS_H_

#include <stdbool.h>

 typedef struct {
  bool is_dir;
  bool exists;
} fsStat;

/**
 * Get current working directory
*/
extern char * fs_cwd();

/**
 * Check if given path exists
*/
extern int fs_exists(char * path);

/**
 * Get file stat fro given path
*/
extern fsStat fs_stat(const char * path);

#endif
