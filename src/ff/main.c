#include <stdio.h>

#include "ff/logger.h"
#include "ff/fs.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    ff_fatal("no input files");
    return 1;
  }

  const char * input = argv[1];
  fsStat stat = fs_stat(input);
  if (!stat.exists) {
    ff_fatal("given input does not exists");
    return 1;


  ff_info("You have entered %d arguments:\n", argc);

  for (int i = 0; i < argc; i++) {
    ff_info("%s\n", argv[i]);
  }

  return 0;
}
