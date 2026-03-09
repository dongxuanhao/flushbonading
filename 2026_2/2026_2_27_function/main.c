#include <stdio.h>
#include "disp.h"
#include "math.h"

// int main()
// {
//     int x, y;
//     printf("Enter two integers: ");
//     scanf("%d %d", &x, &y);
//     display(x, y);
//     return 0;
// }

int main() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 && j == 3) {
                goto exit_loop; // 满足条件，跳出所有循环
            }
            printf("i = %d, j = %d\n", i, j);
        }
    }
exit_loop: // 循环退出标签
    printf("Exited loops at i = %d, j = %d\n", i, j);
    return 0;
}