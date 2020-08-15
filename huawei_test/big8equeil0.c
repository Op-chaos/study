#include<stdio.h>
#include<string.h>
// 按照8个字符一行，打印字符，不足填充0
int main()
{
    int length_c, zero_num, i;
    char c1[100]={0};
    char c2[108]={0};
    while(fgets(c1,100,stdin) != NULL) {
        length_c = strlen(c1);
        if ((length_c-1) % 8 != 0)
        {
            zero_num = 8 - (length_c-1) % 8;
        } else {
            zero_num = 0;
        }
        memcpy(c2, c1, length_c);
        for(i=0; i<zero_num; i++){
            c2[length_c-1 + i] = '0';
        }
        for(i=0; i<length_c -1 + zero_num; i++) {
            printf("%c",c2[i]);
            if((i+1)%8 == 0){
                printf("\n");
            }
        }
    }
    return 0;
}