#ifndef kuesji_dict_h
#define kuesji_dict_h 0

#include <stdlib.h>
#include <string.h>
#include <kuesji/liste.h>

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

dict * dict_create();


/* implementation */

long dict_size(dict * this){
 return this->data->size;
}

int dict_put(dict * this,char * key, void * data){

 liste_item * item = this->data->head;
 while(item){
  dict_item * entry = (dict_item*) item->data;
  if( strcmp(entry->key,key) == 0 ){
   entry->data = data;
   return 0;
  }
  item = item->next;
 }

 
 dict_item * entry = (dict_item*) malloc(sizeof(dict_item));
 entry->key = (char*) malloc(sizeof(char)*strlen(key));
 strcpy(entry->key,key);
 entry->data = data;
 (this->data->add)(this->data,entry);

 return 0;
}

void * dict_get(dict * this,char * key){
 liste_item * item = this->data->head;
 while(item){
  dict_item * entry = (dict_item*) item->data;
  if( strcmp(entry->key,key) == 0 ){
   return entry->data;
  }
  item = item->next;
 }

 return NULL;
}

int dict_remove(dict * this,char * key){
 liste_item * item = this->data->head;

 long index = 0;
 while(item){
  dict_item * entry = (dict_item*) item->data;
  if( strcmp(entry->key,key) == 0 ){
   (this->data->remove)(this->data,index);
   break;
  }
  index += 1;
  item = item->next;
 }

 return 0;
}

liste * dict_keys(dict * this){
 liste * keys = liste_create();

 liste_item * item = this->data->head;
 while(item){
  dict_item * entry = (dict_item*) item->data;
  (keys->add)(keys,entry->key);
  item = item->next;
 }

 return keys;
}

int dict_clear(dict * this){
 liste_item * item = this->data->head;
 while(item){
  dict_item * entry = (dict_item*) item->data;
  free(entry->key);
  free(entry);
  item = item->next;
 }

 (this->data->clear)(this->data);
}

dict * dict_create(){
 dict * this = (dict*) malloc(sizeof(dict));
 this->data = liste_create();

 this->size = &dict_size;
 this->put = &dict_put;
 this->get = &dict_get;
 this->remove = &dict_remove;
 this->keys = &dict_keys;
 this->clear = &dict_clear;

 return this;
}

#endif
