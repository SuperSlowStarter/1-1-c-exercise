#include <stdio.h>

int main()
{
	int jumsu, mok;
	char grade;

	printf("\n ���Է¹��� ������ ���� switch ������ �ش� ����� ��� \n");
	printf("========================================================\n");
	printf(" > ������ �Է��Ͻÿ� : ");
	scanf("%d", &jumsu);

	if (jumsu > 100 || jumsu < 0)
	{
		printf("---------------------------------------------------\n");
		printf(" > ������ ��뱸��(0~100)���� �ƴմϴ�! \n");
		printf("���α׷��� �ٽ� �����Ͻʽÿ�!");
		printf("---------------------------------------------------\n");
	}
	else
	{
		mok = jumsu / 10;
		switch (mok)
		{
		case 10:
			grade = 'A';
			break;
		case 9:
			grade = 'B';
			break;
		case 8:
			grade = 'C';
			break;
		case 7:
			grade = 'D';
			break;
		case 6:
			grade = 'E';
			break;
		default:
			grade = 'F';
			break;
		}
		printf("---------------------------------------------------\n");
		printf(" > �� �� : %d �� \n" , jumsu);
		printf(" > �� �� : %c �� \n" , grade);
		printf("---------------------------------------------------\n");
	}
}