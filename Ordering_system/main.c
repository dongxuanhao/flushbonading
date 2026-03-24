#include "menu_type.h" // 引入点餐系统类型头文件，包含结构体、宏定义和函数声明

// 主函数：点餐系统程序入口，实现客户点餐、商家管理两大核心功能，支持多级菜单交互
int main(int argc, char const *argv[])
{
    Dish menu[MAX_DISHES] = {0};        // 菜品数组，存储系统所有菜品信息
    OrderItem orders[MAX_ORDERS] = {0}; // 订单数组，存储用户已点菜品的订单项
    int order_count = 0;                // 有效订单项数量，初始化为0
    int dish_count = 3;                 // 系统初始菜品数量，默认初始化3道菜品
    int choice;                         // 选择项

    // 初始化3道默认菜品的ID、名称、单价
    menu[0].id = 1;
    strcpy(menu[0].name, "鱼香肉丝");
    menu[0].price = 20.0;
    menu[1].id = 2;
    strcpy(menu[1].name, "宫保鸡丁");
    menu[1].price = 15.9;
    menu[2].id = 3;
    strcpy(menu[2].name, "麻婆豆腐");
    menu[2].price = 18.9;

    // 系统主循环：持续运行，直到用户选择退出
    while (1)
    {
        // 打印系统主菜单
        printf("========点餐系统========\n");
        printf("1.客户点餐\n");
        printf("2.商家\n");
        printf("0.退出系统\n");
        printf("请输入您的选择：");
        if (scanf("%d", &choice) != 1)
        {
            printf("\n输入错误，请重新输入\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        // 主菜单选择逻辑分支
        switch (choice)
        {
        case 1:
            customer_menu(menu, &dish_count, orders, &order_count);
            break;

        // 商家管理功能分支
        case 2:
            merchant_menu(menu, &dish_count, orders, &order_count);
            break;

        // 退出系统
        case 0:
            printf("谢谢使用！\n");
            return 0; // 程序正常退出，返回0

        // 主菜单输入非有效选项
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    }
    return 0;
}