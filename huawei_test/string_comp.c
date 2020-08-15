#include<stdio.h>
#include<string.h>

typedef struct _string
{
    char c[100];
} string_table;

int main()
{
    string_table s[100], stem;
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++){
            scanf("%s", s[i].c);
            // fgets(s[i].c, 100, stdin);
        }
        printf("\n");
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++) {
                if(strcmp(s[i].c, s[j].c) > 0) {
                    stem = s[i];
                    s[i] = s[j];
                    s[j] = stem;
                }
            }
        }
        for(int i = 0; i < n; i++){
            printf("%s\n",s[i].c);
        }
        printf("\n");
    }
}