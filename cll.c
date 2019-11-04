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
struct node *display(struct node *start);
struct node *insertatbeg(struct node *start);
struct node *insertatend(struct node *start);
struct node *insertatpos(struct node *start);
struct node *deleteatbeg(struct node *start);
struct node *deleteatend(struct node *start);
struct node *deleteatpos(struct node *start);
struct node *sort(struct node *start);
struct node *search(struct node *start);
struct node *reverse(struct node *start);
struct node *deleteduplicates(struct node *start);
struct node *insertsorted(struct node *start, int val);
/*struct node *count(struct node *start);
struct node *findmid(struct node *start);
struct node *insertmid(struct node *start);
struct node *deletemid(struct node *start);
struct node *exchangefirstlast(struct node *start);
struct node *split(struct node *start);
struct node *(struct node *start);*/

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
		printf("enter data : ");
		scanf("%d",&num);		
	}
	return start;	
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	printf("linked list is");
	while(ptr->next!=start)
	{
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
	printf("\t %d",ptr->data);
	return start;
}
struct node *insertatbeg(struct node *start)
{
	struct node *ptr,*newnode;
	int num;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the number to be inserted : ");
	scanf("%d",&num);
    newnode->data=num;
	ptr=start;
	while(ptr->next!=start)
	ptr=ptr->next;
	ptr->next=newnode;
	newnode->next=start;
	start=newnode;
	return start;
}
struct node *insertatend(struct node *start)
{
	struct node *ptr,*newnode;
	int num;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the number to be inserted :");
	scanf("%d",&num);
	newnode->data=num;
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
	printf("\n list is empty");
	return 0;
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
	printf("\n list is empty");
	return 0;
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
	printf("\n list is empty");
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
	printf("all duplicate nodes have been deleted");
	return start;
}
}
struct node *insertatpos(struct node *start)
{
	struct node *ptr,*newnode;
	int pos,i=1,data;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n enter  the data ");
    scanf("%d",&data);
    printf("enter the position");
    scanf("%d",&pos);
    ptr=start;
    newnode->data=data;
	if(start==NULL)
	{
       start=newnode;
       newnode->next=start;
	}
	while(i<pos-1 && ptr->next!=start)
	{
		i++;
		ptr=ptr->next;
	}
	newnode->next= ptr->next;
	ptr->next=newnode;
	return start;
	
}
struct node *deleteatpos(struct node *start)
{
	struct node *ptr,*ptr2;
	int pos,i=1;
	if(start==NULL)
	{
		printf("\n linked list empty");
		return 0;
		
	}
	else if(start->next==start)
	{
		start=NULL;
		return start;
	}
	printf("\n enter the position you want to delete");
	scanf("%d",&pos);
	ptr=start;
	while(i<pos-1&&ptr->next!=start)
	{
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
struct node *search(struct node *start)
{
	struct node *ptr;
	int item;
	ptr=start;
	int pos=1;
	if(start==NULL)
	{
		printf("n linked list does not exist");
		return 0;
	}
	printf("enter value to search");
	fflush(stdin);
	scanf("%d",&item);
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			printf("\n value is found at position %d",pos);
			return 0;
		}
		pos++;
		ptr=ptr->next;
		
	}
	return start;
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
