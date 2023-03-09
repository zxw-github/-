#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;
// 循环队列的结构体
typedef struct
{
    ElemType data[MaxSize];
    int front; // 头指针
    int rear;  // 尾指针
} DQueue, *SqQueue;
// 测试
void test(SqQueue s);
// 打印
void PrintQueue(SqQueue s);
// 初始化队列
void InitQueue(SqQueue &s);
// 入队
bool EnQueue(SqQueue &s, ElemType e);
// 出队
bool DelQueue(SqQueue &s);
int main(void)
{
    SqQueue s = NULL;
    ;
    test(s);
    return 0;
}

// 测试
void test(SqQueue s)
{
    ElemType arr[5] = {1, 5, 7, 4, 9};
    InitQueue(s);
    // EnQueue(s,1);
    // EnQueue(s,5);
    // EnQueue(s,7);
    // EnQueue(s,4);
    /*
    bool ret1=EnQueue(s,10);
    if(ret1 == false)
    {
        printf("入队失败\n");
    }else{
        printf("入队成功\n");
    }
    */
    // DelQueue(s,1);
    // DelQueue(s,5);
    // DelQueue(s,7);
    // DelQueue(s,4);
    DelQueue(s);
    bool ret2 = DelQueue(s);
    if (ret2 == false)
    {
        printf("出队失败\n");
    }
    else
    {
        printf("出队成功\n");
    }
    PrintQueue(s);
}
// 打印
void PrintQueue(SqQueue s)
{
    while ((s->front) % MaxSize != s->rear)
    {
        printf("%d ", s->data[s->front]);
        s->front++;
    }
    printf("\n");
}
// 初始化队列
void InitQueue(SqQueue &s)
{
    s = (SqQueue)malloc(sizeof(DQueue));
    s->front = 0;
    s->rear = 0;
}
// 入队
bool EnQueue(SqQueue &s, ElemType e)
{
    // 判断队满
    if ((s->rear + 1) % MaxSize == s->front)
    {
        return false;
    }
    else
    {
        s->data[s->rear] = e;
        s->rear = (s->rear + 1) % MaxSize;
        return true;
    }
}
// 出队
bool DelQueue(SqQueue &s)
{
    // 判断队空
    if (s->front == s->rear)
    {
        return false;
    }
    else
    {
        s->front = (s->front + 1) % MaxSize;
        return false;
    }
}
