#include "menu_type.h"

// 显示菜单函数：打印所有菜品的编号、名称、价格
// 参数：
//   menu: 菜品数组
//   dishCount: 实际菜品数量
void showMenu(Dish menu[], int dishCount)
{
    int i = 0;
    printf("-----------------菜品菜单-----------------\n");
    printf("-编号------------菜品名称------------价格-\n\n");

    // 遍历菜单数组，格式化输出每个菜品信息
    for (i = 0; i < dishCount; i++)
    {
        printf("%-17d%-20s%-20.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// 根据菜品编号查找菜品在菜单数组中的索引
// 参数：
//   menu: 菜品数组
//   dishCount: 实际菜品数量
//   id: 要查找的菜品编号
// 返回值：找到返回对应索引，未找到返回-1
int findDishIndexById(Dish menu[], int dishCount, int id)
{
    int i = 0;

    for (i = 0; i < dishCount; i++)
    {
        if (menu[i].id == id)
        {
            return i; // 找到，返回索引
        }
    }

    return -1; // 未找到，返回-1
}

// 处理顾客点餐的函数
// 参数：
//   menu: 菜品数组，存储所有可点的菜品信息
//   dishCount: 菜单中菜品的总数量
//   orders: 订单数组，用于存储顾客已点的菜品
//   orderCount: 指针，指向当前订单中已点的菜品数量（会被修改）
void customerOrder(Dish menu[], int dishCount, OrderItem orders[], int *orderCount)
{
    int id;       // 存储用户输入的菜品编号
    int quantity; // 存储用户输入的菜品数量
    int index;    // 存储根据菜品编号找到的在menu数组中的索引

    // 调用函数显示菜单内容
    showMenu(menu, dishCount);

    // 提示用户输入菜品编号
    printf("\n请输入菜品编号：");
    scanf("%d", &id);

    // 根据菜品编号查找其在菜单数组中的索引
    index = findDishIndexById(menu, dishCount, id);
    // 如果返回-1，表示未找到该菜品编号
    if (index == -1)
    {
        printf("\n菜品编号不存在！\n");
        return; // 直接结束函数
    }

    // 提示用户输入点餐数量
    printf("\n请输入数量：");
    scanf("%d", &quantity);

    // 检查输入的数量是否合法（必须大于0）
    if (quantity <= 0)
    {
        printf("\n数量必须大于0！\n");
        return; // 直接结束函数
    }

    // 将点的菜品编号和数量存入订单数组的当前位置
    orders[*orderCount].dishId = id;
    orders[*orderCount].quantity = quantity;

    // 订单数量加1（注意括号：保证先解引用再自增）
    (*orderCount)++;

    // 提示点餐成功，并显示菜品名称和数量
    printf("\n点餐成功：%s x %d\n", menu[index].name, quantity);
}

void showOrders(Dish menu[], int dishCount, OrderItem orders[], int orderCount)
{
    int index;

    if (orderCount == 0)
    {
        printf("\n当前订单为空！\n");
        return;
    }

    printf("\n当前订单：\n");
    printf("-----------------菜品菜单-----------------\n");
    printf("--菜名-------------数量-----------总金额--\n\n");
    for (int i = 0; i < orderCount; i++)
    {
        index = findDishIndexById(menu, dishCount, orders[i].dishId);
        if (index != -1)
        {
            printf("%-20s%-14d%.2f\n", menu[index].name, orders[i].quantity, menu[index].price * orders[i].quantity);
        }
    }
}

float calculateTotal(Dish menu[], int dishCount, OrderItem orders[], int orderCount)
{
    float total = 0.0;
    int index;
    for (int i = 0; i < orderCount; i++)
    {
        index = findDishIndexById(menu, dishCount, orders[i].dishId);

        if (index != -1)
        {
            total += menu[index].price * orders[i].quantity;
        }
    }
    return total;
}