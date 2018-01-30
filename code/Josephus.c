#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node * createCList(int n){
	int i = 1;
	node * head = (node *)malloc(sizeof(node));
	node *p = head; 
	node *s;

	if(n != 0){
		while(i <= n){
			s = (node *)malloc(sizeof(node));
			s->data = i++;
			p->next = s;
			p = s;
		}
		p->next = head->next;
	}

	free(head);
}


int main()
{
	int n = 41;
	int m = 3;
	node *p = createCList(n);






	return 0;
}