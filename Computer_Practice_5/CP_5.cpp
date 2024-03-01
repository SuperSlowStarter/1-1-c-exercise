#include <stdio.h>

int main()
{
	int jumsu, mok;
	char grade;

	printf("\n ■입력받은 점수에 따라 switch 문으로 해당 등급을 출력 \n");
	printf("========================================================\n");
	printf(" > 점수를 입력하시오 : ");
	scanf("%d", &jumsu);

	if (jumsu > 100 || jumsu < 0)
	{
		printf("---------------------------------------------------\n");
		printf(" > 점수의 허용구간(0~100)점이 아닙니다! \n");
		printf("프로그램을 다시 실행하십시오!");
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
		printf(" > 점 수 : %d 점 \n" , jumsu);
		printf(" > 점 수 : %c 점 \n" , grade);
		printf("---------------------------------------------------\n");
	}
}