#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct goods //商品信息结构体
{
	char name[20];            //商品名
	char num[20];			 //商品编号
	char money[20];         //商品金额 
	char num_1[20];         //商品数量 
	char date_1[20];         //商品生产日期 
	char date_2[20]; 		//商品保质/保修期 
};
struct employee //员工信息结构体
{
	char name[20];            //员工姓名
	char sex[20];              //员工性别 
	char num[20];			 //员工编号
	char age[20];            //员工年龄 
	char money[20];         //员工每月工资 
	char date[20];         //员工入职日期 
};

int s_size;
struct goods s[1000];
int e_size;
struct employee e[1000];
 

void menu()                                         //菜单 
{   printf("\n");
	printf("     欢迎使用本超市管理系统\n");
	printf("*--------------------------------------*\n");
    printf("*       1,商品信息录入                 *\n");
    printf("*       2,商品查询                     *\n");
    printf("*       3,商品信息更改                 *\n");
    printf("*       4,员工信息录入                 *\n");
    printf("*       5,员工信息查询                 *\n");
    printf("*       6,员工信息更改                 *\n");
    printf("*       7,保存商品信息                 *\n");
    printf("*       8,保存员工信息                   *\n");
    printf("*       0,退出系统                     *\n");
    printf("*--------------------------------------*\n");
    printf("请选择: ");
}
void Add_goods()                                    //增加患者 
{
	char choose_2;
	printf("警告！！商品号输入后不可更改，请确认无误后再输入。");
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("请输入商品编号: ");
	    scanf("%s",s[s_size].num);
	    printf("请输入商品名称: ");
	    scanf("%s",s[s_size].name);
	    printf("请输入商品金额: ");
	    scanf("%s",s[s_size].money);
	    printf("请输入商品数量: ");
	    scanf("%s",s[s_size].num_1);
	    printf("请输入商品的生产日期: ");
		scanf("%s",s[s_size].date_1);
		printf("请输入商品的保质/保修期: ");
		scanf("%s",s[s_size].date_2);
	    s_size++;
	    printf("录入商品信息成功!\n");
	}
}

void Search()                                  //查询商品 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.通过商品编号号查询     B.通过商品的名称查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入商品编号号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入商品名称\n");
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
            printf("该商品的详细信息如下:\n");
            printf("商品编号:%s\n",s[i].num);
            printf("商品名称:%s\n",s[i].name); 
            printf("商品金额:%s\n",s[i].money);
            printf("商品库存:%s\n",s[i].num_1);
            printf("生产日期:%s\n",s[i].date_1); 
            printf("保质/保修期:%s\n",s[i].date_2);
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
   	printf("请输入商品编号\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.商品名称\n2.商品金额\n3.商品库存\n4.生产日期\n5.保质/保修期\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("请输入更改后的商品名称\n");
	            	scanf("%s",&s[i].name);
	            	printf("修改成功!\n") ;
	        	break;
	        	
	        case 2:
	            printf("请输入更改后的商品金额\n");
	            scanf("%s",&s[i].money);
	            printf("修改成功!\n") ;
	            break;
	        case 3:
	        	printf("请输入更改后的商品库存n");
	            scanf("%s",&s[i].num_1);
	            printf("修改成功!\n") ;
	            break;
	        case 4:
	            printf("请输入更改后的生产日期\n");
	            scanf("%s",&s[i].date_1);
	            printf("修改成功!\n") ;
				break; 
	        case 5:
	        	printf("请输入更改后的保质/保修期\n");
	            scanf("%s",&s[i].date_2);
	            printf("修改成功!\n") ;
	            break;
	        default:
	            printf("命令错误!\n");
	            break;
	
	        }
		}
		else
			printf("查无此商品\n");

	}
} 

void Add_employee()                                    //增加职员 
{
	char choose_2;
	printf("警告！！员工号输入后不可更改，请确认无误后再输入。") ;
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("请输入员工号: ");
    scanf("%s",e[e_size].num);
    printf("请输入员工姓名: ");
    scanf("%s",e[e_size].name);
    printf("请输入员工性别: ");
    scanf("%s",e[e_size].sex);
    printf("请输入员工年龄: ");
    scanf("%s",e[e_size].age);
	printf("请输入员工的每月工资: "); 
	scanf("%s",e[e_size].money);
    printf("请输入员工的入职日期: ");
	scanf("%s",e[e_size].date); 
    e_size++;
    printf("录入员工工信息成功!\n");
	}
}

void Searchemployee()                                  //查询职员 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.通过员工的员工号查询     B.通过员工姓名查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入员工的员工号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入员工的姓名\n");
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
            printf("该员工的个人信息如下:\n");
            printf("员工号:%s\n",e[i].num);
            printf("姓名:%s\n",e[i].name);
            printf("性别:%s\n",e[i].sex);
            printf("年龄:%s\n",e[i].age);
            printf("每月工资:%s\n",e[i].money); 
            printf("入职日期:%s\n",e[i].date);
            flag=0;
            break;
        }
    }

}

void Changeemployee()
{
	char id[20];
    char name_2[20];
    char choice_2;
    int i,flag=1; 
   	printf("请输入员工的员工号\n");
   	scanf("%s",&id);
	for(i=0;i<e_size;i++){
		
	
	 	if(strcmp(id,e[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.姓名\n2.性别\n3.年龄\n4.每月工资\n5.入职日期\n");
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
	        	printf("请输入更改后的每月工资\n");
	            scanf("%s",&e[i].money);
	            printf("修改成功!\n") ;
	            break;
	        case 5: 
	        	printf("请输入更改后的入职日期\n");
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
	    fp=fopen("Goods.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].money,s[i].num_1,s[i].date_1,s[i].date_2);
	    }
	    fclose(fp);
	    printf("商品信息已经保存到文件Goods.txt中!\n");
	    
}
void Saveemployee()                                 //保存信息 
{  
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("employee.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",e[i].num,e[i].name,e[i].sex,e[i].age,e[i].money,e[i].date);
	    }
	    fclose(fp);
	    printf("员工信息已经保存到文件employee.txt中!\n");
	    
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
            Add_goods();
            break;
        case 2:
            Search();
            break;
        case 3:
			Change();
			break; 
		case 4:
			Add_employee();
			break; 
		case 5:
			 Searchemployee() ;
			 break; 
		case 6:
			Changeemployee();
			break; 	
        case 7:
            Save();
            break;
        case 8:
        	Saveemployee();
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
