#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student //学生信息结构体
{
	char name[20];            //姓名
	char num[20];			 //学号号
	char sex[20];             //性别 
	char age[20];           //年龄 
	char money[20];         //获奖金额 
	char moneyname[20];           //获奖名称 
	char date[20];         //获奖日期 
};
int s_size;
struct student s[1000];

void menu()                                         //菜单 
{   printf("\n");
	printf("     欢迎使用本奖学金管理系统\n");
	printf("*--------------------------------------*\n");
    printf("*       1,获奖学生信息录入             *\n");
    printf("*       2,获奖学生查询                 *\n");
    printf("*       3,获奖学生信息更改             *\n");
    printf("*       4,保存信息                     *\n");
    printf("*       0,退出系统                     *\n");
    printf("*--------------------------------------*\n");
    printf("请选择: ");
}
void Add_student()                                    //增加患者 
{
	char choose_2;
	printf("警告！！参赛号码输入后不可更改，请确认无误后再输入。") ;
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("请输入获奖学生学号: ");
    scanf("%s",s[s_size].num);
    printf("请输入获奖学生姓名: ");
    scanf("%s",s[s_size].name);
    printf("请输入获奖学生性别: ");
    scanf("%s",s[s_size].sex);
    printf("请输入获奖学生年龄: ");
    scanf("%s",s[s_size].age);
    printf("请输入获奖学生的获奖金额: "); 
	scanf("%s",s[s_size].money);
	printf("请输入获奖学生的获奖名称: "); 
	scanf("%s",s[s_size].moneyname);
    printf("请输入获奖学生的获奖日期: ");
	scanf("%s",s[s_size].date); 
    s_size++;
    printf("录入获奖学生信息成功!\n");
	}
}

void Search()                                  //查询患者 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.通过获奖学生的学号查询     B.通过获奖学生的姓名的查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入获奖学生的学号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入获奖学生的姓名\n");
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
            printf("该获奖学生的住个人信息如下:\n");
            printf("学号:%s\n",s[i].num);
            printf("姓名:%s\n",s[i].name);
            printf("性别:%s\n",s[i].sex);
            printf("年龄:%s\n",s[i].age);
            printf("获奖金额:%s\n",s[i].money); 
            printf("获奖名称:%s\n",s[i].moneyname); 
            printf("获奖日期:%s\n",s[i].date);
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
   	printf("请输入获奖学生的学号\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
		
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.姓名\n2.性别\n3.年龄\n4.获奖金额\n5.获奖名称\n6.获奖日期\n");
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
	            printf("请输入更改后的获奖金额\n");
	            scanf("%s",&s[i].money);
	            printf("修改成功!\n") ;
				break; 
	        case 5:
	        	printf("请输入更改后的获奖名称\n");
	            scanf("%s",&s[s_size].moneyname);
	            printf("修改成功!\n") ;
	            break;
	        case 6: 
	        	printf("请输入更改后的获奖日期\n");
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
	    fp=fopen("Student.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].money,s[i].moneyname,s[i].date);
	    }
	    fclose(fp);
	    printf("获奖学生信息已经保存到文件Student.txt中!\n");
	
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
            Add_student();
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
