#include <stdio.h>
#include <stdlib.h>    // 提供malloc()函数的原型 
#include <string.h>    //提供strcat()函数的原型 
#define TSIZE   45     // 数字的大小 

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
		find = strchr(st, '\n');      // 查找换行符 
		if(find)                          // 如果地址不是NULL 
			*find = '\0';                 // 在此处放置一个空字符 
		else 
			while (getchar() != '\n')
				continue;		         // 处理剩余输入行 
	}
	return ret_val;
}
