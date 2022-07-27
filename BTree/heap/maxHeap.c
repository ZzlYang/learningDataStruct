#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxData 1000
typedef char ElementType;
typedef struct HeapStruct MaxHeap;
struct HeapStruct{
	ElementType *ElementType;
	int size;
	int capacity;
};

MaxHeap* create_Heap(int Maxsize)
{
	MaxHeap*  newHeap = malloc(sizeof(MaxHeap));
	newHeap->ElementType =malloc((Maxsize+1)*sizeof(ElementType));
	newHeap->size = 0;
	newHeap->capacity=Maxsize;
	newHeap->ElementType[0] = MaxData;
}
bool isFull(MaxHeap * h)
{
	return (h->size ==h->capacity);
}
void insertHeap(MaxHeap *heap,ElementType item)
{
	int i;
	if(isFull(heap)){
		printf("最大堆已满！\n");
		return;
	}
	i = ++heap->size;
	for(;heap->ElementType[i/2]<item;i/=2){
		heap->ElementType[i] = heap->ElementType[i/2];
	}
	heap->ElementType[i] = item;
}

int main()
{
	
	return 0;
}
