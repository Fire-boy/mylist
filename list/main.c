#include <stdio.h>
#include <string.h>
#include "list.h"

int main(){
	NODE *node;
	NODE *head;
	ListNode(&node);
	head = node;
	node->data=7;
	PreInsertList(&head,6);
	PreInsertList(&head,6);
	PreInsertList(&head,6);
	PreInsertList(&head,6);
	PreInsertList(&head,6);
	PreInsertList(&head,6);
	PreInsertList(&head,6);
	PreInsertList(&head,7);
	ShowList(head);
	SortList(&head);
	ShowList(head);
	DelListNode(&head,3);
	printf("反转\n");
	ReverseList(&head);	
	ShowList(head);
	DestroyList(head);
	
}

