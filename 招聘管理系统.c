#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct company //公司信息结构体
{
	char name[20];            //公司名称 
	char num[20];			 //公司编号
	char money[20];         //每月工资
	char num_1[20];         //招聘人数 
	char needs[20];        //招聘需求 
	char request[20]; 		//特殊要求
};
struct jobhunter //求职者信息结构体
{
	char name[20];            //求职姓名
	char sex[20];              //求职者性别 
	char num[20];			 //求职者编号
	char age[20];            //求职者年龄 
	char nation[20];         //求职者民族 
	char num_2[20];         //求职者联系电话 
	char status[20];        //求职者状态（是否被录用） 
};

int s_size;
struct company s[1000];
int e_size;
struct jobhunter e[1000];
 

void menu()                                         //菜单 
{   printf("\n");
	printf("     欢迎使用本招聘管理系统\n");
	printf("*--------------------------------------*\n");
    printf("*       1,公司信息录入                 *\n");
    printf("*       2,公司信息查询                 *\n");
    printf("*       3,公司信息更改                 *\n");
    printf("*       4,公司信息录入                 *\n");
    printf("*       5,求职者信息查询               *\n");
    printf("*       6,求职者信息更改               *\n");
    printf("*       7,保存公司信息                 *\n");
    printf("*       8,保存求职人员信息             *\n");
    printf("*       0,退出系统                     *\n");
    printf("*--------------------------------------*\n");
    printf("请选择: ");
}
void Add_company()                                    //增加公司 
{
	char choose_2;
	printf("警告！！公司编号号输入后不可更改，请确认无误后再输入。\n");
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("请输入公司编号: ");
	    scanf("%s",s[s_size].num);
	    printf("请输入公司名称: ");
	    scanf("%s",s[s_size].name);
	    printf("请输入招聘需求: ");
	    scanf("%s",s[s_size].needs);
	    printf("请输入招聘人数: ");
	    scanf("%s",s[s_size].num_1);
	    printf("请输入公司的月薪: ");
		scanf("%s",s[s_size].money);
		printf("请输入公司的特殊要求: ");
		scanf("%s",s[s_size].request);
	    s_size++;
	    printf("录入公司信息成功!\n");
	}
}

void Search()                                  //查询公司 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i;
    while(1){
	    printf("A.通过公司编号查询     B.通过公司的名称查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入公司编号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入公司名称\n");
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
            printf("该公司的详细信息如下:\n");
            printf("公司编号:%s\n",s[i].num);
            printf("公司名称:%s\n",s[i].name); 
            printf("招聘需求:%s\n",s[i].needs);
            printf("招聘人数:%s\n",s[i].num_1);
            printf("公司月薪:%s\n",s[i].money); 
            printf("特殊要求:%s\n",s[i].request);
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
   	printf("请输入公司编号\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.公司名称\n2.招聘需求\n3.招聘人数\n4.公司月薪\n5.特殊要求\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("请输入更改后的公司名称\n");
	            	scanf("%s",&s[i].name);
	            	printf("修改成功!\n") ;
	        	break;
	        	
	        case 2:
	            printf("请输入更改后的招聘需求\n");
	            scanf("%s",&s[i].needs);
	            printf("修改成功!\n") ;
	            break;
	        case 3:
	        	printf("请输入更改后的招聘人数n");
	            scanf("%s",&s[i].num_1);
	            printf("修改成功!\n") ;
	            break;
	        case 4:
	            printf("请输入更改后的公司月薪\n");
	            scanf("%s",&s[i].money);
	            printf("修改成功!\n") ;
				break; 
	        case 5:
	        	printf("请输入更改后的特殊要求\n");
	            scanf("%s",&s[i].request);
	            printf("修改成功!\n") ;
	            break;
	        default:
	            printf("命令错误!\n");
	            break;
	
	        }
		}
		else
			printf("查无此公司\n");

	}
} 

