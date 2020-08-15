#include<stdio.h>
#include<string.h>
int main()
{
    int p11,p12,p13,p14,p21,p22,p23,p24,p31,p32,p33,p34;
    while(scanf("%d.%d.%d.%d %d.%d.%d.%d %d.%d.%d.%d",&p11,&p12,&p13,&p14,&p21,&p22,&p23,&p24,&p31,&p32,&p33,&p34)) {
        printf("%d.%d.%d.%d %d.%d.%d.%d %d.%d.%d.%d",p11,p12,p13,p14,p21,p22,p23,p24,p31,p32,p33,p34);
    }
}