#include "linklist.h"
linklist_status InitList(linklist *L)//初始化链表
{
    *L = (linklist)malloc(sizeof(LNode));
    if (!(*L))
        exit(0);
    (*L)->next = NULL;
    (*L)->length=0;
    return LINKLIST_OK;
}
linklist_status createlist_head(linklist *L, int n){//头插法创建链表
    linklist p;
    int i;
    for (i=0;i<n;i++)
    {
        p=(linklist)malloc(sizeof(LNode));
        if (!p)
            return LINKLIST_ERR_ALLOC;
            p->next=(*L)->next;
            (*L)->next=p;
            (*L)->length++;
            scanf("%d",&p->data);
            return LINKLIST_OK;
    }
}
linklist_status createlist_tail(linklist *L, int n){//尾插法创建链表
    linklist p,r;
    int i;
    r=*L;
    for (i=0;i<n;i++){
        p=(linklist)malloc(sizeof(LNode));
        if (!p)
            return LINKLIST_ERR_ALLOC;
        r->next=p;
        r=p;
        scanf("%d",&p->data);
        (*L)->length++;
    }
    return LINKLIST_OK;
}
linklist_status insert_list(linklist *L,int position,int value){//在链表中插入元素
    if(position<1||position>(*L)->length+1)
        return LINKLIST_ERR_RANGE;
        int i;
        linklist p,s;
        p=*L;
        for(i=1;i<position;i++)
            p=p->next;
        s=(linklist)malloc(sizeof(LNode));  
        if(!s)
            return LINKLIST_ERR_ALLOC;
        s->data=value;
        s->next=p->next;
        p->next=s;
        (*L)->length++;
        return LINKLIST_OK;
}

