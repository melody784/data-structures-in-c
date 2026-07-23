#include "sqlist.h"

/* 测试数据宏定义 */
#define SAMPLE_INIT   {10,20,30,40,50,60,70,80,90}   /* 初始样例数据 */
#define POS_INSERT_NORMAL   5                        /* 插入测试：中间位置 */
#define VAL_INSERT_NORMAL   55                       /* 插入测试：中间插入值 */
#define POS_INSERT_FIRST    1                        /* 插入测试：首位置 */
#define VAL_INSERT_FIRST    5                        /* 插入测试：首位置插入值 */
#define VAL_INSERT_LAST     100                      /* 插入测试：尾后插入值 */
#define POS_INVALID         0                        /* 越界测试：位置0 */
#define VAL_INVALID         999                      /* 越界测试：非法插入值 */

#define POS_DELETE_NORMAL   6                        /* 删除测试：中间位置 */
#define POS_DELETE_FIRST    1                        /* 删除测试：首位置 */

#define POS_UPDATE_NORMAL   3                        /* 修改测试：中间位置 */
#define VAL_UPDATE_NORMAL   200                      /* 修改测试：中间修改值 */
#define VAL_UPDATE_FIRST    300                      /* 修改测试：首位置修改值 */
#define VAL_UPDATE_LAST     300                      /* 修改测试：末位置修改值 */
#define VAL_UPDATE_INVALID  400                      /* 越界测试：非法修改值 */

#define VAL_SEARCH_MISSED   100                      /* 查找测试：不存在的值（已被删除） */
#define VAL_SEARCH_DELETED  55                       /* 查找测试：不存在的值（已被删除） */


