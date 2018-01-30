#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}sqlist, *linklist;

linklist CreateLinkList(int n)
{
    linklist head = NULL;
    linklist s, r;
    int i;
    r = head;
    // 尾插法
    for(i=1; i <= n; i++)
    {
        s = (linklist)malloc(sizeof(sqlist));
        s->data = i;

        if(head == NULL)
            head = s;
        else
            r->next = s;
        r = s;
    }
    // 循环
    r->next = head;
    return head;
}



void printLatin(linklist L, int n){
    int j, k;
    linklist p = L;
    for(j = 1; j <= n; j++){
        k = 1;
        for(; k <= n; k++){
            printf("%d", p->data);
            p = p->next;
        }
        printf("\n");
        p = p->next;
    }
}


int main()
{
    linklist p;
    int n;
    printf("请输入n：\n");
    scanf("%d", &n);

    p = CreateLinkList(n);
    printLatin(p, n);

    return 0;
}
