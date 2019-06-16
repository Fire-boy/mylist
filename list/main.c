#include <stdio.h>
#include <string.h>
#include "list.h"

int main(){
	NODE *node;
	NODE *head;
	ListNode(&node);
	head = node;
	node->data=2;
	TaiInsertList(&head,3);
	PreInsertList(&head,8);
	PreInsertList(&head,9);
	PreInsertList(&head,7);
	ShowList(head);
	SortList(&head);
	ShowList(head);
	
	DestroyList(head);
	ShowList(head);
	
}

