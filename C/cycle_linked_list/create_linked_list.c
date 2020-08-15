#include<stdio.h>
#include <stdlib.h>
typedef struct List{
    int data;
    struct List *next;
} List;
List *creaList(int n){
    List *pL=NULL;
    int i;
    for(i=0;i<n;i++) addList(pL);
    return pL;
}
void addList(List *pL){
    List *p=pL;
    /*lookup tail*/
    while(p->next!=NULL){p=p->next;}
    p->next=malloc(sizeof(List));
    /*initialize p->next*/ memset(p->next,0,sizeof(List));
}
int main(){
    List *p;
    p=creaList(13);
    return 0;
}

// int main()
// {
//     printf("hello world");
//     return 0;
// }