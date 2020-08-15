/*此程序用以链表实现循环线性表，主函数已作出测试。
若使用可将整数类型替换为指针来建立广义表。
作者：姚帅   未经允许不得转载*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>  //载入分配空间的头文件 

typedef int ElemType;  
typedef struct SeqListTerm{
        ElemType data;
        struct SeqListTerm *next;
        } SeqListTerm;
typedef struct SeqList{
    SeqListTerm *rear ,*Qear;
    int length;
}SeqList;

SeqListTerm* intSeqListTerm();        
SeqList* intList(); //初始化链表，带头指针头指针data域为0 
void tailListAdd(SeqList *T,ElemType e);    //表尾添加一个元素e 
void headListAdd(SeqList *T,ElemType e);
void printall(SeqList *T);  //输出表中所有元素 
int getlength(SeqList* T);  //获得表长度 
ElemType getElem(SeqList *T,int i); //获得表的第i个元素 
int findElem(SeqList *T,ElemType e);    //找到元素e所在的位置 
void listInsert(SeqList *T,int i,ElemType e);   //在i位置后面插入元素e 
void listDelete (SeqList *T,int i); //删除表中第i个元素 
bool empty (SeqList *T);   //检查表是否为空 
void destroyList (SeqList *T);  //销毁表 


int main(){
    SeqList *T =intList();
    //printf("%d",T->Qear->data);
    tailListAdd(T,10);
    tailListAdd(T,11);
    headListAdd(T,13);
    headListAdd(T,14);
    printf("测试用例为4个元素：");
    printall(T);
    listInsert(T,2,15);
    printf("插入元素到第2个位置之后：");
    printall(T);
    listDelete(T,4);
    printf("删除第4个元素:"); 
    printall(T);
    printf("检查链表是否为空:%s\n",empty(T)==false?"FALSE":"TRUE");
    printf("找到元素11的位置:%d\n",findElem(T,11)); 
    printf("找到表中第5个元素:%d\n",getElem(T,5));
    destroyList(T); 
    getchar();
}

//初始化节点 
SeqListTerm* intSeqListTerm(){
    SeqListTerm *p;
    p = (SeqListTerm*)malloc(sizeof(SeqListTerm));  //*分配内存* //  
    p->data =0;
    p->next = NULL;
}

//初始化链表 
SeqList* intList(){
    SeqList* T;
    SeqListTerm* p = intSeqListTerm();   
    T = (SeqList*)malloc(sizeof(SeqList));  //*分配内存* // 
    T->rear = p; //rear表示尾指针 
    T->Qear = p; //Qear表示首指针   
    T->length = 0;
    return T;
}

//表尾添加元素e 
void tailListAdd(SeqList *T,ElemType e){
    SeqListTerm *p = intSeqListTerm();
    p->data = e;
    T->rear->next = p; 
    T->rear = p;
    T->rear->next = T->Qear;
    T->length++;
}

//表头添加元素e
void headListAdd(SeqList *T,ElemType e){
    SeqListTerm *p = intSeqListTerm();
    p->data = e;
    p->next = T->Qear->next;
    T->Qear->next = p; 
    T->length++;
} 

//输出所有元素 
void printall(SeqList *T){
    SeqListTerm *a = T->Qear->next;
    while(a!=T->Qear){
        printf("%d--",a->data);
        a = a->next;
    }
    printf("end\n");
}

 //获得表长   
int getlength(SeqList* T){
    return T->length;
}

//获得第i个元素 
ElemType getElem(SeqList *T,int i){
    int j;
    SeqListTerm *a =T->Qear;
    i = i%T->length;
    if(i == 0){
        return T->rear->data;
    }else{
        for(j=0;j<i;j++){
            a = a->next;
        }
        return a->data;
    }
}

//找到元素e的位置    
int findElem(SeqList *T,ElemType e){
    int i = 1;
    SeqListTerm *a = T->Qear->next;
    while(a!=T->Qear){
        if(a->data != e){
        a = a->next;
        i++;
        }else{
            return i;
        }
    }
    return -1;  //e不在表中时返回-1 
}

//插入元素e 
void listInsert(SeqList *T,int i,ElemType e){
    SeqListTerm *p = intSeqListTerm();
    p->data = e;    //创建e节点 
    SeqListTerm *a = T->Qear;
    int j;
    i = i%T->length;
    if(i==0){
        //在表尾后方插入 
        tailListAdd(T,e);
    }else{
        //在表中插入 
        for(j=0;j<i;j++){
            a =a->next;
            }
            p->next = a->next;
            a->next = p;
            T->length++;
        }
}

//删除位置i的元素 
void listDelete (SeqList *T,int i){
    i = i%T->length;
    if(i == 0){
        i = T->length;
    }
    int j;
    SeqListTerm *a = T->Qear;
        for(j=1;j<i;j++){
            a = a->next;
        }
        a->next = a->next->next;
}

//判断是否为空 
bool empty (SeqList *T){
    if(T->length == 0){
        return true;
    }else{
        return false;
    }
}

//销毁链表 
void destroyList (SeqList *T){
    SeqListTerm *a = T->Qear;
    while(a){
        T->Qear = a->next;
        free(a);
        a = T->Qear;
    }
    free(T);
}
