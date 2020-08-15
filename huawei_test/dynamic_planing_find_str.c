#include<stdio.h>
#include<string.h>

int find_str(char shart_s[],char long_s[],char out[])
{
    int length1,length2;
    int i,j,start,flag=0;
    char tmp[1000];
    length1 = strlen(shart_s);
    length2 = strlen(long_s);
    // printf("%d %d\n",length1,length2);

    for(i=length1;i>0;i--){
        for (start = 0;start<=length1-i;start++){
            // printf("%d %d $",i,start);
            char tmp[1000];
            for(j=0;j<i;j++){
                tmp[j] = shart_s[j+start];
            }
            tmp[j] = '\0';
            // printf("%s\n",tmp);
            if(strstr(long_s,tmp)!=NULL){
                printf("%s\n",tmp);
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    return 0;
}

int main()
{
    char str1[1000],str2[1000],out[1000];
    int length1,length2;
    while(fgets(str1,1000,stdin)){
        fgets(str2,1000,stdin);
        length1 = strlen(str1);
        length2 = strlen(str2);
        str1[length1-1] = '\0';
        str2[length2-1] = '\0';
        if (length1 > length2){
            find_str(str2,str1,out);
        } else {
            find_str(str1,str2,out);
        }
    }
}