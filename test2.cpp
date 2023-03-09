#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node, *Node;

void test(Node &p)
{
    int arr[5] = {1, 2, 3, 4, 5};
    p = (Node)malloc(sizeof(node));
    p->next = NULL;
    Node s;
    for (int i = 0; i < 5; i++)
    {
        s = (Node)malloc(sizeof(node));
        s->data = arr[i];
        if (p->next == NULL)
        {
            p->next = s;
        }
        else
        {
            s->next = p->next;
            p->next = s;
        }
    }
}
void print(Node p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void length(Node p)
{
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    printf("%d\n", i);
}
int main()
{
    Node p = NULL;
    test(p);
    length(p);
    print(p);
    return 0;
}