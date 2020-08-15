#include<stdio.h>
#include<string.h>

int main()
{
    int length,i,j;
    char str[1000],tmp;
    while(fgets(str,1000,stdin) != NULL) {
        length = strlen(str);
        for(i = 0; i<length; i++) {
            tmp = str[i];
            for (j = i + 1; j < length; j++){
                if(str[i]>str[j]){
                    tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;
                }
            }
        }
        printf("%s",str);
    }
    return 0;
}