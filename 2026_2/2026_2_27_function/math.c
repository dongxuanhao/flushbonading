#include <stdio.h>
/* 加法函数 */
int add(int a, int b)
{
    return a + b;
}

/* 减法函数 */
int sub(int a, int b)
{
    return a - b;
}

/* 乘法函数 */
int mul(int a, int b)
{
    return a * b;
}

/* 除法函数 */
float divi(int a, int b)
{
    if (b == 0)
    {
        printf("Error: division by zero\n");
        return 0;
    }
    return (float)a / b;
}
