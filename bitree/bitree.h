#ifndef	__BITREE_H
#define	__BITREE_H

typedef	struct __BitreeNode{
	void *data;
	struct __BitreeNode *left;
	struct __BitreeNode *right;
}BiTreeNode;

typedef struct __Bitree{
	int size;			/*节点数*/
	BiTreeNode	*root;		/*根节点*/
	int		(*compare)(const void *key1,const void *key2);
	void		(*destroy)(void *data);
}BiTree;

void bitree_init(BiTree *tree,void(*destroy)(void *data));
void bitree_destroy(BiTree *tree);
int bitree_ins_left(BiTree *tree,BiTreeNode *node,void *data);
int bitree_ins_right(BiTree *tree,BiTreeNode *node,void *data);
void bitree_rem_left(BiTree *tree,BiTreeNode *node);
void bitree_rem_right(BiTree *tree,BiTreeNode *node);
int bitree_merge(BiTree *merge,BiTree *left,BiTree * right,const void *data);

#define bitree_size(tree) 	((tree)->size)
#define bitree_root(tree) 	((tree)->root)
#define bitree_is_eob(node) 	((node) == NULL )
#define bitree_is_leaf(node)	((node)->left == NULL && (node)->right== NULL)
#define bitree_data(node)	((node)->data)
#define	bitree_left(node)	((node)->left)
#define	bitree_right(node)	((node)->right)

#endif
