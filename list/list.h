#ifndef __LIST_H__
#define __LIST_H__
#include "mytype.h"
typedef struct __NODE NODE;
struct __NODE{
	idata data;
	NODE *next;
} ;

int ListNode(NODE **node);
int Listisempty(NODE *head);
int PreInsertList(NODE **head,idata value);
int TaiInsertList(NODE **head,idata value);
int DelListNode(NODE *head,idata value);
int SortList(NODE **head);
int ListMerge(NODE *head1,NODE *head2);
int ShowList(NODE *head2);
int FindNode(NODE *head2,idata value);
int DestroyList(NODE *head2);

#endif