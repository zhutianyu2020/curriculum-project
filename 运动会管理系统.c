#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct competitor //参赛选手信息结构体
{
	char name[20];            //姓名
	char num[20];			 //参赛号码 
	char sex[20];             //性别 
	char age[20];           //年龄 
	char sport[20];         //参赛项目 
	char date[20];         //参赛日期 
};
int s_size;
struct competitor s[1000];

void menu()                                         //菜单 
{   printf("\n");
	printf("     欢迎使用本运动会管理系统\n");
	printf("*--------------------------------------*\n");
    printf("*       1,参赛选手信息录入             *\n");
    printf("*       2,参赛选手信息查询             *\n");
    printf("*       3,参赛选手信息更改             *\n");
    printf("*       4,保存信息                     *\n");
    printf("*       0,退出系统                     *\n");
    printf("*--------------------------------------*\n");
    printf("请选择: ");
}
void Add_competitor()                                    //增加患者 
{
	char choose_2;
	printf("警告！！参赛号码输入后不可更改，请确认无误后再输入。") ;
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("请输入参赛选手的参赛号码: ");
    scanf("%s",s[s_size].num);
    printf("请输入参赛选手姓名: ");
    scanf("%s",s[s_size].name);
    printf("请输入参赛选手性别: ");
    scanf("%s",s[s_size].sex);
    printf("请输入参赛选手年龄: ");
    scanf("%s",s[s_size].age);
    printf("请输入参赛选手的参赛项目: "); 
	scanf("%s",s[s_size].sport);
    printf("请输入参赛选手的参赛日期: ");
	scanf("%s",s[s_size].date); 
    s_size++;
    printf("录入参赛选手信息成功!\n");
	}
}

void Search()                                  //查询患者 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.通过参赛选手的参赛号查询     B.通过参赛选手的姓名查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入参赛的参赛号码\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入参赛选手的姓名\n");
	    	scanf("%s",&name_1);
	    	break;
		}
	    else
	    	printf("输入错误，请重新输入\n"); 
    }	
    for(i=0;i<s_size;i++)
    {
        if(strcmp(id,s[i].num)==0||strcmp(name_1,s[i].name)==0)
        {
            printf("该参赛选手的参赛信息如下:\n");
            printf("参赛号码:%s\n",s[i].num);
            printf("姓名:%s\n",s[i].name);
            printf("性别:%s\n",s[i].sex);
            printf("年龄:%s\n",s[i].age);
            printf("参赛项目:%s\n",s[i].sport);
            printf("参赛日期:%s\n",s[i].date);
            flag=0;
            break;
        }
    }

}

void Change()
{
	char id[20];
    char name_2[20];
    char choice_2;
    int i,flag=1; 
   	printf("请输入参赛的参赛号码\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
		
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.姓名\n2.性别\n3.年龄\n4.参赛项目\n5.参赛日期\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("请输入更改后的姓名\n");
	            	scanf("%s",&s[i].name);
	            	printf("修改成功!\n") ;
	        	break;
	        	
	        case 2:
	            printf("请输入更改后的性别\n");
	            scanf("%s",&s[i].sex);
	            printf("修改成功!\n") ;
	            break;
	        case 3:
	        	printf("请输入更改后的年龄\n");
	            scanf("%s",&s[i].age);
	            printf("修改成功!\n") ;
	            break;
	        case 4:
	            printf("请输入更改后的参赛项目\n");
	            scanf("%s",&s[i].sport);
	            printf("修改成功!\n") ;
				break; 
	        case 5: 
	        	printf("请输入更改后的参赛日期\n");
	            scanf("%s",&s[i].date);
	            printf("修改成功!\n") ;
	            break;
	        default:
	            printf("命令错误!\n");
	            break;
	
	        }
		}
		else
			printf("查无此人\n");

	}
} 

void Save()                                 //保存信息 
{ 
	    FILE *fp;
	    int i;
	    fp=fopen("competitor.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].sport,s[i].date);
	    }
	    fclose(fp);
	    printf("参赛选手信息已经保存到文件competitor.txt中!\n");
	   
}

int main()
{
    int choice=1;
    s_size=0;
    while(choice)
    {
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Add_competitor();
            break;
        case 2:
            Search();
            break;
        case 3:
			Change();
			break; 
        case 4:
            Save();
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
