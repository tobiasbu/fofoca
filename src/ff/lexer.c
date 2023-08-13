
#include "ff/lexer.h"

#include <stdio.h>

void ff_lexer_from_file(const char * fpath) {

  FILE *ptr = fopen(fpath, "r");
  if (ptr == NULL) {
    printf("file can't be opened \n");
    return;
  }

}
