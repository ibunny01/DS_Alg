#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

/* 注意这里不能用int型，因为我们用的*base，
** 如果声明为int型的话，会把栈里相邻的多个元素当成一个整型对待
*/
typedef char ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if( !s->base )
    {
        exit(0);
    }

    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)
{	// 上溢
    if( s->top - s->base >= s->stackSize )
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if( !s->base )
        {
            exit(0);
        }
    }

    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e)
{	// 下溢
    if( s->top == s->base )
    {
        return;
    }
    *e = *--(s->top);
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int main()
{
	ElemType c;
	sqStack s;
	int len, i, sum = 0;

	InitStack(&s);

    printf("请输入二进制数，输入#符号表示结束！\n");
    scanf("%c", &c);

    while(c != '#'){
    	Push(&s, c);
    	scanf("%c", &c);
    }

    // 去掉回车符号，ascii=10
    getchar();

    len = StackLen(s);
    printf("栈的当前容量是: %d\n", len);

    for(i=0; i<len; i++){
    	Pop(&s, &c);
    	// 1的ASCII=49
    	sum = sum + (c-48) * pow(2, i);
    }

    printf("转化为十进制数是: %d\n", sum);

	return 0;
}





