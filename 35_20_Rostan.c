#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    int info;
};
struct node* getnode()
{
    return ((struct node*)malloc(sizeof(struct node)));
}

//to free a node
void freenode(struct node* p)
{
    free(p);
}

//initializing the LL
struct node *list = NULL;

void insert_element(int); 
void delete_element(int); 
void check_priority(int); 
void display_priorityqueue(); 

void main() 
{ 
    int n, choice;
    while (1) 
    { 
        printf("\n\n\n\n-----These are the menu panel-----");
        printf("\n1. To insert element by priority "); 
        printf("\n2. To delete element by priority "); 
        printf("\n3. To display priority queue "); 
        printf("\n4. To exit");  
        printf("\n\n\nEnter your choice : ");    
        scanf("%d", &choice);   
        switch(choice) 
        { 
        case 1: 
            printf("\nEnter element to insert : "); 
            scanf("%d",&n); 
            insert_element(n); 
            break; 
        case 2: 
            printf("\nEnter element to delete : "); 
            scanf("%d",&n); 
            delete_element(n); 
            break; 
        case 3: 
            display_priorityqueue(); 
            break; 
        case 4: 
            exit(0); 
        default: 
            printf("\n Please enter valid choice"); 
        } 
    } 
}

void insert_element(int data) 
{ 
    if(list==NULL)
    { 
        struct node *newnode;
        newnode=getnode();
        newnode->info=data;
        newnode->next=list;
        list=newnode;
    } 
    else 
        check_priority(data); 
}  
void check_priority(int data) 
{ 
    struct node *nn, *temp;
    nn=getnode();
    nn->info=data;
    temp=list;

    while((data >= temp->next->info)&&(temp!=NULL))
    { 
        temp=temp->next;
    }
    nn->next = temp->next;
    temp->next=nn;
}

//to delete a data from LL
void delete_element(int data)  
{ 
    if(list==NULL)
    {
        //if empty
        printf("Empty LL");
        return;
    }

    struct node *temp, *t2;
    temp =list;
    t2=list;

    while(temp->next!=NULL)
    {
        if(data==temp->info)
        {
            t2->next=t2->next->next;
            freenode(temp);
            return;
        }
        t2 = temp;
        temp= temp->next;
    }
    printf("\n%d element not found in queue", data); 
} 

//to display LL
void display_priorityqueue() 
{
    if(list==NULL)
    {
        //if empty
        printf("Empty LL");
        return;
    }
    struct node *temp;
    temp=list;
    while(temp->next!=NULL)
    {
        printf("%d\n", temp->info);
        temp=temp->next;
    }
    printf("%d", temp->info);
}