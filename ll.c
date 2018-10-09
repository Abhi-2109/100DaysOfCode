#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
int data;
struct node* next;
};
int i;
struct node* head=NULL;

struct node* create()
{
//create a node
struct node* tmp=(struct node*)malloc(sizeof(struct node));
printf("Enter data to insert: ");
int x;
scanf("%d",&x);
tmp->data=x;
tmp->next=NULL;
//add node to list
head=tmp;
return head;
}

struct node* insert_front()
{
struct node* tmp=head;
//create first node
struct node* first=(struct node*)malloc(sizeof(struct node));
printf("Enter data to insert: ");
int x;
scanf("%d",&x);
first->data=x;
//add node to front
first->next=head;
//point head to new front node
head=first;
return head;
}

struct node* insert_end()
{
//pointer to head
struct node* tmp=head;
//point tmp to last node
while(tmp->next!=NULL)
tmp=tmp->next;
//construct new node to insert at last position
struct node* last=(struct node*)malloc(sizeof(struct node));
printf("Enter data to insert: ");
int x;
scanf("%d",&x);
last->data=x;
last->next=NULL;
//insert new node at last
//tmp is pointing to last node
tmp->next=last;
return head;
}

struct node* insert_pos()
{
int flag=0;
//pointer to head
struct node* tmp=head;
//Input position for node
printf("Enter position to insert: ");
int pos;
scanf("%d",&pos);
if(pos==1)
return insert_front();
//To insert at given position, we traverse to node just before it
for(i=1;i<pos-1;i++)
{
if(tmp==NULL)
{
flag=1;
printf("Invalid position\n");
break;
}
tmp=tmp->next;
}
if(flag==1)
return head;
//create a node to add it in the position
struct node* mid=(struct node*)malloc(sizeof(struct node));
printf("Enter data to insert: ");
int x;
scanf("%d",&x);
mid->data=x;
//a node ponter to hold rest of list right after position
struct node* hold;
hold=tmp->next;	//tmp at node just before position to be inserted
tmp->next=mid;	//added new node just at position
mid->next=hold;	//linked the new node and rest of the list
return head;
}

struct node* delete_pos()
{
int pos,flag=0;
//a node pointing to same as head
struct node* tmp=head;
struct node* at_pos,link;
printf("Enter position to delete (NOT LAST NODE)");
scanf("%d",&pos);
if(pos==1)
{
at_pos=tmp;
head=tmp->next;
free(at_pos);
return head;
}

//Traverse to node just before position
for(i=1;i<pos-1;i++)
{
if(tmp==NULL)
{
flag=1;
printf("Invalid position\n");
break;
}
tmp=tmp->next;
}
if(flag==1)
return head;
//point to node at position
at_pos=tmp->next;
//link two nodes adjacent to thr node at given position
tmp->next=at_pos->next;
//free node at position
free(at_pos);
return head;
}

struct node* delete_last()
{
struct node* t1;
//pointing to node same as head
struct node* tmp=head;
//
while(tmp->next!=NULL)
{
//to point to node just before tmp
//to hold node just before last node as BACKTRACK impossible
t1=tmp;
//move tmp to next node
tmp=tmp->next;
}
t1->next=NULL;
free(tmp);
return head;
}

void display_pos()
{
int flag=0;
struct node* tmp=head;
printf("Enter position: ");
int pos;
scanf("%d",&pos);
for(i=1;i<pos;i++)
{
if(tmp==NULL)
{
flag=1;
printf("Invalid position\n");
break;
}
tmp=tmp->next;
}
if(flag==0)
printf("%d\n",tmp->data);
}


void display()
{
struct node* tmp=head;
while(tmp->next!=NULL)
{
printf("%d->",tmp->data);
tmp=tmp->next;
}
printf("%d\n",tmp->data);
}

int main()
{
int ch;
bool created=false;
do
{
printf("Enter your choice:\n");
printf("1-Create list\n2-Insert at front\n3-Insert at end\n4-Insert at position");
printf("\n5-Delete node at position\n6-Delete last node\n7-Display data at a node\n8-Display list\n0-exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:	if(created==true)
	printf("\t\tList already created\n");
	else
	{
	head=create();
	created=true;
	}
	break;
case 2: head=insert_front();
	break;
case 3:	head=insert_end();
	break;
case 4: head=insert_pos();
	break;
case 5: head=delete_pos();
	break;
case 6: head=delete_last();
	break;
case 7: display_pos();
	break;
case 8: display();
}
}
while(ch!=0);
printf("\t\tThank you\n");
}
















