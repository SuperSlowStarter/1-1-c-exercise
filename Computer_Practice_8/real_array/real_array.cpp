#include <stdio.h>

int main()
{
	char text[10];

	int i = 0;
	int j = 0;

	printf("문자를 10번 입력받겠습니다.\n");

	printf("\n");

	for ( i = 0; i <= 9; i++)
	{
		printf("%2d 번째 입력 : ", i + 1);
		scanf(" %c", &text[i]);
	}

	printf("\n");

	for ( j = 9; j >= 0; j--)
	{
		printf("%2d 번째 문자는 %c 입니다.\n", j+1, text[j]);
	}
}