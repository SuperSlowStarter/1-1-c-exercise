#include <stdio.h>

int main()
{
	char text[10];

	int i = 0;
	int j = 0;

	printf("���ڸ� 10�� �Է¹ްڽ��ϴ�.\n");

	printf("\n");

	for ( i = 0; i <= 9; i++)
	{
		printf("%2d ��° �Է� : ", i + 1);
		scanf(" %c", &text[i]);
	}

	printf("\n");

	for ( j = 9; j >= 0; j--)
	{
		printf("%2d ��° ���ڴ� %c �Դϴ�.\n", j+1, text[j]);
	}
}