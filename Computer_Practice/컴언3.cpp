#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"	//헤더들
#include "ctype.h"

#define _CRT_SECURE_NO_WARNINGS
#define CLS system("cls");	//정의된 변수 둘
#define MAX 100

int menu(void);
void enter(void), save(int), load(void), edit(int), del(int), find(int);	//함수들

struct student {	//structures [학생의 정보를 저장할 변수들]
	char name[10];
	char num[11];
	int kor;
	int eng;
	int mat;
	float ave;
	float sum;
	int rank;
	char abc[2];
} cat[MAX], tmp;	//struct 변수명 둘

int top = 0;	//순서 관련 전역 변수

int main(void) {
	int choice = 0;	//선택

	load(); //저장된 정보 불러오기

	while (choice != 5) {
		choice = menu();	//처음에 실행할 메뉴함수 호출

		switch (choice) {	//사용자의 선택에 따라 작동할 switch
			case 1:
				enter();	//enter 호출
				break;
			case 2:
				find(top);	//find 호출 (top을 인수로하여 전달)
				break;
			case 3:
				edit(top);	//edit 호출
				break;
			case 4:
				del(top);	//del 호출
				break;
			case 5:
				exit(1);	//exit 호출 (1을 인수로하여 전달)
				break;
		}
	}
}

int menu(void) {
	int i = 0;

	printf("\n\n");
	printf("		############### 성 적 관 리 프 로 그 램 ###############\n\n");
	printf("		                    1.  입     력\n\n");
	printf("		                    2.  조     회\n\n");
	printf("		                    3.  수     정\n\n");
	printf("		                    4.  삭     제\n\n");
	printf("		                    5.  종     료\n\n");
	printf("		#######################################################\n\n");

	while (i < 1 || i > 5) {
		printf("			>> 원하는 번호를 입력하세요 : ");
		scanf("%d", &i);
		//i = (getche() - 48);
		CLS
		printf("\n");
	}
	return i;
}

void enter(void) {
	int i, found, im1=0, im2=0, change, c;
	char choice ;
	while(im1!=1) {
		do {
			im2 = 0;
			printf("\n			>> 입력할 학번을 입력해주세요 : ");
			scanf("%s", tmp.num);
			change = atoi(tmp.num);
			if(! change) {
				printf("			>> 숫자가 아닙니다.");
				im2=1;
				while(c=getchar() != '\n' && c!=EOF);
			}
		} while(im2);
		/*if(strlen(tmp.num)>10) {
			printf("\n			>> 학번은 최대 10글자입니다. ");
		} else
			im1=1;*/
	}
	found=0;
	for(i=0; i<top; i++) {
		if(!strcmp(tmp.num, cat[i].num)) {
			found=1;
			break;
		}

	}

	if(found) {
		printf("\n			>> 같은 번호의 학번이 존재합니다.");
		printf("\n			>> [Enter]키를 누르면 메인화면으로 이동합니다.");
		getch();
		CLS
		main();
	} else {
		CLS
		printf("\n\n\n			[▶%s◀ 학생의 성적을 입력합니다.]\n\n",&tmp.num);
		strcpy(cat[i].num, tmp.num);
		printf("			>> 학   번 : %s\n\n", cat[i].num);
		printf("			>> 이   름 : ");
		scanf("%s", cat[i].name);
		do {
			im2 = 0;
			printf("\n			>> 국 어 : ");
			if(!scanf("%d", &cat[i].kor)) {
				printf("			>> 숫자가 아닙니다.");
				im2=1;
				while(c=getchar() != '\n' && c!=EOF);
			}
		} while(im2);
		while((cat[i].kor>100)||(cat[i].kor<0)) {
			printf("			---------------------------------------------\n");
			printf("			▶범위값(0~100)이 아닙니다. 다시입력하세요\n");
			printf("			---------------------------------------------\n");
			printf("\n			>> 국 어 : ");
			scanf("%d" , &cat[i].kor);
		}
		do {
			im2 = 0;
			printf("\n			>> 수 학 : ");
			if(!scanf("%d" , &cat[i].mat)) {
				printf("			>> 숫자가 아닙니다.");
				im2=1;
				while(c=getchar() != '\n' && c!=EOF);
			}
		} while(im2);
		while((cat[i].mat>100)||(cat[i].mat<0)) {
			printf("			---------------------------------------------\n");
			printf("			▶범위값(0~100)이 아닙니다. 다시입력하세요\n");
			printf("			---------------------------------------------\n");
			printf("			>> 수 학 : ");
			scanf("%d" , &cat[i].mat);
		}
		do {
			im2 = 0;
			printf("\n			>> 영 어 : ");
			if(!scanf("%d" , &cat[i].eng)) {
				printf("			>> 숫자가 아닙니다.");
				im2=1;
				while(c=getchar() != '\n' && c!=EOF);
			}
		} while(im2);
		while((cat[i].eng>100)||(cat[i].eng<0)) {
			printf("			---------------------------------------------\n");
			printf("			▶범위값(0~100)이 아닙니다. 다시입력하세요\n");
			printf("			---------------------------------------------\n");
			printf("			>> 영 어 : ");
			scanf("%d" , &cat[i].eng);
		}
	}

	cat[i].sum = cat[i].kor + cat[i].eng + cat[i].mat;
	cat[i].ave = cat[i].sum / 3;

	printf("\n			>> 총 합 : %.0f", cat[i].sum);
	printf("\n\n			>> 평 균 : %.2f", cat[i].ave);
	printf("\n");
	printf("\n");
	printf("			입력순번=[%d]번 누적인원=[%d]명\n", i+1, i);
	printf("			저장 하시겠습니까? <Y/N> : ");
	do {
		scanf("%c", &choice);
		if(toupper(choice)=='Y' || toupper(choice)=='N')
			break;
	} while(1);
	{
		if(toupper(choice)=='Y') {
			printf("\n			>> 저장되었습니다.\n");
			printf("			>> 아무키나 누르면 메인화면으로 이동합니다.");
			top++;
			save(top);
			getch();
			CLS
			main();
		} else {
			printf("			>> 저장을 취소합니다.\n");
			printf("			>> 아무키나 누르면 메인화면으로 이동합니다.");
			getch();
			CLS
			main();
		}
	}
}

