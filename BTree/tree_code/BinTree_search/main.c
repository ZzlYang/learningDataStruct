#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}*BinTree,BinTNode;

BinTree Insert(char x,BinTree T)
{
	if(T == NULL){
		T = (BinTree)malloc(sizeof(BinTNode));
		T->data = x;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else if(x < T->data){
		T->lchild = Insert(x,T->lchild);
	}
	else if(x > T->data){
		T->rchild = Insert(x,T->rchild);
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

	char array[]={'1','3','4','7','9','8','K','G','N','D'};
    int  array_size=sizeof(array)/sizeof(array[0]);
    for(int i=0;i<array_size;i++){
      	p=Insert(array[i],p);
    }	

	Preorder(p);
	printf("\n");
	Inorder(p);

	return 0;
}