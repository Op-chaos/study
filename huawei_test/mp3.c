#include<stdio.h>
#include<string.h>

int main()
{
    int gb = 1, fist=1;
    int input_len,num,i;
    char action[1000];
    while(scanf("%d\n",&num)) {
        fgets(action,1000,stdin);
        input_len = strlen(action);
        for(i =0;i<input_len;i++) {
            if(action[i] == 'U'){
                if(gb == fist) {
                    gb--;
                    fist--;
                } else {
                    gb--;
                }
                if(gb<1) {
                    gb = num;
                    fist = num - 4 + 1;
                }
            } else if(action[i] == 'D') {
                if(gb == fist + 4 - 1) {
                    gb++;
                    fist++;
                } else {
                    gb++;
                }
                if(gb > num) {
                    gb = 1;
                    fist = 1;
                }
            }
        }
        printf("%d %d %d %d\n",fist,fist+1,fist+2,fist+3);
        printf("%d",gb);
    }
}