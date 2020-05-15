#ifndef kuesji_dict_h
#define kuesji_dict_h 0

#include <stdlib.h>
#include <string.h>
#include <liste/liste.h>

typedef struct dict dict;

struct dict {
 liste * data;

 long   (*size)(dict*);
 int    (*put)(dict*,char*,void*);
 void*  (*get)(dict*,char*);
 int    (*remove)(dict*,char*);
 liste* (*keys)(dict*);
 int    (*clear)(dict*);
};

typedef struct {
 char * key;
 void * data;
} dict_item;
/* implementation */

long dict_size(dict * this);
int dict_put(dict * this,char * key, void * data);
void * dict_get(dict * this,char * key);
int dict_remove(dict * this,char * key);
liste * dict_keys(dict * this);
int dict_clear(dict * this);
dict * dict_create();
#endif
