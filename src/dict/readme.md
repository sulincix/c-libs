# dict.h

## Introduction

a dictionary data structure implementation in c ( also dependant to `liste.h` )

## Code Samples

```
#include "dict.h"

int main(int argc,char * args[]){
 dict * d = dict_create();

 int a = 12;
 int b = 24;

 (d->put)(d,"a",&a);
 (d->put)(d,"b",&b);

 liste * keys = (d->keys)(d);
 for(int i = 0; i < keys->size; i++){
  char * key = (char*) (keys->get)(keys,i);
  printf("%s %s\n",key, *(int*)(d->get)(d,key));
 }

 (d->clear)(d);
 free(d);
}

```
check `dict.h` for more details

## Installation

just put `dict.h` and `liste.h` into your project or library folder
