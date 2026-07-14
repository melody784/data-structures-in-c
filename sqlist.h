#ifndef SQLIST_H
#define SQLIST_H
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;//定义顺序表元素类型为int

typedef enum {
    SQLIST_OK = 0,
    SQLIST_ERR_NULL,
    SQLIST_ERR_RANGE,
    SQLIST_ERR_ALLOC,
    SQLIST_ERR_NOT_FOUND
} sqlist_status;

//定义顺序表结构体
typedef struct{
    ElemType *data;//顺序表的存储空间基址
    int length;//顺序表的当前长度
    int list_size;//顺序表的当前分配容量
} sequential_list, *sequential_list_ptr;
//定义一个顺序表的初始化函数的函数声明
sqlist_status init_sequential_list(sequential_list *L);
//定义一个顺序表的插入函数的函数声明
sqlist_status insert_sequential_list(sequential_list *L, int position, ElemType value);
//定义一个顺序表的删除函数的函数声明
sqlist_status delete_sequential_list(sequential_list *L,int position,ElemType *value);
//定义一个顺序表的修改函数的函数声明
sqlist_status update_sequential_list(sequential_list *L,int position,ElemType value,ElemType *old_value);
//定义一个顺序表的按值查找函数的函数声明
sqlist_status search_sequential_list(sequential_list *L,ElemType value,int *position);
//定义一个顺序表的按位置查找函数的函数声明
sqlist_status get_sequential_list(sequential_list *L,int position,ElemType *value);
//定义一个顺序表的打印函数的函数声明
void print_sequential_list(sequential_list *L);
#endif
