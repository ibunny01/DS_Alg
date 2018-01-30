#include "stdio.h"
#include "stdlib.h"
#include <time.h>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;   /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */


typedef struct Node{
	ElemType data;
	struct Node * next;
}Node;

typedef struct Node *LinkList;


Status InitList(LinkList *L){
	*L = (LinkList)malloc(sizeof(Node));

	if (!(*L))
		return ERROR;

	(*L)->next = NULL;
	return OK;
}

int ListLength(LinkList L){
	int cnt = 0;
	LinkList p = L->next;
	while(p){
		p = p->next;
		cnt++;
	}
	return cnt;
}




Status ListTraverse(LinkList L){
	LinkList p = L->next;
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}

	printf("\n");
	return OK;
}



Status CreateListTail(LinkList *L, int n){
	LinkList p, r;
	int i;
	srand(time(0));
	r = (*L);

	for(i=0; i<n; i++){
		p = (LinkList)malloc(sizeof(Node));
		if (!p)
			return ERROR;
		p->data = rand()%100+1;
		r->next = p;
		r = p;
	}

	r->next = NULL;
	return OK;
}


Status CreateListHead(LinkList *L, int n){
	LinkList p;
	int i;
	srand(time(0));

	for(i=0; i<n; i++){
		p = (LinkList)malloc(sizeof(Node));
		if(!p)
			return ERROR;
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}

	return OK;
}



Status GetMidNode(LinkList L, ElemType *e){
	LinkList search, mid;
	search = mid = L;
	while(search->next != NULL){
		if(search->next->next != NULL){
			search = search->next->next;
			mid = mid->next;
		}
		else
			search = search->next;
	}
	(*e) = mid->data;
	return OK;
}


int main(){
	LinkList L;
	Status s;
	char op;
	ElemType e;
	int len;

	s = InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    printf("\n1.查看链表 \n2.创建链表（尾插法）\n3.创建链表（头插法） \n4.链表长度 \n5.中间结点值 \n0.退出 \n请选择你的操作：\n");
    while(op != '0'){
    	scanf("%c", &op);
    	switch(op){
    		case '1':
    			ListTraverse(L);
    			printf("\n");
    			break;
    		case '2':
    			CreateListTail(&L, 20);
    			printf("\n");
    			break;
    		case '3':
    			CreateListHead(&L, 20);
    			printf("\n");
    			break;
    		case '4':
                printf("ListLength(L)=%d \n",ListLength(L));
    			printf("\n");
    			break;
    		case '5':
    			GetMidNode(L, &e);
                printf("链表中间结点的值为：%d\n", e);
                printf("\n");
                break;
            case '0':
            	exit(0);
    	}

    }






}