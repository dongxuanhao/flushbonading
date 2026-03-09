#include <stdio.h>
#include "math.h"
/* 显示函数 */
void display(int x, int y)
{
    printf("Add: %d\n", add(x, y));
    printf("Sub: %d\n", sub(x, y));
    printf("Mul: %d\n", mul(x, y));
    printf("Div: %.2f\n", (double)divi(x, y));
}