#include<stdio.h>
#include<string.h>
// int main()
// {
//     char C[1000];
//     int lenth;
//     while (fgets(C, 1000, stdin) != NULL) {
//         lenth = strlen(C);
//         for( int i=lenth - 1; i >= 0; i--) {
//             printf("%c", C[i]);
//         }
//     }

//     return 0;
// }

// 根据空格 翻转字符串
int main()
{
    char C[1000], *p;
    int lenth;
    while (fgets(C, 1000, stdin) != NULL) {
        while(p = strrchr(C, ' ')) {
            printf("%s ",p+1);
            *p = '\0';
        }
        printf("%s",C);
    }

    return 0;
}