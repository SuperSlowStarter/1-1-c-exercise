#include <stdio.h>

int main()
{
	char ary [6] = "power";

	printf("��迭�� ����Ͽ� ���ڿ��� ó���ϴ� ���α׷� \n");
	printf("-------------------------------------------\n");

	printf("->���ڿ��� ��� : [%s]\n", ary);
	printf("->���ڿ��� ��� ���� ��� : [%c]\n", ary[2]);

	ary[2] = ary[2] + 1;
	printf("->���ڿ��� ��� : [%s]\n", ary);
	printf("->���ڿ��� ��� ���� ��� : [%c]\n", ary[2]);

	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%c", &ary[2]);
	printf("->���ڿ��� ��� : [%s]\n", ary);
	printf("->���ڿ��� ��� ���� ��� : [%c]\n", ary[2]);
}