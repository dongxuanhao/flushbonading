// #include <stdio.h>
// #include <stdlib.h>

// int first_appear(char *arr, char c)
// {
//     int position = 0;
//     while (*arr != '\0')
//     {
//         arr++;
//         position++;
//         if (*arr == c)
//         {
//             return position;
//         }
//     }
//     return -1;
// }

// int main(int argc, char const *argv[])
// {
//     char arr[] = "Hello World";
//     char c = 'o';
//     if(first_appear(arr,c)==-1)
//     {
//         printf("字符 %c 未在字符串 %s 中出现\n", c, arr);
//     }
//     else
//     {
//         printf("字符 %c 首次出现在字符串 %s 的第 %d 个位置\n", c, arr, first_appear(arr, c));
//     }
//     return 0;
// }

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     int a, b;
//     char opr;
//     printf("请输入一个算术表达式（例如：3 + 4）：");
//     scanf("%d %c %d", &a, &opr, &b);
//     switch (opr)
//     {
//     case '+':
//         printf("%d + %d = %d\n", a, b, a + b);
//         break;
//     case '-':
//         printf("%d - %d = %d\n", a, b, a - b);
//         break;
//     case '*':
//         printf("%d * %d = %d\n", a, b, a * b);
//         break;
//     case '/':
//         if (b != 0)
//             printf("%d / %d = %d\n", a, b, a / b);
//         else
//             printf("除数不能为零！\n");
//         break;
//     }
//     return 0;
// }

// #include <stdio.h>

// #define SIZE 10

// int main(int argc, char const *argv[])
// {
//     printf("请输入十个整型数字（范围0 ~ 10）：\n");
//     int count[11] = {0}; // Initialize all elements to 0
//     for (int i = 0; i < SIZE;)
//     {
//         int temp;

//         if (scanf("%d", &temp) != 1) // 检查输入的是否不是数字，如果不是数字则清空输入缓冲区
//         {
//             printf("输入无效，请输入一个整数。\n");
//             int ch;
//             while ((ch = getchar()) != '\n' && ch != EOF)
//                 ;
//             continue;
//         }

//         if (temp < 0 || temp > 10) // 检查输入的数字是否在0到10的范围内
//         {
//             printf("输入超出范围，请重新输入。\n");
//             continue;
//         }

//         printf("DEBUG: i=%d, temp=%d\n", i, temp); // 调试信息，打印当前循环的索引和输入的数字
//         count[temp]++;
//         i++; // 只在成功时递增
//     }
//     for (int j = 0; j <= SIZE; j++)
//     {
//         printf("元素%d出现的次数为:%d\n", j, count[j]);
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// void reverseArray(char *arr, int size)
// {
//     for (int i = 0; i < (size / 2); i++)
//     {
//         int temp = 0;
//         temp = arr[i];
//         arr[i] = arr[size - 1 - i];
//         arr[size - 1 - i] = temp;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     char arr[5] = {'H', 'e', 'l', 'l', 'o'};
//     reverseArray(arr, 5);
//     char *p = arr;
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%c ", *p);
//         p++;
//     }
//     return 0;
// }

// #include <stdio.h>

// typedef struct{
//     char name[20];
//     int age;
// }Person;

// int main(int argc, char const *argv[])
// {
//     Person person;
//     printf("请输入姓名：");
//     scanf("%s", person.name);
//     printf("请输入年龄：");
//     scanf("%d", &person.age);
//     printf("姓名：%s，年龄：%d\n", person.name, person.age);
//     return 0;
// }

// #include <stdio.h>

// int countDigits(int num)
// {
//     int count=0;
//     while(num!=0)
//     {
//         num/=10;
//         count++;
//     }
//     return count;
// }
// int main(int argc, char const *argv[])
// {
//     printf("请输入一个整数：");
//     int num;
//     scanf("%d", &num);
//     printf("该整数有 %d 位\n", countDigits(num));
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(int argc, char const *argv[])
// {
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             if (i == 5 && j == 5)
//                 goto out;
//             printf("i = %d,j = %d\n", i, j);
//         }
//     }
// out:
//     printf("程序结束\n");
//     return 0;
// }
