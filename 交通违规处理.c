#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ticket //��������Ϣ�ṹ��
{
	char num[20];            //����������
	char car_num[20];		//���ƺ� 
	char num_police[20];	//������������  
	char date[20];         //����ʱ�� 
	char status[20];       //  ����״̬ 
};

int s_size=0;
struct ticket s[1000];
struct ticket temp;

void menu()                                         //�˵� 
{
	printf("\n");
	printf("     ��ӭʹ�ý�ͨ����������ϵͳ\n");
	printf("* * * * * * * * * * * * * * * * * * * *\n");
	printf("*       1,������¼��                  *\n");
	printf("*       2,���������                  *\n");
	printf("*       3,��ͨΥ�洦��                *\n");
	printf("*       4,��������ѯ                  *\n");
	printf("*       5,������ɾ��                  *\n");
	printf("*       6,����������                  *\n");
	printf("*       7,���                        *\n");
	printf("*       0,�˳�ϵͳ                    *\n");
	printf("* * * * * * * * * * * * * * * * * * * *\n");
	printf("��ѡ��: ");
}
void in_ticket()                                    //������¼�� 
{
	char choose_1 = 't'; 
	while (choose_1 == 't') {
		printf("�����봦�������: ");
		scanf("%s", s[s_size].num);
		printf("�����복�ƺ�: ");
		scanf("%s", s[s_size].car_num);
		printf("�����뿪����������: ");
		scanf("%s", s[s_size].num_police);
		printf("�����봦��ʱ��: ");
		scanf("%s", s[s_size].date);
		printf("�����봦��״̬:(1Ϊδ����,0Ϊ�Ѵ���)");
		scanf("%s", s[s_size].status);
		printf("¼�봦������Ϣ�ɹ�!\n");
		printf("���������밴 t,�����밴�����\n");
		scanf("%c", &choose_1);
		scanf("%c", &choose_1);
		s_size++;
	}
	int i, j, t;
	int len = s_size; 
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i; j++) {
			if (strcmp(s[j].num,s[j+1].num)==1) {
				temp=s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}											//��������������(ð������) 
	FILE* fp;
	 s_size++; 
	fp = fopen("ticket.txt", "w");
	if (fp != NULL)
	{
		for (i = 0; i<s_size; i++)
			fprintf(fp, "%s %s %s %s %s\n", s[i].num, s[i].car_num, s[i].num_police, s[i].date, s[i].status);
	}
	fclose(fp);
	printf("��������Ϣ�Ѿ����浽�ļ�ticket.txt��!\n");
	//��������Ϣ���� 
}

void Add_ticket()
{
	char choose_1 = 't';
	while (choose_1 == 't') {
		printf("�����봦�������: ");
		scanf("%s", s[s_size].num);
		printf("�����복�ƺ�: ");
		scanf("%s", s[s_size].car_num);
		printf("�����뿪����������: ");
		scanf("%s", s[s_size].num_police);
		printf("�����봦��ʱ��: ");
		scanf("%s", s[s_size].date);
		printf("�����봦��״̬:    (1Ϊδ����,0Ϊ�Ѵ���)\n");
		scanf("%s", s[s_size].status);
		s_size++;
		printf("¼�봦������Ϣ�ɹ�!\n");
		printf("���������밴 t,�����밴�����\n");
		scanf("%c", &choose_1);
		scanf("%c", &choose_1);
	}
	int i, j, t;
	int len = s_size; 
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i; j++) {
			if (strcmp(s[j].num,s[j+1].num)==1) {
				temp=s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}											//��������������(ð������) 
	s_size++;
	FILE* fp;
	fp = fopen("ticket.txt", "w");
	if (fp != NULL)
	{
		for (i = 0; i< s_size; i++)
			fprintf(fp, "%s %s %s %s %s\n", s[i].num, s[i].car_num, s[i].num_police, s[i].date, s[i].status);
	}
	fclose(fp);
	printf("��������Ϣ�Ѿ���ӵ��ļ�ticket.txt��!\n");
	//��������Ϣ���� 
}


