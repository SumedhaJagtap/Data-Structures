#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node 
{
	int data;
	struct Node *next;
};

struct queue
{
	struct Node *front,*rear;
};

struct Node *newnode(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

struct queue *createQueue()
{
	struct queue *q=(struct queue *)malloc(sizeof(struct queue));
	q->front=q->rear=NULL;
	return q;
}

void enqueue(struct queue *q,int data)
{
	struct Node *temp=newnode(data);
	if(!temp)
		return;
	if(q->rear==NULL)
	{
		q->front=q->rear=temp;
		return;
	}
	q->rear->next=temp;	
	q->rear=temp;
} 
/*
int dequeue(struct queue *q)
{
	if(q->front==NULL)
		return 0;
	int d=q->front->data;
	struct Node *temp=q->front;
	q->front=temp->next;
	free(temp);
	return d;
}*/

struct Node *dequeue(struct queue *q)
{
	if(q->front==NULL)
		return NULL;
	struct Node *temp=q->front;
	q->front=q->front->next;
	if(q->front==NULL)
		q->rear=NULL;
	return temp;

}
void printQueue(struct queue *q)
{
	struct Node *temp=q->front;
	if(temp)
	{
		printf("\n");
		while(temp)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	else
		return;

}
