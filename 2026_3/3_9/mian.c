#include <stdio.h>
int main(int argc, char const *argv[])
{
    //求N的阶乘
    int n = 0,result=1;
    printf("请输入一个整数:\n");
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        result *= i;
    }
    printf("n的阶乘是: %d\n", result);
    return 0;
}
