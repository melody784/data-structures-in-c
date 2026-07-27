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
#endif