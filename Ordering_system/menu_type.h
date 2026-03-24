// 头文件保护，防止重复包含导致重定义
#ifndef MENU_TYPE_H
#define MENU_TYPE_H

#include <stdio.h>  // 提供控制台输入输出函数（printf/scanf）
#include <stdlib.h> // 预留内存操作函数，适配后续功能扩展
#include <string.h> // 提供字符串处理函数，用于菜品名称相关操作

#define MAX_DISHES 100 // 系统支持的最大菜品数量，限制菜品数组容量
#define MAX_ORDERS 100 // 订单支持的最大订单项数量，限制订单数组容量

// 菜品结构体：封装单道菜品的基础信息，作为菜品数据的统一载体
typedef struct
{
    int id;        // 菜品唯一标识ID，用于菜品查找和匹配
    char name[20]; // 菜品名称，字符数组固定长度，兼容常规菜品名
    float price;   // 菜品单价，浮点型支持小数价格（如18.8、25.5）
} Dish;

// 订单项结构体：封装订单中单个菜品的点餐信息，关联菜品与点餐数量
typedef struct
{
    int dish_id;  // 关联菜品的唯一ID，与Dish结构体的id字段对应
    int quantity; // 该菜品的点餐数量，需保证输入为正整数
} OrderItem;

// 显示菜品菜单：遍历菜品数组，格式化打印所有菜品的编号、名称、单价
void show_menu(Dish menu[], int dish_count);

// 根据菜品ID查找菜品数组索引：匹配成功返回对应索引，未找到返回-1
int find_dish_index_by_id(Dish menu[], int dish_count, int id);

// 根据菜品ID查找订单数组索引：匹配成功返回对应订单项索引，未找到返回-1
int find_order_index_by_dish_id(OrderItem orders[], int order_count, int dish_id);

// 根据菜品名称查找菜品数组索引：匹配成功返回对应索引，未找到返回-1
int find_dish_index_by_name(Dish menu[], int dish_count, char name[]);

// 顾客点餐核心逻辑：处理选品/数量输入/重复加量/输入校验，输入0结束点餐，通过指针更新订单数量
void customer_order(Dish menu[], int dish_count, OrderItem orders[], int *order_count);

// 显示当前订单详情：遍历订单数组匹配菜品信息，打印菜名、数量、单菜品总价，空订单给出提示
void show_orders(Dish menu[], int dish_count, OrderItem orders[], int order_count);

// 计算订单总金额：累加所有订单项的单价*数量，返回浮点型的订单总价
float calculate_total(Dish menu[], int dish_count, OrderItem orders[], int order_count);

void clear_screen(void);

void add_dish(Dish menu[], int *dish_count);

void delete_dish(Dish menu[], int *dish_count, OrderItem orders[], int order_count);

void modify_dish(Dish menu[],int dish_count);

void customer_menu(Dish menu[], int *dish_count, OrderItem orders[], int *order_count);

void merchant_menu(Dish menu[], int *dish_count, OrderItem orders[], int *order_count);
#endif