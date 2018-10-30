#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>


int main(){
  struct stat fileStats;
  stat("stat.c", &fileStats);
  printf("Size: %ld\n", fileStats.st_size);
  printf("Permissions: %o\n", fileStats.st_mode);
  printf("Last Access Time: %s", ctime(&fileStats.st_atime));
  printf("Last Modify Time: %s", ctime(&fileStats.st_mtime));
  printf("%s\n", "HI" );

  return 0;
}
