#include "menu_type.h"

int main(int argc, char const *argv[])
{
    Dish menu[MAX_DISHES] = {0};        // 定义菜单数组并初始化为0
    OrderItem orders[MAX_ORDERS] = {0}; // 定义订单数组并初始化为0
    int orderCount = 0;                 // 初始化订单数量为0
    int dishCount = 3;                  // 实际菜品数量（这里手动设置为3）

    // 初始化第1个菜品信息
    menu[0].id = 1;
    strcpy(menu[0].name, "鱼香肉丝"); // 还原合理的菜品名称
    menu[0].price = 20.0;

    // 初始化第2个菜品信息
    menu[1].id = 2;
    strcpy(menu[1].name, "宫保鸡丁"); // 还原合理的菜品名称
    menu[1].price = 15.9;

    // 初始化第3个菜品信息
    menu[2].id = 3;
    strcpy(menu[2].name, "麻婆豆腐"); // 还原合理的菜品名称
    menu[2].price = 18.9;

    // 调用显示菜单函数
    customerOrder(menu, dishCount, orders, &orderCount);

    // 调用显示订单函数
    showOrders(menu, dishCount, orders, orderCount);

    printf("\n订单总价:%.2f\n\n",calculateTotal(menu,dishCount,orders,orderCount));

    return 0; // 程序正常退出
}