void find(int top) {
	int choice = 0, i = 0, j = 0, found = 0, page = 0;
	char str[10], in;
	//bool goodToGo = false;

	printf("\n           %d 명의학생이 검색되었습니다", top);

	while (choice < 1 || choice>3) {
		printf("\n\n\n			>> 성 적  조 회\n");
		printf("\n\n			>> 1. 전체 조회\n\n");
		printf("			>> 2. 개인 조회\n\n");
		printf("			>> 3. 전체 메뉴\n\n\n");
		printf("\n			>> 원하는 번호를 선택하세요 : ");
		scanf("%d", &choice);
	}

	switch (choice) {
		case 1:
			for (i = 0; i < top; i++) {
				for (j = 0; j <= top; j++) {
					if ((cat[i].rank) < (cat[j].rank)) {
						tmp = cat[j];
						cat[j] = cat[i];
						cat[i] = tmp;
					}
				}
			}

			CLS;
			printf("			********************** 성 적 조 회 결 과 ********************\n");
			printf("			========================================================\n");

			//학생 정보 표시 시작============================================================================================================
			printf("              [W]로 다음 10개를 더보기\n\n              [E]로 돌아가기\n\n");

			printf("			%10s %10s %4s %6s %6s %6s     %6s %6s %6s\n\n", "학번", "이름", "국어", "영어", "수학", "총합", "평균", "학점", "등수");

			for (i = 0; i < top; i++) {
				if (i % 10 == 0 && i > 0) {
					//goodToGo = false;

					while (in != 'w' && in != 'e') { //goodToGo == false)
						in = getch();

						if (in == 'w') {	//W를 누르면
							page++;
							printf("==> %d page <========================================================================\n", page);
							//goodToGo = true;
						} else if (in == 'e') {	//E를 누르면
							CLS;
							main();
						}
					}
				}

				printf("			%10s %10s %4d %6d %6d %6d     %6.3f %6s %6d\n", cat[i].num, cat[i].name,
				       cat[i].kor, cat[i].eng, cat[i].mat, cat[i].sum, cat[i].ave, cat[i].abc, cat[i].rank);
			}
			//학생 정보 표시 끝============================================================================================================

			printf("====================================================================================\n");
			break;
		case 2:
			printf("\n			>> 조회할 학번을 입력해주세요 : ");
			scanf("%s", str);

			for (i = 0; i < top + 1; i++) {
				if (!strcmp(str, cat[i].num)) {
					CLS;

					printf("\n			>> 개 인  조 회\n");
					printf("\n");
					printf("\n");
					printf("\n			>> 학  번 : %s", cat[i].num);
					printf("\n");
					printf("\n			>> 이  름 : %s", cat[i].name);
					printf("\n");
					printf("\n			>> 국  어 : %d", cat[i].kor);
					printf("\n");
					printf("\n			>> 영  어 : %d", cat[i].eng);
					printf("\n");
					printf("\n			>> 수  학 : %d", cat[i].mat);
					printf("\n");
					printf("\n			>> 합  계 : %.0f", cat[i].sum);
					printf("\n");
					printf("\n			>> 평  균 : %.3f", cat[i].ave);
					printf("\n");
					printf("\n			>> 학  점 : %s", cat[i].abc);
					printf("\n");
					printf("\n			>> 등  수 : %d", cat[i].rank);
					found = 1;
				}
			}

			if (!found) printf("\n			>> 학번를 잘못 입력하셨습니다.\n");
			break;
		case 3:
			main();
			break;
	}

	//printf("\n\n       메뉴로 이동하려면 Enter키를 누르세요.");
	printf("\n\n			다시 조회하려면 'W', 돌아가려면 'E'를 누르세요. ");

	in = '\r';		//in값을 '\r'로 초기화

	while (in != 'w' && in != 'e') {
		in = getch();

		if (in == 'w') {	//W를 누르면
			CLS;
			find(top);
		} else if (in == 'e') {	//E를 누르면
			CLS;
			main();
		}
	}
}

