#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

char * readable_form(long size){
  int index = 0;
  char * sizes[] = {"B", "KB", "MB", "GB"};
  while (size >= 1024){
    size /= 1024;
    index+=1;
  }
  return sizes[index];
}

void permissions(mode_t mode,char * buffer){
	char pers[10] ="rwxrwxrwx";
	for(int i = 0; i < 9; i++){
		if(mode & (1 << (8-i))){
			 //do nothing
		}
		else{
			pers[i] = '-';
		}
	}
	strcat(buffer,pers);
}

int main(){
  struct stat fileStats;
  stat("stat.c", &fileStats);
  float size = (float) fileStats.st_size;
  float nsize = size;
  char * place = readable_form(size);
  while (size >= 1024){
    size /= 1024;
  }
  char per[10];
  printf("File size (byte): %f \n", nsize);
  printf("File size (human readable form): %f %s \n", size , place );
  printf("Permissions (octal): %o\n", fileStats.st_mode);
  permissions(fileStats.st_mode,per);
  printf("Permissions (as seen in ls -l): %s\n",per);
  printf("Last Accessed Time: %s", ctime(&fileStats.st_atime));
  printf("Last Modified Time: %s", ctime(&fileStats.st_mtime));


  return 0;
}
