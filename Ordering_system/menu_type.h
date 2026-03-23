#ifndef MENU_TYPE_H  
#define MENU_TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 宏定义
#define MAX_DISHES 100  // 菜单最大菜品数量
#define MAX_ORDERS 100  // 订单最大菜品项数量

// 菜品结构体声明
typedef struct
{
    int id;         // 菜品编号
    char name[20];  // 菜品名称
    float price;    // 菜品价格
} Dish;

// 订单项结构体声明
typedef struct
{
    int dishId;     // 关联的菜品编号
    int quantity;   // 点餐数量
} OrderItem;

void showMenu(Dish menu[], int dishCount);
int findDishIndexById(Dish menu[], int dishCount, int id);
void customerOrder(Dish menu[], int dishCount, OrderItem orders[], int *orderCount);
void showOrders(Dish menu[], int dishCount, OrderItem orders[], int orderCount);
float calculateTotal(Dish menu[], int dishCount, OrderItem orders[], int orderCount);

#endif  // 结束头文件保护