#include <stdio.h>
int main(void)
{
    int a = 0, b = 3;
    switch (a + b && a && b++ && a++)
    {
    case 0:
        a++;
    case 1:
        b++;
    case 2:
        a += b;
        break;
    case 3:
        a -= b;
    default:
        a;
    }
    printf("%d %d\n", a, b);
    return 0;
}