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
int file_open(file * this,char * path,uint8_t mode);
int file_read(file * this,char * buffer,int size);
int file_write(file * this, char * data);
long file_size(file * this);
int file_seek(file * this,long position);
int file_close(file * this);
void file_init(file * this);
void file_destroy(file * this);
#endif
