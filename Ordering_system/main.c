#include "menu_type.h"

// 主函数：点餐系统程序入口，实现客户点餐、商家管理两大核心功能
int main(int argc, char const *argv[])
{
    Dish menu[MAX_DISHES] = {0};        // 菜品数组，存储系统所有菜品信息
    OrderItem orders[MAX_ORDERS] = {0}; // 订单数组，存储用户已点菜品的订单项
    int order_count = 0;                // 有效订单项数量
    int dish_count = 3;                 // 系统初始菜品数量
    int choice;                         // 用户菜单选择
    float total_sale = 0.0;            // 今日销售额，用于统计所有订单项的单价*数量和

    // 初始化3道默认菜品
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
        // 显示主菜单
        printf("========点餐系统========\n");
        printf("1.客户点餐\n");
        printf("2.商家\n");
        printf("0.退出系统\n");
        printf("请输入您的选择：");
        
        // 输入验证
        if (scanf("%d", &choice) != 1)
        {
            printf("\n输入错误，请重新输入\n");
            while (getchar() != '\n')  // 清除输入缓冲区
                ;
            continue;
        }

        // 主菜单选择处理
        switch (choice)
        {
        case 1:
            // 进入客户点餐菜单
            customer_menu(menu, &dish_count, orders, &order_count,&total_sale);
            break;

        case 2:
            // 进入商家管理菜单
            merchant_menu(menu, &dish_count, orders, &order_count, &total_sale);
            break;

        case 0:
            // 退出系统
            printf("谢谢使用！\n");
            return 0;

        default:
            // 输入无效选项
            printf("输入错误，请重新输入\n");
            break;
        }
    }
    
    return 0;
}
