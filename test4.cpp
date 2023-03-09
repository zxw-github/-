#include <stdio.h>

int main()
{
    float a, b;
    a = 32.00000, b = 64.2000;
    printf("%.4f\n", a * b);

    double d, e;
    d = 32.00000, e = 64.2000;
    printf("%.4lf\n", d * e);
    return 0;
}