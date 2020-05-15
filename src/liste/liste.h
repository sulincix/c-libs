#ifndef liste

#include <stdlib.h>
#include <stdint.h>

typedef struct liste liste;
typedef struct liste_item liste_item;

struct liste {
 uint64_t size;
 liste_item * head;
 liste_item * tail; /* for faster append */

 void  (*add)(liste*,void*);
 void  (*insert)(liste*,uint64_t,void*);
 void  (*set)(liste*,uint64_t,void*);
 void* (*get)(liste*,uint64_t);
 void  (*remove)(liste*,uint64_t);
 void  (*clear)(liste*);
};

struct liste_item {
 void * data;
 liste_item * next;
};

liste * liste_create();

/* implementation */

void liste_add(liste * l,void * data);
void liste_insert(liste *l,uint64_t index,void * data);
void liste_set(liste * l,uint64_t index,void * data);
void * liste_get(liste * l,uint64_t index);
void liste_remove(liste * l,uint64_t index);
void liste_clear(liste * l);
#endif
