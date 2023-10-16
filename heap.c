#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq==NULL || pq->size==0){
    return NULL;
  }
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq==NULL || pq->size==0){
    return;
  }
  
  if(pq->size==pq->capac){
    int newCapac=pq->capac*2+1;
    pq->heapArray=realloc(pq->heapArray, newCapac*sizeof(heapElem));
    pq->capac=newCapac;
  }
  
  int i=pq->size;
  pq->heapArray[i].data=data;
  pq->heapArray[i].priority=priority;

  while(i>0 && pq->heapArray[i].priority>pq->heapArray[(i-1)/2].prioity){
    heapElem aux=pq->heapArray[i];
    pq->heapArray[i]=pq->heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2]=aux;
    i=(i-1)/2;
  }
  pq->size++;
}


void heap_pop(Heap* pq){
  if(pq==NULL || pq->size==0){
    return;
  }
}

Heap* createHeap(){
  Heap* dato=malloc(sizeof(Heap));
  dato->capac=3;
  dato->size=0;
  dato->heapArray=malloc(3*sizeof(heapElem));
  return dato;
}
