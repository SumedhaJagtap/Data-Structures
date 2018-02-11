#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int data;
	struct stack *next;
};
void printStack(struct stack **s);
struct stack *createStack()
{
	return NULL;
}
/*struct stack *createNode(char data){
	struct stack *s=(struct stack *)malloc(sizeof(struct stack));
	s->data=data;
	s->next=NULL;
	return s;
}
*/


void push(struct stack **s,int data)
{
//	struct stack *temp=s;
	struct stack *temp;
	temp=(struct stack *)malloc(sizeof(struct stack));
	if(temp==NULL)
	{
		return;
	}
/*	else
	{
	printf("\n%c\n",data);
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=createNode(data);	
	}
*/
	//temp=(struct stack *)malloc(sizeof(struct stack));
	//temp->data=data;
		temp->data=data;
		temp->next=*s;
		*s=temp;
}

int isEmpty(struct stack **s)
{
	return &s==NULL;
}
int pop(struct stack **s)
{
/*	struct stack *temp=s,*t1;
	if(!isEmpty(s))
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		char c=temp->data;
		free(temp);
		return c;
	}
	else
		return '-';
*/
	struct stack *temp;
	if(!isEmpty(s))
	{
		temp=*s;
		int data=temp->data;
		*s=temp->next;
		free(temp);
		return data;
	}
	else
		exit(0);
}
void printStack(struct stack **s)
{

	struct stack *temp;
	temp=*s;
	if(!s)
		return;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

/*

int check(char a,char b)
{
	if(a=='(' && b==')')
		return 1;
	if(a=='{' && b=='}')
		return 1;
	if(a=='[' && b==']')
		return 1;
	else
		return 0;

}
int isBalanced(char s[])
{
	int i=0;
	char c;
	struct stack *st=createStack();
	while(s[i]!='\0')
	{
		if(s[i]=='(' || s[i]=='[' || s[i]=='{')
		{
			push(&st,s[i]);
		}
		if(s[i]=='}' || s[i]==')' || s[i]==']')
		{
			if(st==NULL)
				return 0;
			else if(!check(pop(&st),s[i]))
				return 0;
		}
		i++;
	}
	if(isEmpty(&st))
		return 1;
	return 0;
}

*/
