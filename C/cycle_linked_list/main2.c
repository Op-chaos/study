#include <stdio.h>
#include <stdlib.h>    // �ṩmalloc()������ԭ�� 
#include <string.h>    //�ṩstrcat()������ԭ�� 
#define TSIZE   45     // ���ֵĴ�С 

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;     
};
char *s_gets(char * st, int n); 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	struct film *head = NULL;
	struct film *prev, *current;
	char input[TSIZE];
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		printf("%s",input);
	}
	printf("%s",input);
	return 0;
}

char *s_gets(char *st, int n)
{
	char * ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');      // ���һ��з� 
		if(find)                          // �����ַ����NULL 
			*find = '\0';                 // �ڴ˴�����һ�����ַ� 
		else 
			while (getchar() != '\n')
				continue;		         // ����ʣ�������� 
	}
	return ret_val;
}
