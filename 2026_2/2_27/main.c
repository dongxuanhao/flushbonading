// #include <stdio.h>

// int add(int a, int b);

// int main(int argc, char const *argv[])
// {
//     int a, b;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);
//     int sum = add(a, b);
//     printf("the sum of %d and %d is %d \n", a, b, sum);
//     return 0;
// }

// int add(int a, int b)
// {
//     return a + b;
// }

// #include <stdio.h>

// int isEven(int a);

// int main(int argc, char const *argv[])
// {
//     printf("enter a number:");
//     int a;
//     scanf("%d", &a);
//     int flag = isEven(a);
//     if (flag == 0)
//     {
//         printf("%d is even number\n", a);
//     }
//     else
//     {
//         printf("%d is odd number\n", a);
//     }
//     return 0;
// }
// int isEven(int a)
// {
//     return a % 2;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     /* code */
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             if (i == 5 && j == 5)
//             {
//                 goto out;
//             }
//             printf("i is %d,j is %d\n", i, j);
//         }
//     }
// out:
//     printf("j is 5 and i is 5\n");
//     return 0;
// }

// #include <stdio.h>

// int bigger(int a, int b);

// int main(int argc, char const *argv[])
// {
//     int a, b;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);
//     int bigger_one = bigger(a, b);
//     printf("the bigger one of %d and %d is %d \n", a, b, bigger_one);
//     return 0;
// }

// int bigger(int a, int b)
// {
//     return a > b ? a : b;
// }

// #include <stdio.h>
// // 用递归的方式算一数的阶乘

// int main(int argc, char const *argv[])
// {
//     printf("enter a number:");
//     int a;
//     scanf("%d", &a);
//     int result = factorial(a);
//     printf("%d! is %d\n", a, result);
//     return 0;
// }

// int factorial(int a)
// {
//     if (a == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return a * factorial(a - 1);
//     }
// }

// #include <stdio.h>

// int product(int a, int b);

// int main(int argc, char const *argv[])
// {
//     int a, b;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);
//     int result = product(a, b);
//     printf("the product of %d and %d is %d \n", a, b, result);
//     return 0;
// }

// int product(int a, int b)
// {
//     return a * b;
// }

// #include <stdio.h>

// int isPrime(int a);
// int main(int argc, char const *argv[])
// {
//     int result;
//     printf("enter a number:");
//     int a;
//     scanf("%d", &a);
//     result = isPrime(a);
//     if (result == 0)
//     {
//         printf("%d is not a prime number\n", a);
//     }
//     else
//     {
//         printf("%d is a prime number\n", a);
//     }
//     return 0;
// }

// int isPrime(int a)
// {
//     if (a == 1)
//     {
//         return 0;
//     }
//     for (int i = 2; i < a; i++)
//     {
//         if (a % i == 0)

//         {
//             return 0;
//         }
//         else
//         {
//             return 1;
//         }
//     }
// }

// #include <stdio.h>
// #include <string.h>

// // 反转字符串的函数
// void reverse(char *str) {
//     int len = strlen(str);
//     int left = 0;
//     int right = len - 1;
//     char temp;

//     // 双指针交换首尾字符
//     while (left < right) {
//         temp = str[left];
//         str[left] = str[right];
//         str[right] = temp;
//         left++;
//         right--;
//     }
// }

// int main() {
//     char str[] = "Hello, World!";

//     printf("原字符串: %s\n", str);

//     reverse(str);

//     printf("反转后: %s\n", str);

//     return 0;
// }

// #include <stdio.h>

// int sumArray(int arr[], int size)
// {
//     int sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum += arr[i];
//     }
//     return sum;
// }

// int main(int argc, char const *argv[])
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int sum = sumArray(arr, size);
//     printf("Sum of array elements: %d\n", sum);
//     return 0;
// }

// #include <stdio.h>

// int countDigits(int num);
// {
//     int count = 0;
//     while (num != 0)
//     {
//         num /= 10;
//         count++;
//     }
//     return count;
// }

// int main(int argc, char const *argv[])
// {
//     int num;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     int digitCount = countDigits(num);
//     printf("Number of digits: %d\n", digitCount);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int *mergeArrays(int arr1[], int size1, int arr2[], int size2)
// {
//     int *mergedArray = malloc((size1 + size2) * sizeof(int));

//     if (mergedArray == NULL) {
//         printf("Memory allocation failed\n");
//         return NULL;
//     }

//     int i = 0, j = 0, k = 0;

//     while (i < size1 && j < size2)
//     {
//         mergedArray[k++] = (arr1[i] <= arr2[j]) ? arr1[i++] : arr2[j++];
//     }

//     while (i < size1)
//         mergedArray[k++] = arr1[i++];

//     while (j < size2)
//         mergedArray[k++] = arr2[j++];

//     return mergedArray;
// }

// int main()
// {
//     int arr1[] = {1, 3, 5, 12, 27, 48, 59};
//     int arr2[] = {2, 4, 13, 26, 37, 46, 55, 65};

//     int size1 = sizeof(arr1) / sizeof(arr1[0]);
//     int size2 = sizeof(arr2) / sizeof(arr2[0]);
//     int mergedSize = size1 + size2;

//     int *mergedArray = mergeArrays(arr1, size1, arr2, size2);

//     if (mergedArray == NULL)
//         return 1;

//     printf("Merged Array: ");

//     for (int i = 0; i < mergedSize; i++)
//         printf("%d ", mergedArray[i]);

//     printf("\n");

//     free(mergedArray);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int gcdf(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcmf(int a, int b)
{
    return abs(a / gcdf(a, b) * b);
}

int main(int argc, char const *argv[])
{

    // 输入：两个整数 a, b
    //  输出：它们的 最大公约数 gcd 和 最小公倍数 lcm
    //  常识关系：lcm(a,b) = |a*b| / gcd(a,b)（前提 a、b 不全为 0）
    // gcd(a, b) = gcd(b, a % b)，直到 b == 0，答案是 a

    // 伪代码
    /*
    读入 a, b
    x = abs(a), y = abs(b)
    while y != 0:
        t = x % y
        x = y
        y = t
    gcd = x
    lcm = abs(a / gcd * b)   // 用这种写法减少溢出风险
    输出 gcd 和 lcm
        return 0;
    */
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    int gcd = gcdf(a, b);
    int lcm = lcmf(a, b);
    printf("gcd = %d, lcm = %d\n", gcd, lcm);
}
