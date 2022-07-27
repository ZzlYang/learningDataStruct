#include <stdio.h>
#include <stdlib.h>

typedef struct pNode{
	char data;
	struct pNode *next;
}*pLink,Node;

pLink creatHeadNode(); //创建表头
void disPlayNode(pLink headNode);	//遍历链表
void insertNodebyHead(pLink headNode,char data); //插入链表
void delNode(pLink headNode,int k);	//删除指定位置节点
int getLength(pLink headNode); 		//获取链表长度

int main()
{
	pLink pList;
	pList = creatHeadNode();

    char ch = 'A';

	for(int i =0;i<10;i++,ch++){
		insertNodebyHead(pList,ch);
	}
	printf("%d\n",getLength(pList) );
	disPlayNode(pList);
	return 0;
}

void disPlayNode(pLink headNode)
{
	pLink pMove = headNode->next;
	while(pMove){
		printf("%c\n",pMove->data );
		pMove = pMove->next;
	}
}

void insertNodebyHead(pLink headNode,char data)
{
	pLink newNode=(pLink)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;

	newNode->next=headNode->next;
	headNode->next = newNode;

}


pLink creatHeadNode()
{
	pLink headNode =(pLink)malloc(sizeof(Node));
	headNode->next =NULL;
	return headNode;
}

int getLength(pLink headNode)
{
	int count=0;
	pLink pMove = headNode->next;
	while(pMove){
		pMove=pMove->next;
		count++;
	}
	return count;
}
