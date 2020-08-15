#include<stdio.h>
#include<string.h>
// 26个字母制作蜜月

int main()
{
    char encryption[100], key[100], key_out[100],decoder[30];
    int i,j,cnt=0,length;
    while(fgets(encryption,100,stdin) && fgets(key,100,stdin)){
        length = strlen(encryption);
        encryption[length - 1] = '\0';
        length = strlen(key);
        key[length - 1] = '\0';
        for(i= 0;i<strlen(encryption);i++){
            for(j= 0;j<cnt;j++){
                if (encryption[i] >= 'A' && encryption[i] <= 'Z') {
                    encryption[i] = encryption[i] - 'A' + 'a';
                }
                if (encryption[i] == decoder[j]) {
                    break;
                }
            }
            if (cnt==j){
                if (encryption[i] >= 'A' && encryption[i] <= 'Z') {
                    encryption[i] = encryption[i] - 'A' + 'a';
                }
                decoder[cnt] = encryption[i];
                cnt++;
            }
        }
        for(i= 0;i<26;i++){
            for(j= 0;j<cnt;j++){
                if ('a'+ i == decoder[j]) {
                    break;
                }
            }
            if (cnt==j){
                char c[2] = {'a'+ i};
                strcat(decoder, c);
                cnt++;
            }
        }
        decoder[cnt] = '\0';
        // printf("%s",decoder);
        for(i=0;i<strlen(key);i++){
            if (key[i] >= 'A' && key[i] <= 'Z'){
                printf("%c",decoder[key[i] - 'A'] - 'a' + 'A');
            } else if (key[i] >= 'a' && key[i] <= 'z'){
                printf("%c",decoder[key[i] - 'a']);
            } else {
                printf("%c", key[i]);
            }
        }
    }
    return 0;
}