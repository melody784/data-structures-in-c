#include "sqlist.h"
#include <stdlib.h>
#include <stdio.h>

//本文件用于复习C语言数据结构的代码
//第一节顺序表

//定义一个顺序表的初始化函数
sqlist_status init_sequential_list(sequential_list *L){
    if(L==NULL){
        return SQLIST_ERR_NULL;
    }
    L->data = (ElemType *)malloc(sizeof(ElemType)*100);//分配100个元素的存储空间
    if(L->data==NULL){
        return SQLIST_ERR_ALLOC;
    }
    L->length = 0;//初始化长度为0
    L->list_size = 100;//初始化容量为100
    return SQLIST_OK;
}
//定义一个顺序表的插入函数
sqlist_status insert_sequential_list(sequential_list *L, int position, ElemType value){
    if(L==NULL||L->data==NULL){
        return SQLIST_ERR_NULL;
    }
    //判断插入位置是否合理
    if (position <1||position >L->length+1){
        return SQLIST_ERR_RANGE;
    }
    else {
        //判断顺序表是否已满
        if(L->length>=L->list_size){
            //顺序表已满，重新分配内存
            //先使用临时指针接收原来的数据指针
            ElemType *temp=(ElemType *) realloc(L->data,sizeof(ElemType) *(L->list_size+10));//每次增加10个元素的存储空间
            if(temp==NULL){
                return SQLIST_ERR_ALLOC;
            }
            else {
            L->data=temp;//将新的数据指针赋值给顺序表的data
            L->list_size+=10;//更新顺序表的容量
            }
        }
        int i=L->length-1;//从最后一个元素开始向前移动
        while(i>=position-1){
            L->data[i+1]=L->data[i];//将元素向后移动一位
            i--;
        }
        L->data[position-1]=value;//将新元素插入到指定位置
        L->length++;//顺序表长度加1
    }
    return SQLIST_OK;
}
//定义一个顺序表的删除函数
sqlist_status delete_sequential_list(sequential_list *L,int position,ElemType *value){
    if(L==NULL||L->data==NULL||value==NULL){
        return SQLIST_ERR_NULL;
    }
    //判断删除位置是否合理
     if (position <1||position >L->length){
        return SQLIST_ERR_RANGE;
    }
        int i=position-1;//将删除位置转换为数组下标
        *value=L->data[i];//将删除的元素值赋值给value
        while(i<L->length-1){
            L->data[i]=L->data[i+1];//将元素向前位移一位
            i++;
        }
        L->length--;//顺序表长度减1
        return SQLIST_OK;
}
//定义一个顺序表的修改函数
sqlist_status update_sequential_list(sequential_list *L,int position,ElemType value,ElemType *old_value){
    if(L==NULL||L->data==NULL||old_value==NULL){
        return SQLIST_ERR_NULL;
    }
    //判断修改位置是否合理
    if (position <1||position >L->length){
        return SQLIST_ERR_RANGE;
    }
        int i=position-1;//将修改位置转换为数组下标
        *old_value=L->data[i];//将原来的元素值赋值给old_value
        L->data[i]=value;//将新元素值赋值给顺序表的指定位置
        return SQLIST_OK;
}
//定义一个顺序表的按值查找函数
sqlist_status search_sequential_list(sequential_list *L,ElemType value,int *position){
    if(L==NULL||L->data==NULL||position==NULL){
        return SQLIST_ERR_NULL;
    }
    int i=0;
    while(i<L->length){
        if(L->data[i]==value){//如果找到该元素，返回其位置
            *position=i+1;
            return SQLIST_OK;
        }
        i++;
    }
    return SQLIST_ERR_NOT_FOUND;
}
//定义一个顺序表的按位置查找函数
sqlist_status get_sequential_list(sequential_list *L,int position,ElemType *value){
    if(L==NULL||L->data==NULL||value==NULL){
        return SQLIST_ERR_NULL;
    }
    //判断查找位置是否合理
    if (position <1||position >L->length){
        return SQLIST_ERR_RANGE;
    }
        int i=position-1;//将查找位置转换为数组下标
        *value=L->data[i];//返回顺序表的指定位置的元素值
        return SQLIST_OK;
}
//定义一个顺序表的打印函数
void print_sequential_list(sequential_list *L){
    if(L==NULL||L->data==NULL){
        return;
    }
    int i=0;
    while(i<L->length){
        printf("%-8d",L->data[i]);//打印顺序表的元素值
        i++;
    }
    printf("\n");//打印换行符
}
