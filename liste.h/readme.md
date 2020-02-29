# liste - linked list in c

## Introduction

a linkedlist implementation in c language.

warning: it is only allocate memory for itself, not your variables you must handle memory for your own data. this is just gives interface to easily group them.

## Code Samples

```
#include "liste.h"

int main(int argc,char * args[]){
 liste * l = liste_create();
 int n = 64;
 char * name = "liste";

 // add item
 (l->add)(l,&n);
 (l->add)(l,&name);

 // get item
 printf("num:%d,name:%s \n",*(int*)(l->get)(l,0),*(char*)(l->get)(l,1));

 // remove item 
 (l->remove)(l,0);

 // insert item
 (l->insert)(l,0,&n);

 // clear list
 (l->clear)(l);

 // securely destroy after clear
 free(l);

 return 0;
}


```

## Installation

just put `liste.h` into your project or library folder ( e.g /usr/include in linux )
