#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	double value;
	struct _node *next;
} ListNode_t;

typedef struct _list{
	ListNode_t *head;
} List_t;        // 专门定义了一个Node类型的指针

ListNode_t *ListInit(List_t* pList,int size);
ListNode_t* ListUpdate(List_t* pList, double *newdata);
void print(List_t *pList);

List_t HV_Lat_List;

// 被调用才会运行一次
int cycle(double newdata)
{
	int rc = 0;
	List_t list;            // 定义了变量list，list的成员head存放的是地址变量
	// list.head = NULL;

	if(HV_Lat_List.head == NULL)
	{
		// list.head = NULL;     // 刚开始链表list的成员head为空     关键
    	HV_Lat_List.head = ListInit(&list, 1);
	}
	HV_Lat_List.head = ListUpdate(&HV_Lat_List, &newdata);
	// print all data in linked-list
	print(&HV_Lat_List);
	return 0;
}

// 进程，一直运行着的
int main()
{
	double  newdata;
    do{
		scanf("%lf",&newdata);
		if(newdata !=-1){
			cycle(newdata);    // add 返回的是Node类型的指针
		}
	} while(newdata !=-1);
	print(&HV_Lat_List);
	printf("program is over\n");

	return 0;
}

ListNode_t *ListInit(List_t* pList,int size)
{
	// if (size <= 0) {
    //     D_ERROR("FIFO size error: size = %d", size);
    // }
    int i;
	pList->head = NULL;     // 很关键
    for(i=0;i<size;i++)
    {
        ListNode_t *p = (ListNode_t*)malloc(sizeof(ListNode_t));
        p->value = 0;
        p->next = NULL;
        // find the last
        ListNode_t *last = pList->head;
        if(last){
            while (last->next){            // 如果 pList->head 不是空（初始可能是野指针），会造成这步错误
                last = last->next;
                }
            last->next = p;
        } else{
            pList->head = p;
        }
    }
    return pList->head;
}

ListNode_t* ListUpdate(List_t* pList, double *newdata)
{
	// add to lined-list
	ListNode_t *p = pList->head;
    pList->head = p->next;
	p->value =  *newdata;
	p->next = NULL;
	// find the last
	ListNode_t *last = pList->head;
	if(last){
		while (last->next){
			last = last->next;
			}
		last->next = p;
	} else{
		pList->head = p;
	}
	return pList->head;
}
// output all data in the linked-list
void print(List_t *pList)
{
	ListNode_t *p;
	for (p=pList->head; p; p = p->next) {
		printf("%lf\t",p->value);
	}
	printf("链表数据已经全部输出");
	printf("\n");
}


