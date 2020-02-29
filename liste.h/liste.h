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

void liste_add(liste * l,void * data){
 liste_item * item = (liste_item*) malloc(sizeof(liste_item));
 item->data = data;
 item->next = NULL;

 if( l->head != NULL ){
  l->tail->next = item;
  l->tail = item;
 } else {
  l->head = item;
  l->tail = item;
 }

 l->size++;
}

void liste_insert(liste *l,uint64_t index,void * data){
 if(index >= 0){
  liste_item * item = (liste_item*) malloc(sizeof(liste_item));
  item->data = data;
  item->next = NULL;

  if(index == 0){
   item->next = l->head;
   l->head = item;
   l->size++;
  } else if(index > l->size){
   (l->add)(l,data);
  } else {
   liste_item * current = l->head;
   for(int i = 0; i < index-1; i++){
    current = current->next;
   }
   item->next = current->next;
   current->next = item;
   l->size++;
  }
 }
}

void liste_set(liste * l,uint64_t index,void * data){
 if(index >= 0 && index < l->size){
  if(index == l->size-1){
   l->tail->data = data;
  } else {
   liste_item * current = l->head;
   for(int i = 0; i < index; i++){
    current = current->next;
   }
   current->data = data;
  }
 }
}

void * liste_get(liste * l,uint64_t index){ 
 if(index == 0){
  return l->head->data;
 } else if(index == l->size-1){
  return l->tail->data;
 } else if(index > 0 && index < l->size){
  liste_item * current = l->head;
  for(int i = 0; i < index; i++){
   current = current->next;
  }
  return current->data;
 }

 return NULL;
}

void liste_remove(liste * l,uint64_t index){
 if(index == 0){
  liste_item * current = l->head;
  l->head = l->head->next;
  free(current);
  l->size--;
 } else if(index < l->size){
  liste_item * current = l->head;
  for(int i = 0; i < index-1; i++){
   current = current->next;
  }
  liste_item * tmp = current->next;
  if(index == l->size-1){
   l->tail = current;
   current->next = NULL;
  } else {
   current->next = current->next->next;
  }
  free(tmp);
  l->size--;
 }
}

void liste_clear(liste * l){
 if(l->size > 0){
  liste_item * prev;
  liste_item * current = l->head;

  while(current->next != NULL){
   prev = current;
   current = current->next;
   free(prev);
   l->size--;
  }

  free(current);
  l->size--;
  l->head = NULL;
  l->tail = NULL;
 }
}

liste * liste_create(){
 liste * l = (liste*) malloc(sizeof(liste));
 l->size = 0;
 l->add = &liste_add;
 l->insert = &liste_insert;
 l->set = &liste_set;
 l->get = &liste_get;
 l->remove = &liste_remove;
 l->clear = &liste_clear;

 return l;
}

#endif
