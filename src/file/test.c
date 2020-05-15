#include <stdio.h>
#include "file.h"

int main(int argc,char * args[] ){
 file * f = file_create();
 (f->open)(f,"test.txt",FILE_READ | FILE_WRITE);

 for(int i = 0; i < 16; i++)
  (f->write)(f,"kuesji kuesji kuesji\n");

 (f->seek)(f,0);

 char buffer[256];
 while( (f->read)(f,buffer,sizeof(buffer)) == 0 ){
  printf("%s",buffer);
 }

 printf("size: %ld\n",(f->size)(f));

 (f->close)(f);
 file_destroy(f);

 puts("");
 return 0;
}
