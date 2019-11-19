#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *create(struct node *start);
void display(struct node *start);
struct node *insertatbeg(struct node *start, int num);
struct node *insertatend(struct node *start, int num);
struct node *insertatpos(struct node *start, int num, int pos);
struct node *deleteatbeg(struct node *start);
struct node *deleteatend(struct node *start);
struct node *deleteatpos(struct node *start, int pos);
struct node *sort(struct node *start);
int search(struct node *start, int item);
struct node *reverse(struct node *start);
struct node *deleteduplicates(struct node *start);
struct node *insertsorted(struct node *start, int val);
int count(struct node *start);
int findmid(struct node *start);
struct node *insertmid(struct node *start,int data);
struct node *deletemid(struct node *start);
struct node *exchangefirstlast(struct node *start);
struct node *split(struct node *start);


struct node *create(struct node *start)
{
	struct node *newnode, *ptr;
	int num;
	printf("Enter -1 to end. \n");
	printf("Enter data : ");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=num;
		if(start==NULL)
		{
			newnode->next=newnode;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			ptr=ptr->next;
			ptr->next=newnode;
			newnode->next=start;
		}
		printf("Enter data : ");
		scanf("%d",&num);		
	}
	return start;	
}

void display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	printf("Circular linked list is: ");
	if(start == NULL){
		printf("Empty!");
		return;
	}

	while(ptr->next!=start)
	{
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
	printf("\t %d",ptr->data);
}

struct node *insertatbeg(struct node *start, int num)
{
	struct node *ptr,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = num;
	newnode->next = NULL;

	if(start == NULL)
	{
		start = newnode;
		newnode->next = start;
	}

	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;

	ptr->next=newnode;
	newnode->next=start;
	start=newnode;
	return start;
}

struct node *insertatend(struct node *start, int num)
{
	struct node *ptr,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	newnode->next = NULL;

	if(start == NULL)
	{
		start = newnode;
		newnode->next = start;
	}

    ptr=start;
    while(ptr->next!=start)
		ptr=ptr->next;

    ptr->next=newnode;
    newnode->next=start;
    return start;
}

struct node *deleteatbeg(struct node *start)
{
	struct node *ptr,*temp;
	if(start==NULL)
	{
		printf("\nList is empty");
		return NULL;
	}

	else if(start->next==start)
	{
		start=NULL;
		return start;
	}

	else
	{    
	    ptr=temp=start;
		while(ptr->next!=start)
			ptr=ptr->next;
		ptr->next=temp->next;
		start=ptr->next;
		free(temp);
		return start;
	}
}

struct node *deleteatend(struct node *start)
{
	struct node *ptr,*preptr;
	if(start==NULL)
	{
		printf("\nList is empty");
		return NULL;
	}

	else if(start->next==start)
	{
			start=NULL;
			return start;
	}

	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		return start;
	}
}

struct node *deleteduplicates(struct node *start)
{
	struct node *ptr,*ptr2,*ptr3;
	ptr=start;
	if(start==NULL)
	{
		printf("\nList is empty");
		return 0;
	}
	else
	{
		while(ptr->next!=start)
		{
			ptr2=ptr;
			ptr3=ptr->next;
			while(ptr3!=start)
			{
				if(ptr3->data==ptr->data)
				{
					ptr2->next=ptr3->next;
					free(ptr3);
					ptr3=ptr2;
				}
				ptr3=ptr3->next;
			}
			ptr=ptr->next;
		}
		printf("All duplicate nodes have been deleted");
		return start;
	}
}

struct node *insertatpos(struct node *start, int data, int pos)
{
	struct node *ptr,*newnode;
	int i=1;
	newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = data;
	newnode->next = NULL;

    ptr=start;

	if(pos <= 0){
		printf("Position number exceeded!");
		return start;
	}

	if(start==NULL)
	{
       start=newnode;
       newnode->next=start;
	}

	if(pos == 1){
		while(ptr->next != start)
			ptr = ptr->next;
		newnode->next= ptr->next;
		ptr->next=newnode;
		return newnode;
	}

	while(i<pos-1)
	{
		if(ptr->next==start)
		{
			printf("Position number exceeded!");
			return start;
		}
		i++;
		ptr=ptr->next;
	}
	newnode->next= ptr->next;
	ptr->next=newnode;

	return start;
}

struct node *deleteatpos(struct node *start, int pos)
{
	struct node *ptr,*ptr2;
	int i=1;
	if(start==NULL)
	{
		printf("\nLinked list empty");
		return 0;
		
	}

