#include <stdio.h>

// 自定义函数：将整数转换为二进制字符串输出
void print_binary(int num)
{
    // 对于32位整数，从最高位（第31位）开始检查
    for (int i = 31; i >= 0; i--)
    {
        // 使用位运算检查第i位是否为1
        if (num & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        // 每4位添加一个空格，提高可读性
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    int num, n;
    printf("please enter an integer:\n");
    scanf("%d", &num);
    printf("please enter the position of the bit:");
    scanf("%d", &n);

    // printf("the original number is:\n");
    // printf("decimalism:%d\n", num);
    // printf("binary:");
    // print_binary(num);

    // 创建掩码：1左移3位，得到0000 1000（二进制）
    int mask = 1 << n;
    // 使用按位或操作将位3设为0
    num = num & mask;
    if (num == mask)
    {
        printf("the bit of n is 1\n");
    }
    else
    {
        printf("the bit of n is 0\n");
    }

    // printf("\nAfter setting bit 3 (counting from 0) to 1\n");
    // printf("decimalism:%d\n", num);
    // printf("binary:");
    // print_binary(num);

    return 0;
}

// #include <stdio.h>
// int main (void)
// {
//     const float PI = 3.1415926f;
//     float r,area;
//     printf("please enter the radius of the circle:");
//     scanf("%f",&r);
//     area=PI *r*r;
//     printf("the area of the circle is: %f",area);
//     return 0;
// }

// #include <stdio.h>
// int main ( void)
// {
//     int a=234;
//     a=a&0x0f;
//     printf("a=%x",a);
// }

// #include <stdio.h>
// int main(void)
// {
//     int a = 6;
//     a = ~a + 1;
//     printf("a=%d", a);
// }

// #define PI 3.14159
// int main(void)

// {
//     float radius,Area,Circumference;
//     printf("please enter the radius of the circle:");
//     scanf("%f",&radius);
//     printf("the area of the circle is: %.3f\n",PI*radius*radius);
//     printf("the circumference of the circle is: %.3f",2*PI*radius);
//     return 0;
// }

// int main(void)
// {
//     int length, width, Area, Perimeter;
//     printf("please enter the length and width of the rectangle:");
//     scanf("%d %d", &length, &width);
//     Area = length * width;
//     Perimeter = 2 * (length + width);
//     printf("the area of the rectangle is: %d\n", Area);
//     printf("the perimeter of the rectangle is: %d", Perimeter);
//     return 0;
// }