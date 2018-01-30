#include <stdio.h>
#include <stdlib.h>

typedef int Status;   


typedef struct cLinkList
{
	int data;
	struct cLinkList *next;
}node;


void ds_init(node **pNode){
	int item;
	node *target, *temp;

	printf("输入结点的值，输入0完成初始化\n");

	while(1){
		scanf("%d", &item);
		fflush(stdin);
		if(item == 0)
			return;

		/*如果循环链表中只有一个结点*/
		if(*pNode == NULL){
			*pNode = (node*)malloc(sizeof(struct cLinkList));
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		}
		else{
			/*找到next指向第一个结点的结点*/
            // if target->next == (*pNode), 说明target已经到达尾部
			for(target=(*pNode); target->next != (*pNode);target=target->next);
            
            /*生成一个新的结点*/
			temp = (node*)malloc(sizeof(node));
		    
		    // 如果分配失败，exit
			if(!temp)
				exit(0);
			
			temp->data = item;
			target->next = temp;
			temp->next = (*pNode);
		}
	}
}


/*遍历*/
void ds_traverse(node *pNode){
	// pNode存有数据
	node *p = pNode;
	printf("***********链表中的元素******************\n");

	while(p->next != pNode){

		printf("%4d \n", p->data);
		p = p->next;
	}
	printf("\n");
}


/*插入结点*/
/*参数：链表的第一个结点，插入的位置*/
void ds_insert(node **pNode, int i){
	node *temp;
	node *target;

	int item;
	printf("输入要插入结点的值:");
	scanf("%d", &item);

	temp = (node*)malloc(sizeof(node));
	if(!temp)
		exit(0); 
	temp->data = item;

	/* 如果新插入的结点作为第一个结点 */
	if(i==1){

		/*寻找到最后一个结点*/
		for(target = (*pNode); target->next != (*pNode); target=target->next);
        
        // temp->next指向原来的第一个节点，因为原来的第一个节点现在变为第二个了
		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp;
	}

	else{

        // 如果插入的不是第1个位置，就索引到要插入的位置，线性表从1开始
		target = *pNode;
		for (int j = 1; j<(i-1) ; j++)
		{
			target = target->next;
		}

		temp->next = target->next;
		target->next = temp;
	}
}


/*删除结点*/
void ds_delete(node **pNode, int i){
	node *target, *temp;

	// 如果删除的是第一个结点
	if (i==1){
		/*找到最后一个结点，指向第一个结点的下一个结点*/
		for(target = (*pNode);target->next != (*pNode); target=target->next);
		temp = *pNode;
		target->next = temp->next;
		free(temp);	
		// 记得*pNode要更新
		*pNode = temp;
	}

	else{
		target = *pNode;
		for (int j = 1; j < i; j++)
		{
			target = target->next;
		}
		temp = target->next;
		target->next = temp->next;
		free(temp);
	}
}


int ds_search(node *pNode, int elem){
	int i = 1;
	node *target = pNode;
	for(; (target->data != elem) && (target->next != pNode); target=target->next){
		i++;
	}
	/*表中不存在该元素*/
	if(target->next == pNode)
		// 线性表从1开始
		return 0;
	else
		return i;
}


int main()
{
	node *pHead = NULL;
	char opp;
	int find;


    printf("1.初始化链表 \n\n2.插入结点 \n\n3.删除结点 \n\n4.返回结点位置 \n\n5.遍历链表  \n\n0.退出 \n\n请选择你的操作：");
    while(opp != '0')
	{
        scanf("%c", &opp);
        switch(opp)
		{
            case '1':
                ds_init(&pHead);
                printf("\n");
                ds_traverse(pHead);
                break;

            case '2':
                printf("输入需要插入结点的位置？");
                scanf("%d",  &find);
                ds_insert(&pHead, find);
                printf("在位置%d插入值后：\n",  find);
                ds_traverse(pHead);
                printf("\n");
                break;

            case '3':
                printf("输入需要删除的结点位置？");
                scanf("%d",  &find);
                ds_delete(&pHead, find);
                printf("删除第%d个结点后:\n",  find);
                ds_traverse(pHead);
                printf("\n");
                break;

            case '4':
                printf("你要查找的元素的值？");
                scanf("%d",  &find);
                printf("元素%d所在位置：%d\n",  find,  ds_search(pHead, find));
                //ListTraverse(L);
                printf("\n");
                break;

            case '5':
                ds_traverse(pHead);
                printf("\n");
                break;

            case '0':
                exit(0);
        }
    }

    return 0;
}