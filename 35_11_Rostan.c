#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *S;
};
void create(struct stack *st)
{
    printf("Enter size of stack:\n");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}
void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
        printf("STACK OVERFLOW\n");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}
int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
        printf("STACK UNDERFLOW\n");
    else
    {
      x=st->S[st->top];
      st->top--;
    }
    return x;
}
int peek(struct stack st,int index)
{   
    int x=-1;
    if((st.top-index+1) < 0)
        printf("Invalid Index\n");
    else
    {
        x=st.S[st.top-index+1];
    }
    return x;
}
int StackTop(struct stack st)
{
    if(st.top==-1)
        return -1;
    else
        return st.S[st.top];
}
int isEmpty(struct stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}
int isFull(struct stack st)
{
    if(st.top==st.size-1)
        return 1;
    else
        return 0;
}
void Display(struct stack st)
{   if(!isEmpty(st))
    {   
        int i;
        printf("Element in stack:\n");
        for(i=st.top;i>=0;i--)
        printf("%d ",st.S[i]);
        printf("\n");
    }
}
int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    Display(st);
    printf("Pop Result=%d\n",pop(&st));
    Display(st);
    printf("Peek Result=%d\n",peek(st,2));
    printf("Stack Top =%d\n",StackTop(st));
    printf("Stack Empty?=%d\n",isEmpty(st));
    printf("Stack Full?=%d\n",isFull(st));
    return 0;
    
}
