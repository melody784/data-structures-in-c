#include "linklist.h"

linklist_status InitList(linklist *L) {
    *L = (linklist)malloc(sizeof(LNode));
    if (!(*L)) {
        exit(0);
    }

    (*L)->next = NULL;
    (*L)->length = 0;
    return LINKLIST_OK;
}

linklist_status createlist_head(linklist *L, int n) {
    linklist p;
    int i;

    for (i = 0; i < n; i++) {
        p = (linklist)malloc(sizeof(LNode));
        if (!p) {
            return LINKLIST_ERR_ALLOC;
        }

        p->next = (*L)->next;
        (*L)->next = p;
        (*L)->length++;
        scanf("%d", &p->data);
    }

    return LINKLIST_OK;
}

linklist_status createlist_tail(linklist *L, int n) {
    linklist p, r;
    int i;

    r = *L;
    for (i = 0; i < n; i++) {
        p = (linklist)malloc(sizeof(LNode));
        if (!p) {
            return LINKLIST_ERR_ALLOC;
        }

        r->next = p;
        r = p;
        scanf("%d", &p->data);
        (*L)->length++;
    }

    r->next = NULL;
    return LINKLIST_OK;
}

linklist_status insert_list(linklist *L, int position, int value) {
    if (position < 1 || position > (*L)->length + 1) {
        return LINKLIST_ERR_RANGE;
    }

    int i;
    linklist p, s;

    p = *L;
    for (i = 1; i < position; i++) {
        p = p->next;
    }

    s = (linklist)malloc(sizeof(LNode));
    if (!s) {
        return LINKLIST_ERR_ALLOC;
    }

    s->data = value;
    s->next = p->next;
    p->next = s;
    (*L)->length++;
    return LINKLIST_OK;
}

linklist_status delete_list(linklist *L, int position) {
    if (position < 1 || position > (*L)->length) {
        return LINKLIST_ERR_RANGE;
    }

    int i;
    linklist p, q;

    p = *L;
    for (i = 1; i < position; i++) {
        p = p->next;
    }

    q = p->next;
    p->next = q->next;
    free(q);
    (*L)->length--;
    return LINKLIST_OK;
}

linklist_status get_elem(linklist *L, int position, int *value) {
    if (position < 1 || position > (*L)->length) {
        return LINKLIST_ERR_RANGE;
    }

    int i;
    linklist p;

    p = *L;
    for (i = 1; i <= position; i++) {
        p = p->next;
    }

    *value = p->data;
    return LINKLIST_OK;
}
