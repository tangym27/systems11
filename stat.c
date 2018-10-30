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
	for(int i = 0; i < 10;i++){
		if(mode & (1 << (8-i))){
			 pers[i];
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
  char * place = readable_form(size);
  while (size >= 1024){
    size /= 1024;
  }
  char per[10];
  printf("Size: %f %s \n", size , place );
  printf("Permissions: %03o\n", fileStats.st_mode);
  permissions(fileStats.st_mode,per);
  printf("Permissions: %s\n",per);
  printf("Last Accessed Time: %s", ctime(&fileStats.st_atime));
  printf("Last Modified Time: %s", ctime(&fileStats.st_mtime));


  return 0;
}
