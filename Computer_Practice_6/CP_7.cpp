#include <stdio.h>
int main()
{
   int i, j;
   printf("과제) 다음 결과를 나타내는 프로그램을 중첩된 for문을 이용하여 작성하시오\n");
   for (i = 5; i >= 1; i--)
   {
       for ( j = 1; j <= i; j++)
       {
           printf("%d", j);
        }
     printf("\n");
    }
}