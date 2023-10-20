#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int Front;
    int Rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->Front = q->Rear = -1;
    q->Q = (int *)malloc(sizeof(int) * q->size);
}

void enqueue(struct Queue *q, int x)
{
    if (q->Rear == q->size - 1)
        printf("Queue is Full\n");
    else
    {
        q->Rear++;
        q->Q[q->Rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->Rear == q->Front)
        printf("Queue is Empty\n");
    else
    {
        q->Front++;
        x = q->Q[q->Front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i;
    printf("Queue Element\n");
    for (i = q.Front + 1; i <= q.Rear; i++)
    {
        printf("%d\t", q.Q[i]);
    }
    printf("\n");
}

int isEmpty(struct Queue q)
{
    if (q.Rear == q.Front)
        return 1;
    else
        return 0;
}

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    struct Queue q;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    create(&q, n); // Initialize the queue with size n
    enqueue(&q, i);
    while (!isEmpty(q))
    {
        i = dequeue(&q);
        for (j = 1; j <= n; j++) // Start from vertex 1
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}

int main()
{
    struct Queue q;
    int G[7][7] =
        {
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0, 0, 0},
            {0, 1, 0, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 0, 0},
            {0, 0, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 3, 7); // Starting from vertex 4

    return 0;
}