void edit(int top) {
	char temp[10], choice = '\r', n_tmp[10], im1 = 0;	//n_tmp 추가
	char s_save[200], kor[20], eng[20], mat[20];
	//ㄴ진행된 모든 string을 저장할 변수

	char in = '\r';	//단축키 입력을 받을 변수

	int i = 0, a = 0, found = 0, page = 0;
	//학생 10명당 1페이지

	bool Stop = false, wrongInput = false;

	//학생 정보 표시 시작============================================================================================================
	printf("              [W]로 다음 10개를 더보기\n\n              [E]로 수정 시작\n\n");

	printf("			%10s %10s %4s %6s %6s %6s     %6s %6s %6s\n\n", "학번", "이름", "국어", "영어", "수학", "총합", "평균", "학점", "등수");

	for (i = 0; i < top; i++) {
		if (i % 10 == 0 && i > 0) {
			while (in != 'w' && in != 'e') {
				in = '\r';
				in = getch();

				if (in == 'w') {	//W를 누르면
					page++;
					printf("==> %d <========================================================================================\n", page);
				}
			}
		}

		if (in != 'w' && in != 'e') {
			printf("			%10s %10s %4d %6d %6d %6d     %6.3f %6s %6d\n", cat[i].num, cat[i].name,
			       cat[i].kor, cat[i].eng, cat[i].mat, cat[i].sum, cat[i].ave, cat[i].abc, cat[i].rank);
		}
	}
	//학생 정보 표시 끝============================================================================================================

	printf("			===========================================================>>>>\n");
	printf("\n			>> 수정할 학번 또는 이름을 입력해주세요 : ");	//학번 또는 이름을 입력 하라고 알림
	scanf("%s", n_tmp);	//사용자의 입력을 받음

	for (i = 0; i < top; i++) {
		if (!strcmp(n_tmp, cat[i].num)) { //입력한 값이 학번과 같은지 검사
			found = 1;
			break;
		} else if (!strcmp(n_tmp, cat[i].name)) {	//입력한 값이 이름과 같은지 검사
			found = 1;
			break;
		}
	}

	if (found == 0) {	//입력한 값과 같은 학번 또는 이름이 없으면 실행
		printf("\n			>> 해당 학생이 존재하지 않거나 잘못 입력하셨습니다.");
		printf("\n			>> 다시 입력하려면 'W', 첫 화면으로 돌아가려면 'E'를 누르세요.");

		in = '\r';

		while (in != 'w' && in != 'e') {
			in = getch();

			if (in == 'w') {
				CLS;
				printf("\n");
				edit(top);
			} else if (in == 'e') {
				CLS;
				main();
			}
		}
	} else {	//입력한 값과 같은 학번 또는 이름이 있으면 실행
		CLS;

		printf("\n\n\n			 %s을 수정\n", n_tmp);
		printf("\n\n			>> 학  번 : ");
		scanf("%s", tmp.num);

		strcpy(s_save, "\n\n\n			>> ");
		strcat(s_save, n_tmp);
		strcat(s_save, "을 수정\n\n\n			>> 학  번 : ");

		while (Stop == false) {
			if (strlen(tmp.num) != 8) {	//학번의 형식이 올바른지 확인
				a = 8;

				for (int b = 0; b < 8; b++) {
					if (isdigit(tmp.num[b]) == 0) {	//입력한 학번의 문자가 모두 숫자인지 확인
						a--;
					}
					if (a != strlen(tmp.num)) {
						printf("\n\n			학번의 형식이 잘못되었습니다. 다시 입력해주세요. [ENTER]");
						getch();
						CLS;
						printf("%s", s_save);
						scanf("%s", tmp.num);
						continue;
					}
				}
			} 
			else {									//학번의 형식이 올바르면 실행
				for (int b = 0; b < atoi(cat[b].num); b++) {	//입력한 학번이 이미 존재하는지 확인
					if (strcmp(cat[b].num, tmp.num) == 0) {	//존재하면 실행
						CLS;

						printf("%s", s_save);
						printf("%s", tmp.num);

						printf("\n\n			입력한 학번은 이미 존재합니다. \n			진행 하려면 'Y', 다시 입력하려면 'N'를 누르세요 : ");

						in = '\r';		//in을 '\r'로 초기화

						while (in != 'y' && in != 'n') {
							in = getch();

							if (in == 'y') {
								CLS;
								printf("%s", s_save);
								printf("%s\n", tmp.num);
								Stop = true;
							} else if (in == 'n') {
								CLS;
								printf("%s", s_save);
								scanf("%s", tmp.num);
								continue;
							}
						}
					}
				}


				if (Stop == true) {
					if (!strlen(tmp.num))
						strcpy(tmp.num, cat[i].num);

					strcat(s_save, tmp.num);
				}
			}
		}

		printf("\n\n			>> 이  름 : ");

		while (!strcmp(tmp.name, "")) {
			gets(tmp.name);

			/*if (!strlen(tmp.name))
				strcpy(tmp.name, cat[i].name);*/
		}

		strcat(s_save, "\n\n\n			>>  이  름 : ");
		strcat(s_save, tmp.name);
		strcat(s_save, "\n");

		while (1) {
			//국어 입력 시작===============================================
			Stop = false;

			while (Stop == false) {
				wrongInput = false;

				printf("\n\n			>> 국  어 : ");
				scanf("%s", &kor);

				a = strlen(kor);

				for (i = 0; i < strlen(kor); i++) {
					if (wrongInput == false) {
						if (isdigit(kor[i]) == 0) {	//입력받은 값이 0~9인 10진수면 0이 아닌 값
							//입력받은 값이 숫자면 a--
							a--;
						}

						if (a != strlen(kor)) {
							printf("\n			잘못된 입력입니다. 다시입력하세요. [ENTER]");
							getch();
							CLS;
							printf("%s", s_save);
							wrongInput = true;
						}
					}
				}

				if (wrongInput == false) {
					if ((atoi(kor) > 100) || (atoi(kor) < 0)) {
						printf("\n			▶범위값(0~100)이 아닙니다. 다시입력하세요. [ENTER]\n");
						getch();
						CLS;
						printf("%s", s_save);
						continue;
					}

					if (!strlen(kor))
						tmp.kor = cat[i].kor;
					else
						tmp.kor = atoi(temp);

					strcat(s_save, "\n\n			>> 국  어 : ");
					strcat(s_save, kor);
					strcat(s_save, "\n");

					Stop = true;
				}
			}

			Stop = false;					//영어 입력 시작===============================================

			while (Stop == false) {
				wrongInput = false;

				printf("\n\n			>> 영  어 : ");
				scanf("%s", &eng);

				a = strlen(eng);

				for (i = 0; i < strlen(eng); i++) {
					if (wrongInput == false) {
						if (isdigit(eng[i]) == 0) {	//입력받은 값이 0~9인 10진수면 0이 아닌 값
							//입력받은 값이 숫자면 a--
							a--;
						}

						if (a != strlen(eng)) {
							printf("\n			잘못된 입력입니다. 다시입력하세요. [ENTER]");
							getch();
							CLS;
							printf("%s", s_save);
							wrongInput = true;
						}
					}
				}

				if (wrongInput == false) {
					if ((atoi(eng) > 100) || (atoi(eng) < 0)) {
						printf("\n			▶범위값(0~100)이 아닙니다. 다시입력하세요. [ENTER]\n");
						getch();
						CLS;
						printf("%s", s_save);
						continue;
					}

					if (!strlen(eng))
						tmp.eng = cat[i].eng;
					else
						tmp.eng = atoi(temp);

					strcat(s_save, "\n\n			>> 영  어 : ");
					strcat(s_save, eng);
					strcat(s_save, "\n");
				}

				Stop = true;
			}

			Stop = false;									//수학 입력 시작===============================================

			while (Stop == false) {
				wrongInput = false;

				printf("\n\n			>> 영  어 : ");
				scanf("%s", &mat);

				a = strlen(mat);

				for (i = 0; i < strlen(mat); i++) {
					if (wrongInput == false) {
						if (isdigit(mat[i]) == 0) {	//입력받은 값이 0~9인 10진수면 0이 아닌 값
							//입력받은 값이 숫자면 a--
							a--;
						}

						if (a != strlen(mat)) {
							printf("\n			잘못된 입력입니다. 다시입력하세요. [ENTER]");
							getch();
							CLS;
							printf("%s", s_save);
							wrongInput = true;
						}
					}
				}

				if (wrongInput == false) {
					if ((atoi(mat) > 100) || (atoi(mat) < 0)) {
						printf("\n			▶범위값(0~100)이 아닙니다. 다시입력하세요. [ENTER]\n");
						getch();
						CLS;
						printf("%s", s_save);
						continue;
					}

					if (!strlen(mat))
						tmp.mat = cat[i].mat;
					else
						tmp.mat = atoi(temp);

					strcat(s_save, "\n\n			>> 수  학 : ");
					strcat(s_save, mat);
					strcat(s_save, "\n");
				}

				Stop = true;
			}

			break;
		}

		tmp.sum = tmp.kor + tmp.eng + tmp.mat;
		tmp.ave = tmp.sum / 3;

		while (choice != 'y' && choice != 'n') {
			printf("\n			저장하시겠습니까? (Y/N) : ");
			choice = getch();
		}

		if (toupper(choice) == 'Y') {
			cat[i] = tmp;
			save(top);
		}

		printf("\n\n			저장을 완료했습니다. [ENTER]");
		getch();

		CLS;

		main();
	}
}

