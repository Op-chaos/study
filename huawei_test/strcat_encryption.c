#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int itoa(int num, char str[])
{
    for (int i = 0; i< 4; i++)
    {
        str[i] = (num & 1) + '0';
        num = num >> 1;
    }
    return 0;
}

int main()
{
    char str1[101],str2[101];
    int len_in = 0, len_out = 0;
    int i,j,cnt = 0, tmp10,tmp16,tmp;
    char tmpchr[5], tmpchr2[5],tmp2[5];
    char ji[101],ou[101];
    while(scanf("%s %s",str1,str2))
    {
        strcat(str1,str2);
        printf("%s\n",str1);
        len_in = strlen(str1);
        for (i = 0; i < len_in; i++) {
            if ((str1[i] <= '9' && str1[i] >= '0') || (str1[i] <= 'F' && str1[i] >= 'A') || (str1[i] <= 'f' && str1[i] >= 'a'))
            {
                if (i % 2 == 0) {
                    ou[i / 2] = str1[i];
                } else {
                    ji[i / 2] = str1[i];
                }
            }
        }
        for(i = 0; i < strlen(ou); i++){
            char s;
            for(j = i+1; j<strlen(ou); j++){
                if (ou[i]>ou[j]){
                    s = ou[i];
                    ou[i] = ou[j];
                    ou[j] = s;
                }
            }
        }
        for(i = 0; i < strlen(ji); i++){
            char s;
            for(j = i+1; j<strlen(ji); j++){
                if (ji[i]>ji[j]){
                    s = ji[i];
                    ji[i] = ji[j];
                    ji[j] = s;
                }
            }
        }
        strcat(ou,ji);
        printf("%s\n",ou);
        for (i = 0; i < len_in; i++) {
            if ('0' <= ou[i] && ou[i] <= '9') {
                tmp10 = (int)(ou[i] - '0');
                cnt = 0;
                itoa(tmp10, tmp2);
                for(j = 0; j < strlen(tmp2); j++) {
                    tmpchr2[cnt] = tmp2[j];
                    cnt++;
                }
                tmp = strtol(tmpchr2, NULL, 2);
                printf("%X", tmp);
            } else if (str1[i] <= 'F' && str1[i] >= 'A') {
                tmp10 = (int)(ou[i] - 'A' + 10);
                itoa(tmp10, tmp2);
                cnt = 0;
                for(j = 0; j < strlen(tmp2); j++) {
                    tmpchr2[cnt] = tmp2[j];
                    cnt++;
                }
                tmp = strtol(tmpchr2, NULL, 2);
                printf("%X", tmp);
            } else if (str1[i] <= 'f' && str1[i] >= 'a') {
                tmp10 = (int)(ou[i] - 'a' + 10);
                itoa(tmp10, tmp2);
                cnt = 0;
                for(j = 0; j < strlen(tmp2); j++) {
                    tmpchr2[cnt] = tmp2[j];
                    cnt++;
                }
                tmp = strtol(tmpchr2, NULL, 2);
                printf("%X", tmp);
            }
        }
    }
}