#include <stdio.h>

int main()
{
	int count = 0;
	int dap = 80;
	int na = 0;

	printf("���ڸ� ������ �����Դϴ�.\n");

	while ( 1 )
	{
		printf(" > ���ڸ� �Է����ּ��� : ");
		scanf("%d", &na);

		if ( na > dap )
		{
			printf("���亸�� Ů�ϴ�.\n");
			count++;
			continue;
		}

		else if ( na < dap )
		{
			printf("���亸�� �۽��ϴ�.\n");
			count++;
			continue;
		}

		else
		{
			printf("�����Դϴ�!!!\n");
			count++;
			break;
		}
	}

	printf("\n������ ���߼̽��ϴ�!\n�õ� Ƚ���� %d ���Դϴ�.\n������ %d �����ϴ�!!", count, dap);

}