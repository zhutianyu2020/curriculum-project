#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct equipment //实验设备信息结构体
{
	char name[20];            //设备名动 
	char num[20];			 //设备编号
	char money[20];         //设备价格 
	char date_1[20];         //设备购入日期 
	char status[20];		//设备状态，是否报废
	char date_2[20];        //报废日期 
};
struct record //设备使用记录结构体
{
	char name[20];            //使用记录者姓名
	char sex[20];              //使用记录者性别 
	char num[20];			 //使用记录者编号
	char age[20];            //使用记录者年龄 
	char date[20];         //使用日期 
};

int s_size;
struct equipment s[1000];
int e_size;
struct record e[1000];
 

void menu()                                         //菜单 
{   printf("\n");
	printf("     欢迎使用本实验设备管理系统\n");
	printf("*----------------------------------------- *\n");
    printf("*       1,实验设备信息录入                 *\n");
    printf("*       2,实验设备信息查询                 *\n");
    printf("*       3,实验设备信息更改                 *\n");
    printf("*       4,使用信息录入                     *\n");
    printf("*       5,使用信息查询                     *\n");
    printf("*       6,使用信息更改                     *\n");
    printf("*       7,保存实验设备信息                 *\n");
    printf("*       8,保存使用信息                     *\n");
    printf("*       0,退出系统                         *\n");
    printf("*----------------------------------------- *\n");
    printf("请选择: ");
}
void Add_equipment()                                    //增加实验设备 
{
	char choose_2;
	printf("警告！！实验设备编号输入后不可更改，请确认无误后再输入。\n");
	printf("确认请按T，返回请按任意键\n");
	scanf("%c",&choose_2);                           //读取回车 
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("请输入实验设备编号: ");
	    scanf("%s",s[s_size].num);
	    printf("请输入实验设备名称: ");
	    scanf("%s",s[s_size].name);
	    printf("请输入实验设备价格: ");
	    scanf("%s",s[s_size].money);
	    printf("请输入实验设备购入日期: ");
		scanf("%s",s[s_size].date_1);
		printf("请输入实验设备状态: ");
		scanf("%s",s[s_size].status);
		printf("请输入实验设备报废日期:(如未报废则不需要输入)"); 
		scanf("%s",s[s_size].date_2);
	    s_size++;
	    printf("录入实验设备信息成功!\n");
	}
}

void Search()                                  //查询实验设备 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.通过实验设备编号查询     B.通过实验设备名称查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入实验设备编号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入实验设备名称\n");
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
            printf("该实验设备的详细信息如下:\n");
            printf("实验设备编号:%s\n",s[i].num);
            printf("实验设备名称:%s\n",s[i].name); 
            printf("实验设备价格:%s\n",s[i].money); 
            printf("实验设备购入日期:%s\n",s[i].date_1);
            printf("实验设备状态:%s\n",s[i].status);
            printf("实验设备报废日期:%s\n",s[i].date_2);
            flag=0;
            break;
        }
    }

}

void Change()																				//更改实验设备 
{
	char id[20];
    char name_2[20];
    char choice_2;
    int i,flag=1; 
   	printf("请输入实验设备编号\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.实验设备名称\n2.实验设备价格\n3.实验设备购入日期\n4.实验设备状态\n5.实验设备报废日期\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("请输入更改后的实验设备名称\n");
	            	scanf("%s",&s[i].name);
	            	printf("修改成功!\n") ;
	        	break;
	        	
	        case 2:
	            printf("请输入更改后的实验设备价格\n");
	            scanf("%s",&s[i].money);
	            printf("修改成功!\n") ;
	            break;
	        case 3:
	        	printf("请输入更改后的实验设备购入日期\n");
	            scanf("%s",&s[i].date_1);
	            printf("修改成功!\n") ;
	            break;
	        case 4:
	            printf("请输入更改后的实验设备状态\n");
	            scanf("%s",&s[i].status);
	            printf("修改成功!\n") ;
				break; 
	        case 5:
	        	printf("请输入更改后的实验设备报废日期\n");
	            scanf("%s",&s[i].date_2);
	            printf("修改成功!\n") ;
	            break;
	        default:
	            printf("命令错误!\n");
	            break;
	
	        }
		}
		else
			printf("查无此设备\n");

	}
} 

void Add_record()                                    //增加记录
{
	char choose_2;
	printf("警告！！使用者编号输入后不可更改，请确认无误后再输入。\n") ;
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("请输入使用者的编号: ");
    scanf("%s",e[e_size].num);
    printf("请输入使用者姓名: ");
    scanf("%s",e[e_size].name);
    printf("请输入使用者性别: ");
    scanf("%s",e[e_size].sex);
    printf("请输入使用者年龄: ");
    scanf("%s",e[e_size].age);
    printf("请输入使用日期: ");
	scanf("%s",e[e_size].date); 
    e_size++;
    printf("录入使用者信息成功!\n");
	}
}

void Searchrecord()                                  //查询记录
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
    	printf("\n");
	    printf("A.通过使用者编号查询     B.通过使用者姓名查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入使用者的编号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入使用者的姓名\n");
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
            printf("该使用者的个人信息如下:\n");
            printf("编号:%s\n",e[i].num);
            printf("姓名:%s\n",e[i].name);
            printf("性别:%s\n",e[i].sex);
            printf("年龄:%s\n",e[i].age); 
            printf("使用日期:%s\n",e[i].date);
            flag=0;
            break;
        }
    }

}

void Changerecord()                                                            //更改记录 
{
	char id[20];
    char name_2[20];
    char choice_2;
    int i,flag=1; 
   	printf("请输入使用者的编号\n");
   	scanf("%s",&id);
	for(i=0;i<e_size;i++){
		
	
	 	if(strcmp(id,e[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.姓名\n2.性别\n3.年龄\n4使用日期\n");
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
	        	printf("请输入更改后的使用日期\n");
	            scanf("%s",&e[i].date);
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
	    fp=fopen("equipment.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].money,s[i].date_1,s[i].status,s[i].date_2);
	    }
	    fclose(fp);
	    printf("实验设备信息已经保存到文件equipment.txt中!\n");
	    
}
void Saverecord()                                 //保存信息 
{  
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("record.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s\n",e[i].num,e[i].name,e[i].sex,e[i].age,e[i].date);
	    }
	    fclose(fp);
	    printf("使用者信息已经保存到文件record.txt中!\n");
	    
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
            Add_equipment();
            break;
        case 2:
            Search();
            break;
        case 3:
			Change();
			break; 
		case 4:
			Add_record();
			break; 
		case 5:
			 Searchrecord() ;
			 break; 
		case 6:
			Changerecord();
			break; 	
        case 7:
            Save();
            break;
        case 8:
        	Saverecord();
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
