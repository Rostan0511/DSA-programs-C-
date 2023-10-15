#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("STACK OVERFLOW\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop()
{
    
    int x=-1;
    struct Node *p;
    if(top==NULL)
        printf("STACK UNDERFLOW\n");
    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int StackTop()
{
    if(top)
    return top->data;
    else
    return -1;
}
int isEmpty()
{
    if(top)
    return 1;
    else
    return 0;
}
int isFull()
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    int r=t?1:0;
    free(t);
    return r;
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    Display();
    printf("Element popped=%d\n",pop());
    Display();
    printf("StackTop=%d\n",StackTop());
    printf("Empty?=%d\n",isEmpty());
    printf("Full?=%d\n",isFull());
    return 0;
}
