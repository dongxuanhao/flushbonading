// #include <stdio.h>
// int main(void)
// {
//     int a = 0, b = 0, c = 0;
//     printf("please enter three integers:\n");
//     scanf("%d %d %d", &a, &b, &c);

//     // 比较交换法，确保三个数从大到小排序
//     int temp;

//     // 确保a是最大的
//     if (a < b) {
//         temp = a;
//         a = b;
//         b = temp;
//     }
//     if (a < c) {
//         temp = a;
//         a = c;
//         c = temp;
//     }
//     // 确保b是第二大的
//     if (b < c) {
//         temp = b;
//         b = c;
//         c = temp;
//     }

//     // 输出结果
//     printf("%d %d %d", a, b, c);

//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int a;
//     printf("please enter an integer:");
//     scanf("%d", &a);
//     if (a > 0)
//     {
//         printf("a is positive\n");
//     }
//     else if (a < 0)
//     {
//         printf("a is negative\n");
//     }
//     else
//     {
//         printf("a is zero\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int year = 0;
//     printf("please enter a year:");
//     scanf("%d", &year);
//     if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//     {
//         /* code */
//         printf("%d is a leap year\n", year);
//     }
//     else
//     {
//         printf("%d is not a leap year\n", year);
//     }

//     return 0;
// }
// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int a;
//     printf("please enter an integer:");
//     scanf("%d", &a);
//     if (a % 2 == 0)
//     {
//         printf("%d is even\n", a);
//     }
//     else
//     {
//         printf("%d is odd\n", a);
//     }

//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int a;
//     printf("please enter an integer:");
//     scanf("%d", &a);
//     if (a % 5 == 0 && a % 7 == 0)
//     {
//         printf("%d is divisible by both 5 and 7\n", a);
//     }
//     else
//     {
//         printf("%d is not divisible by both 5 and 7\n", a);
//     }

//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int a, b;
//     printf("please enter two integers:");
//     scanf("%d %d", &a, &b);
//     if (a > b)
//     {
//         printf("%d ", a);
//     }
//     else
//     {
//         printf("%d\n", b);
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int month_num = 0;
//     printf("please enter the month number:\n");
//     scanf("%d", &month_num);
//     switch (month_num)
//     {
//     case 12:
//     case 1:
//     case 2:
//     {
//         printf("winter\n");
//     }
//     break;
//     case 3:
//     case 4:
//     case 5:
//     {
//         printf("spring\n");
//     }
//     break;
//     case 6:
//     case 7:
//     case 8:
//     {
//         printf("summer\n");
//     }
//     break;
//     case 9:
//     case 10:
//     case 11:
//     {
//         printf("autumn\n");
//     }
//     break;
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int x = 7;
//     if (x > 0 && x < 10)
//     {
//         printf("x is between 0 and 10\n");
//     }
//     else
//     {
//         printf("x is not between 0 and 10\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int a, b;
//     printf("please enter two integers:\n");
//     scanf("%d %d", &a, &b);
//     char opt;
//     printf("please enter an operator:\n");
//     scanf(" %c", &opt);
//     switch (opt)
//     {

//     case '+':
//     {
//         printf("the result is:%d", a + b);
//         break;
//     }

//     case '-':
//     {
//         printf("the result is:%d", a - b);
//         break;
//     }

//     case '*':
//     {
//         printf("the result is:%d", a * b);
//         break;
//     }

//     case '/':
//     {
//         if (b != 0)
//         {
//             printf("the result is:%d", a / b);
//         }
//         else
//         {
//             printf("divisor is zero,illegal operation!\n");
//         }
//         break;
//     }

//     default:
//     {
//         printf("the operator you entered is illegal!");
//     }
//     break;
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     char c;
//     printf("please enter a char:\n");
//     scanf(" %c", &c);
//     if (c >= 65 && c <= 90)
//     {
//         printf("%c is a capital letter!\n", c);
//     }
//     else if (c >= 97 && c <= 122)
//     {
//         printf("%c is a lowercase letter!\n", c);
//     }
//     else if (c >= 48 && c <= 57)
//     {
//         printf("%c is a number!\n", c);
//     }
//     else
//     {
//         printf("%c represents other characters!\n ", c);
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     for (int i = 1; i <= 100; i++)
//     {
//         if (i % 3 == 0)
//         {
//             printf("%d\n", i);
//         }
//     }
//     return 0;
// }

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     for (int i = 1; i <= 9; i++)
//     {
//         for (int j = 1; j <= 9; j++)
//         {
//             printf("%d * %d = %d ", i, j, i * j);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int sum = 0;
//     for (int i = 1; i <= 100; i++)
//     {
//         if (i % 2 == 1)
//         {
//             sum += i;
//             printf("sum=%d + %d=%d\n", sum - i, i, sum);
//         }
//     }
//     printf("the sum of all odd numbers from 1 to 100 is:%d", sum);
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int a = 0;
//     printf("please enter an integer:");
//     scanf("%d", &a);
//     long long factorial = 1;
//     for (int i = 1; i <= a; i++)
//     {
//         factorial *= i;
//     }
//     printf("the factorial of %d is:%lld", a, factorial);
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     for (int i = 1; i <= 100; i++)
//     {
//         if ((i % 5 == 0) && (i % 3 != 0))
//             printf("%d\n", i);

//     }
//     return 0;
// }
// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     long long a = 0, b = 0;
//     printf("please enter an integer:");
//     if (scanf("%lld", &a) != 1)
//     {
//         printf("input error!\n");
//     }
//     long long original = a;
//     while (1)
//     {
//         b = b * 10 + a % 10;
//         a = a / 10;
//         if (a == 0)
//         {
//             break;
//         }
//     }
//     printf("original:%lld,Reversed:%lld", original, b);
//     return 0;
// }

#include <stdio.h>
int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (i + j == 8)
            {
                printf("%d\n", i * 10 + j);
            }
        }
    }
    return 0;
}
