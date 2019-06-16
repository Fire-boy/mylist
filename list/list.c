#include "list.h"
#include <stdio.h>
#include <string.h>

void * mymalloc(int x){
	void * ptr = malloc(x);
	return ptr;
}

int ListNode(NODE **node){
	*node = (NODE *) mymalloc(sizeof(NODE));	
	if ( *node != NULL )
	{
		(*node)->next=NULL;
		return 0;
	}
	else
	{
		return -1;
	}
}
int Listisempty(NODE *head){
	if ( head == NULL )
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int PreInsertList(NODE **head,idata value){
	if ( head == NULL )
	{
		return -1;
	}
	NODE *ptmp;
	ptmp = (NODE *) mymalloc(sizeof(NODE));
	if ( ptmp == NULL )
	{
		return -1;
	}
	ptmp->next = *head;
	ptmp->data = value;
	*head = ptmp;
	return 0;
}

int TaiInsertList(NODE **head,idata value){
	if ( *head == NULL )
	{
		return -1;
	}
	NODE *ptmp;
	ptmp = (NODE *) mymalloc(sizeof(NODE));
	if ( ptmp == NULL )
	{
		return -1;
	}
	ptmp->next = (*head)->next;
	ptmp->data = value;
	(*head)->next = ptmp;
	return 0;
}

int DelListNode(NODE *head,idata value){
	if ( head == NULL )
	{
		return -1;
	}
	/*判断边界条件删除头节点*/
	
	NODE *ptmp=head;
	if ( ptmp->data == value )
	{
		head = ptmp->next;
		free(ptmp);
		return 0;
	}
	NODE *ptmp1 = ptmp;
	while ( ptmp != NULL )
	{	
		
		if ( ptmp->data == value )
		{
			ptmp1->next = ptmp->next;
			ptmp->next = NULL;
			free(ptmp);
			break;
		}

		ptmp = ptmp->next;
		
		if ( ptmp == NULL )
		{
			return -1;
		}
		ptmp1 = ptmp;
		
	}
	return 0;
}
int SortList(NODE **head){
	int flag=1;
	if ( *head == NULL || (*head)->next == NULL )
	{
		return -1;
	}
	NODE *ptmp=*head;
	NODE *ptmp1=*head;

	/*ptmp1后驱节点*/
	NODE *ptmp2=(*head)->next;
	/*ptmp1前驱节点*/
	NODE *ptmp3;
	do{

		ptmp1=ptmp;
		ptmp2=ptmp1->next;
		/*最后一个节点不必比较*/
		if ( ptmp2 == NULL )
		{
			break;
		}
		ptmp3=ptmp1;
		flag=0;
		while ( ptmp1 != NULL ){
			
			printf("ptmp1->data=%d ptmp2->data=%d ptmp1->next->data =%d \n",ptmp1->data,ptmp2->data,ptmp1->next->data);
			if ( ptmp1->data < ptmp2->data )
			{
				/*单独处理头节点没有前驱节点的情况*/
				if ( ptmp1 == *head )
				{
					ptmp1->next = ptmp2->next;
					ptmp2->next = ptmp1;
					(*head)=ptmp2;
					ptmp=*head;
					ptmp3=ptmp2;
				}
				else
				{
					
					ptmp1->next = ptmp2->next;
					ptmp2->next = ptmp1;
					ptmp3->next = ptmp2; 
					ptmp3=ptmp2;
					
				}
				flag=1;
				if ( ptmp1 == NULL || ptmp1->next == NULL )
				{
					break;
				}
				ptmp2=ptmp1->next;
			}
			else
			{
				ptmp3 = ptmp1;
				ptmp1 = ptmp1->next;
				if ( ptmp1 == NULL || ptmp1->next == NULL)
				{
					printf("ptmp1->data=%d ptmp2->data=%d\n",ptmp1->data,ptmp2->data);
					break;
				}
				ptmp2=ptmp1->next;
			}
		}

	}while( flag );
	return 0;
}
int ReverseList(NODE **head){
	NODE * tmp,*tmp1,*tmp3;
	/*前驱节点*/
	tmp = *head;
	/*后驱节点*/
	tmp1 = (*head)->next;
	/*临时变量节点*/
	
	if ( tmp == NULL || tmp1 == NULL )
	{
		return -1;
	}
	while(tmp1 != NULL)
	{
		/*如果是最后一个节点将其变为头节点，原本头节点的next置为null*/
		if ( tmp1->next == NULL )
		{
			(*head)->next=NULL;
			*head=tmp1;
			(*head)->next = tmp;
			break;
		}
		/*后驱节点的next指针保存在tmp3中*/
		tmp3 = tmp1->next;
		/*将next指向前驱*/
		tmp1->next = tmp;
		/*保存前驱节点*/
		tmp = tmp1;
		/*移动指针tmp1*/
		tmp1 = tmp3;
	}
	
	return 0;
}

int ListMerge(NODE *head1,NODE *head2){
	if ( head1 == NULL || head2 == NULL )
	{
		return -1;
	}
	NODE *tmp=head1;
	while( tmp->next != NULL )
	{
		tmp = tmp->next;
	}
	tmp->next=head2;
	return 0;
}
int ShowList(NODE *head2){
	printf("step into %s \n",__func__);
	if ( head2 == NULL )
	{
		return -1;
	}
	NODE *tmp=head2;
	while ( tmp!=NULL )
	{
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
	return 0;
}
int FindNode(NODE *head2,idata value){
	if ( head2 == NULL )
	{
		return -1;
	}
	NODE *tmp=head2;
	while ( tmp != NULL )
	{
		if ( tmp->data ==  value)
		{
			break;
		}
		tmp=tmp->next;
	}
}
int DestroyList(NODE *head){
	if ( head == NULL )
	{
		return -1;
	}
	NODE *tmp=(NODE *)mymalloc(sizeof(NODE));
	while ( head != NULL )
	{	
		printf("free %d ",head->data);
		memcpy((char *)tmp,(char *)head,sizeof(NODE));
		free(head);
		head->next = NULL;
		head = tmp->next;
	}
	printf("\n");
	return 0;
}