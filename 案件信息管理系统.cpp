#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct lawcase //案件信息结构体
{
	char name[20];            //案件名称 
	char num[20];			 //案件编号号
	char personname[20];         //案件负责人 
	char sex[20];             //案件负责人姓名 
	char age[20];           //案件负责人年龄 
	char status[20];           //案件状态 
	char date[20];         //接管案件信息日期 
};
int s_size;
struct lawcase s[1000];

void menu()                                         //菜单 
{   printf("\n");
	printf("     欢迎使用本案件信息管理系统\n");
	printf("*--------------------------------------*\n");
    printf("*       1,案件信息录入                 *\n");
    printf("*       2,案件查询                     *\n");
    printf("*       3,案件信息更改                 *\n");
    printf("*       4,保存案件信息                 *\n");
    printf("*       0,退出系统                     *\n");
    printf("*--------------------------------------*\n");
    printf("请选择: ");
}
void Add_lawcase()                                    //增加患者 
{
	int choose_2; 
	printf("警告！！案件编号号输入后不可更改，请确认无误后再输入。") ;
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("请输入案件编号号: ");
    scanf("%s",s[s_size].num);
    printf("请输入案件名称: ");
    scanf("%s",s[s_size].name);
     printf("请输入案件负责人名称: ");
    scanf("%s",s[s_size].personname);
    printf("请输入案件负责人性别: ");
    scanf("%s",s[s_size].sex);
    printf("请输入案件负责人年龄: ");
    scanf("%s",s[s_size].age);
    printf("请输入接管案件日期: ");
	scanf("%s",s[s_size].date); 
    printf("请输入案件状态: "); 
	scanf("%s",s[s_size].status);
    s_size++;
    printf("录入案件信息成功!\n");
	}
}

void Search()                                  //查询患者 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.通过案件编号查询     B.通过案件名称查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入案件的编号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入案件的名称\n");
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
            printf("该案件的详细信息如下:\n");
            printf("案件编号:%s\n",s[i].num);
            printf("案件名称:%s\n",s[i].name);
            printf("案件负责人姓名:%s\n",s[i].personname);
            printf("案件负责人性别:%s\n",s[i].sex);
            printf("案件负责人年龄:%s\n",s[i].age);
            printf("该案件负责人接管案件日期:%s\n",s[i].date);
            printf("案件状态:%s\n",s[i].status); 
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
   	printf("请输入案件编号\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
		
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.案件名称\n2.案件负责人\n3.案件负责人性别\n4.案件负责人年龄\n5.该案件负责人接管案件的日期\n6.案件状态\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        	printf("请输入更改后的案件名称\n");
	            scanf("%s",&s[i].name);
	            printf("修改成功!\n") ;
	        	break;
	        case 2:
				printf("请输入更改后的案件负责人\n");
	            scanf("%s",&s[i].name);
	            printf("修改成功!\n") ;
	        	break;	
	        case 3:
	            printf("请输入更改后的案件负责人性别\n");
	            scanf("%s",&s[i].sex);
	            printf("修改成功!\n") ;
	            break;
	        case 4:
	        	printf("请输入更改后的案件负责人年龄\n");
	            scanf("%s",&s[i].age);
	            printf("修改成功!\n") ;
	            break;
	        case 5:
	            printf("请输入更改后的接管日期\n");
	            scanf("%s",&s[i].date);
	            printf("修改成功!\n") ;
				break; 
	        case 6:
	        	printf("请输入更改后的案件状态\n");
	            scanf("%s",&s[i].status);
	            printf("修改成功!\n") ;
	            break;
	        default:
	            printf("命令错误!\n");
	            break;
	
	        }
		}
		else
			printf("查无此案件\n");

	}
} 

void Save()                                 //保存信息 
{  
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("lawcase.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].personname,s[i].sex,s[i].age,s[i].date,s[i].status);
	    }
	    fclose(fp);
	    printf("患者住院信息已经保存到文件lawcase.txt中!\n");
	    
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
            Add_lawcase();
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
