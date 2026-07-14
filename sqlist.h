#ifndef SQLIST_H
#define SQLIST_H
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;//定义顺序表元素类型为int
//定义顺序表结构体
typedef struct{
    ElemType *data;//顺序表的存储空间基址
    int length;//顺序表的当前长度
    int list_size;//顺序表的当前分配容量
} sequential_list, *sequential_list_ptr;
//定义一个顺序表的初始化函数的函数声明
void init_sequential_list(sequential_list *L);
//定义一个顺序表的插入函数的函数声明
void insert_sequential_list(sequential_list *L, int position, ElemType value);
//定义一个顺序表的删除函数的函数声明
void delete_sequential_list(sequential_list *L,int position,ElemType *value);
//定义一个顺序表的修改函数的函数声明
void update_sequential_list(sequential_list *L,int position,ElemType value,ElemType *old_value);
//定义一个顺序表的按值查找函数的函数声明
void search_sequential_list(sequential_list *L,ElemType value);
//定义一个顺序表的按位置查找函数的函数声明
ElemType get_sequential_list(sequential_list *L,int position);
//定义一个顺序表的打印函数的函数声明
void print_sequential_list(sequential_list *L);
#endif
