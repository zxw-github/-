#include <stdio.h>

//将&写在形参的位置是C++的语法，称为引用
//如果要在子函数中对外部的变量进行操作，都需要加上引用 

void modifynum_a(int *p)
{
    *p=*p+1;
}
void modifynum_b(int &p)
{
    p=p+1;
}
int main(void)
{
    int a=10;
    int b=10;

    //使用C的语法
    modifynum_a(&a);//地址传递

    //使用C++的语法
    modifynum_b(b);

    printf("%d,%d\n",a,b);//11,11
}