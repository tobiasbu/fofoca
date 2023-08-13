

#include "ff/config.h"
#include "ff/fs.h"

//#include <errno.h>
#include <assert.h>
#include <stdlib.h>

#ifdef FF_OS_LINUX
  #include <linux/limits.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/stat.h>
#elif FF_OS_WINDOWS
  // TODO
  #include <io.h>
  #define F_OK 0
  #define access _access
#endif


char * fs_cwd() {

#ifdef FF_OS_LINUX

  char * cwd = (char*)malloc(PATH_MAX);
  if (getcwd(cwd, PATH_MAX) == NULL) {
    perror("fs_current_dir failed");
    return 0;
  }

  return cwd;

#else
    // TODO(tobiasbu): Win32 implementation
#endif

}

int fs_exists(char * path) {
  // TODO(tobiasbu): Win32 implementation
  return access(path, F_OK) == 0 ? true : false;
}


fsStat fs_stat(const char * path)
{
  // TODO(tobiasbu): Win32 implementation
  fsStat res = { .exists = false };
  struct stat buf;
  if (stat(path, &buf) != -1) {
    res.exists = true;
    res.is_dir = S_ISREG(buf.st_mode);
  }

  return res;
}
