#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

void bitree_init(BiTree * tree,void (*destroy)(void *data)){
	tree->size	=	0;
	tree->root	=	NULL;
	tree->destroy	=	destroy;
	return ;
}

void bitree_rem_left(BiTree *tree,BiTreeNode *node){
	
	BiTreeNode **position;
	/*如果是空树*/
	if ( bitree_size(tree) == 0  )	
	{
		return ;
	}
	if ( node == NULL )
	{
		position	=	&tree->root;
	}
	else
	{
		position	=	&node->left;
	}
	
	if ( *position!=NULL )
	{
	
		bitree_rem_left(tree,*position);
		bitree_rem_right(tree,*position);
		if ( tree->destroy != NULL )
		{
			tree->destroy((*position)->data);
		}
		free(*position);
		*position=NULL;
		tree->size--;
	}
	return ;
	
}

void bitree_rem_right(BiTree *tree,BiTreeNode *node){
	BiTreeNode **position;
	/*如果是空树*/
	if ( bitree_size(tree) == 0 )
	{
		return ;
	}
	if ( node == NULL )
	{
		position	=	&tree->root;
	}
	else
	{
		position	=	&tree->right;
	}
	if ( (*position) != NULL )
	{
		bitree_rem_left(tree,*position);	
		bitree_rem_right(tree,*position);
		if ( tree->destroy != NULL )
		{
			tree->destroy((*position)->data);
		}
		free(*position);
		*position=NULL;
		tree->size--;
	}
	return ;

}

void bitree_destroy(BiTree *tree){

	bitree_rem_left(tree, NULL);	
	memset(tree,0x00,sizeof(BiTree));
	return ;
}


/*实际使用的时候一般会加锁，保持互斥*/
int bitree_ins_left(BiTree *tree,BiTreeNode *node,const void *data	){
	BiTreeNode *new_node,**position;
	if ( node == NULL )
	{
		if ( bitree_size(tree) > 0 )
		{
			return -1;	
		}
		position = &tree->root;
	}	
	else
	{
		if ( bitree_left(tree) != NULL )
		{
			return -1;
		}	
		position = &tree->left;
	}
	new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	if ( new_node == NULL )
	{
		return -1;	
	}
	
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	*position = new_node;
	
	tree->size++;
	
	return 0;
}

int bitree_ins_right(BiTree * tree,BiTreeNode *node,const void *data){
	BiTreeNode *new_node,**position;
	if ( node == NULL )
	{
		if ( bitree_size(tree) > 0 )
		{
			return -1;	
		}
		position = &tree->root;
	}
	else
	{
		if ( bitree_right(tree) ！= NULL )
		{
			return -1;	
		}	
		position = &tree->right;
	}
	new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	new_node->data = data;
	new_node->left=new_node->right=NULL;
	*position = new_node;
	tree->size++;
	
	return 0;	
}

