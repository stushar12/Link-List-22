#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *top=NULL;
struct node * insert(int,struct node *);
struct node * delete(struct node *);
 struct node *traverse(struct node *);
int choice,data;
int main()
{
  struct node *p;
  char str[10];
  while(1)
  {
    printf("\n Enter yes to continue and no to stop \n");
    scanf("%s",str);
    if(strcmp(str,"no")==0)
    break;
    else
    {
      printf("\nEnter 1 for insertion \n2 for traverse \n3 for deletion\n");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
        printf("\n Enter the value to be inserted ");
        scanf("%d",&data);
        top=insert(data,top);
        break;
        case 2:
        traverse(top);
        break;
        case 3:
        top=delete(top);
        break;
        default:
        printf("\n Wrong choice made\n");
        exit(0);
      }
    }
  }
}
struct node *insert(int x,struct node *top)
{
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=top;
return temp;
}

struct node *traverse(struct node *p)
{
  struct node *q=p;
  if(p==NULL)
  {
    printf("\n Stack is empty\n");
  }
  else
  {
    printf("\n Element in stack are \n");
    while(p!=NULL)
    {
      printf("%d\n",p->data);
      p=p->next;
    }
  }
  p=q;
}
struct node *delete(struct node *p)
{
  struct node *temp;
  if(p==NULL)
  {
    printf("\n Stack is empty\n");
  }
  else
  {
    temp=p;
    p=p->next;
    printf("\n Element deleted is %d",temp->data);
    free(temp);
  }
  return p;
}
