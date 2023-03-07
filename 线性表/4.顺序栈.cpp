#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef int ElemType;
//顺序存储的栈的结构体定义
typedef struct {
    ElemType data[MaxSize];//数组用来存储元素
    int top;//栈顶指针
}SqStack;

//测试
void test(SqStack s);
//打印栈中元素
void PrintStack(SqStack s);
//初始化栈
void InitStack(SqStack &s,int arr[],int n);
//进栈
bool PushStack(SqStack &s,ElemType e);
//出栈
bool PopStack(SqStack &s,ElemType &e);
int main(void)
{
    SqStack s;
    test(s);
    return 0;
}

//测试
void test(SqStack s)
{
    int e=20;
    int arr[]={1,5,7,4,9,2,0,1,3,20};
    InitStack(s,arr,10);
    /*
    bool ret1=PushStack(s,e);
    if(ret1 == false)
    {
        printf("进栈失败\n");
    }else{
        printf("进栈成功\n");
    }
    */
    bool ret2=PopStack(s,e);
    if(ret2 == false)
    {
        printf("出栈失败\n");
    }else{
        printf("出栈成功,该元素为%d\n",e);
    }
    PrintStack(s);
}
//打印栈中元素
void PrintStack(SqStack s)
{
    for(int i=0;i<=s.top;i++)
    {
        printf("%d ",s.data[i]);
    }
    printf("\n");
}
//初始化栈
void InitStack(SqStack &s,int arr[],int n)
{
    s.top=-1;
    for(int i=0;i<n;i++)
    {
        s.top++;
        s.data[s.top]=arr[i];
    }
}
//进栈
bool PushStack(SqStack &s,ElemType e)
{
    //判断栈满
    if(s.top == MaxSize-1)
    {
        return false;
    }else{
        s.top++;
        s.data[s.top]=e;
        return true;
    }
}
//出栈
bool PopStack(SqStack &s,ElemType &e)
{
    //判断栈空
    if(s.top == -1)
    {
        return false;
    }else{
        e=s.data[s.top];
        s.top--;
        return true;
    }
}