	if(pos <= 0){
		printf("Position number exceeded!");
		return start;
	}

	else if(start->next==start)
	{
		start=NULL;
		return start;
	}

	ptr=start;
	if(pos == 1){
		while(ptr->next != start)
			ptr = ptr->next;
		ptr2 = ptr->next;
		ptr->next=ptr2->next;
		free(ptr2);
		return ptr->next;
	}

	while(i<pos-1)
	{
		if(ptr->next!=start)
		{
			printf("Position number exceeded!");
			return start;
		}
		ptr=ptr->next;
		i++;
    }
    ptr2=ptr->next;
    ptr->next=ptr2->next;
    free(ptr2);
    return start;
}

struct node *reverse(struct node *start)
{
	struct node *prev,*curr,*tail,*temp;
	prev=tail=start;
	curr=start->next;
	start=start->next;
	while(start!=tail)
	{
		start=start->next;
		curr->next=prev;
		prev=curr;
		curr=start;
	}
	curr->next=prev;
	start=prev;
	return start;
}

int search(struct node *start, int item)
{
	struct node *ptr;
	ptr=start;
	int pos=1;

	if(start==NULL)
	{
		printf("\nLinked list does not exist");
		return 0;
	}

	do
	{
		if(ptr->data==item)
			return pos;
		pos++;
		ptr=ptr->next;
	}while(ptr!=start);

	return -1;
}

struct node *sort(struct node *start)
{
	struct node *p,*q;
	int temp;
	p=start;
	while((p->next)!=start)
	{
		q=p->next;
		while(q!=start)
		{
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
	}
	return start;
}

struct node *insertsorted(struct node *start, int val)
{
	struct node *ptr, *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = NULL;
	ptr = start;

	if((start == NULL) || (start->data >= newnode->data))
	{
		while(ptr->next != start)
			ptr = ptr->next;

		ptr->next = newnode;
		newnode->next = start;
		start = newnode;
	}

	else
	{
		while(ptr->next != NULL && ptr->next->data < newnode->data)
			ptr = ptr->next;

		newnode->next = ptr->next;
		ptr->next = newnode;
	}
	return start;
}

int count(struct node *start)
{
	if(start==NULL)
	printf("list is empty");
	struct node *ptr;
	int cnt=0;
	ptr=start;
	while(ptr->next!=start)
	{
		cnt++;
		ptr=ptr->next;
	}
	printf(" \nThe no. of nodes %d",cnt+1);
	return (cnt+1);
}
int findmid(struct node *start)
{
	struct node *ptr,*ptr2;
	ptr=ptr2=start;
	int cnt=0,m=1,mid;
	cnt=count(start);
	if(cnt%2!=0)
		mid=(cnt+1)/2;	
	else
		mid=cnt/2;
	while(ptr->next!=start)
	{
		while(m<mid)
		{
			ptr2=ptr2->next;
			m++;
			
		}
		ptr=ptr->next;
	}
	printf("/n the middle element %d ",ptr2->data);	
	return mid;
}
struct node *insertmid(struct node *start,int data)
{
	int b,m=1;
	struct node *ptr2,*newn;
	ptr2=start;
	b=findmid(start);
	while(ptr2->next!=start&&m<b)
		{
			ptr2=ptr2->next;
			m++;
		}
	newn=(struct node*)malloc(sizeof(struct node));
	newn->data=data;
	newn->next=ptr2->next;
	ptr2->next=newn;
	return start;
}

struct node *deletemid(struct node *start)
{
	int b,m=1;
	struct node *ptr,*temp;
	if(start==NULL)
	printf("list is empty");
	ptr=start;
	b=findmid(start);
	while(ptr->next!=start&&m<(b-1))
	{
		ptr=ptr->next;
		m++;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	free(temp);
	return start;
}

struct node *split(struct node *start)
{
	if(start==NULL)
	printf("linked list empty");
	else
	{
		struct node *fast,*slow;
		slow=fast=start;
		while(fast->next!=start&&fast->next->next!=start)
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		struct node *head1=start,*head2=slow->next;
		slow->next=head1;
		if(fast->next->next==start)
		{
			fast=fast->next;
		}
		fast->next=head2;
		display(head1);
		display(head2);
	}
}

struct node *exchangefirstlast(struct node *start)
{
	struct node *ptr=start,*qtr=start;
	if(start==NULL)
		printf("list is empty");
	int t=0;
	while(ptr->next!=start)
		ptr=ptr->next;
	t=ptr->data;
	ptr->data=qtr->data;
	qtr->data=t;
    return start;
}