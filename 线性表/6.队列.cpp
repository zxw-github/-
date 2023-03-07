#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef int ElemType;
//循环队列的结构体
typedef struct{
    ElemType data[MaxSize];
    int front;//头指针
    int rear;//尾指针
}SqQueue;
//测试
void test(SqQueue s);
//打印
void PrintQueue(SqQueue s);
//初始化队列
void InitQueue(SqQueue &s,ElemType arr[],int n);
//入队
//出队

int main(void)
{
    SqQueue s;
    test(s);
    return 0;
}

//测试
void test(SqQueue s)
{
    ElemType arr[5]={1,5,7,4,9};
    InitQueue(s,arr,5);
    PrintQueue(s);
}
//打印
void PrintQueue(SqQueue s)
{
    
}
//初始化队列
void InitQueue(SqQueue &s,ElemType arr[],int n)
{
    s.front=0;
    for(int i=0;i<n;i++)
    {
        s.data[i]=arr[i];
        s.rear++;
    }
}

