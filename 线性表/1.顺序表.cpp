#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
typedef int ElemType;
// //静态定义
// typedef struct {
//     ElemType data[MaxSize];
//     int length;
// }SqList;

//动态定义
typedef struct 
{
    ElemType *data;
    int length;
}SqList;

//初始化顺序表
void InitSqList(SqList &L);
//动态初始化顺序表
void InitSeqList(SqList &L);
//打印顺序表
void PrintSqList(SqList &L);
//顺序表的插入
bool InsertSqList(SqList &L,int i,ElemType e);
//测试插入
void test_Insert(SqList L);
//顺序表的删除
bool DelSqList(SqList &L,int i);
//测试删除
void test_del(SqList L);
//顺序表的修改
bool ModifySqList(SqList &L,int i,ElemType e);
//测试修改
void test_Modify(SqList L);
//顺序表的查询
int FindSqList(SqList L,ElemType e);
//测试查询
void test_Find(SqList L);
int main(void)
{
    SqList L; //定义顺序表
    // InitSqList(L);//初始化顺序表
    InitSeqList(L);
    // test_Insert(L);//测试插入
    // test_del(L);//测试删除
    // test_Modify(L);
    test_Find(L);//测试查询

    return 0;
}

//静态初始化顺序表
void InitSqList(SqList &L)
{
    // int num=0;
    // L.length=0;
    // while(scanf("%d",&num)!=EOF)
    // {
    //     L.data[L.length++]=num;
    // }

    //静态定义
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.data[3]=4;
    L.length=4;

}
//动态初始化顺序表
void InitSeqList(SqList &L)
{
    L.data = (ElemType *) malloc(MaxSize*sizeof(SqList));
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.data[3]=4;
    L.length=4;
}
//打印顺序表
void PrintSqList(SqList &L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
//测试插入
void test_Insert(SqList L)
{
    bool ret;   //查看返回值
    ret = InsertSqList(L,2,10);
    if(ret == false)
    {
        //插入失败
        printf("插入失败\n");
    }
    else{
        printf("插入成功\n");
        PrintSqList(L);
    }
}
//顺序表的插入
bool InsertSqList(SqList &L,int i,ElemType e)
{
    //在顺序表的第i个元素的位置（下标为i-1）插入元素e
    // //判断顺序表是否已满
    // if(L.length == MaxSize)
    // {
    //     return false;
    // }
    // //判断插入的位置是否合法
    // if(i<1 || i>L.length)
    // {
    //     return false;
    // }

    //判断插入是否合法
    if(L.length==MaxSize || i<1 || i>L.length+1)
    {
        return false;
    }
    //位置合法开始插入
    for(int j=L.length;j>=i;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;//插入到第i个位置，下标为i-1
    L.length++;//表长+1
    return true;
}
//测试删除
void test_del(SqList L)
{
    bool ret=DelSqList(L,2);
    if(ret == false)
    {
        printf("删除失败\n");
    }else{
        printf("删除成功\n");
        PrintSqList(L);
    }
}
//顺序表的删除
bool DelSqList(SqList &L,int i)
{
    //删除顺序表中位置为i处的元素，并返回该元素
    int temp=0;
    //判断删除的位置是否合法
    if(i<1 || i>L.length)
    {
        return false;
    }
    //判断顺序表是否为空
    if(L.length == 0)
    {
        return false;
    }
    //删除
    for(int j=i;j<L.length;j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
//顺序表的修改
bool ModifySqList(SqList &L,int i,ElemType e)
{
    //修改顺序表第i个元素为e
    //判断修改的位置是否合法
    if(i<1 || i>L.length)
    {
        return false;
    }
    //判断是否为空
    if(L.length == 0)
    {
        return false;
    }
    L.data[i-1] =e;
    return true;
}
//测试修改
void test_Modify(SqList L)
{
    bool ret = ModifySqList(L,2,100);
    if(ret == false)
    {
        printf("修改失败\n");
    }
    else{
        printf("修改成功\n");
        PrintSqList(L);
    }
}
//测试查询
void test_Find(SqList L)
{
    int ret = FindSqList(L,4);
    if(ret == -1)
    {
        printf("查询失败\n");
    }else{
        printf("查询成功\n");
        printf("查询元素位置是%d\n",ret);
    }
}
//顺序表的查询
int FindSqList(SqList L,ElemType e)
{
    //查询元素，返回所在下标
    int temp =-1;
    //判断是否为空
    if(0 == L.length)
    {
        return -1;
    }
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i] == e)
        {
            temp = i;
        }
    }
    return temp;
}

