#include<stdio.h>
#include<string.h>


int main()
{
	char str[5000] = {0};
	char *s = NULL;
	while(NULL != fgets(str, 5000, stdin))
    {
		s = strrchr(str, ' ');
		if(s = NULL) {
            int len = strlen(str);
			printf("%d", len);
		} else {
            int len = strlen(s + 1);
			printf("%d",len);
		}
    }

    return 0;
}