#include <stdio.h>

int a, b, c;
int compare1, compare2;

int main()
{
	printf ("����) Ű����� 3���� ������ �Է¹޾� ���� �����ڷ� �ִ밪�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.\n\n");
	printf ("Ű����� 3���� ������ �Է��Ͻÿ�.(�����ڴ� �޸� ���) : ");
	scanf ("%d, %d, %d", &a, &b, &c);
	printf ("Ű����� �Է��� 3���� ������ %d,%d,%d�̸�\n", a, b, c);
	
	compare1 = (a > b) ? a : b;
	compare2 = (compare1 > c) ? compare1 : c;

	printf ("���߿��� �ִ밪�� %d �Դϴ�.\n", compare2);
}