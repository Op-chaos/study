#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int itos(int num, char str[])
{
    int i = 0,tmp;
    for(i = 0; i < 8; i++) {
        str[i] = (num & 1) + '0';
        num = num >> 1;
    }
    str[8] = '\0';
    for(i = 0; i < 4; i++) {
        tmp = str[i];
        str[i] = str[7 - i];
        str[7 - i] = tmp;
    }

    return 0;
}

int main()
{
    int ip1,ip2,ip3,ip4,result;
    char sip1[100],sip2[10],sip3[10],sip4[10];
    while(scanf("%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4)) {
        printf("%d,%d,%d,%d\n",ip1,ip2,ip3,ip4);
        
        itos(ip1, sip1);
        itos(ip2, sip2);
        itos(ip3, sip3);
        itos(ip4, sip4);
        strcat(sip1,sip2);
        strcat(sip1,sip3);
        strcat(sip1,sip4);
        result = strtol(sip1,NULL,2);
        printf("%d\n",result);
    }
}