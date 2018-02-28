#define LH 1   // 左孩子高
#define EH 0   // 平衡
#define RH -1  // 右孩子高

typedef struct BiTNode{
	int data; 
	int bf; // 平衡因子
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 让p节点的左孩子指向p的左孩子(L)的右子树（此时为NULL）
// 再让L的右孩子指向p，让树根指向L
void R_Rotate(BiTree *p){
	BiTree L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	*p = L;
	
}

void LeftBalance(BiTree *T){
	BiTree L, Lr;
	L = (*T)->lchild;
	
	switch(L->bf){
		// 新插入的结点在T的左孩子左子树位置，需要右旋处理
		case LH:
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		// 新插入的结点在T的左孩子右子树位置，先修改左平衡操作后的平衡因子
		case RH:
			Lr = L->rchild;
			switch(Lr->bf){
				case LH:
					(*T)->bf = RH;
					L->bf = EH;
					break
				case EH:
					(*T)->bf = L->bf = EH;
					break;
				case RH:
					(*T)->bf = EH;
					L->bf = LH;
					break;
			}
			Lr->bf = EH;
			// 对T的左子树，左旋
			L_Rotate(&(*T)->lchild);
			// 再右旋T
			R_Rotate(T);
	}
}


// taller表示插入新结点后，树长高了没有，没长高就是balance的
int InsertAVL(BiTree *T, int e, int *taller){
	if( !*T ){
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	}
	else{
		// 要插入的data已经存在
		if(e == (*T)->data){
			*taller = FALSE;
			return FALSE;
		}
		// 
		if(e < (*T)->data){
			// 由于是递归代码，如果该data已存在，False
			if(!InsertAVL(&(*T)->lchild, e, taller))
				return FALSE;
			// 如果树长高了，check一下平衡因子
			if(*taller){
				switch((*T)->bf){
					case LH:
						LeftBalance(T);
						*taller = FALSE;
						break;
					// 原本树是平衡的，但是因为左子树+1，所以树变高了
					case EH:
						(*T)->bf = LH;
						*taller = TRUE;
						break;
					// 原本右子树高，但是加了左子树，树变平衡了
					case RH:
						(*T)->bf = EH;
						*taller = FALSE;
						break;
				}
			}
		}
		// e > (*T->data)
		else{
			if(!InsertAVL(&(*T)->rchild, e, taller))
				return FALSE;

			// 若右孩子+1，导致树变高了
			if(*taller){
				switch((*T)->bf){
					// 本来左子树高1，现在加了一个右孩子，平衡了
					case LH:
						(*T)->bf = EH;
						*taller = FALSE;
						break;
					case EH:
						(*T)->bf = RH;
						*taller = TRUE;
						break;
					case RH:
						RightBalance(T);
						*taller = FALSE;
						break;
				}
			}
		}
	}
}