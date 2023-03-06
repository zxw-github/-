#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
typedef int ElemType;

//单链表结构体的定义
typedef struct LNode 
{
    ElemType data;
    struct LNode *next; 
}LNode,*LinkList;

//打印单链表
void PrintList(const LinkList L);
//头插法建立单链表
void HeadInsert(LinkList &L);
//尾插法建立单链表
void TailInsert(LinkList &L);
//插入结点
bool InsterLink(LinkList &L,int i,ElemType e);
//测试插入
void test_Insert(const LinkList L);
//删除结点
bool DelLink(LinkList L,int i);
//测试删除
void test_Del(const LinkList L);
//修改结点
bool ModifyLink(LinkList L,int i,ElemType e);
//测试修改
void test_Modify(const LinkList L);
//查询-按序号
ElemType FindLink(const LinkList L,int i);
//测试查询-按序号
void test_Find(const LinkList L);
//查询-按值
int SearchLink(const LinkList L,ElemType e);
//测试查询-按值
void test_Search(const LinkList L);
int main(void)
{
    LinkList L;
    // HeadInsert(L);
    TailInsert(L);
    test_Insert(L);
    // test_Del(L);
    // test_Modify(L);
    // test_Find(L);
    // test_Search(L);
    return 0;
}
//打印单链表
void PrintList(const LinkList L)
{
    LinkList PLink =(LinkList) L->next;
    while(PLink!= NULL)
    {
        printf("%d ",PLink->data);
        PLink=PLink->next;
    }
    printf("\n");
}
//头插法建立单链表-带头结点
void HeadInsert(LinkList &L)
{
    int x;//需要插入的元素的值
    L=(LinkList)malloc(sizeof(LNode)); //头结点
    L->next=NULL;//初始为空 
    // while(scanf("%d",&x))
    // {
    //     if(getchar()!='\n')
    //     {
    //         LinkList s=(LinkList)malloc(sizeof(LNode));//为需要插入的元素创建结点
    //         s->data=x;
    //         s->next=L->next;//将s指向头结点指向的结点
    //         L->next=s;//头结点指向s  
    //     }   
    // }
    do{
        scanf("%d",&x);
        LinkList s=(LinkList)malloc(sizeof(LNode));//为需要插入的元素创建结点
        s->data=x;
        s->next=L->next;//将s指向头结点指向的结点
        L->next=s;//头结点指向s 
    }
    while(getchar()!='\n');
    //打印单链表
    // PrintList(L);
}
//尾插法建立单链表-带头结点
void TailInsert(LinkList &L)
{
    int x;//需要插入的元素
    L = (LinkList)malloc(sizeof(LNode));//头结点
    L->next=NULL;
    LinkList tail=L;//表示尾结点,开始没有结点，指向头结点
    do
    {
        scanf("%d",&x);
        LinkList s= (LinkList)malloc(sizeof(LNode));//创建插入结点
        s->data=x;
        tail->next=s;
        tail=s;
    } while (getchar()!='\n');
    tail->next=NULL;
    // PrintList(L);
}
//插入结点
bool InsterLink(LinkList &L,int i,ElemType e)
{
    int j=1;
    LinkList p=L;
    LinkList s;
    while(p && j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p || j>i)
    {
        return false;
    }
    //插入
    s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
//测试插入
void test_Insert(LinkList L)
{
    bool ret = InsterLink(L,2,10);
    if(ret==false)
    {
        printf("插入失败\n");
    }else
    {
        printf("插入成功\n");
        PrintList(L);
    }
}
//删除结点
bool DelLink(LinkList L,int i)
{
    //删除第i个结点
    int j=1;
    LinkList p=L;//指向前一个结点
    LinkList q=p->next;
    while(q && j<i)
    {
        p=q;
        q=q->next;
        j++;
    }
    if(!q || j>i)
    {
        return false;
    }
    //删除，此时q指向被删的结点
    p->next=q->next;
    q=NULL;
    return true;
}
//测试删除
void test_Del(const LinkList L)
{
    int ret =DelLink(L,3);
    if(ret == false)
    {
        printf("删除失败\n");
    }else{
        printf("删除成功\n");
        PrintList(L);
    }
}
//修改结点
bool ModifyLink(LinkList L,int i,ElemType e)
{
    //修改第i个元素为e
    int j=1;
    LinkList p=L->next;//p指向第一个结点
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    p->data=e;
    if(!p || j>i)//当p为NULL或j>i时查询失败
    {
        return false;
    }
    return true;
}
//测试修改
void test_Modify(const LinkList L)
{
    bool ret=ModifyLink(L,3,100);
    if(ret==false)
    {
        printf("修改失败\n");
    }else
    {
        printf("修改成功\n");
        PrintList(L);
    }
}
//查询-按序号
ElemType FindLink(const LinkList L,int i)
{
    //查找第i个元素，返回第i个元素的值
    int j=1;
    LinkList p=(LinkList)L->next;// p指向第一个元素
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)//当p为NULL或j>i时查询失败
    {
        return -1;
    }
    return p->data;
}
//测试查询-按序号
void test_Find(const LinkList L)
{
    int i=3;
    int ret = FindLink(L,i);
    if(ret == -1)
    {
        printf("查询失败\n");
    }else{
        printf("查询成功,查询的第%d个元素为%d\n",i,ret);
    }
}
//查询-按值
int SearchLink(const LinkList L,ElemType e)
{
    //查询元素e，返回其位置
    int i=1;
    LinkList p=(LinkList)L->next;// p指向第一个元素
    //若链表为空，返回-1
    while(p)
    {
        if(p->data == e)
        {
            return i;
        }
        p=p->next;
        i++;
    }
    return -1;
}
//测试查询-按值
void test_Search(const LinkList L)
{
    int i=4;
    int ret=SearchLink(L,i);
    if(ret == -1)
    {
        printf("查询失败\n");
    }else{
        printf("查询成功,查询的元素%d是第%d个\n",i,ret);
    }
}
