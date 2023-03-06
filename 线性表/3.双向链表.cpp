#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
typedef int ElemType;

//双向链表的结构体定义
typedef struct DNode {
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

//测试
void test(DLinkList L);
//打印链表
void PrintDLink(DLinkList L);
//双向链表的头插法
void InsertHead(DLinkList &L,ElemType a[], int n);
//双向链表的尾插法
void InsertTail(DLinkList &L,ElemType a[], int n);
//插入
bool InsertDLink(DLinkList &L,int i,ElemType e);
//删除
bool DelDLink(DLinkList &L,int i);
//修改
bool ModifyDLink(DLinkList &L,int i,ElemType e);
//查询-按序
DLinkList FindDLink(DLinkList L,int i);
//查询-按值
int SearchDLink(DLinkList L,ElemType e);

int main(void)
{
    DLinkList L;
    test(L);
    return 0;
}

//测试
void test(DLinkList L)
{
    int a[]={1,5,3,7,9,4};
    // InsertHead(L,a,6);
    InsertTail(L,a,6);
    PrintDLink(L);
    /*
    int ret1 =InsertDLink(L,3,10);
    if(ret1 == false)
    {
        printf("插入失败\n");
    }else{
        printf("插入成功\n");
        PrintDLink(L);
    }
    */
   /*
   int ret2=DelDLink(L,2);
   if(ret2 == false)
   {
        printf("删除失败\n");
    }else{
        printf("删除成功\n");
        PrintDLink(L);
   }
   */
    /*
   int ret3=ModifyDLink(L,4,100);
   if(ret3 == false)
   {
        printf("修改失败\n");
    }else{
        printf("修改成功\n");
        PrintDLink(L);
    }
    */
   /*
    DLinkList ret4 = FindDLink(L,4);
    printf("查找到的值为%d\n",ret4->data);
    */
    int i=7;
    int ret5=SearchDLink(L,i);
    if(ret5 == -1)
    {
        printf("查询失败\n");
    }else{
        printf("查询成功,所查询的值%d是第%d个\n",i,ret5);
    }
}
//打印链表
void PrintDLink(DLinkList L)
{
    DLinkList p=L->next;
    while(NULL != p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
//双向链表的头插法
// void InsertHead(DLinkList &L)
// {
//     //创建头结点
//     L=(DLinkList)calloc(0,sizeof(DNode));
//     L->next=NULL,L->prior=NULL;
//     int x;//需要插入的元素
//     do
//     {
//         scanf("%d",&x);
//         DLinkList s=(DLinkList)calloc(0,sizeof(DNode));
//         s->data = x;
//         //初始为空
//         if(NULL == L->next)
//         {
//             L->next=s;
//             s->prior=L;
//         }
//         //不为空时
//         else{
//             s->next=L->next;
//             L->next->prior=s;
//             s->prior=L;
//             L->next=s;
//         }
//     } while (getchar() != '\n');
// }
void InsertHead(DLinkList &L, ElemType a[], int n)
{
	DLinkList s;
	L = new DNode;
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = new DNode;
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
		{
			L->next->prior = NULL;
		}
		L->next = s;
		s->prior = L;
	}
}
//双向链表的尾插法
void InsertTail(DLinkList &L,ElemType a[], int n)
{
    DLinkList r;//尾指针,初始指向头结点
    DLinkList s;//插入的结点指针
    L=(DLinkList)malloc(sizeof(DNode));//头结点
    r=L;
    // L->next=L->prior=NULL;
    for(int i=0;i<n;i++)
    {
        s=(DLinkList)malloc(sizeof(DNode));//申请插入结点的空间
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
    }
    s->next=NULL;
}
//插入
bool InsertDLink(DLinkList &L,int i,ElemType e)
{
    //在链表的第i个位置插入元素e
    int j=1;
    DLinkList s;
    DLinkList p=L;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
    {
        return false;
    }
    else{
        s=(DLinkList)malloc(sizeof(DNode));
        s->data=e;
        s->next=p->next;
        if(p->next != NULL)
        {
            p->next->prior=s;
        }
        s->prior=p;
        p->next=s;
        return true; 
    }
}
//删除
bool DelDLink(DLinkList &L,int i)
{
    //删除第i个位置的元素
    // int j=1;
    int j=0;
    // DLinkList p=L->next;
    DLinkList p=L;
    DLinkList q;
    while(p && j<i)
    {
        j++;
        q=p;
        p=p->next;
    }
    if(!p || j>i)
    {
        return false;
    }else{
        q->next=p->next;
        if(p->next != NULL)
        {
            q->next->prior=p;
        }
        p=NULL;
        return true;
    }
}
//修改
bool ModifyDLink(DLinkList &L,int i,ElemType e)
{
    //修改第i个元素为e
    int j=0;
    DLinkList p=L;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
    {
        return false;
    }else{
        p->data=e;
        return true;
    }
}
//查询-按序
DLinkList FindDLink(DLinkList L,int i)
{
    //查询第i个元素的值
    int j=1;
    DLinkList p=L->next;
    while(p && j<i)
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
    {
        return NULL;
    }
    return p;
}
//查询-按值
int SearchDLink(DLinkList L,ElemType e)
{
    int j=1;
    DLinkList p=L->next;
    while(p && p->data !=e)
    {
        p=p->next;
        j++;
    }
    if(p == NULL) return -1;
    else return j;
}

