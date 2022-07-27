#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode{
    char data;
    struct BTNode* lchild;
    struct BTNode* rchild;
}*BiTree;

void creat_BinTree(BiTree  *BT)
{
    char ch;
    scanf("%c",&ch);
    if(ch == '#'){
        *BT = NULL;
    }
    else{
        *BT = (BiTree)malloc(sizeof(struct BTNode));
        (*BT)->data = ch;
        creat_BinTree(&(*BT)->lchild);
        creat_BinTree(&(*BT)->rchild);
    }

}
void preOrder(BiTree BT)
{
    if(BT){
        printf("%c",BT->data);
        preOrder(BT->lchild);
        preOrder(BT->rchild);
    }
}
int main()
{

    BiTree bt;
    creat_BinTree(&bt);
    preOrder(bt);
    return 0;
}

