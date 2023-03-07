#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
// 链栈的结构体定义
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next; // 指向下一个结点的指针
} StackNode, *LinkStack;

//测试
void test(LinkStack s);
//打印
void PrintStack(LinkStack s);
//初始化
void InitStack(LinkStack &s,ElemType arr[],int n);
//进栈
void PushStack(LinkStack &s,ElemType e);
//出栈
void PopStack(LinkStack &s,ElemType &e);

int main()
{
    LinkStack s=NULL;//栈底栈顶指针
    test(s);
    return 0;
}

//测试
void test(LinkStack s)
{
    int x=0,e=20;
    ElemType arr[5]={9,3,1,4,7};
    InitStack(s,arr,5);
    //进栈
    PushStack(s,e);
    //出栈
    PopStack(s,x);
    PrintStack(s);
}
//打印
void PrintStack(LinkStack s)
{
    while(s)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}
//初始化
void InitStack(LinkStack &s,ElemType arr[],int n)
{
    LinkStack p;
    for(int i=0;i<n;i++)
    {
        p=(LinkStack)malloc(sizeof(StackNode));
        p->data=arr[i];
        p->next=s;
        s=p;
    }
}
//进栈
void PushStack(LinkStack &s,ElemType e)
{
    LinkStack p=(LinkStack)malloc(sizeof(StackNode));
    p->data=e;
    p->next=s;
    s=p;
}
//出栈
void PopStack(LinkStack &s,ElemType &e)
{
    e=s->data;
    s=s->next;
}