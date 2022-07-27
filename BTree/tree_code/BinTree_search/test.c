#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	char data;
	struct Node *next;
}pNode;

typedef struct Point{
	pNode *head;
	pNode *tail;
}xPoint;
