#include "menu_type.h" // 引入菜单类型头文件，包含结构体和宏定义

// 清屏函数：调用系统命令清空控制台屏幕
void clear_screen(void)
{
    system("cls");
}

// 显示菜品菜单：遍历菜品数组，格式化打印编号、名称、单价
void show_menu(Dish menu[], int dish_count)
{
    int i = 0;
    // 打印菜单表头
    printf("-----------------菜品菜单-----------------\n");
    printf("-编号------------菜品名称------------价格-\n\n");
    // 循环输出所有菜品信息
    for (i = 0; i < dish_count; i++)
    {
        printf("%-17d%-20s%-20.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// 根据菜品ID查找菜单数组索引，找到返回索引，未找到返回-1
int find_dish_index_by_id(Dish menu[], int dish_count, int id)
{
    int i = 0;
    for (i = 0; i < dish_count; i++)
    {
        if (menu[i].id == id)
        {
            return i; // 匹配到菜品，立即返回索引
        }
    }
    return -1; // 无匹配菜品，返回异常标识
}

// 根据菜品名称查找菜单数组索引，找到返回索引，未找到返回-1
int find_dish_index_by_name(Dish menu[], int dish_count, char name[])
{
    int i = 0;
    for (i = 0; i < dish_count; i++)
    {
        if (strcmp(menu[i].name, name) == 0)
        {
            return i; // 匹配到菜品，立即返回索引
        }
    }
    return -1; // 无匹配菜品，返回异常标识
}

// 根据菜品ID查找订单数组索引，找到返回索引，未找到返回-1
int find_order_index_by_dish_id(OrderItem orders[], int order_count, int dish_id)
{
    int i = 0;
    for (i = 0; i < order_count; i++)
    {
        if (orders[i].dish_id == dish_id)
        {
            return i; // 匹配到订单项，立即返回索引
        }
    }
    return -1; // 无匹配订单项，返回异常标识
}

// 根据菜品ID和桌号查找订单数组索引，找到返回索引，未找到返回-1
int find_order_index_by_dish_id_and_table_id(OrderItem orders[], int order_count, int dish_id, int table_id)
{
    for (int i = 0; i < order_count; i++)
    {
        if (orders[i].dish_id == dish_id && orders[i].table_id == table_id)
        {
            return i;
        }
    }
    return -1;
}

// 顾客点餐核心逻辑：支持选品/数量输入/重复加量/输入校验，输入0结束点餐
void customer_order(Dish menu[], int dish_count, OrderItem orders[], int *order_count, int table_id)
{
    int id, quantity;            // 菜品编号、点餐数量
    int menu_index, order_index; // 菜品索引、订单项索引
    show_menu(menu, dish_count); // 点餐前置，展示菜品菜单

    while (1) // 循环点餐，直到主动退出
    {
        printf("\n请输入要点的菜品编号(输入0结束点餐)：");
        if (scanf("%d", &id) != 1)
        {
            printf("\n输入错误，重新输入！\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (id == 0) // 输入0，结束点餐循环
            break;

        // 校验菜品ID是否有效
        menu_index = find_dish_index_by_id(menu, dish_count, id);
        if (menu_index == -1)
        {
            printf("\n菜品编号不存在，请重新输入！\n");
            continue;
        }

        // 校验点餐数量是否有效
        printf("\n请输入要点的菜品数量：");
        if (scanf("%d", &quantity) != 1)
        {
            printf("\n输入错误，重新输入！\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (quantity <= 0)
        {
            printf("\n数量必须大于0，请重新输入！\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        // 检查菜品是否已在订单，存在则累加数量
        order_index = find_order_index_by_dish_id_and_table_id(orders, *order_count, id, table_id);
        if (order_index != -1)
        {
            orders[order_index].quantity += quantity;
            printf("\n已累加数量，%s 当前数量：%d\n", menu[menu_index].name, orders[order_index].quantity);
        }
        else
        {
            // 订单满额校验，无法新增订单项
            if (*order_count >= MAX_ORDERS)
            {
                printf("\n订单已满，无法继续点餐！\n");
                break;
            }
            // 新增订单项，更新订单数量（指针解引用修改外部变量）
            orders[*order_count].dish_id = id;
            orders[*order_count].quantity = quantity;
            orders[*order_count].table_id = table_id;
            (*order_count)++;
            printf("\n点餐成功：%s x %d\n", menu[menu_index].name, quantity);
        }
        printf("-----------------------------------\n");
    }
    printf("\n点餐结束，感谢您的光临！\n");
}

// 展示当前订单详情：打印菜品名称、数量、单菜品总价，空订单给出提示
void show_orders(Dish menu[], int dish_count, OrderItem orders[], int order_count, int table_id)
{
    int menu_index;
    int found = 0;
    // 空订单特殊处理

    if (order_count == 0)
    {
        printf("\n%d号桌当前订单为空！\n", table_id);
        return;
    }

    // 打印订单表头
    printf("\n当前订单：\n");
    printf("-----------------%d号桌菜品订单-----------------\n", table_id);
    printf("--菜名-------------数量-----------总金额--\n\n");

    // 循环输出所有订单项信息
    for (int i = 0; i < order_count; i++)
    {
        if (orders[i].table_id == table_id)
        {
            menu_index = find_dish_index_by_id(menu, dish_count, orders[i].dish_id);
            if (menu_index != -1) // 防止菜品编号异常，双重校验
            {
                printf("%-20s%-14d%.2f\n", menu[menu_index].name, orders[i].quantity,
                       menu[menu_index].price * orders[i].quantity);
                found = 1;
            }
        }
    }
    if (found == 0)
    {
        printf("\n%d号桌当前订单为空！\n", table_id);
    }
}

// 计算订单总金额：累加所有订单项的单价*数量，返回浮点型总价
float calculate_total(Dish menu[], int dish_count, OrderItem orders[], int order_count, int table_id)
{
    float total = 0.0; // 订单总价初始化
    int menu_index;
    // 循环累加每个订单项的金额
    for (int i = 0; i < order_count; i++)
    {
        if (orders[i].table_id == table_id)
        {
            menu_index = find_dish_index_by_id(menu, dish_count, orders[i].dish_id);
            if (menu_index != -1) // 防止菜品编号异常，双重校验
            {
                total += menu[menu_index].price * orders[i].quantity;
            }
        }
    }
    return total;
}

void check_table(Dish menu[], int dish_count, OrderItem orders[], int *order_count, int table_id, float *total_sale)
{
    float calculate = calculate_total(menu, dish_count, orders, *order_count, table_id);

    if (calculate == 0)
    {
        printf("该桌没有要结算的订单。\n");
        return;
    }

    *total_sale += calculate;

    for (int i = 0; i < *order_count; i++)
    {
        if (orders[i].table_id == table_id)
        {
            int menu_index = find_dish_index_by_id(menu, dish_count, orders[i].dish_id);
            if (menu_index != -1) // 防止菜品编号异常，双重校验
            {
                menu[menu_index].sale_quantity += orders[i].quantity;
                menu[menu_index].sale_total += (menu[menu_index].price * orders[i].quantity);
            }
        }
    }

    printf("\n%d号桌订单总价：%.2f\n", table_id, calculate);
    printf("\n正在结算...\n");

    for (int i = 0; i < *order_count;)
    {
        if (orders[i].table_id == table_id)
        {
            for (int j = i; j < *order_count - 1; j++)
            {
                orders[j] = orders[j + 1];
            }
            (*order_count)--;
        }
        else
        {
            i++;
        }
    }
    printf("\n该桌已结算完成!\n");
}

void show_sales(Dish menu[], int dish_count, float total_sale)
{
    printf("\n-----------------今日销售情况-----------------\n");
    printf("--菜名-------------销量-----------销售额------\n\n");

    for (int i = 0; i < dish_count; i++)
    {
        printf("%-20s%-14d%.2f\n",
               menu[i].name,
               menu[i].sale_quantity,
               menu[i].sale_total);
    }

    printf("\n今日总营业额：%.2f\n", total_sale);
}

// 新增菜品：向菜单中添加新菜品，包含输入校验和重复名称检查
void add_dish(Dish menu[], int *dish_count)
{
    int max_id = 0;
    char new_name[20];
    float new_price;

    if (*dish_count >= MAX_DISHES)
    {
        printf("\n菜单已满，无法新增菜品！\n");
        return;
    }

    for (int i = 0; i < *dish_count; i++)
    {
        if (menu[i].id > max_id)
        {
            max_id = menu[i].id;
        }
    }

    menu[*dish_count].id = max_id + 1;

    while (1)
    {
        printf("正在新增菜品...\n");
        printf("\n请输入菜品名称：");
        if (scanf("%19s", new_name) != 1)
        {
            printf("\n输入错误，新增失败\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (find_dish_index_by_name(menu, *dish_count, new_name) != -1)
        {
            printf("\n菜品名称已存在，请重新输入！\n");
            continue;
        }

        printf("\n请输入菜品价格：");
        if (scanf("%f", &new_price) != 1)
        {
            printf("\n输入错误，新增失败\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (new_price <= 0)
        {
            printf("\n菜品价格必须大于0，请重新输入！\n");
            continue;
        }
        break;
    }
    strcpy(menu[*dish_count].name, new_name);
    menu[*dish_count].price = new_price;
    (*dish_count)++;

    printf("\n菜品%s已成功添加！\n", menu[*dish_count - 1].name);
}

// 删除菜品：从菜单中删除指定菜品，包含订单关联检查
void delete_dish(Dish menu[], int *dish_count, OrderItem orders[], int order_count)
{
    int id;
    int delete_index;
    char delete_name[20];

    if (*dish_count == 0)
    {
        printf("\n菜单为空，无法删除菜品！\n");
        return;
    }

    show_menu(menu, *dish_count);
    printf("正在删除菜品...\n");
    printf("\n请输入要删除的菜品编号：");

    if (scanf("%d", &id) != 1)
    {
        printf("输入错误，删除失败\n");
        while (getchar() != '\n')
            ;
        return;
    }
    delete_index = find_dish_index_by_id(menu, *dish_count, id);
    if (delete_index == -1)
    {
        printf("\n菜品编号不存在，无法删除！\n");
        return;
    }
    else if (delete_index != -1)
    {
        if (find_order_index_by_dish_id(orders, order_count, id) != -1)
        {
            printf("\n菜品已被点餐，无法删除！\n");
            return;
        }
    }

    // 删除菜品
    strcpy(delete_name, menu[delete_index].name);
    for (int i = delete_index; i < *dish_count - 1; i++)
    {
        menu[i] = menu[i + 1];
    }
    (*dish_count)--;

    printf("\n菜品%s已成功删除！\n", delete_name);
}

// 修改菜品：修改菜单中已有菜品的名称和价格
void modify_dish(Dish menu[], int dish_count)
{
    int id;
    int modify_index;
    char new_name[20];
    int same_name_index = 0;
    float new_price;

    if (dish_count == 0)
    {
        printf("\n菜单为空，无法修改菜品！\n");
        return;
    }

    show_menu(menu, dish_count);

    while (1)
    {
        printf("正在修改菜品...\n");
        printf("\n请输入要修改的菜品编号：");
        if (scanf("%d", &id) != 1)
        {
            printf("\n输入错误，修改失败\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        modify_index = find_dish_index_by_id(menu, dish_count, id);
        if (modify_index == -1)
        {
            printf("\n菜品编号不存在，无法修改！\n");
            continue;
        }
        break;
    }
    while (1)
    {

        printf("\n请输入新的菜品名称：");
        if (scanf("%19s", new_name) != 1)
        {
            printf("\n菜品名称输入失败，无法修改\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        same_name_index = find_dish_index_by_name(menu, dish_count, new_name);
        if (same_name_index != -1 && same_name_index != modify_index)
        {
            printf("\n菜品名称已存在，请重新输入！\n");
            continue;
        }

        printf("\n请输入新的菜品价格：");
        if (scanf("%f", &new_price) != 1)
        {
            printf("\n输入错误，修改失败\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (new_price <= 0)
        {
            printf("\n菜品价格必须大于0，修改失败！\n");
            continue;
        }
        break;
    }

    strcpy(menu[modify_index].name, new_name);
    menu[modify_index].price = new_price;

    printf("\n菜品 %s 已成功修改！\n", menu[modify_index].name);

    show_menu(menu, dish_count);
}

// 客户菜单：提供客户操作的菜单界面，包括查看菜单、点餐、显示订单、计算总价等功能
void customer_menu(Dish menu[], int *dish_count, OrderItem orders[], int *order_count, float *total_sale)
{
    int choice;
    int table_id = 0;
    clear_screen();
    while (1)
    {
        // 打印客户子菜单
        printf("\n========客户菜单========\n");
        printf("1.查看菜单\n");
        printf("2.点餐\n");
        printf("3.显示订单\n");
        printf("4.结算订单\n");
        printf("0.返回上一级\n");
        printf("\n请输入您的选择：");
        if (scanf("%d", &choice) != 1)
        {
            printf("\n输入错误，请重新输入\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        // 客户子菜单选择逻辑分支
        switch (choice)
        {
        case 1: // 调用函数，展示所有菜品菜单
            clear_screen();
            show_menu(menu, *dish_count);
            break;
        case 2: // 调用函数，处理客户点餐逻辑
            clear_screen();
            printf("请输入您的桌号：");
            if (scanf("%d", &table_id) != 1 || table_id <= 0)
            {
                printf("\n输入错误，请重新输入\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            customer_order(menu, *dish_count, orders, order_count, table_id);
            break;
        case 3: // 调用函数，展示客户订单
            clear_screen();
            printf("请输入您的桌号：");
            if (scanf("%d", &table_id) != 1 || table_id <= 0)
            {
                printf("\n输入错误，请重新输入\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            show_orders(menu, *dish_count, orders, *order_count, table_id);
            break;
        case 4: // 调用函数，结算客户订单
            clear_screen();
            printf("请输入您要结算的桌号：");
            if (scanf("%d", &table_id) != 1 || table_id <= 0)
            {
                printf("\n输入错误，请重新输入\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            check_table(menu, *dish_count, orders, order_count, table_id, total_sale);
            break;
        case 0: // 返回上一级
            clear_screen();
            return;
        default: // 输入非有效选项，提示错误
            clear_screen();
            printf("输入错误，请重新输入\n");
            break; // 输入非有效选项，提示错误
        }
    }
}

// 商家菜单：提供商家操作的菜单界面，包括查看/新增/删除/修改菜品等功能
void merchant_menu(Dish menu[], int *dish_count, OrderItem orders[], int *order_count, float *total_sale)
{
    int choice;
    int table_id;
    clear_screen();
    // 商家子菜单循环，持续提供商家操作选项
    while (1)
    {
        // 打印商家子菜单
        printf("\n========商家菜单========\n");
        printf("1.查看菜单\n");
        printf("2.查看订单\n");
        printf("3.查看某桌订单总价\n");
        printf("4.查看今日销售情况\n");
        printf("5.新增菜品\n");
        printf("6.删除菜品\n");
        printf("7.修改菜品\n");
        printf("0.返回上一级\n");
        printf("\n请输入您的选择：");
        if (scanf("%d", &choice) != 1)
        {
            printf("\n输入错误，请重新输入\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        // 商家子菜单选择逻辑分支
        switch (choice)
        {
        case 1: // 调用函数，展示所有菜品菜单
            clear_screen();
            show_menu(menu, *dish_count);
            break;
        case 2: // 调用函数，查看当前订单详情
            clear_screen();
            printf("请输入要查看的桌号：");
            if (scanf("%d", &table_id) != 1 || table_id <= 0)
            {
                printf("\n输入错误，请重新输入\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            show_orders(menu, *dish_count, orders, *order_count, table_id);
            break;
        case 3: // 调用函数，计算并打印总营业额（即当前订单总价）
            clear_screen();
            printf("请输入要查看的订单的桌号：");
            if (scanf("%d", &table_id) != 1 || table_id <= 0)
            {
                printf("\n输入错误，请重新输入\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            printf("订单总价:%.2f\n\n", calculate_total(menu, *dish_count, orders, *order_count, table_id));
            break;
        case 4: // 调用函数，查看今日销售情况
            clear_screen();
            show_sales(menu, *dish_count, *total_sale);
            break;
        case 5: // 调用函数，新增菜品
            clear_screen();
            add_dish(menu, dish_count);
            break;
        case 6: // 调用函数，删除菜品
            clear_screen();
            delete_dish(menu, dish_count, orders, *order_count);
            break;
        case 7: // 调用函数，修改菜品
            clear_screen();
            modify_dish(menu, *dish_count);
            break;
        case 0: // 返回上一级
            clear_screen();
            return;
        default: // 输入非有效选项，提示错误
            clear_screen();
            printf("输入错误，请重新输入\n");
            break; // 输入非有效选项，提示错误
        }
    }
}
