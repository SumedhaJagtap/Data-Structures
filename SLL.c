#include<stdio.h>
#include "SLL.h"

void main()
{
/*	struct SLL *head=createNode(1);
	printf("Initial LinkList");
	printList(head);
	printf("Insert at position 2");
	head=insert(head,2,2);
	printList(head);
	printf("Insert at position 1");
	head=insert(head,0,1);
	printList(head);
	printf("Insert at position 2");
	head=insert(head,3,2);
	printList(head);
	printf("Delete from position 5 but listLength=4");
	head=delete(head,5);
	printList(head);
	printf("Delete from position 2");
	head=delete(head,2);
	printList(head);
	printf("Deleting link list");
	head=deleteList(head);
	printList(head);
	struct SLL *t0=createNode(3);
	struct SLL *t1=createNode(4);
	struct SLL *t2=createNode(5);
	struct SLL *t3=createNode(6);
	struct SLL *t4=createNode(7);
	struct SLL *t5=createNode(8);
	struct SLL *t6=createNode(9);
	struct SLL *t7=createNode(2);
	struct SLL *t8=createNode(28);
	struct SLL *t9=createNode(19);
	t1->next=t2;
	t2->next=t3;
	t3->next=t4;
	t4->next=t5;
	t5->next=t3;

	if(cycle(t1)==1)
	{
		int d=startOfCycle(t1);
		printf("\nList Has cycle at %d",d);
	}
	else
		printf("\nList does not have cycle");
	t0->next=t1;
	t1->next=t2;
	t2->next=t3;
	t3->next=t4;
	t5->next=t4;
	t4->next=t6;
	printf("\nList1:");printList(t0);	
	printf("\nList1=2:");printList(t5);	
	printf("mergePoint: %d\n",mergePoint(t0,t5)->data);
	printf("mering two sorted link list\n");
	
	printf("\nList1:");
	t7->next=t8;
	t7=insert(t7,1,1);
	t7=insert(t7,5,3);
	t7=insert(t7,10,4);
	t7=insert(t7,18,5);
	printList(t7);	
	printf("\nList1=2:");
	t9=insert(t9,3,1);	
	t9=insert(t9,6,2);	
	t9=insert(t9,9,3);	
	t9=insert(t9,11,4);	
	t9=insert(t9,29,6);	
	t9=insert(t9,92,7);	
	printList(t9);
	struct SLL *mergedList=mergeSortedList(t7,t9);
	printList(mergedList);
*/
	printf("Reversing List Pair Wise\nlist:");
	struct SLL *t10=createNode(11);
	t10=insert(t10,12,2);
	t10=insert(t10,13,3);
	t10=insert(t10,14,4);
	t10=insert(t10,15,5);
	t10=insert(t10,16,6);
//	printList(t10);
	struct SLL *pairWiseRev=reverseListPairWise(t10);
//	printList(pairWiseRev);	
}
