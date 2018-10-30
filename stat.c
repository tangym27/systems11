#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

char * readable_form(long size){
  int index = 0;
  char * sizes[] = {"B", "KB", "MB", "GB"};
  while (size >= 1024){
    size /= 1024;
    index+=1;
  }
  return sizes[index];
}

int main(){
  struct stat fileStats;
  stat("stat.c", &fileStats);
  float size = (float) fileStats.st_size;
  char * place = readable_form(size);
  while (size >= 1024){
    size /= 1024;
  }
  printf("Size: %f %s \n", size , place );
  printf("Permissions: %o\n", fileStats.st_mode);
  printf("Last Accessed Time: %s", ctime(&fileStats.st_atime));
  printf("Last Modified Time: %s", ctime(&fileStats.st_mtime));


  return 0;
}
