#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"	//�����
#include "ctype.h"

#define _CRT_SECURE_NO_WARNINGS
#define CLS system("cls");	//���ǵ� ���� ��
#define MAX 100

int menu(void);
void enter(void), save(int), load(void), edit(int), del(int), find(int);	//�Լ���

struct student {	//structures [�л��� ������ ������ ������]
	char name[10];
	char num[11];
	int kor;
	int eng;
	int mat;
	float ave;
	float sum;
	int rank;
	char abc[2];
} cat[MAX], tmp;	//struct ������ ��

int top = 0;	//���� ���� ���� ����

int main(void) {
	int choice = 0;	//����

	load(); //����� ���� �ҷ�����

	while (choice != 5) {
		choice = menu();	//ó���� ������ �޴��Լ� ȣ��

		switch (choice) {	//������� ���ÿ� ���� �۵��� switch
			case 1:
				enter();	//enter ȣ��
				break;
			case 2:
				find(top);	//find ȣ�� (top�� �μ����Ͽ� ����)
				break;
			case 3:
				edit(top);	//edit ȣ��
				break;
			case 4:
				del(top);	//del ȣ��
				break;
			case 5:
				exit(1);	//exit ȣ�� (1�� �μ����Ͽ� ����)
				break;
		}
	}
}

