#include "doulinklist.h"
dlinklist_status dlinklist_init(dlinklist* L) {//初始化带头尾节点的双向链表
    *L = (dlinklist)malloc(sizeof(struct dlinklist));
    if (*L == NULL) {
        return D_LINKLIST_ERR_ALLOC;
    }
   dnode *head,*tail;
    head = (dnode*)malloc(sizeof(dnode));
    tail = (dnode*)malloc(sizeof(dnode));
    if (head == NULL || tail == NULL) {
        free(*L);
        return D_LINKLIST_ERR_ALLOC;
    }
    head->prior = NULL;
    head->next = tail;
    tail->prior = head;
    tail->next = NULL;
    (*L)->head = head;
    (*L)->tail = tail;
    (*L)->length = 0;
    return D_LINKLIST_OK;

}
dlinklist_status dlinklist_insert(dlinklist L,int position,int data) {//在双向链表中插入元素
    if (L == NULL) {
        return D_LINKLIST_ERR_NULL;
    }
    if (position < 1 || position > L->length + 1) {
        return D_LINKLIST_ERR_RANGE;
    }
    dnode* new_node = (dnode*)malloc(sizeof(struct Dnode));
    if (new_node == NULL) {
        return D_LINKLIST_ERR_ALLOC;
    }
    new_node->data = data;
    if (position <=(L->length + 1)/2) {
        dnode* current = L->head;
        for (int i = 0; i <position; i++) {
            current = current->next;
        }
        new_node->prior = current;
        new_node->next = current->next;
        current->next->prior = new_node;
        current->next = new_node;
    } else {
    dnode* current = L->tail;
        for (int i = L->length; i >= position; i--) {
            current = current->prior;
        }
        new_node->next = current;
        new_node->prior = current->prior;
        current->prior->next = new_node;
        current->prior = new_node;
    }
    return D_LINKLIST_OK;
    L->length++;
}