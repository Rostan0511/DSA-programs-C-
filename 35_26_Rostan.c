#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
void preorder(struct Node *p)
{
    if(p)
    {
       printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
        
    }
}

void postorder(struct Node *p)
{
    if(p)
    {
      postorder(p->lchild);
       postorder(p->rchild);
        printf("%d ",p->data);
       
    }
}

struct Node * Search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return  NULL;
}
struct Node *findMin(struct Node *node)
{
    while (node->lchild != NULL)
        node = node->lchild;
    return node;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->lchild = deleteNode(root->lchild, key);
    else if (key > root->data)
        root->rchild = deleteNode(root->rchild, key);
    else
    {
        if (root->lchild == NULL)
        {
            struct Node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            struct Node *temp = root->lchild;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->rchild);
        root->data = temp->data;
        root->rchild = deleteNode(root->rchild, temp->data);
    }
    return root;
}
int main()
{
    struct Node *temp;
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
  
    root = deleteNode(root, 5);
    printf("\nInorder\n");
    Inorder(root);
    printf("\npreorder\n");
    preorder(root);
    printf("\npostorder\n");
    postorder(root);
    printf("\n");
    temp=Search(20);
    if(temp!=NULL)
        printf("Element %d found\n",temp->data);
    else
        printf("Element not found\n");
    
    return 0;
}