int menu(void) {
	int i = 0;

	printf("\n\n");
	printf("		############### �� �� �� �� �� �� �� �� ###############\n\n");
	printf("		                    1.  ��     ��\n\n");
	printf("		                    2.  ��     ȸ\n\n");
	printf("		                    3.  ��     ��\n\n");
	printf("		                    4.  ��     ��\n\n");
	printf("		                    5.  ��     ��\n\n");
	printf("		#######################################################\n\n");

	while (i < 1 || i > 5) {
		printf("			>> ���ϴ� ��ȣ�� �Է��ϼ��� : ");
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
			printf("\n			>> �Է��� �й��� �Է����ּ��� : ");
			scanf("%s", tmp.num);
			change = atoi(tmp.num);
			if(! change) {
				printf("			>> ���ڰ� �ƴմϴ�.");
				im2=1;
				while(c=getchar() != '\n' && c!=EOF);
			}
		} while(im2);
		/*if(strlen(tmp.num)>10) {
			printf("\n			>> �й��� �ִ� 10�����Դϴ�. ");
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
		printf("\n			>> ���� ��ȣ�� �й��� �����մϴ�.");
		printf("\n			>> [Enter]Ű�� ������ ����ȭ������ �̵��մϴ�.");
		getch();
		CLS
		main();
	} else {
		CLS
		printf("\n\n\n			[��%s�� �л��� ������ �Է��մϴ�.]\n\n",&tmp.num);
		strcpy(cat[i].num, tmp.num);
		printf("			>> ��   �� : %s\n\n", cat[i].num);
		printf("			>> ��   �� : ");
		scanf("%s", cat[i].name);
		do {
			im2 = 0;
			printf("\n			>> �� �� : ");
			if(!scanf("%d", &cat[i].kor)) {
				printf("			>> ���ڰ� �ƴմϴ�.");
				im2=1;
				while(c=getchar() != '\n' && c!=EOF);
			}
		} while(im2);
		while((cat[i].kor>100)||(cat[i].kor<0)) {
			printf("			---------------------------------------------\n");
			printf("			��������(0~100)�� �ƴմϴ�. �ٽ��Է��ϼ���\n");
			printf("			---------------------------------------------\n");
			printf("\n			>> �� �� : ");
			scanf("%d" , &cat[i].kor);
		}
		do {
			im2 = 0;
			printf("\n			>> �� �� : ");
			if(!scanf("%d" , &cat[i].mat)) {
				printf("			>> ���ڰ� �ƴմϴ�.");
				im2=1;
				while(c=getchar() != '\n' && c!=EOF);
			}
		} while(im2);
		while((cat[i].mat>100)||(cat[i].mat<0)) {
			printf("			---------------------------------------------\n");
			printf("			��������(0~100)�� �ƴմϴ�. �ٽ��Է��ϼ���\n");
			printf("			---------------------------------------------\n");
			printf("			>> �� �� : ");
			scanf("%d" , &cat[i].mat);
		}
		do {
			im2 = 0;
			printf("\n			>> �� �� : ");
			if(!scanf("%d" , &cat[i].eng)) {
				printf("			>> ���ڰ� �ƴմϴ�.");
				im2=1;
				while(c=getchar() != '\n' && c!=EOF);
			}
		} while(im2);
		while((cat[i].eng>100)||(cat[i].eng<0)) {
			printf("			---------------------------------------------\n");
			printf("			��������(0~100)�� �ƴմϴ�. �ٽ��Է��ϼ���\n");
			printf("			---------------------------------------------\n");
			printf("			>> �� �� : ");
			scanf("%d" , &cat[i].eng);
		}
	}

	cat[i].sum = cat[i].kor + cat[i].eng + cat[i].mat;
	cat[i].ave = cat[i].sum / 3;

	printf("\n			>> �� �� : %.0f", cat[i].sum);
	printf("\n\n			>> �� �� : %.2f", cat[i].ave);
	printf("\n");
	printf("\n");
	printf("			�Է¼���=[%d]�� �����ο�=[%d]��\n", i+1, i);
	printf("			���� �Ͻðڽ��ϱ�? <Y/N> : ");
	do {
		scanf("%c", &choice);
		if(toupper(choice)=='Y' || toupper(choice)=='N')
			break;
	} while(1);
	{
		if(toupper(choice)=='Y') {
			printf("\n			>> ����Ǿ����ϴ�.\n");
			printf("			>> �ƹ�Ű�� ������ ����ȭ������ �̵��մϴ�.");
			top++;
			save(top);
			getch();
			CLS
			main();
		} else {
			printf("			>> ������ ����մϴ�.\n");
			printf("			>> �ƹ�Ű�� ������ ����ȭ������ �̵��մϴ�.");
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

	printf("\n           %d �����л��� �˻��Ǿ����ϴ�", top);

	while (choice < 1 || choice>3) {
		printf("\n\n\n			>> �� ��  �� ȸ\n");
		printf("\n\n			>> 1. ��ü ��ȸ\n\n");
		printf("			>> 2. ���� ��ȸ\n\n");
		printf("			>> 3. ��ü �޴�\n\n\n");
		printf("\n			>> ���ϴ� ��ȣ�� �����ϼ��� : ");
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
			printf("			********************** �� �� �� ȸ �� �� ********************\n");
			printf("			========================================================\n");

			//�л� ���� ǥ�� ����============================================================================================================
			printf("              [W]�� ���� 10���� ������\n\n              [E]�� ���ư���\n\n");

			printf("			%10s %10s %4s %6s %6s %6s     %6s %6s %6s\n\n", "�й�", "�̸�", "����", "����", "����", "����", "���", "����", "���");

			for (i = 0; i < top; i++) {
				if (i % 10 == 0 && i > 0) {
					//goodToGo = false;

					while (in != 'w' && in != 'e') { //goodToGo == false)
						in = getch();

						if (in == 'w') {	//W�� ������
							page++;
							printf("==> %d page <========================================================================\n", page);
							//goodToGo = true;
						} else if (in == 'e') {	//E�� ������
							CLS;
							main();
						}
					}
				}

				printf("			%10s %10s %4d %6d %6d %6d     %6.3f %6s %6d\n", cat[i].num, cat[i].name,
				       cat[i].kor, cat[i].eng, cat[i].mat, cat[i].sum, cat[i].ave, cat[i].abc, cat[i].rank);
			}
			//�л� ���� ǥ�� ��============================================================================================================

			printf("====================================================================================\n");
			break;
		case 2:
			printf("\n			>> ��ȸ�� �й��� �Է����ּ��� : ");
			scanf("%s", str);

			for (i = 0; i < top + 1; i++) {
				if (!strcmp(str, cat[i].num)) {
					CLS;

					printf("\n			>> �� ��  �� ȸ\n");
					printf("\n");
					printf("\n");
					printf("\n			>> ��  �� : %s", cat[i].num);
					printf("\n");
					printf("\n			>> ��  �� : %s", cat[i].name);
					printf("\n");
					printf("\n			>> ��  �� : %d", cat[i].kor);
					printf("\n");
					printf("\n			>> ��  �� : %d", cat[i].eng);
					printf("\n");
					printf("\n			>> ��  �� : %d", cat[i].mat);
					printf("\n");
					printf("\n			>> ��  �� : %.0f", cat[i].sum);
					printf("\n");
					printf("\n			>> ��  �� : %.3f", cat[i].ave);
					printf("\n");
					printf("\n			>> ��  �� : %s", cat[i].abc);
					printf("\n");
					printf("\n			>> ��  �� : %d", cat[i].rank);
					found = 1;
				}
			}

			if (!found) printf("\n			>> �й��� �߸� �Է��ϼ̽��ϴ�.\n");
			break;
		case 3:
			main();
			break;
	}

	//printf("\n\n       �޴��� �̵��Ϸ��� EnterŰ�� ��������.");
	printf("\n\n			�ٽ� ��ȸ�Ϸ��� 'W', ���ư����� 'E'�� ��������. ");

	in = '\r';		//in���� '\r'�� �ʱ�ȭ

	while (in != 'w' && in != 'e') {
		in = getch();

		if (in == 'w') {	//W�� ������
			CLS;
			find(top);
		} else if (in == 'e') {	//E�� ������
			CLS;
			main();
		}
	}
}

void edit(int top) {
	char temp[10], choice = '\r', n_tmp[10], im1 = 0;	//n_tmp �߰�
	char s_save[200], kor[20], eng[20], mat[20];
	//������� ��� string�� ������ ����

	char in = '\r';	//����Ű �Է��� ���� ����

	int i = 0, a = 0, found = 0, page = 0;
	//�л� 10��� 1������

	bool Stop = false, wrongInput = false;

	//�л� ���� ǥ�� ����============================================================================================================
	printf("              [W]�� ���� 10���� ������\n\n              [E]�� ���� ����\n\n");

	printf("			%10s %10s %4s %6s %6s %6s     %6s %6s %6s\n\n", "�й�", "�̸�", "����", "����", "����", "����", "���", "����", "���");

	for (i = 0; i < top; i++) {
		if (i % 10 == 0 && i > 0) {
			while (in != 'w' && in != 'e') {
				in = '\r';
				in = getch();

				if (in == 'w') {	//W�� ������
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
	//�л� ���� ǥ�� ��============================================================================================================

	printf("			===========================================================>>>>\n");
	printf("\n			>> ������ �й� �Ǵ� �̸��� �Է����ּ��� : ");	//�й� �Ǵ� �̸��� �Է� �϶�� �˸�
	scanf("%s", n_tmp);	//������� �Է��� ����

	for (i = 0; i < top; i++) {
		if (!strcmp(n_tmp, cat[i].num)) { //�Է��� ���� �й��� ������ �˻�
			found = 1;
			break;
		} else if (!strcmp(n_tmp, cat[i].name)) {	//�Է��� ���� �̸��� ������ �˻�
			found = 1;
			break;
		}
	}

	if (found == 0) {	//�Է��� ���� ���� �й� �Ǵ� �̸��� ������ ����
		printf("\n			>> �ش� �л��� �������� �ʰų� �߸� �Է��ϼ̽��ϴ�.");
		printf("\n			>> �ٽ� �Է��Ϸ��� 'W', ù ȭ������ ���ư����� 'E'�� ��������.");

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
	} else {	//�Է��� ���� ���� �й� �Ǵ� �̸��� ������ ����
		CLS;

		printf("\n\n\n			 %s�� ����\n", n_tmp);
		printf("\n\n			>> ��  �� : ");
		scanf("%s", tmp.num);

		strcpy(s_save, "\n\n\n			>> ");
		strcat(s_save, n_tmp);
		strcat(s_save, "�� ����\n\n\n			>> ��  �� : ");

		while (Stop == false) {
			if (strlen(tmp.num) != 8) {	//�й��� ������ �ùٸ��� Ȯ��
				a = 8;

				for (int b = 0; b < 8; b++) {
					if (isdigit(tmp.num[b]) == 0) {	//�Է��� �й��� ���ڰ� ��� �������� Ȯ��
						a--;
					}
					if (a != strlen(tmp.num)) {
						printf("\n\n			�й��� ������ �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���. [ENTER]");
						getch();
						CLS;
						printf("%s", s_save);
						scanf("%s", tmp.num);
						continue;
					}
				}
			} 
			else {									//�й��� ������ �ùٸ��� ����
				for (int b = 0; b < atoi(cat[b].num); b++) {	//�Է��� �й��� �̹� �����ϴ��� Ȯ��
					if (strcmp(cat[b].num, tmp.num) == 0) {	//�����ϸ� ����
						CLS;

						printf("%s", s_save);
						printf("%s", tmp.num);

						printf("\n\n			�Է��� �й��� �̹� �����մϴ�. \n			���� �Ϸ��� 'Y', �ٽ� �Է��Ϸ��� 'N'�� �������� : ");

						in = '\r';		//in�� '\r'�� �ʱ�ȭ

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

		printf("\n\n			>> ��  �� : ");

		while (!strcmp(tmp.name, "")) {
			gets(tmp.name);

			/*if (!strlen(tmp.name))
				strcpy(tmp.name, cat[i].name);*/
		}

		strcat(s_save, "\n\n\n			>>  ��  �� : ");
		strcat(s_save, tmp.name);
		strcat(s_save, "\n");

		while (1) {
			//���� �Է� ����===============================================
			Stop = false;

			while (Stop == false) {
				wrongInput = false;

				printf("\n\n			>> ��  �� : ");
				scanf("%s", &kor);

				a = strlen(kor);

				for (i = 0; i < strlen(kor); i++) {
					if (wrongInput == false) {
						if (isdigit(kor[i]) == 0) {	//�Է¹��� ���� 0~9�� 10������ 0�� �ƴ� ��
							//�Է¹��� ���� ���ڸ� a--
							a--;
						}

						if (a != strlen(kor)) {
							printf("\n			�߸��� �Է��Դϴ�. �ٽ��Է��ϼ���. [ENTER]");
							getch();
							CLS;
							printf("%s", s_save);
							wrongInput = true;
						}
					}
				}

				if (wrongInput == false) {
					if ((atoi(kor) > 100) || (atoi(kor) < 0)) {
						printf("\n			��������(0~100)�� �ƴմϴ�. �ٽ��Է��ϼ���. [ENTER]\n");
						getch();
						CLS;
						printf("%s", s_save);
						continue;
					}

					if (!strlen(kor))
						tmp.kor = cat[i].kor;
					else
						tmp.kor = atoi(temp);

					strcat(s_save, "\n\n			>> ��  �� : ");
					strcat(s_save, kor);
					strcat(s_save, "\n");

					Stop = true;
				}
			}

			Stop = false;					//���� �Է� ����===============================================

			while (Stop == false) {
				wrongInput = false;

				printf("\n\n			>> ��  �� : ");
				scanf("%s", &eng);

				a = strlen(eng);

				for (i = 0; i < strlen(eng); i++) {
					if (wrongInput == false) {
						if (isdigit(eng[i]) == 0) {	//�Է¹��� ���� 0~9�� 10������ 0�� �ƴ� ��
							//�Է¹��� ���� ���ڸ� a--
							a--;
						}

						if (a != strlen(eng)) {
							printf("\n			�߸��� �Է��Դϴ�. �ٽ��Է��ϼ���. [ENTER]");
							getch();
							CLS;
							printf("%s", s_save);
							wrongInput = true;
						}
					}
				}

				if (wrongInput == false) {
					if ((atoi(eng) > 100) || (atoi(eng) < 0)) {
						printf("\n			��������(0~100)�� �ƴմϴ�. �ٽ��Է��ϼ���. [ENTER]\n");
						getch();
						CLS;
						printf("%s", s_save);
						continue;
					}

					if (!strlen(eng))
						tmp.eng = cat[i].eng;
					else
						tmp.eng = atoi(temp);

					strcat(s_save, "\n\n			>> ��  �� : ");
					strcat(s_save, eng);
					strcat(s_save, "\n");
				}

				Stop = true;
			}

			Stop = false;									//���� �Է� ����===============================================

			while (Stop == false) {
				wrongInput = false;

				printf("\n\n			>> ��  �� : ");
				scanf("%s", &mat);

				a = strlen(mat);

				for (i = 0; i < strlen(mat); i++) {
					if (wrongInput == false) {
						if (isdigit(mat[i]) == 0) {	//�Է¹��� ���� 0~9�� 10������ 0�� �ƴ� ��
							//�Է¹��� ���� ���ڸ� a--
							a--;
						}

						if (a != strlen(mat)) {
							printf("\n			�߸��� �Է��Դϴ�. �ٽ��Է��ϼ���. [ENTER]");
							getch();
							CLS;
							printf("%s", s_save);
							wrongInput = true;
						}
					}
				}

				if (wrongInput == false) {
					if ((atoi(mat) > 100) || (atoi(mat) < 0)) {
						printf("\n			��������(0~100)�� �ƴմϴ�. �ٽ��Է��ϼ���. [ENTER]\n");
						getch();
						CLS;
						printf("%s", s_save);
						continue;
					}

					if (!strlen(mat))
						tmp.mat = cat[i].mat;
					else
						tmp.mat = atoi(temp);

					strcat(s_save, "\n\n			>> ��  �� : ");
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
			printf("\n			�����Ͻðڽ��ϱ�? (Y/N) : ");
			choice = getch();
		}

		if (toupper(choice) == 'Y') {
			cat[i] = tmp;
			save(top);
		}

		printf("\n\n			������ �Ϸ��߽��ϴ�. [ENTER]");
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
	printf("			    �й�        �̸�   ����   ����   ����    ����     ���     ����   ���\n");
	for(i=0; i<top; i++) {
		if(i)
			if((i)%10==0) {
				printf("\n			���� 10���� ������ ENTERŰ�� ��������.\n\n");
				getch();
			}
		printf("			%10s %10s %4d %6d %6d %6.0f     %6.3f %6s %6d\n", cat[i].num, cat[i].name,
		       cat[i].kor, cat[i].eng, cat[i].mat,cat[i].sum, cat[i].ave,cat[i].abc,cat[i].rank);
	}
	printf("			===========================================================\n");
	do {
		im2 = 0;
		printf("\n			>> ������ �й��� �Է����ּ��� : ");
		scanf("%s", tmp.num);
		change = atoi(tmp.num);
		if(! change) {
			printf("			>> ���ڰ� �ƴմϴ�.");
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
		printf("			>> ��ġ�ϴ� �й��� �����ϴ�.\n");
		printf("			>> [Y]Ű: ����ȭ������ �̵��մϴ�.\n");
		printf("			>> [N]Ű: �Է¶����� �̵��մϴ�.\n");
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
	printf("\n\n			>> ��   ��   ��  ��\n");
	printf("\n");
	printf("\n			>> ��  �� : %s", cat[i].num);
	printf("\n");
	printf("\n			>> ��  �� : %s", cat[i].name);
	printf("\n");
	printf("\n			>> ��  �� : %d", cat[i].kor);
	printf("\n");
	printf("\n			>> ��  �� : %d", cat[i].eng);
	printf("\n");
	printf("\n			>> ��  �� : %d", cat[i].mat);
	printf("\n");
	printf("\n			>> ��  �� : %.0f", cat[i].sum);
	printf("\n");
	printf("\n			>> ��  �� : %.2f", cat[i].ave);
	printf("\n");
	printf("\n			>> ������ �����Ͻðڽ��ϱ�? (Y/N) : ");
	do {
		scanf("%c", &choice);
		if(toupper(choice) == 'Y' || toupper(choice)  == 'N')
			break;
	} while(1);
	if(toupper(choice) == 'Y') {
		printf("			>> �����Ǿ����ϴ�.\n");
		flag = i;
		top--;
		printf("			>> [Y]Ű: ����ȭ������ �̵��մϴ�.\n");
		printf("			>> [N]Ű: �Է¶����� �̵��մϴ�.\n");
		choice = getche();
		if(toupper(choice)=='Y') {
			CLS
			main();
		} else {
			CLS
			del(top);
		}
	} else {
		printf("			>> ������ ��ҵǾ����ϴ�.\n");
		printf("			>> [Y]Ű: ����ȭ������ �̵��մϴ�.\n");
		printf("			>> [N]Ű: �Է¶����� �̵��մϴ�.\n");
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
		printf("			���� �Էµ� �л��� ����Ÿ�� �����ϴ�. �Է��Ͻø� student.txt������ �����˴ϴ�.\n");
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

