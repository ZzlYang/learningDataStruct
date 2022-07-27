#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}*BinTree,BinTNode;

BinTree Insert(BinTree T,char x)
{
	if(T == NULL){
		T = (BinTree)malloc(sizeof(BinTNode));
		T->data = x;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else if(x < T->data){
		T->lchild = Insert(T->lchild,x);
	}
	else if(x > T->data){
		T->rchild = Insert(T->rchild,x);
	}
	return T;
}

void Preorder(BinTree p)
{
    if (p != NULL)
    {
        printf("%2c", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
//中序遍历
void Inorder(BinTree p)
{
    if (p != NULL)
    {
        Inorder(p->lchild);
        printf("%2c", p->data);
        Inorder(p->rchild);
    }
}

int main()
{	
	BinTree p = NULL;

	char array[]={'a','C','4','F','9','8','K','G','N','M'};
    int  array_size=sizeof(array)/sizeof(array[0]);
    for(int i=0;i<array_size;i++){
      	p=Insert(p,array[i]);
    }	
    printf("num=%d",array_size);
	Preorder(p);
	printf("\n");
	Inorder(p);
    printf("\n");
	return 0;
}