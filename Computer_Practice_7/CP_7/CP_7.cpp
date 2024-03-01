#include <stdio.h>

int main()
{
	int count = 0;
	int dap = 80;
	int na = 0;

	printf("숫자를 맞히는 게임입니다.\n");

	while ( 1 )
	{
		printf(" > 숫자를 입력해주세요 : ");
		scanf("%d", &na);

		if ( na > dap )
		{
			printf("정답보다 큽니다.\n");
			count++;
			continue;
		}

		else if ( na < dap )
		{
			printf("정답보다 작습니다.\n");
			count++;
			continue;
		}

		else
		{
			printf("정답입니다!!!\n");
			count++;
			break;
		}
	}

	printf("\n정답을 맞추셨습니다!\n시도 횟수는 %d 번입니다.\n정답은 %d 였습니다!!", count, dap);

}