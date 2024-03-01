#include <stdio.h>

int a, b, c;
int compare1, compare2;

int main()
{
	printf ("과제) 키보드로 3개의 정수를 입력받아 조건 연산자로 최대값을 출력하는 프로그램을 작성하시오.\n\n");
	printf ("키보드로 3개의 정수를 입력하시오.(구분자는 콤마 사용) : ");
	scanf ("%d, %d, %d", &a, &b, &c);
	printf ("키보드로 입력한 3개의 정수는 %d,%d,%d이며\n", a, b, c);
	
	compare1 = (a > b) ? a : b;
	compare2 = (compare1 > c) ? compare1 : c;

	printf ("그중에서 최대값은 %d 입니다.\n", compare2);
}