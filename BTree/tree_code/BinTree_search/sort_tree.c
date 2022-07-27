#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode{
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTree,*BinTree;

void preorder(BinTree T);
BinTree insert(BinTree T,char data);
int leftCount(BinTree T);
int getMaxHight(BinTree T);
BinTree FindMax(BinTree T);


int main()
{
	BinTree p=NULL;
	
	char array[] = {'1','2','3','4','5','6','7','8','9','0'};
	for(int i=0;i<10;i++){
		p = insert(p,array[i]);
	}

	preorder(p);
	printf("\nleftNum == %2d\n",leftCount(p));
	printf("The Tree MaxDepth is %2d\n",getMaxHight(p));
	int maxVal = (FindMax(p)->data);
	printf("The maxVal is %c\n",maxVal);
	return 0;
}

void preorder(BinTree T)
{
	if(T){
		printf("%2c",T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

BinTree insert(BinTree T,char x)
{
	if(T == NULL){
		T =(BinTree)malloc(sizeof(BTree));
		T->data = x;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else if( x < T->data){
		T->lchild = insert(T->lchild,x);	
	}
	else if( x > T->data){
		T->rchild = insert(T->rchild,x);
	}
	return T; 
}

int leftCount(BinTree T)
{
	if(T ==NULL){
		return 0;
	}
	else if(T->lchild == NULL &&T->rchild==NULL){
			return 1;
		}
		else
			return leftCount(T->lchild)+leftCount(T->rchild);
}


int getMaxHight(BinTree T)
{
	int LD,RD;
	if(T==NULL){
		return 0;
	}
	else {
		LD = getMaxHight(T->lchild);
		RD = getMaxHight(T->rchild);
		return (LD > RD? LD:RD)+1;
	}
}

BinTree FindMax(BinTree T) {
    if (T == NULL)
        return 0;
    else if (T->rchild == NULL)
        return T;
    else
        return FindMax(T->rchild);
}