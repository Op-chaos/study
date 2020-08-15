#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char a[100],c[10];
    double b;
    scanf("%s",a);
    b = strtol(a,NULL,10);
    c = a[2:6];
    printf("%s %lf",a,b);
}

