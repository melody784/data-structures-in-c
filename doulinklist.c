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
     L->length++;
    return D_LINKLIST_OK;
}
dlinklist_status dlinklist_delete(dlinklist L,int position) {//删除双向链表中的元素
    if (L == NULL) {
        return D_LINKLIST_ERR_NULL;
    }
    if (position < 1 || position > L->length) {
        return D_LINKLIST_ERR_RANGE;
    }
    dnode* current;
    if (position <= L->length / 2) {
        current = L->head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
    } else {
        current = L->tail;
        for (int i = L->length; i >= position; i--) {
            current = current->prior;
        }
    }
    current->prior->next = current->next;
    current->next->prior = current->prior;
    free(current);
    L->length--;
    return D_LINKLIST_OK;
}
dlinklist_status dlinklist_get(dlinklist L,int position,int* data) {//获取双向链表中指定位置的元素
    if (L == NULL) {
        return D_LINKLIST_ERR_NULL;
    }
    if (position < 1 || position > L->length) {
        return D_LINKLIST_ERR_RANGE;
    }
    dnode* current;
    if (position <= L->length / 2) {
        current = L->head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
    } else {
        current = L->tail;
        for (int i = L->length; i >= position; i--) {
            current = current->prior;
        }
    }
    *data = current->data;
    return D_LINKLIST_OK;
}
dlinklist_status dlinklist_update(dlinklist L,int position,int data) {//更新双向链表中指定位置的元素
    if (L == NULL) {
        return D_LINKLIST_ERR_NULL;
    }
    if (position < 1 || position > L->length) {
        return D_LINKLIST_ERR_RANGE;
    }
    dnode* current;
    if (position <= L->length / 2) {
        current = L->head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
    } else {
        current = L->tail;
        for (int i = L->length; i >= position; i--) {
            current = current->prior;
        }
    }
    current->data = data;
    return D_LINKLIST_OK;
}
dlinklist_status dlinklist_destroy(dlinklist* L) {//销毁双向链表
    if (*L == NULL) {
        return D_LINKLIST_ERR_NULL;
    }
    dnode* current = (*L)->head;
    while (current != NULL) {
        dnode* temp = current;
        current = current->next;
        free(temp);
    }
    free(*L);
    *L = NULL;
    return D_LINKLIST_OK;
}
void dlinklist_print(dlinklist L) {//打印双向链表中的元素
    if (L == NULL) {
        printf("The doubly linked list is empty.\n");
        return;
    }
    dnode* current = L->head->next;
    while (current != L->tail) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
dlinklist_status dlinklist_find(dlinklist L,int data,int* position) {//获取双向链表中指定元素的位置
    if (L == NULL) {
        return D_LINKLIST_ERR_NULL;
    }
    dnode* current = L->head->next;
    int pos = 1;
    while (current != L->tail) {
        if (current->data == data) {
            *position = pos;
            return D_LINKLIST_OK;
        }
        current = current->next;
        pos++;
    }
    return D_LINKLIST_ERR_NOT_FOUND;
}