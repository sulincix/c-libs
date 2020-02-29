# file.h

## Introduction

> easy to use file read & write wrapper

## Code Samples

dynamic
```c
file * f = file_create();
(f->open)(f,"test.txt",FILE_READ | FILE_WRITE);

for(int i = 0; i < 16; i++)
 (f->write)(f,"hello world");

(f->seek)(f,0);

char buffer[256];
while( (f->read)(f,buffer,sizeof(buffer)) == 0)
 printf("%s",buffer);

(f->close)(f);
file_destroy(f);

```
static
```c
file f;
file_init(&f);
(f.open)(f,"test.txt",FILE_READ | FILE_WRITE);

for(int i = 0; i < 16; i++)
 (f.write)(f,"hello world");

(f.seek)(f,0);

char buffer[256];
while( (f.read)(f,buffer,sizeof(buffer)) == 0)
 printf("%s",buffer);

(f.close)(f);
```



available modes (use with bitwise or because they are flags):
```c
FILE_READ, FILE_WRITE, FILE_APPEND
```
available functions (returns -1 when fail):
```c
int open(file * this, char * path, uint8_t mode);
int read(file * this,char * buffer, int readsize);
int write(file * this,char * data);
int size(file * this); /* doesnt return file size on disk, returns character count in file*/
int seek(file * this,long position);
int close(file * this);
```

## Installation

this is single header library. just put `file.h` into your includes.
