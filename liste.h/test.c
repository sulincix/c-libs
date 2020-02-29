#include <stdio.h>
#include "liste.h"

int test1(){
 printf("testing add/get: ");
 liste * l = liste_create();

 int n0 = 16, n1 = 32, n2 = 64;
 (l->add)(l,&n0);
 (l->add)(l,&n1);
 (l->add)(l,&n2);

 int status = 0;
 if( *(int*)(l->get)(l,0) != n0 ) 
  status = 1;
 else if( *(int*)(l->get)(l,1) != n1)
  status = 1;
 else if( *(int*)(l->get)(l,2) != n2)
  status = 1;

 if( status )
  printf("fail\n");
 else
  printf("success\n");


 (l->clear)(l);
 free(l);
 return status;
}

int test2(){
 printf("testing insert: ");
 liste * l = liste_create();
 
 int n1 = 16, n2 = 32 , n3 =  64, n0 = 8;
 
 (l->add)(l,&n1);
 (l->add)(l,&n2);
 (l->add)(l,&n3);
 (l->insert)(l,1,&n0);

 int status = 0;
 if( *(int*)(l->get)(l,1) != n0 ){
  status = 1;
  printf("fail\n");
 } else
  printf("success\n");


 (l->clear)(l);
 free(l);
 return status;
}

int test3(){
 printf("testing set: ");
 liste * l = liste_create();
 int n0 = 8, n1 = 16, n2 = 32, n3 = 64;

 (l->add)(l,&n0);
 (l->add)(l,&n1);
 (l->add)(l,&n2);

 (l->set)(l,1,&n3);

 int status = 0;
 if( *(int*)(l->get)(l,1) != n3 ){
  status = 1;
  printf("fail\n");
 } else
  printf("success\n");

 (l->clear)(l);
 free(l);
 return status;
}

int test4(){
 printf("testing remove: ");
 liste * l = liste_create();
 int n0 = 8, n1 = 16, n2 = 32, n3 = 64;

 (l->add)(l,&n0);
 (l->add)(l,&n1);
 (l->add)(l,&n2);
 (l->add)(l,&n3);

 (l->remove)(l,1);

 int status = 0;
 if( *(int*)(l->get)(l,1) != n2 ){
  status = 1;
  printf("fail\n");
 } else 
  printf("success\n");

 (l->clear)(l);
 free(l);
 return status;
}

int test5(){
 printf("testing clear: ");
 liste * l = liste_create();
 int n0 = 8, n1 = 16, n2 = 32;
 
 (l->add)(l,&n0);
 (l->add)(l,&n1);
 (l->add)(l,&n2);

 (l->clear)(l);
 
 int status = 0;
 if( l->size != 0 ){
  status = 1;
  printf("fail\n");
  printf("s:%ld\n",l->size);
 } else
  printf("success\n");

 free(l);
 return status;
}

int main(int argc,char * args[]){
 test1();
 test2();
 test3();
 test4();
 test5();
 return 0; 
}
