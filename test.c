#include <stdio.h>
int main()
{
    int arr[20] = {0};
    int a = 0, i = 0, count = 0;
    // 输入的第一个字符有可能是数字，所以用do while循环（即第一次循环体一定要执行）
    do
    {
        scanf("%d", &a); // "%d",只有遇到数字scanf才会读入
        arr[i++] = a;
        count++;
    } while (getchar() != '\n');
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}