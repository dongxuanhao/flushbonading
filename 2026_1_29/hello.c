#include <stdio.h>
int add(int x, int y) {
    return x + y;
}

int main() {
    int a = 0;
    printf("Hello, World!\n");
    a = 5;
    
    // 测试add函数
    int result = add(3, 4);
    printf("3 + 4 = %d\n", result);
    
    return 0;
}
