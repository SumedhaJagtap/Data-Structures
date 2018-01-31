#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


struct SLL{
	int data;
	struct SLL *next;
};

struct SLL *createNode(int data)
{
	struct SLL *node=(struct SLL *)malloc(sizeof(struct SLL));
	node->data=data;
	node->next=NULL;
	return node;
}

void printList(struct SLL *head)
{
	struct SLL *temp=head;
	printf("\n");
	if(!head)
		return;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int listLength(struct SLL *head)
{
	int cnt=0;
	struct SLL *temp=head;
	while(temp!=NULL)
	{
		cnt++;		
		temp=temp->next;
	}
	return cnt;
}
struct SLL *insert(struct SLL *head,int data,int position)
{
	struct SLL *temp=head,*t1,*t2;
	int k=1;
	struct SLL *newnode=createNode(data);
	if(!head)
		return newnode;
	if(position==1)
	{
		newnode->next=head;
		head=newnode;
	}
	else{
		while(k<position-1 && temp!=NULL)
		{
			k++;
			if(temp->next) 
				temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		
	}
	return head;
}


struct SLL *delete(struct SLL *head,int position)
{
	struct SLL *temp=head,*t1,*t2;
	int k=1;
	if(position==1)
		head=head->next;
	else
	{
		while(k<position-1 && temp!=NULL)
		{
			k++;
			if(temp->next)
				temp=temp->next;
		}
		t1=temp;
		t2=temp->next;
		if(t2==NULL)
		{
			printf("\nposition not exist\n");
			return head;
		}
		t1->next=t2->next;
		temp=t2;
	}	
	free(temp);
	return head;
}


struct SLL *deleteList (struct SLL *head)
{
	struct SLL *temp=head,*t1;
	while(temp!=NULL)
	{
		t1=temp->next;
		free(temp);
		temp=t1;
	}

	return head;
}

int cycle(struct SLL *head)
{
	struct SLL *temp=head;
	struct SLL *slow=temp,*fast=temp;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			return 1;
	}
	return 0;
}

int startOfCycle(struct SLL *head)
{
	struct SLL *slow=head,*fast=head;
	int flag=0;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;	
		if(slow==fast)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		slow=head;
		while(slow!=fast)
		{
			slow=slow->next;
			fast=fast->next;
		}
		return slow->data;
	}
	else
	{
		return -1;
	}
}

struct SLL *mergePoint(struct SLL *list1,struct SLL *list2)
{
	struct SLL *head1=list1,*head2=list2;
	int l1=0,l2=0,diff=0;
	l1=listLength(list1);
	l2=listLength(list2);
	if(l1>l2)
	{
		head1=list1;
		head2=list2;
		diff=l1-l2;
	}
	else
	{

		head1=list2;
		head2=list1;
		diff=l2-l1;
	}
	for(int i=0;i<diff;i++)
	{
		head1=head1->next;
	}
	while(head1 && head2)
	{
		if(head1==head2)
			return head1;
		head1=head1->next;
		head2=head2->next;
	}	
	return NULL;
}


struct SLL *mergeSortedList(struct SLL *list1,struct SLL *list2)
{
	struct SLL *head1=list1,*head2=list2,*temp=NULL;
	struct SLL *newnode=(struct SLL *)malloc(sizeof(struct SLL));
	newnode->next=NULL;
	temp=newnode;
	while(head1 && head2)
	{
		if(head1->data<=head2->data)
		{
			temp->next=head1;
			temp=temp->next;
			head1=head1->next;		
		//	temp=insert(temp,head1->data,listLength(temp));
		}
		else
		{
			temp->next=head2;
			temp=temp->next;
			head2=head2->next;		
		//	temp=insert(temp,head2->data,listLength(temp));
		}
	}
	if(head1!=NULL)
		temp->next=head1;
	else
		temp->next=head2;
	temp=newnode->next;
	free(newnode);
	return temp;
}

struct SLL *reverseListPairWise(struct SLL *head)
{
	struct SLL *temp=head,*t1=NULL,*t2=NULL;
/*	while(temp && temp->next)
	{
		t2=temp;
		t1=temp->next;
		t2->next=temp->next->next;
		t1->next=t2;
		temp=t2->next;

		t2=temp;
		t1=t2->next;
		t2->next=t1->next;
		t1->next=t2;
		printf("%d %d %d\n",t2->data,t1->data,temp->data);
		temp=temp->next;
	}	
*/
/*	while(temp && temp->next)
	{
		if(t1==NULL)
			t1=temp;
		else
			t1=temp->next;
		printf("t1=%d\t",t1->data);
	//	sleep(2);
		if(t2==NULL)
		{	head=t2;
			t2=temp->next;
		}
		else
			t2=temp->next->next;
		
		printf("t2=%d\t",t2->data);
	//	sleep(2);
		t1->next=t2->next;
if(t1->next)		printf("t1->next=%d\t",t1->next->data);
	//	sleep(2);
		t2->next=temp;
		printf("t2->next=%d\t",t2->next->data);
	//	sleep(2);
		
		temp=t2->next;
		printf("temp=%d\n",temp->data);
		printList(t2);
	}
*/
/*	if(head==NULL || head->next==NULL)
		return NULL;
	else
	{
		temp=head->next;
		head->next=temp->next;
		temp->next=head;
		head=temp;
		head->next->next=reverseListPairWise(head->next->next);
	}
	return head;
*/

	while(temp && temp->next)
	{
		t1=temp;
		if(t2==NULL)
		{
			head=t2;
		}
		else
		{
			t1->next=t2;
		}
		t2=temp->next;	
		t1->next=t2->next;
		t2->next=t1;
		temp=temp->next;
if(t1->next)	
	printf("\ntemp=%d,%d,%d",temp->data,t1->data,t2->data);
	printList(t2);
	}
	return t2;
}
