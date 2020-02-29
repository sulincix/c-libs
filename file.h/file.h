#ifndef kuesji_file_h
#define kuesji_file_h 0

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct file file;
const int FILE_READ = 1;
const int FILE_WRITE = 2;
const int FILE_APPEND = 4;

struct file {
 FILE * fd;
 uint8_t mode;
 
  /* this, path, mode */
 int (*open)(file*,char*,uint8_t);
  /* this, buffer, size */
 int (*read)(file*,char*,int);
  /* this, data */
 int (*write)(file*,char*);
  /* this */
 long (*size)(file*);
  /* this, position */
 int (*seek)(file*,long);
  /* this */
 int (*close)(file*);
};

file * file_create(); /* dynamic */
void file_init(file * this); /* static */

/* implementation */

int file_open(file * this,char * path,uint8_t mode){
 char modestr [3];
 modestr[2] = '\0';

 if( mode & FILE_READ ){
  modestr[0] = 'r';
 } else  if( mode & FILE_WRITE ){
  modestr[0] = 'w';
 }
 if( mode & FILE_APPEND ){
  modestr[0] = 'a';
 }

 if( mode & FILE_READ && mode & FILE_WRITE ){
  modestr[1] = '+';
 }

 this->mode = mode;
 this->fd = fopen(path,modestr);
 if( this->fd == NULL){
  if( this->mode & FILE_READ && this->mode & FILE_WRITE ){
   this->fd = fopen(path,"w+");
   if( this->fd == NULL )
    return -1;
  } else {
   return -1;
  }
 }

 return 0;
}

int file_read(file * this,char * buffer,int size){
 if( this->mode & FILE_READ ){
  if( fgets(buffer,size,this->fd) == NULL ){
   return -1;
  }
 } else {
  return -1;
 }

 return 0;
}

int file_write(file * this, char * data){
 if( this->mode & FILE_WRITE ){
  int result = fputs(data,this->fd);
  if( result >= 0 )
   return -1;
 } else {
  return -1;
 }

 return 0;
}

long file_size(file * this){
 long pos = ftell(this->fd);
 long size = 0;
 if( fseek(this->fd,0,SEEK_END) != 0)
  return -1;

 size = ftell(this->fd);
 if( fseek(this->fd,pos,SEEK_SET) != 0)
  return -1;

 return size;
}

int file_seek(file * this,long position){
 return fseek(this->fd,position,SEEK_SET);
}

int file_close(file * this){
 int result = fclose(this->fd);
 if( result != 0 )
  return -1;
 
 return 0;
}

void file_init(file * this){
 this->fd = NULL;
 this->mode = 0;
 this->open = &file_open;
 this->read = &file_read;
 this->write = &file_write;
 this->size = &file_size;
 this->seek = &file_seek;
 this->close = &file_close;
}

file * file_create(){
 file * this = (file*) malloc(sizeof(file));
 file_init(this);
 return this;
}

void file_destroy(file * this){
 free(this);
}

#endif