void del(int top) {

	char choice;
	int i, flag, j, found=0;
	int change, c, im2=0;
	for(i=0; i<top; i++) {
		for(j=0; j<=top; j++) {
			if((cat[i].rank) < (cat[j].rank)) {
				tmp = cat[j];
				cat[j] = cat[i];
				cat[i] = tmp;
			}
		}
	}
	printf("			    학번        이름   국어   영어   수학    총합     평균     학점   등수\n");
	for(i=0; i<top; i++) {
		if(i)
			if((i)%10==0) {
				printf("\n			다음 10개를 보려면 ENTER키를 누르세요.\n\n");
				getch();
			}
		printf("			%10s %10s %4d %6d %6d %6.0f     %6.3f %6s %6d\n", cat[i].num, cat[i].name,
		       cat[i].kor, cat[i].eng, cat[i].mat,cat[i].sum, cat[i].ave,cat[i].abc,cat[i].rank);
	}
	printf("			===========================================================\n");
	do {
		im2 = 0;
		printf("\n			>> 삭제할 학번를 입력해주세요 : ");
		scanf("%s", tmp.num);
		change = atoi(tmp.num);
		if(! change) {
			printf("			>> 숫자가 아닙니다.");
			im2=1;
			while(c=getchar() != '\n' && c!=EOF);
		}
	} while(im2);

	for(i=0; i<top; i++) {
		if(!strcmp(tmp.num, cat[i].num)) {
			found=1;
		}
	}
	if(!found) {
		printf("			>> 일치하는 학번이 없습니다.\n");
		printf("			>> [Y]키: 메인화면으로 이동합니다.\n");
		printf("			>> [N]키: 입력란으로 이동합니다.\n");
		choice = getche();
		if(toupper(choice)=='Y') {
			CLS
			main();
		} else {
			CLS
			del(top);
		}
	}
	CLS
	printf("\n\n			>> 성   적   삭  제\n");
	printf("\n");
	printf("\n			>> 학  번 : %s", cat[i].num);
	printf("\n");
	printf("\n			>> 이  름 : %s", cat[i].name);
	printf("\n");
	printf("\n			>> 국  어 : %d", cat[i].kor);
	printf("\n");
	printf("\n			>> 영  어 : %d", cat[i].eng);
	printf("\n");
	printf("\n			>> 수  학 : %d", cat[i].mat);
	printf("\n");
	printf("\n			>> 합  계 : %.0f", cat[i].sum);
	printf("\n");
	printf("\n			>> 평  균 : %.2f", cat[i].ave);
	printf("\n");
	printf("\n			>> 정말로 삭제하시겠습니까? (Y/N) : ");
	do {
		scanf("%c", &choice);
		if(toupper(choice) == 'Y' || toupper(choice)  == 'N')
			break;
	} while(1);
	if(toupper(choice) == 'Y') {
		printf("			>> 삭제되었습니다.\n");
		flag = i;
		top--;
		printf("			>> [Y]키: 메인화면으로 이동합니다.\n");
		printf("			>> [N]키: 입력란으로 이동합니다.\n");
		choice = getche();
		if(toupper(choice)=='Y') {
			CLS
			main();
		} else {
			CLS
			del(top);
		}
	} else {
		printf("			>> 삭제가 취소되었습니다.\n");
		printf("			>> [Y]키: 메인화면으로 이동합니다.\n");
		printf("			>> [N]키: 입력란으로 이동합니다.\n");
		choice = getche();
		if(toupper(choice)=='Y') {
			CLS
			main();
		} else {
			CLS
			del(top);
		}
	}
	for(i=flag; i<top; i++) {
		cat[i] = cat[i+1];
	}
	save(top-1);
	CLS
	main();
}

