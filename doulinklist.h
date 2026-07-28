#ifndef _DOULINKLIST_H_
#define _DOULINKLIST_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct dlinklist {//双向链表头尾节点结构体
    struct Dnode* head;
    struct Dnode* tail;
    int length;
}*dlinklist;
typedef struct Dnode {//双向链表节点结构体
    int data;
    struct Dnode* prior;
    struct Dnode* next;
}dnode;
typedef enum {
    D_LINKLIST_OK=0,//操作成功
    D_LINKLIST_ERR_NULL,//链表为空
    D_LINKLIST_ERR_ALLOC,//内存分配失败
    D_LINKLIST_ERR_RANGE,//位置不合法
    D_LINKLIST_ERR_NOT_FOUND//未找到元素
} dlinklist_status; 
dlinklist_status dlinklist_init(dlinklist* L);//初始化带头尾节点的双向链表
dlinklist_status dlinklist_insert(dlinklist L,int position,int data);//在双向链表中插入元素
dlinklist_status dlinklist_delete(dlinklist L,int position);//删除双向链表中的元素
dlinklist_status dlinklist_get(dlinklist L,int position,int* data);//获取双向链表中指定位置的元素
dlinklist_status dlinklist_update(dlinklist L,int position,int data);//更新双向链表中指定位置的元素
dlinklist_status dlinklist_destroy(dlinklist* L);//销毁双向链表
void dlinklist_print(dlinklist L);//打印双向链表中的元素
dlinklist_status dlinklist_find(dlinklist L,int data,int* position);//查找双向链表中指定元素的位置
#endif