//头文件卫士
#ifndef LINKLIST_H
#define LINKLIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct linklist{//链表结构体
         int data;
         struct Node* next;
            int length;
} *linklist;
typedef struct Node{//链表节点结构体
         int data;
         struct Node* next;
} LNode;
typedef enum {
    LINKLIST_OK=0,//操作成功
    LINKLIST_ERR_NULL,//链表为空
    LINKLIST_ERR_ALLOC,//内存分配失败
    LINKLIST_ERR_RANGE,//位置不合法
    LINKLIST_ERR_NOT_FOUND//未找到元素
} linklist_status;
linklist_status InitList(linklist *L);//初始化链表
linklist_status createlist_head(linklist *L, int n);//头插法创建链表
linklist_status createlist_tail(linklist *L, int n);//尾插法创建链表
linklist_status insert_list(linklist *L,int position,int value);//在链表中插入元素
linklist_status delete_list(linklist *L,int position);//删除链表中的元素
linklist_status get_elem(linklist *L,int position,int *value);//获取链表中指定位置的元素
linklist_status update_elem(linklist *L,int position,int value);//更新链表中指定位置的元素
linklist_status find_elem(linklist *L,int value,int *position);//查找链表中指定元素的位置
void print_list(linklist *L);//打印链表
#endif