void load(void) {
	FILE* fp;

	if ((fp = fopen("student.txt", "rt")) == NULL) {
		printf("			현재 입력된 학생의 데이타가 없습니다. 입력하시면 student.txt파일이 생성됩니다.\n");
		return;
	}

	fread(&top, sizeof top, 1, fp);
	fread(cat, sizeof cat, 1, fp);
	fclose(fp);
}

void save(int top) {
	FILE* fp;

	int i = 0, j = 0;

	for (i = 0; i < top; i++) {
		if (cat[i].ave >= 95) strcpy(cat[i].abc, "A+");
		else if (cat[i].ave >= 90) strcpy(cat[i].abc, "A");
		else if (cat[i].ave >= 85) strcpy(cat[i].abc, "B+");
		else if (cat[i].ave >= 80) strcpy(cat[i].abc, "B");
		else if (cat[i].ave >= 75) strcpy(cat[i].abc, "C+");
		else if (cat[i].ave >= 70) strcpy(cat[i].abc, "C");
		else if (cat[i].ave >= 65) strcpy(cat[i].abc, "D+");
		else if (cat[i].ave >= 60) strcpy(cat[i].abc, "D");
		else strcpy(cat[i].abc, "F");
	}

	for (i = 0; i < top; i++) {
		cat[i].rank = 1;
		for (j = 0; j <= top + 1; j++) {
			if (cat[i].ave < cat[j].ave) cat[i].rank++;
		}
	}

	for (i = 0; i < top; i++) {
		for (j = 0; j <= top; j++) {
			if (atoi(cat[i].num) < atoi(cat[j].num)) {
				tmp = cat[j];
				cat[j] = cat[i];
				cat[i] = tmp;
			}
		}
	}

	if ((fp = fopen("student.txt", "wt")) == NULL) {
		printf("Cannot open catalog file\n");
		exit(1);
	}

	fwrite(&top, sizeof top, 1, fp);
	fwrite(cat, sizeof cat, 1, fp);
	fclose(fp);
}

