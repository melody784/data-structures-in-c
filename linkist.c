#include <stdio.h>
#include <stdlib.h>
//此文件用来练习C语言单链表
//单链表的基本操作：创建、插入、删除、查找、遍历等
//单链表的结构定义
typedef struct nodes{
    int data;
    struct nodes *next;
}Lnode,*Linklist;
//第一个功能： 头插法创建单链表
void cre_list_head(Linklist *L,int n){//此时L是一个指向指针的指针，*L是一个指针，**L是一个结构体
    *L=(Linklist)malloc(sizeof (Lnode));
    (*L)->next=NULL;
    for(int i=0;i<n;i++){
        Lnode *p=(Lnode*)malloc(sizeof(Lnode));
        scanf("%d",&p->data);
        p->next=(*L)->next;
        (*L)->next=p;
    }
}
