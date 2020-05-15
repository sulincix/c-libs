#include <stdio.h>
#include "dict.h"

int test1(){
 dict * d = dict_create();
 
 int a = 12;
 int b = 24;
 int c = 36;

 (d->put)(d,"a",&a);
 (d->put)(d,"b",&b);
 (d->put)(d,"c",&c);

 puts("size test");
 if( (d->size)(d) != 3 )
  return 1;

 puts("get test");
 if( *(int*)(d->get)(d,"a") != a )
  return 1;
 
 (d->put)(d,"a",&b);

 puts("set value via put test");
 if( *(int*)(d->get)(d,"a") != b )
  return 1;

 (d->remove)(d,"a");

 puts("remove test");
 if( (d->size)(d) != 2 )
  return 1;

 puts("list keys");
 liste * keys = (d->keys)(d);
 if( keys->size != 2 )
  return 1;
 (keys->clear)(keys);
 free(keys);

 (d->clear)(d);
 free(d);

 return 0;
}

int main(){
 if( test1() == 0)
  puts("tests passed");
 else
  puts("tests failed");

 return 0;
}
