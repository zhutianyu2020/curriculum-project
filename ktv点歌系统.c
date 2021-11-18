#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ticket //处罚单信息结构体
{
	char num[20];            //处罚单号码
	char car_num[20];		//车牌号 
	char num_police[20];	//开单交警号码  
	char date[20];         //处罚时间 
	char status[20];       //  处罚状态 
};

int s_size;
struct ticket s[1000];

void menu()                                         //菜单 
{
	printf("\n");
	printf("     欢迎使用交通处罚单管理系统\n");
	printf("* * * * * * * * * * * * * * * * * * * *\n");
	printf("*       1,处罚单录入                  *\n");
	printf("*       2,处罚单添加                  *\n");
	printf("*       3,交通违规处理                *\n");
	printf("*       4,处罚单查询                  *\n");
	printf("*       5,处罚单删除                  *\n");
	printf("*       6,处罚单排序                  *\n");
	printf("*       7,浏览                        *\n");
	printf("*       0,退出系统                    *\n");
	printf("* * * * * * * * * * * * * * * * * * * *\n");
	printf("请选择: ");
}
void in_ticket()                                    //处罚单录入 
{
	char choose_1 = 1;
	while (choose_1 == 1) {
		printf("请输入处罚单编号: ");
		scanf("%s", s[s_size].num);
		printf("请输入车牌号: ");
		scanf("%s", s[s_size].car_num);
		printf("请输入开单交警号码: ");
		scanf("%s", s[s_size].num_police);
		printf("请输入处罚时间: ");
		scanf("%s", s[s_size].date);
		printf("请输入处罚状态:    (1为未处理,0为已处理)");
		scanf("%s", s[s_size].status);
		s_size++;
		printf("录入处罚单信息成功!\n");
		printf("继续输入请按 1,返回请按任意键\n");
		scanf("%d", choose_1);
	}

	int i, j, t;
	struct ticket* p;
	int len = s_size;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i; j++) {
			if (s[j].num > s[j + 1].num) {
				p = &s[j];
				s[j] = s[j + 1];
				s[j + 1] = *p;
			}
		}
	}											//处罚单号码排序(冒泡排序法) 

	FILE* fp;
	fp = fopen("ticket.txt", "w");
	if (fp != NULL)
	{
		for (t = 0; t < s_size; t++)
			fprintf(fp, "%s %s %s %s %s\n", s[i].num, s[i].car_num, s[i].num_police, s[i].date, s[i].status);
	}
	fclose(fp);
	printf("处罚单信息已经保存到文件ticket.txt中!\n");
	//处罚单消息保存 
}

void Add_ticket()
{
	char choose_1 = 1;
	while (choose_1 == 1) {
		printf("请输入处罚单编号: ");
		scanf("%s", s[s_size].num);
		printf("请输入车牌号: ");
		scanf("%s", s[s_size].car_num);
		printf("请输入开单交警号码: ");
		scanf("%s", s[s_size].num_police);
		printf("请输入处罚时间: ");
		scanf("%s", s[s_size].date);
		printf("请输入处罚状态:    (1为未处理,0为已处理)\n");
		scanf("%s", s[s_size].status);
		s_size++;
		printf("录入处罚单信息成功!\n");
		printf("继续输入请按 1,返回请按任意键\n");
		scanf("%d", &choose_1);
	}

	int i, j, t, len = s_size;
	struct ticket* p;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len - i; j++) {
			if (s[j].num > s[j + 1].num) {
				p = &s[j];
				s[j] = s[j + 1];
				s[j + 1] = *p;
			}
		}
	}
	//处罚单号码排序(冒泡排序法) 
	FILE* fp;
	fp = fopen("ticket.txt", "a");
	if (fp != NULL)
	{
		for (t = 0; t < s_size; t++)
			fprintf(fp, "%s %s %s %s %s\n", s[i].num, s[i].car_num, s[i].num_police, s[i].date, s[i].status);
	}
	fclose(fp);
	printf("处罚单信息已经添加到文件ticket.txt中!\n");


}


