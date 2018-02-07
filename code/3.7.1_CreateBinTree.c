#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTreeNode
{
	ElemType data;
	struct BiTreeNode *lchild, *rchild;
}BiTreeNode, *BiTree;

// 递归创建一棵二叉树，约定用户遵照前序遍历的方式输入数据
void CreateBiTree(BiTree *T){
	ElemType c;
	scanf("%c", &c);

	// 若输入的是空格，表示没有儿子，是空指针
	if(' ' == c)
		*T = NULL;
	else{
		*T = (BiTreeNode *)malloc(sizeof(BiTreeNode));
		(*T)->data = c;
		// 创建左子树
		CreateBiTree(&(*T)->lchild);
		// 创建右子树；
		CreateBiTree(&(*T)->rchild);
	}
}


// 访问二叉树结点的具体操作
void visit(ElemType c, int level){
	printf("%c 位于第 %d 层\n", c, level);
}



// 前序遍历二叉树
void PreOrderTraverse(BiTree T, int level){
	if(T){
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level+1);
		PreOrderTraverse(T->rchild, level+1);
	}
}


int main(){
	int level = 1;
	BiTree T = NULL;

	printf("请按前序遍历的顺序输入结点数据:\n");

	CreateBiTree(&T);
	PreOrderTraverse(T, level);

	return 0;
}


