#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
    printf("Queue is Full\n");
    else
    {
        t->data = x;
        t->next=NULL;
        if(front == NULL)
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    int x=-1;
    struct Node *t;
    if(front == NULL)
    printf("Queue empty\n");
    else
    {
        t=front;
        x=front->data;
        front=front->next;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    while (p)
    {
     printf("%d ",p->data);
     p=p->next;
    }
    printf("\n");
}
int SearchElement(int key)
{
    struct Node *p = front;
    int pos = 1;

    while (p)
    {
        if (p->data == key)
            return pos;
        p = p->next;
        pos++;
    }

    return -1; // Element not found
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
       Display();
       printf("%d ",dequeue());
       //printf("Element found at position %d",SearchElement(5));
       int searchKey = 20;
    int position = SearchElement(searchKey);
    if (position != -1)
        printf("Element %d found at position %d\n", searchKey, position);
    else
        printf("Element %d not found in the queue\n", searchKey);

       return 0;
}
