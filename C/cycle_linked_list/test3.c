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
Node* updatelist(List* pList, int number);
void print(List *pList);

int cycle(int number)
{
	static List list;            // 定义了变量list，list的成员head存放的是地址变量
	list.head = NULL;     // 刚开始链表list的成员head为空
	list.head = creaList(&list, number);
	// print all data in linked-list
	print(&list);
	return 0;
}

int main()
{
	int number;
    do{
		scanf("%d",&number);
		if(number !=-1){
			cycle(number);    // add 返回的是Node类型的指针
		}
	} while(number !=-1);
	printf("program is over\n");

	return 0;
}

Node *creaList(List* pList,int number)
{
    Node *pL=NULL;
    int i;
    Node *last = pList->head;   // 定义了一个 Node 型指针 ，专门用来存链表最后一个节点的地址
    if(!pList->head)
    {
        for(i=0;i<3;i++)
        {
            Node *p = (Node*)malloc(sizeof(Node));
            p->value = 0;
            p->next = NULL;
            // find the last
            if(last){
                while (last->next){     // 第一个node的last不为空，但next为空。第一次满足if条件时，while不满足
                    last = last->next;  // 3、寻找最后一个node，第三次赋值才进入。更新last指向，last指向最新一个节点，所以是上一节点的next
                    }
                last->next = p;         // 2、赋第二个node，刚形成那一个节点的地址赋给最后一节点存地址的next
            } else{
                pList->head = p;        // 1、赋第一个node，如果是第一个 ，直接把刚形成的那一节点的地址赋给头地址
            }
        }
    }

    Node *q = pList->head;
    pList->head = q->next;
	q->value = number;
	q->next = NULL;
	// find the last
	if(last){
		while (last->next){     // 现在的头指针是原来原来的头指针存地址 pList->head = q->next;有可能是空
			last = last->next;
			}
		last->next = q;         // 寻找最后一个node
	} else{
		pList->head = q;        // 只有一个node
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
	printf("链表数据已经全部输出");
	printf("\n");
}

