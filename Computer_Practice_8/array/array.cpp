#include <stdio.h>
#include <conio.h>

long plus(int, int);
long minus(int,int);
long multiple(int,int);
long divide(int, int);

int main()
{
	int num1,num2;
	char op, input;
	long result;

	do
	{
		printf("������ �����ڸ� �Է��ϼ��� > ");
		scanf("%d %c %d", &num1, &op, &num2);

		switch(op)
		{
		case '+':
			result = plus(num1, num2);
			printf("result = %d\n", result);
			break;
		case '-':
			result = minus(num1, num2);
			printf("result = %d\n", result);
			break;
		case '*':
			result = multiple(num1, num2);
			printf("result = %d\n", result);
			break;
		case '/':
			result = divide(num1, num2);
			printf("result = %d\n", result);
			break;
		default:
			printf("������� �ʴ� ���Դϴ�.\n");
			break;
		}
		
		printf("���α׷��� ��� �����ұ��?? (Y/N)\n");
		input = getch();
	}while(input == 'Y' || input == 'y');
}

long plus (int a, int b)
{
	return(a + b);
}
long minus (int a, int b)
{
	return(a - b);
}
long multiple (int a, int b)
{
	return(a * b);
}
long divide (int a, int b)
{
	return(a / b);
}