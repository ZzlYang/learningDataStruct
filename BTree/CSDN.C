#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
Position Find(int x, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
typedef struct TreeNode {
    SearchTree left;
    SearchTree right;
    int data;
}*Bintree;
// Bintree InitTree(int x, SearchTree T);//插入节点（创建二叉查找树） 
Bintree Delete(int x, SearchTree T);//删除节点 
//构造二叉查找树树（插入操作）
Bintree InitTree(int x, Bintree T) {
//    int i = 0;
    if (T == NULL) {
        T = (Bintree)malloc(sizeof(struct TreeNode));
        if (T == NULL)
            return 0;
        else {
            T->data = x;
            T->right = NULL;//先右节点，在左节点
            T->left = NULL;
        }
    }
    else if (x < T->data) {
        T->left = InitTree(x, T->left);
    }
    else if (x > T->data) {
        T->right = InitTree(x, T->right);
    }
    else
        printf("%d has inserted\n", x);
    return T;
}
//查找元素
Position Find(int x, SearchTree T) {
    if (T == NULL)
        return 0;
    if (x < T->data)
        return Find(x, T->left);
    else if (x > T->data)
        return Find(x, T->right);
    else
        return T;
}
//查找最小值
Position FindMin(SearchTree T) {
    if (T == NULL)
        return 0;
    else if (T->left == NULL)
        return T;
    else
        return FindMin(T->left);
}
//查找最大值
Position FindMax(SearchTree T) {
    if (T == NULL)
        return 0;
    else if (T->right == NULL)
        return T;
    else
        return FindMin(T->right);
}
Bintree Delete(int x, SearchTree T) {
    Position temp;
    if (T == NULL)
        return 0;
    else if (x < T->data)
        T->left = Delete(x, T->left);
    else if (x > T->data)
        T->right = Delete(x, T->right);
    else if (T->left && T->right) {
        temp = FindMin(T->right);
        T->data = temp->data;
        T->right = Delete(T->data, T->right);
    }
    else {
        temp = T;
        if (T->left == NULL)
            T = T->right;
        else if (T->right == NULL)
            T = T->left;
        free(temp);
    }
    return T;
}
//先序遍历
void Preorder(Bintree p)
{
    if (p != NULL)
    {
        printf("%d", p->data);
        Preorder(p->left);
        Preorder(p->right);
    }
}
//中序遍历
void Inorder(Bintree p)
{
    if (p != NULL)
    {
        Inorder(p->left);
        printf("%d", p->data);
        Inorder(p->right);
    }
}
//后序遍历
void Postorder(Bintree p)
{
    if (p != NULL)
    {
        Postorder(p->left);
        Postorder(p->right);
        printf("%d", p->data);
    }
}
int main() {
    Bintree p = NULL;
    int a[MaxSize];
    int num, x, y;
    Bintree find, min, max;
    printf("scanf element number：");
    scanf("%d", &num);
    printf("scanf element：");
    for (int i = 0; i < num; i++) {
        scanf("%d", &a[i]);
        p = InitTree(a[i], p);
    }
    printf("Preorder is:");//先序遍历
    Preorder(p);
    printf("\n");
    printf("Inorder is:");//中序遍历
    Inorder(p);
    printf("\n");
    printf("Postorder is:");//后序遍历
    Postorder(p);
    printf("\n");
    printf("scanf element you want find：");
    scanf("%d", &x);
    find = Find(x, p);//查找元素
    printf("find success：%d\n", find->data);
    min = FindMin(p);//查找最小值
    printf("min element is:%d\n", min->data);
    max = FindMax(p);//查找最大值
    printf("max element is:%d\n", max->data);
    printf("scanf element you want delete：");
    scanf("%d", &y);
    p = Delete(y, p);//删除节点
    Inorder(p);//中序遍历检查是否删除成功
    return 0;
}