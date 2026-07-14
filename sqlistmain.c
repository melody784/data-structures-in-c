#include "sqlist.h"

int main(){
    sequential_list L;//定义一个顺序表变量
    sequential_list *L_ptr=&L;//定义一个顺序表指针变量
    init_sequential_list(L_ptr);//初始化顺序表
    int index=0;
    ElemType deleted_value=0;
    ElemType old_value=0;
    ElemType sample_data[]={10,20,30,40,50,60,70,80,90};
    int sample_count=(int)(sizeof(sample_data)/sizeof(sample_data[0]));

    for(index=0;index<sample_count;index++){
        L_ptr->data[index]=sample_data[index];//使用固定样例数据，便于重复测试
        L_ptr->length++;//顺序表长度加1
    }

    printf("Initial list:\n");
    print_sequential_list(L_ptr);//打印初始顺序表

    insert_sequential_list(L_ptr,5,55);//正常测试：在中间插入元素
    printf("After normal insert:\n");
    print_sequential_list(L_ptr);

    insert_sequential_list(L_ptr,1,5);//边界测试：在首位置插入元素
    printf("After insert at position 1:\n");
    print_sequential_list(L_ptr);

    insert_sequential_list(L_ptr,L_ptr->length+1,100);//边界测试：在尾后位置插入元素
    printf("After insert at last+1:\n");
    print_sequential_list(L_ptr);

    insert_sequential_list(L_ptr,0,999);//越界测试：非法位置
    insert_sequential_list(L_ptr,L_ptr->length+2,999);//越界测试：非法位置

    delete_sequential_list(L_ptr,6,&deleted_value);//正常测试：删除中间元素
    printf("After normal delete:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the deleted element is %d\n",deleted_value);//打印删除的元素值

    delete_sequential_list(L_ptr,1,&deleted_value);//边界测试：删除首元素
    printf("After delete at position 1:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the deleted element is %d\n",deleted_value);//打印删除的元素值

    delete_sequential_list(L_ptr,L_ptr->length,&deleted_value);//边界测试：删除最后一个元素
    printf("After delete at last position:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the deleted element is %d\n",deleted_value);//打印删除的元素值

    delete_sequential_list(L_ptr,0,&deleted_value);//越界测试：非法位置
    delete_sequential_list(L_ptr,L_ptr->length+1,&deleted_value);//越界测试：非法位置

    update_sequential_list(L_ptr,3,200,&old_value);//正常测试：修改中间元素
    printf("After normal update:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the old element is %d\n",old_value);//打印原来的元素值

    update_sequential_list(L_ptr,1,300,&old_value);//边界测试：修改首元素
    printf("After update at position 1:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the old element is %d\n",old_value);//打印原来的元素值

    update_sequential_list(L_ptr,L_ptr->length,300,&old_value);//边界测试：修改最后一个元素
    printf("After update at last position:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the old element is %d\n",old_value);//打印原来的元素值

    update_sequential_list(L_ptr,0,400,&old_value);//越界测试：非法位置
    update_sequential_list(L_ptr,L_ptr->length+1,400,&old_value);//越界测试：非法位置

    search_sequential_list(L_ptr,100);//查找顺序表中是否有元素100
    search_sequential_list(L_ptr,55);//查找顺序表中是否有元素55

    index=get_sequential_list(L_ptr,1);//边界测试：获取首位置元素值
    printf("The numericai value of position 1 is %d\n",index);//打印获取的元素值

    index=get_sequential_list(L_ptr,L_ptr->length);//边界测试：获取最后一个位置元素值
    printf("The numericai value of last position is %d\n",index);//打印获取的元素值

    index=get_sequential_list(L_ptr,0);//越界测试：非法位置
    index=get_sequential_list(L_ptr,L_ptr->length+1);//越界测试：非法位置
    printf("The numericai value of invalid get tests is %d\n",index);
    return 0;
}