void handle()                                       //��ͨΥ�洦��
{
	char id[20];
	char choose_1 = 1;
	int i=0;
	FILE* fp;
	fp = fopen("ticket.txt", "r+");
	if (fp != NULL)
	{
		printf("������Υ�泵�ƺ�\n");
		scanf("%s",&id);
		for (i = 0; i < s_size; i++)
		{
			if (strcmp(id,s[i].num) == 0)
			{
				printf("����״̬:%s\n", s[i].status);
				printf("\n");
				printf("�Ƿ�Ҫ�޸Ĵ���״̬�����밴t�����밴�����");
				scanf("%c", &choose_1);
				scanf("%c", &choose_1);
				if (choose_1 == 't') {
					printf("�������޸ĺ�Ĵ���״̬\n");
					scanf("%d", &s[i].status);
					if (scanf("%d", &s[i].status) == 1)
						printf("�޸ĳɹ���\n");
				}
	
				break;
			}
			else {
				printf("���޴˽�ͨΥ��\n");
				break;
			}
		}
	}
	else
		printf("�޷���\n"); 
	fclose(fp);

}

void search()                                       //��ͨΥ���ѯ 
{
	char id[20], num_1[20], num_2[20];
	char choose_1 = 1;
	int i;
	while (1) {
		printf("A.ͨ�����ƺŲ�ѯ\nB.ͨ������״̬��ѯ:\nC.ͨ���������������ѯ");
		scanf("%c", &choose_1);               //��ȡ�س��� 
		scanf("%c", &choose_1);
		if (choose_1 == 'A') {
			printf("�����복�ƺ�\n");
			scanf("%s", &id);
			break;
		}
		else if (choose_1 == 'B') {
			printf("�����봦��״̬\n");
			scanf("%s", &num_1);
			break;
		}
		else if (choose_1 == 'C') {
			printf("�����뿪����������\n");
			scanf("%s", &num_2);
			break;
		}

		else
			printf("�����������������\n");
		}
		for (i = 0; i < s_size; i++)
		{
			if (strcmp(id, s[i].car_num) == 0 || strcmp(num_1, s[i].status) == 0 || strcmp(num_2, s[i].num_police) == 0)
			{
				printf("�ý�ͨΥ�����ϸ��Ϣ����:\n");
				printf("���������:%s\n", s[i].num);
				printf("���ƺ�:%s\n", s[i].car_num);
				printf("������������:%s\n", s[i].num_police);
				printf("����ʱ��:%s\n", s[i].date);
				printf("����״̬:%s\n", s[i].status);
				printf("\n");
			}
			else {
				printf("���޴˽�ͨΥ��\n");
				break;
			}
		}
}
	void del()
	{
		char id[20], choose='t', i=0, j=0, temp, t=0;
		int len = s_size;
		FILE* fp;
		fp = fopen("ticket.txt", "r+");
		if (fp != NULL)
		{
			printf("�����봦�������");
			scanf("%s", id);
			for (i = 0; i < s_size; i++) {
				if (strcmp(id, s[i].num) == 0) {
					printf("���ָô��������Ƿ�ɾ�������밴t�����밴�����");
					scanf("%c", &choose);
					scanf("%c", &choose);
					if (choose == 't') {
						for (j=i; j<len; j++)
							s[j]=s[j+1];
						printf("ɾ���ɹ���");
						break;
					}
				}	
			}
			if(choose=='t')
				printf("���޴˷���\n");
			for (i = 0; i< s_size; i++)
				fprintf(fp, "%s %s %s %s %s\n", s[i].num, s[i].car_num, s[i].num_police, s[i].date, s[i].status);
		}
		else
			printf("�޷���\n");
		fclose(fp);

	}

	void sort()
	{
		int i, j, t;
		int len = s_size;
		for (i = 0; i < len; i++) {
			for (j = 0; j < len - i; j++) {
				if (strcmp(s[j].date, s[j + 1].date)) {
					temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
				}
			}
		}
 
		for (i = 1; i <len; i++) {
			printf("��ͨΥ�����ϸ��Ϣ����:\n");
			printf("���������:%s\n", s[i].num);
			printf("���ƺ�:%s\n", s[i].car_num);
			printf("������������:%s\n", s[i].num_police);
			printf("����ʱ��:%s\n", s[i].date);
			printf("����״̬:%s\n", s[i].status);
		}

	}

	int main()
	{
		int choice = 1;
		s_size = 0;

		while (choice)
		{
			menu();
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				in_ticket();
				break;
			case 2:
				Add_ticket();
				break;
			case 3:
				handle();
				break;
			case 4:
				search();
				break;
			case 5:
				del();
				break;
			case 6:
				sort();
				break;
			case 7:
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("�������!\n");
				break;

			}
		}
		return 0;
	}
