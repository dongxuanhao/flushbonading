// 餐厅点餐系统 - 数据类型定义头文件
// 包含菜品和订单项的数据结构定义及相关的函数声明
#ifndef MENU_TYPE_H
#define MENU_TYPE_H

#include <stdio.h>  // 提供控制台输入输出函数（printf/scanf）
#include <stdlib.h> // 提供系统函数（如system）和通用工具函数
#include <string.h> // 提供字符串处理函数，用于菜品名称相关操作

#define MAX_DISHES 100 // 系统支持的最大菜品数量，限制菜品数组容量
#define MAX_ORDERS 100 // 订单支持的最大订单项数量，限制订单数组容量

// 菜品结构体：封装单道菜品的基础信息，作为菜品数据的统一载体
typedef struct
{
    int id;        // 菜品唯一标识ID，用于菜品查找和匹配
    char name[20]; // 菜品名称，字符数组固定长度，兼容常规菜品名
    float price;   // 菜品单价，浮点型支持小数价格（如18.8、25.5）
    int sale_quantity; // 菜品已售数量，用于统计菜品销售量
    float sale_total; // 菜品总价，用于统计菜品销售金额
} Dish;

// 订单项结构体：封装订单中单个菜品的点餐信息，关联菜品与点餐数量
typedef struct
{
    int dish_id;  // 关联菜品的唯一ID，与Dish结构体的id字段对应
    int table_id; // 关联的餐桌ID，用于关联订单项与具体餐桌
    int quantity; // 该菜品的点餐数量，需保证输入为正整数
} OrderItem;

// 显示菜品菜单：遍历菜品数组，格式化打印所有菜品的编号、名称、单价
void show_menu(Dish menu[], int dish_count);

// 根据菜品ID查找菜品数组索引：匹配成功返回对应索引，未找到返回-1
int find_dish_index_by_id(Dish menu[], int dish_count, int id);

// 根据菜品名称查找菜品数组索引：匹配成功返回对应索引，未找到返回-1
int find_dish_index_by_name(Dish menu[], int dish_count, char name[]);

// 根据菜品ID查找订单数组索引：匹配成功返回对应订单项索引，未找到返回-1
int find_order_index_by_dish_id(OrderItem orders[], int order_count, int dish_id);

// 根据桌号查找订单数组索引：匹配成功返回对应订单项索引，未找到返回-1
int find_order_index_by_table_id(OrderItem orders[], int order_count, int table_id);

// 根据菜品ID和桌号查找订单数组索引：匹配成功返回对应索引，未找到返回-1
int find_order_index_by_dish_id_and_table_id(OrderItem orders[], int order_count, int dish_id, int table_id);

// 顾客点餐核心逻辑：处理选品/数量输入/重复加量/输入校验，输入0结束点餐，通过指针更新订单数量
void customer_order(Dish menu[], int dish_count, OrderItem orders[], int *order_count, int table_id);

// 显示当前订单详情：遍历订单数组匹配菜品信息，打印菜名、数量、单菜品总价，空订单给出提示
void show_orders(Dish menu[], int dish_count, OrderItem orders[], int order_count, int table_id);

// 计算订单总金额：累加所有订单项的单价*数量，返回浮点型的订单总价
float calculate_total(Dish menu[], int dish_count, OrderItem orders[], int order_count, int table_id);

void check_table(Dish menu[], int dish_count, OrderItem orders[], int *order_count, int table_id, float *total_sale);

void show_sales(Dish menu[], int dish_count, float total_sale);

// 清屏函数：清除控制台屏幕上的内容
void clear_screen(void);

// 添加菜品：向菜单中添加新的菜品
void add_dish(Dish menu[], int *dish_count);

// 删除菜品：从菜单中删除指定菜品，同时处理相关订单
void delete_dish(Dish menu[], int *dish_count, OrderItem orders[], int order_count);

// 修改菜品：修改菜单中现有菜品的信息
void modify_dish(Dish menu[], int dish_count);

// 顾客菜单：显示顾客端的操作菜单
void customer_menu(Dish menu[], int *dish_count, OrderItem orders[], int *order_count,float *total_sale);

// 商家菜单：显示商家端的操作菜单
void merchant_menu(Dish menu[], int *dish_count, OrderItem orders[], int *order_count,float *total_sale);

#endif // 结束头文件保护，防止重复包含
