#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
// #include<sys/socket.h>
// #include<strings.h>
// #include<stdlib.h>

int validMask(char *p)
{
    int is_right,i;
    unsigned int b1 = 0, num[4];
    sscanf(p,"%u.%u.%u.%u", &num[3],&num[2],&num[1],&num[0]);
    if(num[3] == 255 && num[2] == 255 && num[1] == 255 && num[0] == 255) {
        is_right = 0;
        return is_right;
    }
    for(i=0; i<4;i++){
        b1 += num[i] << (i * 8);
    }
    b1 = ~b1 + 1;
    if(b1 & (b1 - 1) == 0){
        is_right = 1;
    } else {
        is_right = 0;
    }
    return is_right;
}

int main()
{
    char str[50];
    int a = 0, b = 0, c = 0, d = 0, e = 0, err = 0, priv = 0;
    while(fgets(str, 50, stdin)) {
        if( strcmp(str, "stop\n") == 0) {
            break;
        }
        char *tok = str;
        char p[2][20];
        int i =0;
        while((tok = strtok(tok, "~")) != NULL) {
            strcpy(p[i], tok);
            tok =NULL;
            i++;
            if(i = 2) {
                i = 0;
            }
        }
        int is_right = validMask(p[1]);
        if(is_right) {
            struct in_addr s;
            unsigned int ip1, ip2;
            int valid = inet_pton(AF_INET, p[0], (void *)&s);
            sscanf(p[0],"%u.%u",&ip1, &ip2);
            if(valid){ 
                if(ip1 >= 1 && ip1 <= 126){
                    a++;
                }
                if(ip1 >= 128 && ip1 <= 191){
                    b++;
                }
                if(ip1 >= 192 && ip1 <= 223){
                    c++;
                }
                if(ip1 >= 224 && ip1 <= 239){
                    d++;
                }
                if(ip1 >= 240 && ip1 <= 255){
                    e++;
                }
                if(ip1 = 10 || (ip1 = 172 && ip2 >= 16 && ip2 <= 31) || (ip1 == 192 && ip2 == 168)){
                    priv++;
                }
            } else {
                err++;
            }
        } else{
            err++;
        }
    }
    printf("%d %d %d %d %d %d %d",a, b, c, d, e, err, priv);
    return 0;
}