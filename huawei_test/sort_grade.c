#include<stdio.h>
#include<strings.h>
int main()
{
    typedef struct student{
        char name[100];
        int grade;
    } student;
    int length,i,j,k,num,ismaxtomin,g;
    while(scanf("%d\n",&num)) {
        student students[1000];
        scanf("%d\n",&ismaxtomin);
        for(i =0;i<num;i++){
            scanf("%s %d",students[i].name,&students[i].grade);
        }
        for(i =0;i<num;i++){
            printf("%s %d\n",students[i].name,students[i].grade);
        }
    }
}