#include <stdio.h>

int main()
{
   char get_moji;

   printf("※※※과제 : 다중 if~else 문을 사용하여 영문자, 숫자, 기타 문자를 판별하는 프로그램을 작성하시오.※※※\n\n");
   printf(" >>> 키보드에서 알파벳, 숫자 중 하나만 딱 눌러주세요! : ");
   scanf("%c", &get_moji);
   printf("----------------------------------------------------------\n");
   printf("입력하신 문자는 ");

   if (get_moji >= '0' && get_moji <= '9')
      printf("숫자입니다. 숫자 %c 를 입력하셨습니다.\n", get_moji);
   else if (get_moji >= 'a' && get_moji <= 'z')
      printf("알파벳 소문자입니다. 소문자 %c 를 입력하셨습니다.\n", get_moji);
   else if (get_moji >= 'A' && get_moji <= 'Z')
      printf("알파벳 대문자입니다. 대문자 %c 를 입력하셨습니다.\n", get_moji);
   else
      printf("기타 문자입니다. 다시 입력해 주십시오.\n");

   printf("----------------------------------------------------------\n");
}