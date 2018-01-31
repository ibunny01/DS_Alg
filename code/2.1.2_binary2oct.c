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
	sqStack bin;
    sqStack oct;
	int len, i, j = 0;
    int octSum = 0;

	InitStack(&bin);
    InitStack(&oct);

    printf("请输入二进制数，输入#符号表示结束！\n");
    scanf("%c", &c);

    while(c != '#'){
    	Push(&bin, c);
    	scanf("%c", &c);
    }
    getchar();      // 把'\n'从缓冲区去掉

    len = StackLen(bin);
    for(i=0; i<len; i+=3){
        for(j=0; j<3; j++){
            Pop(&bin, &c);
            octSum += (c-48) * power(2, j);
            if (bin.top == bin.base)
                break;
        }
        Push(&oct, c);
        sum = 0;
    }

    len = StackLen(oct);
    printf("\n转化为八进制数是: ");
    for(i=0; i<len; i++){
        Pop(&oct, &c);
        printf("%c", c);
    }
	return 0;
}





