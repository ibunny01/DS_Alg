#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct DualNode
{
	ElemType data;
	struct DualNode *prior;
	struct DualNode *next;
}DualNode, *DuLinkList;


Status InitLinkList(DuLinkList *L){
	DualNode *p, *q;
	int i;

	// 初始化头结点
	*L = (DuLinkList)malloc(sizeof(DualNode));
	if (!(*L))
		return ERROR;
	(*L)->next = (*L)->prior = NULL;
	p = (*L);

	// 初始化其他结点
	for (i=0; i<26; i++){
		q = (DualNode*)malloc(sizeof(DualNode));
		if(!q)
			return ERROR;
		q->data = 'A'+i;

		q->prior = p;
		q->next = p->next;
		p->next = q;

		p = q;

	}

	// 最后去掉头结点，最后一个结点指向第一个结点
	p->next = (*L)->next;
	(*L)->next->prior = p;

	return OK;
}


void Caeser(DuLinkList *L, int i){
	if(i > 0){
		do {
			(*L) = (*L)->next;
		}while(--i);
	}

	if(i < 0)
		do {
			(*L) = (*L)->next;
		}while(++i);

}


int main()
{
	DuLinkList L;
	int i, n;

	InitLinkList(&L);

	printf("请输入一个整数：");
	scanf("%d", &n);
	printf("\n");

	Caeser(&L, n);

	for(i = 0; i < 26; i++){
		L = L->next;
		printf("%c", L->data);
	}
	
	return 0;
}