/**编写一个链队列，任意输入一串字符，以#作为结束标志，然后将队列中的元素显示到屏幕上。**/
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct Qnode{
    ElemType data;
    struct Qnode *next;
}Qnode, *QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;


void InitQueue(LinkQueue *q){
    q->front = q->rear = (QueuePtr)malloc(sizeof(Qnode));
    if(!q->front || !q->rear)
        exit(0);
    q->front = q->rear;

}

void InsertQueue(LinkQueue *q, ElemType e){
    QueuePtr p = (QueuePtr)malloc(sizeof(Qnode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

void DeleteQueue(LinkQueue *q, ElemType *e){
    if(q->front == q->rear)
        return;
    QueuePtr p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    free(p);

    if(q->rear == p){
        q->rear = q->front;
    }
}

void DestroyQueue(LinkQueue *q){
    while(q->front){
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}


int main()
{
    LinkQueue q;
    InitQueue(&q);
    char c;
    printf("please input a sequence of numbers, end with '#':\n");
    scanf("%c", &c);
    while(c != '#'){
        InsertQueue(&q, c);
        scanf("%c", &c);
    }
    printf("\nThe elements in the queue are:\n");
    while(q.front != q.rear){
        DeleteQueue(&q, &c);
        printf("%c", c);
    }
    return 0;
}
