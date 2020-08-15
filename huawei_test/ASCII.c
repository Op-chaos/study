#include<stdio.h>
#include<string.h>
// 统计ASCII个数
int main()
{
    char C[1000],c;
    int n = 0, length;
    while (1)
    {
        fgets(C, 1000, stdin);
        length = strlen(C);
        n = 0;
        for (int i =0; i < length; i++) {
            c = C[i];
            if((int)c >= 0 && (int)c < 128) {
                n++;
            }
        }
        printf("%d\n", n);
    }

    return 0;
}