// #include <stdio.h>

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     return;
// }
// int main(int argc, char const *argv[])
// {
//     printf("enter two numbers: ");
//     int a, b;
//     scanf("%d %d",&a,&b);
//     swap(&a,&b);
//     printf("after swapping: %d %d",a,b);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int *reverse_array(int *arr, int size)
// {
//     int *rev_arr = (int *)malloc(size * sizeof(int));
//     for (int i = 0; i < size; i++)
//     {
//         rev_arr[i] = arr[size - 1 - i];
//     }
//     return rev_arr;
// }

// int main(int argc, char const *argv[])
// {
//     int arr[5] = {1, 2, 3, 4, 5};
//     int *rev_arr = reverse_array(arr, 5);
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", rev_arr[i]);
//     }
//     free(rev_arr);
//     return 0;
// }

// #include <stdio.h>

// int calculateAverage(int *arr, int size)
// {
//     int sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum += arr[i];
//     }
//     return sum / size;
// }

// int main(int argc, char const *argv[])
// {
//     int arr[5] = {10, 20, 30, 40, 50};
//     int average = calculateAverage(arr, sizeof(arr) / sizeof(arr[0]));
//     printf("Average: %d\n", average);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int sumArray(int *arr, int size)
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
//     int *arr = (int *)malloc(5 * sizeof(int));
//     for (int i = 0; i < 5; i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     int sum = sumArray(arr, 5);
//     printf("Sum: %d\n", sum);
//     free(arr);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int findMax(int *arr, int size)
// {
//     int max = arr[0];
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }

// int main(int argc, char const *argv[])
// {
//     int a[20] = {16, 2, 77, 40, 12071, 11, 3, 101, 5, 7, 9, 13, 17, 19, 23, 29, 31, 37, 41, 43};
//     int max = findMax(a, 20);
//     printf("Maximum element in the array: %d\n", max);
//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// void concatenateString(char *str1, char *str2, char *result)
// {
//     while (*str1 != '\0')
//     {
//         *result = *str1;
//         str1++;
//         result++;
//     }
//     while (*str2 != '\0')
//     {
//         *result = *str2;
//         str2++;
//         result++;
//     }
//     *result = '\0';
// }

// int main(int argc, char const *argv[])
// {
//     char str1[100], str2[100], result[200];
//     printf("Enter first string: ");
//     scanf("%s", str1);
//     printf("Enter second string: ");
//     scanf("%s", str2);
//     concatenateString(str1, str2, result);
//     printf("Concatenated string: %s\n", result);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define Equal 1
// #define NotEqual 0

// int areStringEqual(char *arr1, char *arr2)
// {
//     while (*arr1 != '\0' && *arr2 != '\0')
//     {
//         if (*arr1 != *arr2)
//         {
//             return NotEqual;
//         }
//         arr1++;
//         arr2++;
//     }
//     if (*arr1 == '\0' && *arr2 == '\0')
//     {
//         return Equal;
//     }
//     else
//     {
//         return NotEqual;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     char str1[100], str2[100];
//     printf("Enter first string: ");
//     scanf("%s", str1);
//     printf("Enter second string: ");
//     scanf("%s", str2);
//     if (areStringEqual(str1, str2))
//     {
//         printf("Strings are equal\n");
//     }
//     else
//     {
//         printf("Strings are not equal\n");
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int first_allocation(char *arr, char a)
{
    int location = 1;
    while (*arr != '\0')
    {
        if (*arr == a)
        {
            return location;
        }
        arr++;
        location++;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    char arr[100], a;
    printf("Enter a string: ");
    scanf("%s", arr);
    printf("Enter a character: ");
    scanf(" %c", &a);
    if (first_allocation(arr, a) == -1)
    {
        printf("not found\n");
    }
    else
    {
        printf("the first:%d\n", first_allocation(arr, a));
    }
    return 0;
}
