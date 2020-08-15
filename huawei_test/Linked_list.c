#include<stdio.h>
#include<malloc.h>
int main()
{
    typedef struct node_{
        int num;
        struct node_ *next;
    } node;
    typedef struct _list{
        node *head;
    }link_list;
    int i,n,num,fd;
    link_list list;
    node *p;
    while(scanf("%d",&n)){
        for (i =0;i<n;i++){
            scanf("%d",&num);
            if (list.head ==NULL) {
                p = (node *)malloc(sizeof(node));
                //memset(p,0x00,sizeof(node));
                p->num = num;
                list.head = p;
            } else {
                p = (node *)malloc(sizeof(node));
                p->num =num;
                p->next = list.head;
                list.head = p;
            }
        }
        scanf("%d",&fd);
        for(i= 0,p = list.head; i<fd-1;i++){
            p = p->next;
        }
        printf("%d",p->num);
    }
    return 0;
}