void Add_jobhunter()                                    //增加求职者
{
	char choose_2;
	printf("警告！！求职者编号输入后不可更改，请确认无误后再输入。\n") ;
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("请输入求职者编号: ");
    scanf("%s",e[e_size].num);
    printf("请输入求职者姓名: ");
    scanf("%s",e[e_size].name);
    printf("请输入求职者性别: ");
    scanf("%s",e[e_size].sex);
    printf("请输入求职者年龄: ");
    scanf("%s",e[e_size].age);
	printf("请输入求职者的民族: "); 
	scanf("%s",e[e_size].nation);
    printf("请输入求职者的联系电话: ");
	scanf("%s",e[e_size].num_2); 
	printf("请输入求职者录用状态: ");
	scanf("%s",e[e_size].status);  
    e_size++;
    printf("录入求职者信息成功!\n");
	}
}

void Searchjobhunter()                                  //查询求职者
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i; 
    while(1){
    	printf("\n");
	    printf("A.通过求职者的编号查询     B.通过求职者姓名查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入求职者的编号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入求职者的姓名\n");
	    	scanf("%s",&name_1);
	    	break;
		}
	    else
	    	printf("输入错误，请重新输入\n"); 
    }	
    for(i=0;i<e_size;i++)
    {
        if(strcmp(id,e[i].num)==0||strcmp(name_1,e[i].name)==0)
        {
            printf("该求职者的个人信息如下:\n");
            printf("求职者编号:%s\n",e[i].num);
            printf("姓名:%s\n",e[i].name);
            printf("性别:%s\n",e[i].sex);
            printf("年龄:%s\n",e[i].age);
            printf("民族:%s\n",e[i].nation); 
            printf("联系电话:%s\n",e[i].num_2);
            printf("录用状态:%s\n",e[i].status);
            break;
        }
    }

}

void Changejobhunter()
{
	char id[20];
    char name_2[20];
    char choice_2;
    int i,flag=1; 
   	printf("请输入求职者的编号\n");
   	scanf("%s",&id);
	for(i=0;i<e_size;i++){
		
	
	 	if(strcmp(id,e[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.姓名\n2.性别\n3.年龄\n4.民族\n5.联系电话\n6.录用状态");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("请输入更改后的姓名\n");
	            	scanf("%s",&e[i].name);
	            	printf("修改成功!\n") ;
	        	break;
	        	
	        case 2:
	            printf("请输入更改后的性别\n");
	            scanf("%s",&e[i].sex);
	            printf("修改成功!\n") ;
	            break;
	        case 3:
	        	printf("请输入更改后的年龄\n");
	            scanf("%s",&e[i].age);
	            printf("修改成功!\n") ;
	            break;
	        case 4:
	        	printf("请输入更改后的民族\n");
	            scanf("%s",&e[i].nation);
	            printf("修改成功!\n") ;
	            break;
	        case 5: 
	        	printf("请输入更改后的联系电话\n");
	            scanf("%s",&e[i].num_2);
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
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("company.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].needs,s[i].num_1,s[i].money,s[i].request);
	    }
	    fclose(fp);
	    printf("公司信息已经保存到文件company.txt中!\n");
	    
}
void Savejobhunter()                                 //保存信息 
{  
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("jobhunter.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s %s\n",e[i].num,e[i].name,e[i].sex,e[i].age,e[i].nation,e[i].num_2,e[i].status);
	    }
	    fclose(fp);
	    printf("求职者信息已经保存到文件jobhunter.txt中!\n");
	    
}

int main()
{
    int choice=1;
    s_size=0;
    e_size=0;
    while(choice)
    {
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Add_company();
            break;
        case 2:
            Search();
            break;
        case 3:
			Change();
			break; 
		case 4:
			Add_jobhunter();
			break; 
		case 5:
			 Searchjobhunter() ;
			 break; 
		case 6:
			Changejobhunter();
			break; 	
        case 7:
            Save();
            break;
        case 8:
        	Savejobhunter();
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
