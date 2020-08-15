#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node{
	double value;
	struct _node *next;
} ListNode_t;

typedef struct _list{
	ListNode_t *head;
    ListNode_t *tail;
} List_t;        // 专门定义了一个Node类型的指针

int ListInit(List_t* pList,int size);
int ListUpdate(List_t* pList, double *newdata);
int ListFree(List_t* pList);
void print(List_t *pList);

List_t HV_Lat_List;
// memset(HV_Lat_List, 0, sizeof(HV_Lat_List));

// 被调用才会运行一次
int cycle(double newdata)
{
	int rc = 0;

	// memset(HV_Lat_List, 0, sizeof(List_t));
	printf("HV_Lat_List cycle is %p\n", &HV_Lat_List);
	printf("HV_Lat_List.head is %p\n",HV_Lat_List.head);
	if(HV_Lat_List.head == NULL)
	{
		// list.head = NULL;     // 刚开始链表list的成员head为空     关键
    	ListInit(&HV_Lat_List, 5);
	}
	ListUpdate(&HV_Lat_List, &newdata);
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
        printf("the tail = %lf\n", HV_Lat_List.tail->value);
	} while(newdata !=-1);
    ListFree(&HV_Lat_List);
	print(&HV_Lat_List);
	printf("program is over\n");

	return 0;
}

int ListInit(List_t* pList,int size)
{
	// if (size <= 0) {
    //     D_ERROR("FIFO size error: size = %d", size);
    // }
    int i;
	pList->head = NULL;     // 很关键
    pList->tail = NULL;
    for(i=0;i<size;i++)
    {
        ListNode_t *p = (ListNode_t*)malloc(sizeof(ListNode_t));
        p->value = 0;
        p->next = NULL;
        // find the last
        if(pList->tail){
            pList->tail->next = p;
            pList->tail = p;
        } else{
            pList->head = p;
            pList->tail = p;
        }
    }
    return 0;
}

int ListUpdate(List_t* pList, double *newdata)
{
	// add to lined-list
	ListNode_t *p = pList->head;
    pList->head = p->next;
	p->value =  *newdata;
	p->next = NULL;

    pList->tail->next = p;
    pList->tail = p;
	return 0;
}

int ListFree(List_t* pList)
{
	// add to lined-list
	ListNode_t *p, *q;
    for(p = pList->head; p; p=q){
		q = p->next;
		free(p);
	}
    pList->head = NULL;
    pList->tail = NULL;
    printf("free memrey");

	return 0;
}
// output all data in the linked-list
void print(List_t *pList)
{
	ListNode_t *p;
	for (p=pList->head; p; p = p->next) {
		printf("%lf\t",p->value);
	}
	printf("\n");
}


