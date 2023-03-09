#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
// 链式队列的结构体
typedef struct QNode
{
    ElemType data;      // 数据域
    struct QNode *next; // 指向下一个结点的指针
} QNode, *QueuePtr;
typedef struct Queue
{
    QueuePtr front; // 对头指针
    QueuePtr rear;  // 队尾指针
} LinkNode, *LinkQueue;

// 测试
void test(LinkQueue q);
// 打印
void PrintQueue(const LinkQueue q);
// 初始化
void InitLinkQueue(LinkQueue &q);
// 入队
bool EnQueue(LinkQueue &q, ElemType e);
// 出队
bool DelQueue(LinkQueue &q);
// 求队长
void LengthQueue(const LinkQueue q);
int main(void)
{
    LinkQueue q;
    test(q);
    return 0;
}
// 测试
void test(LinkQueue q)
{
    InitLinkQueue(q);
    EnQueue(q, 3);
    EnQueue(q, 7);
    EnQueue(q, 9);
    DelQueue(q);
    LengthQueue(q);
    PrintQueue(q);
}
// 打印
void PrintQueue(const LinkQueue q)
{
    LinkQueue s = (LinkQueue)q;
    while (s->front)
    {
        printf("%d ", s->front->data);
        s->front = s->front->next;
    }
    printf("\n");
}
// 初始化
void InitLinkQueue(LinkQueue &q)
{
    q = (LinkQueue)malloc(sizeof(LinkNode));
    q->rear = NULL;
    q->front = NULL;
}
// 入队
bool EnQueue(LinkQueue &q, ElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    s->data = e;
    s->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = s;
    }
    else
    {
        q->front->next = s;
        q->front = s;
    }
    return true;
}
// 出队
bool DelQueue(LinkQueue &q)
{
    // 判空
    if (q->front == NULL)
    {
        return false;
    }
    else
    {
        q->front = q->front->next;
        return true;
    }
}
// 求队长
void LengthQueue(const LinkQueue q)
{
    LinkQueue s = (LinkQueue)q;
    int count = 0;
    while (s->front)
    {
        count++;
        s->front = s->front->next;
    }
    printf("%d\n", count);
}