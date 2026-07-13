#include <stdlib.h>
#include <stdio.h>

//本文件用于复习C语言数据结构的代码
//第一节顺序表
typedef int ElemType;//定义顺序表元素类型为int
typedef struct{
    ElemType *data;//存储空间基址
    int length;//顺序表的当前长度
    int list_size;//顺序表的当前分配容量
}sequential_list, *sequential_list_ptr;

//定义一个顺序表的初始化函数
void init_sequential_list(sequential_list *L){
    L->data = (ElemType *)malloc(sizeof(int)*100);//分配100个元素的存储空间
    L->length = 0;//初始化长度为0
    L->list_size = 100;//初始化容量为100
    //判断内存分配是否成功
    if(!L->data){
        exit(0);//内存分配失败，退出程序
    }
}
//定义一个顺序表的插入函数
void insert_sequential_list(sequential_list *L, int position, ElemType value){
    //判断插入位置是否合理
    if (position <1||position >L->length+1){
        exit(0);//插入位置不合理，退出程序
    }
    else {
        //判断顺序表是否已满
        if(L->length>=L->list_size){
            //顺序表已满，重新分配内存
            //先使用临时指针接收原来的数据指针
            ElemType *temp=(ElemType *) realloc(L->data,sizeof(ElemType) *(L->list_size+10));//每次增加10个元素的存储空间
            if(temp==NULL){
                exit(0);//内存分配失败，退出程序
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
    return;
}
//定义一个顺序表的删除函数
void delete_sequential_list(sequential_list *L,int position,ElemType *value){
    //判断删除位置是否合理
     if (position <1||position >L->length+1){
        exit(0);}//插入位置不合理，退出程序
        int i=position-1;//将删除位置转换为数组下标
        *value=L->data[i];//将删除的元素值赋值给value
        while(i<L->length-1){
            L->data[i]=L->data[i+1];//将元素向前位移一位
            i++;
        }
        L->length--;//顺序表长度减1
}
//定义一个顺序表的修改函数
void update_sequential_list(sequential_list *L,int position,ElemType value,ElemType *old_value){
    //判断修改位置是否合理
    if (position <1||position >L->length+1){
        exit(0);}//位置不合理，退出程序
        int i=position-1;//将修改位置转换为数组下标
        *old_value=L->data[i];//将原来的元素值赋值给old_value
        L->data[i]=value;//将新元素值赋值给顺序表的指定位置
}
//定义一个顺序表的按值查找函数
void search_sequential_list(sequential_list *L,ElemType value){
    int i=0;
    while(i<L->length){
        if(L->data[i]==value){//如果找到该元素，返回其位置
            printf("The position of the element is %d\n",i+1);
            return;
        }
        i++;
    }
    printf("The element is not found\n");//如果没有找到该元素，打印提示信息
    return;//如果没有找到该元素
}
//定义一个顺序表的按位置查找函数
ElemType get_sequential_list(sequential_list *L,int position){
    //判断查找位置是否合理
    if (position <1||position >L->length+1){
        exit(0);}//位置不合理，退出程序
        int i=position-1;//将查找位置转换为数组下标
        return L->data[i];//返回顺序表的指定位置的元素值
}
void print_sequential_list(sequential_list *L){
    int i=0;
    while(i<L->length){
        printf("%-8d",L->data[i]);//打印顺序表的元素值
        i++;
    }
    printf("\n");//打印换行符
}
int main(){
    sequential_list L;//定义一个顺序表变量
    sequential_list *L_ptr=&L;//定义一个顺序表指针变量
    init_sequential_list(L_ptr);//初始化顺序表
    int i=0;
    for(i=0;i<10;i++){
        scanf("%d",&L_ptr->data[i]);//输入顺序表的元素值
        L_ptr->length++;//顺序表长度加1
    }
    print_sequential_List(L_ptr);//打印顺序表的元素值
    insert_sequential_list(L_ptr,5,100);//在顺序表的第5个位置插入元素100
    print_sequential_List(L_ptr);//打印顺序表的元素值
    delete_sequential_list(L_ptr,8,&i);//删除顺序表的第8个位置的元素，并将其值赋值给i
    print_sequential_List(L_ptr);//打印顺序表的元素值
    printf("The numericai value of the deleted element is %d\n",i);//打印删除的元素值
    update_sequential_list(L_ptr,3,200,&i);//将顺序表的第3个位置的元素修改为200，并将原来的值赋值给i
    print_sequential_list(L_ptr);//打印顺序表的元素值
    printf("The numericai value of the old element is %d\n",i);//打印原来的元素值
    search_sequential_list(L_ptr,100);//查找顺序表中是否有元素100
    i=get_sequential_list(L_ptr,9);//获取顺序表的第9个位置的元素值
    printf("The numericai value of the position is %d\n",i);//打印获取的元素值
    return 0;
}