void handle()                                       //交通违规处理
{
	char id[20];
	char choose_1 = 1;
	int i;
	printf("请输入违规车牌号\n");
	scanf("%s", id);
	for (i = 0; i < s_size; i++)
	{
		if (strcmp(id, s[i].car_num) == 0)
		{
			printf("处罚状态:%s\n", s[i].status);
			printf("\n");
			printf("是否要修改处罚状态？是请按1，否请按任意键");
			scanf("%s", &choose_1);
			if (choose_1 == 1) {
				printf("请输入修改后的处罚状态\n");
				scanf("%d", &s[i].status);
				if (scanf("%d", &s[i].status) == 1)
					printf("修改成功！\n");
			}

			break;
		}
		else {
			printf("查无此交通违规\n");
			break;
		}
	}

}

void search()                                       //交通违规查询 
{
	char id[20], num_1[20], num_2[20];
	char choose_1 = 1;
	int i;
	while (1) {
		printf("A.通过车牌号查询\nB.通过处罚状态查询:\nC.通过开单交警号码查询");
		scanf("%c", &choose_1);               //读取回车键 
		scanf("%c", &choose_1);
		if (choose_1 == 'A') {
			printf("请输入车牌号\n");
			scanf("%s", &id);
			break;
		}
		else if (choose_1 == 'B') {
			printf("请输入处罚状态\n");
			scanf("%s", &num_1);
			break;
		}
		else if (choose_1 == 'C') {
			printf("请输入开单交警号码\n");
			scanf("%s", &num_2);
			break;
		}

		else
			printf("输入错误，请重新输入\n");
		scanf("%s", id);
		for (i = 0; i < s_size; i++)
		{
			if (strcmp(id, s[i].car_num) == 0 || strcmp(num_1, s[i].status) == 0 || strcmp(num_2, s[i].num_police) == 0)
			{
				printf("该交通违规的详细信息如下:\n");
				printf("处罚单编号:%s\n", s[i].num);
				printf("车牌号:%s\n", s[i].car_num);
				printf("开单交警号码:%s\n", s[i].num_police);
				printf("处罚时间:%s\n", s[i].date);
				printf("处罚状态:%s\n", s[i].status);
				printf("\n");
			}
			else {
				printf("查无此交通违规\n");
				break;
			}
		}

	}
}
	void del()
	{
		char id[20], choose, i, j, temp, t;
		int len = s_size;
		FILE* fp;
		fp = fopen("ticket.txt", "r+");
		if (fp != NULL)
		{
			printf("请输入处罚单编号");
			scanf("%s", id);
			for (i = 0; i < s_size; i++) {
				if (strcmp(id, s[i].num) == 0) {
					printf("发现该处罚单，是否删除，是请按1，否请按任意键");
					scanf("%d", &choose);
					if (choose == 1) {
						for (j = i; j < len; j++)
							s[j] = s[j + 1];
						printf("删除成功！");
						break;
					}
				}
				else
					printf("查无此处罚单\n");
			}
			for (t = 0; t < s_size; t++)
				fprintf(fp, "%s %s %s %s %s\n", s[i].num, s[i].car_num, s[i].num_police, s[i].date, s[i].status);
		}
		else
			printf("无法打开\n");
		fclose(fp);

	}

	void sort()
	{
		int i, j, t;
		int len = s_size;
		struct ticket* p;
		for (i = 0; i < len; i++) {
			for (j = 0; j < len - i; j++) {
				if (strcmp(s[j].date, s[j + 1].date)) {
					p = &s[j];
					s[j] = s[j + 1];
					s[j + 1] = *p;
				}
			}
		}
		for (i = len; i > 0; i--) {
			printf("该交通违规的详细信息如下:\n");
			printf("处罚单编号:%s\n", s[i].num);
			printf("车牌号:%s\n", s[i].car_num);
			printf("开单交警号码:%s\n", s[i].num_police);
			printf("处罚时间:%s\n", s[i].date);
			printf("处罚状态:%s\n", s[i].status);
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
				printf("命令错误!\n");
				break;

			}
		}
		return 0;
	}
