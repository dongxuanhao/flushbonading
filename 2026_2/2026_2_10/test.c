// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[10], sum = 0, i = 0;
//     printf("please enter 10 numbers:");
//     for (i = 0; i < 10; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     for (i = 0; i < 10; i++)
//     {
//         sum += arr[i];
//     }
//     printf("the sum is %d", sum);
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[5], i = 0;
//     int *p=arr;
//     printf("please enter 5 numbers:");
//     for (i = 0; i < 5; i++)
//     {
//         scanf("%d", p+i);
//     }
//     int max = arr[0], min = arr[0];
//     for (i = 0; i < 5; i++)
//     {
//         if (arr[i] < min)
//         {
//             min = arr[i];
//         }
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     printf("the max is %d\n", max);
//     printf("the min is %d", min);
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[5], i = 0, temp = 0;
//     printf("please enter 5 numbers:");
//     for (i = 0; i < 5; i++)
//     {
//         scanf("%d", arr + i);
//     }
//     printf("the original array is:");
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     for (i = 0; i < sizeof(arr) / sizeof(arr[0]) / 2; i++)
//     {
//         temp = arr[i];
//         arr[i] = arr[sizeof(arr) / sizeof(arr[0]) - 1 - i];
//         arr[sizeof(arr) / sizeof(arr[0]) - 1 - i] = temp;
//     }
//     printf("the reverse array is:");
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[5], i = 0, flag = 1;
//     printf("please enter 5 numbers:");
//     for (i = 0; i < 5; i++)
//     {
//         scanf("%d", arr + i);
//     }
//     for (i = 0; i < 4; i++)
//     {
//         if (arr[i] > arr[i + 1])
//         {
//             flag = 0;
//             break;
//         }
//     }
//     if (flag == 1)
//     {
//         printf("the array is ascending ordered:");
//     }
//     else
//     {
//         printf("the array is not ascending ordered:");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[5], i = 0, flag = 1;
//     printf("please enter 5 numbers:");
//     for (i = 0; i < 5; i++)
//     {
//         scanf("%d", arr + i);
//     }
//     int max_first = arr[0], max_second = arr[0];
//     for (i = 0; i < 5; i++)
//     {
//         if (arr[i] > max_first)
//         {
//             max_second = max_first;
//             max_first = arr[i];
//         }
//         else if (arr[i] > max_second)
//         {
//             max_second = arr[i];
//         }
//     }
//     printf("max_first=%d,max_second=%d\n", max_first, max_second);
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[10], i = 0, sum = 0;
//     printf("please enter 10 numbers:");
//     for (i = 0; i < 10; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     for (i = 0; i < 10; i++)
//     {
//         if (arr[i] % 2 == 0)
//         {
//             sum += arr[i];
//         }
//     }
//     printf("the sum is %d", sum);
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[10], i = 0, temp = 0;
//     int count[11] = {0};
//     printf("please enter 10 numbers:(the range of number is between 0 and 10)\n");
//     while (i < 10)
//     {
//         scanf("%d", &temp);
//         if (temp >= 0 && temp <= 10)
//         {
//             arr[i] = temp;
//             count[temp]++;
//             i++;
//         }
//         else
//         {
//             printf("the number %d is out of range.please enter a number between 0 and 10.\n", temp);
//         }
//     }
//     for (i = 0; i < 11; i++)
//     {
//         printf("the number %d appears %d times.\n", i, count[i]);
//     }
//     return 0;
// }
// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     int arr[5], i = 0;
//     int flag = 0;
//     printf("please enter 5 numbers:");
//     for (i = 0; i < 5; i++)
//     {
//         scanf("%d", arr + i);
//     }
//     for (i = 0; i < 4; i++)
//     {
//         for (int j = i + 1; j < 5; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 printf("the number %d appears more than once.\n", arr[i]);
//                 flag = 1;
//                 break;
//             }
//         }
//     }
//     if (flag == 0)
//     {
//         printf("all numbers are unique.\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[10] = {0}, i = 0;
//     int sum = 0;
//     printf("please enter 10 numbers:");
//     for (i = 0; i < 10; i++)
//     {
//         scanf("%d", arr + i);
//     }
//     for (i = 0; i < 10; i++)
//     {
//         if (arr[i] % 2 == 1)
//         {
//             sum += arr[i];
//         }
//     }
//     printf("the sum of odd numbers is %d", sum);
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[3][3] = {0}, i = 0, j = 0;
//     int temp;
//     printf("please enter 9 numbers:");
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for (i = 0; i < 3; i++)
//     {
//         for (j = i + 1; j < 3; j++)
//         {
//             temp = arr[i][j];
//             arr[i][j] = arr[j][i];
//             arr[j][i] = temp;
//         }
//     }
//     printf("the matrix is:\n");
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[5][5] = {0}, i = 0, j = 0;
//     int sum = 0;
//     printf("please enter 25 numbers:");
//     for (i = 0; i < 5; i++)
//     {
//         for (j = 0; j < 5; j++)
//         {
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for (i = 0; i < 5; i++)
//     {
//         for (j = 0; j < 5; j++)
//         {
//             if (i == j)
//             {
//                 sum += arr[i][j];
//             }
//         }
//     }
//     printf("the sum of the diagonal elements is %d\n", sum);
//     return 0;
// }

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int arr[4][4] = {0}, i = 0, j = 0;
//     int max = 0, max_count = 0;
//     int row = 0, col = 0;
//     printf("please enter 16 numbers:");
//     for (i = 0; i < 4; i++)
//     {
//         for (j = 0; j < 4; j++)
//         {
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     for (i = 0; i < 4; i++)
//     {
//         for (j = 0; j < 4; j++)
//         {
//             if (arr[i][j] > max)
//             {
//                 max = arr[i][j];
//                 row = i;
//                 col = j;
//                 max_count = 1;
//             }
//             else if (arr[i][j] == max)
//             {
//                 max_count++;
//             }
//         }
//     }

//     printf("the max number is %d\n", max);
//     printf("the max number is in the %dth row and %dth column.\n", row, col);
//     return 0;
// }

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[3][3] = {0}, i = 0, j = 0;
    int flag = 0;
    printf("please enter 9 numbers:");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("the matrix is symmetric.\n");
    }
    else
    {
        printf("the matrix is not symmetric.\n");
    }
    return 0;
}