int main(){
    sequential_list L;//定义一个顺序表变量
    sequential_list *L_ptr=&L;//定义一个顺序表指针变量
    sqlist_status status=init_sequential_list(L_ptr);//初始化顺序表
    sqlist_status expected=SQLIST_OK;
    int index=0;
    int position=0;
    ElemType deleted_value=0;
    ElemType old_value=0;
    ElemType got_value=0;
    ElemType sample_data[]=SAMPLE_INIT;
    int sample_count=(int)(sizeof(sample_data)/sizeof(sample_data[0]));

    printf("[Init] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    if(status!=SQLIST_OK){
        return 1;
    }

    for(index=0;index<sample_count;index++){
        status=insert_sequential_list(L_ptr,L_ptr->length+1,sample_data[index]);//通过插入函数依次构造初始顺序表
        expected=SQLIST_OK;
        if(status!=expected){
            printf("[Load sample %d] expected=%d got=%d FAIL\n",index+1,expected,status);
            return 1;
        }
    }

    printf("Initial list:\n");
    print_sequential_list(L_ptr);//打印初始顺序表

    status=insert_sequential_list(L_ptr,POS_INSERT_NORMAL,VAL_INSERT_NORMAL);//正常测试：在中间插入元素
    expected=SQLIST_OK;
    printf("[Insert normal] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    printf("After normal insert:\n");
    print_sequential_list(L_ptr);

    status=insert_sequential_list(L_ptr,POS_INSERT_FIRST,VAL_INSERT_FIRST);//边界测试：在首位置插入元素
    expected=SQLIST_OK;
    printf("[Insert first] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    printf("After insert at position 1:\n");
    print_sequential_list(L_ptr);

    status=insert_sequential_list(L_ptr,L_ptr->length+1,VAL_INSERT_LAST);//边界测试：在尾后位置插入元素
    expected=SQLIST_OK;
    printf("[Insert last+1] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    printf("After insert at last+1:\n");
    print_sequential_list(L_ptr);

    status=insert_sequential_list(L_ptr,POS_INVALID,VAL_INVALID);//越界测试：非法位置
    expected=SQLIST_ERR_RANGE;
    printf("[Insert invalid 0] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");

    status=insert_sequential_list(L_ptr,L_ptr->length+2,VAL_INVALID);//越界测试：非法位置
    expected=SQLIST_ERR_RANGE;
    printf("[Insert invalid length+2] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");

    status=delete_sequential_list(L_ptr,POS_DELETE_NORMAL,&deleted_value);//正常测试：删除中间元素
    expected=SQLIST_OK;
    printf("[Delete normal] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    printf("After normal delete:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the deleted element is %d\n",deleted_value);//打印删除的元素值

    status=delete_sequential_list(L_ptr,POS_DELETE_FIRST,&deleted_value);//边界测试：删除首元素
    expected=SQLIST_OK;
    printf("[Delete first] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    printf("After delete at position 1:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the deleted element is %d\n",deleted_value);//打印删除的元素值

    status=delete_sequential_list(L_ptr,L_ptr->length,&deleted_value);//边界测试：删除最后一个元素
    expected=SQLIST_OK;
    printf("[Delete last] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    printf("After delete at last position:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the deleted element is %d\n",deleted_value);//打印删除的元素值

    status=delete_sequential_list(L_ptr,POS_INVALID,&deleted_value);//越界测试：非法位置
    expected=SQLIST_ERR_RANGE;
    printf("[Delete invalid 0] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");

    status=delete_sequential_list(L_ptr,L_ptr->length+1,&deleted_value);//越界测试：非法位置
    expected=SQLIST_ERR_RANGE;
    printf("[Delete invalid length+1] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");

    status=update_sequential_list(L_ptr,POS_UPDATE_NORMAL,VAL_UPDATE_NORMAL,&old_value);//正常测试：修改中间元素
    expected=SQLIST_OK;
    printf("[Update normal] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    printf("After normal update:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the old element is %d\n",old_value);//打印原来的元素值

    status=update_sequential_list(L_ptr,POS_INSERT_FIRST,VAL_UPDATE_FIRST,&old_value);//边界测试：修改首元素
    expected=SQLIST_OK;
    printf("[Update first] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    printf("After update at position 1:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the old element is %d\n",old_value);//打印原来的元素值

    status=update_sequential_list(L_ptr,L_ptr->length,VAL_UPDATE_LAST,&old_value);//边界测试：修改最后一个元素
    expected=SQLIST_OK;
    printf("[Update last] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");
    printf("After update at last position:\n");
    print_sequential_list(L_ptr);
    printf("The numericai value of the old element is %d\n",old_value);//打印原来的元素值

    status=update_sequential_list(L_ptr,POS_INVALID,VAL_UPDATE_INVALID,&old_value);//越界测试：非法位置
    expected=SQLIST_ERR_RANGE;
    printf("[Update invalid 0] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");

    status=update_sequential_list(L_ptr,L_ptr->length+1,VAL_UPDATE_INVALID,&old_value);//越界测试：非法位置
    expected=SQLIST_ERR_RANGE;
    printf("[Update invalid length+1] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");

    status=search_sequential_list(L_ptr,VAL_SEARCH_MISSED,&position);//查找顺序表中是否有元素100
    expected=SQLIST_ERR_NOT_FOUND;
    printf("[Search 100] expected=%d got=%d position=%d %s\n",expected,status,position,(status==expected)?"PASS":"FAIL");

    status=search_sequential_list(L_ptr,VAL_SEARCH_DELETED,&position);//查找顺序表中是否有元素55
    expected=SQLIST_ERR_NOT_FOUND;
    printf("[Search 55] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");

    status=get_sequential_list(L_ptr,POS_INSERT_FIRST,&got_value);//边界测试：获取首位置元素值
    expected=SQLIST_OK;
    printf("[Get first] expected=%d got=%d value=%d %s\n",expected,status,got_value,(status==expected)?"PASS":"FAIL");

    status=get_sequential_list(L_ptr,L_ptr->length,&got_value);//边界测试：获取最后一个位置元素值
    expected=SQLIST_OK;
    printf("[Get last] expected=%d got=%d value=%d %s\n",expected,status,got_value,(status==expected)?"PASS":"FAIL");

    status=get_sequential_list(L_ptr,POS_INVALID,&got_value);//越界测试：非法位置
    expected=SQLIST_ERR_RANGE;
    printf("[Get invalid 0] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");

    status=get_sequential_list(L_ptr,L_ptr->length+1,&got_value);//越界测试：非法位置
    expected=SQLIST_ERR_RANGE;
    printf("[Get invalid length+1] expected=%d got=%d %s\n",expected,status,(status==expected)?"PASS":"FAIL");

    (void)index;
    return 0;
}
