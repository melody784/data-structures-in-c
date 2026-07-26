#include "linklist.h"
int main() {
    linklist L;
    int n, position, value, result;

    // 初始化链表
    InitList(&L);

    // 创建链表
    printf("请输入链表的长度: ");
    scanf("%d", &n);
    createlist_tail(&L, n);

    // 打印链表
    print_list(&L);

    // 插入元素
    printf("请输入插入位置和元素值: ");
    scanf("%d %d", &position, &value);
    result = insert_list(&L, position, value);
    if (result == LINKLIST_OK) {
        printf("插入成功!\n");
        print_list(&L);
    } else {
        printf("插入失败，错误码: %d\n", result);
    }

    // 删除元素
    printf("请输入删除位置: ");
    scanf("%d", &position);
    result = delete_list(&L, position);
    if (result == LINKLIST_OK) {
        printf("删除成功!\n");
        print_list(&L);
    } else {
        printf("删除失败，错误码: %d\n", result);
    }

    // 获取元素
    printf("请输入获取位置: ");
    scanf("%d", &position);
    result = get_elem(&L, position, &value);
    if (result == LINKLIST_OK) {
        printf("获取成功! 位置 %d 的元素值为: %d\n", position, value);
    } else {
        printf("获取失败，错误码: %d\n", result);
    }
}