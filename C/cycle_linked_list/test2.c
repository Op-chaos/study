#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int value;
	struct _node *next;
} Node;

typedef struct _list{
	Node *head;
} List;        // 专门定义了一个Node类型的指针

Node *creaList(List* pList,int n);
void print(List *pList);

int main()
{
	List list;            // 定义了变量list，list的成员head存放的是地址变量
	int number;
    list.head = NULL;     // 刚开始链表list的成员head为空
    do{
		scanf("%d",&number);
		if(number !=-1){
			list.head = creaList(&list, number);
		}
	} while(number !=-1);
	// print all data in linked-list
	print(&list);

	return 0;
}

Node *creaList(List* pList,int number)
{
	/*
	pList: 是一个List型指针
	number：最新的一个数 */
    Node *pL=NULL;
    int i;
	int n=2;                          // 设置要存的数据长度
    Node *last = pList->head;
	// init linked list
    if(!pList->head)
    {
        for(i=0;i<1;i++)
        {
            Node *p = (Node*)malloc(sizeof(Node));
            p->value = 0;
            p->next = NULL;
            // find the last
            if(last){
                while (last->next){
                    last = last->next;
                    }
                last->next = p;
            } else{
                pList->head = p;
            }
        }
    }
	// update linked list
    Node *q = pList->head;
    pList->head = q->next;
	q->value = number;
	q->next = NULL;
	if(last){
		while (last->next){
			last = last->next;
			}
		last->next = q;
	} else{
		pList->head = q;
	}

    return pList->head;
}

// output all data in the linked-list
void print(List *pList)
{
	Node *p;
	for (p=pList->head; p; p = p->next) {
		printf("%d\t",p->value);
	}
	printf("\n");
}

