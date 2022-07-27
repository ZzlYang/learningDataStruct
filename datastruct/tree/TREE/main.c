#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode{
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTree;

void preorder(BTree *T);
BTree *insert(BTree *T,char data);
BTree* Delet(char x,BTree* BST);
BTree* FindMin(BTree* T);
int main()
{
	BTree *p=NULL;
    char bh;
	char array[] = {'a','c','d','b','g','h','q','s'};
	for(int i=0;i<8;i++){
		p = insert(p,array[i]);
	}
    char ch = FindMin(p)->data;
    printf("%c\n",ch);
    bh = array[3];
    preorder(p);
    Delet(bh,p);
    printf("\n");
	preorder(p);
    printf("\n");
	return 0;
}

void preorder(BTree *T)
{
	if(T){
		printf("%2c",T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

BTree *insert(BTree* T,char x)
{
	if(T == NULL){
		T =(BTree*)malloc(sizeof(BTree));
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


BTree* Delet(char x,BTree* BST)
{
    BTree *tmp;
    if(BST == NULL){
        printf("要删除的元素未找到！");
    }
    else if( x < BST->data){
            BST->lchild = Delet(x,BST->lchild);
    }
    else if(x > BST->data){
            BST->rchild=Delet(x,BST->rchild);
    }
    else
    {
        if(BST->lchild && BST->rchild){
            tmp = FindMin(BST->rchild);

            BST->data = tmp->data;
            BST->rchild = Delet(BST->data,BST->rchild);
        } else {
            tmp = BST;
            if(!BST->lchild){
                BST = BST->rchild;
            }
            else if(!BST->rchild){
                BST=BST->lchild;
            }

            free(tmp);
        }
    }
    return BST;
}




BTree* FindMin(BTree* T)
{
    BTree *p=T;
    if(p){
    while(p->lchild != NULL){
        p=p->lchild;
    }
    }
    return p;
}