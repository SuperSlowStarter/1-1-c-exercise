#include <stdio.h>

int main()
{
	char ary [6] = "power";

	printf("■배열을 사용하여 문자열을 처리하는 프로그램 \n");
	printf("-------------------------------------------\n");

	printf("->문자열의 출력 : [%s]\n", ary);
	printf("->문자열의 가운데 문자 출력 : [%c]\n", ary[2]);

	ary[2] = ary[2] + 1;
	printf("->문자열의 출력 : [%s]\n", ary);
	printf("->문자열의 가운데 문자 출력 : [%c]\n", ary[2]);

	printf("문자를 입력하세요 : ");
	scanf("%c", &ary[2]);
	printf("->문자열의 출력 : [%s]\n", ary);
	printf("->문자열의 가운데 문자 출력 : [%c]\n", ary[2]);
}