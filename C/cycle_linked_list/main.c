#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int value;
	struct _node *next;
} Node;

typedef struct _list{
	Node *head;
} List;        // 专门定义了一个Node类型的指针

Node* add(List* pList, int number);
void print(List *pList);

int main()
{
	List list;            // 定义了变量list，list的成员head存放的是地址变量 
	int number;
	list.head = NULL;     // 刚开始链表list的成员head为空
	do{
		scanf("%d",&number);
		if(number !=-1){
			list.head = add(&list, number);    // add 返回的是Node类型的指针 
		}
	} while(number !=-1);
	// print all data in linked-list
	print(&list);
	// find certain number
	printf("input the dta that you want to find:\n");
	scanf("%d",&number);
	Node *p;                     // 定义一个Node型指针，便于搜索
	int isFound = 0;
	for (p=list.head; p; p=p->next){
		if( p->value == number){
			printf("find:%d\n",number);
			isFound = 1;
			break;
		}
	}
	if(!isFound){
		printf("no found\n");
	}

	// delete certain number
	printf("input the dta that you want to delete:\n");
	scanf("%d",&number);
	Node *q;
	// q is ahead,p is next
	for (q= NULL, p=list.head; p; q=p,p=p->next){
		if( p->value == number){
			if(q){
				printf("find:%d,and delete it\n",number);
				q->next = p->next;
			}else{
				list.head = p->next;   // when q is fist one
			}

			free(p->next);
			break;
		}
	}
	
	print(&list);

	// delete all linked-list
	printf("delete all data\n");
	for(p=list.head; p; p=q){
		q = p->next;
		free(p);
	}
	return 0;
}
// add the data to linked-list
Node* add(List* pList, int number)
{
	// add to lined-list   创建一个Node类型的内存空间，并存上数 ，形成一个节点 
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	// find the last
	Node *last = pList->head;   // 定义了一个 Node 型指针 ，专门用来存最后一个节点的地址 
	if(last){
		while (last->next){     // 第一次满足if条件时，while不满足 
			last = last->next;  // 3、更新last指向，last指向最新一个节点，所以是上一节点的next 
			}
		last->next = p;         // 2、刚形成那一个节点的地址赋给最后一节点存地址的next 
	} else{
		pList->head = p;        // 1、如果是第一个Node ，直接把刚形成的那一节点的地址赋给头地址 
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

