#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct patient //患者信息结构体
{
	char name[20];            //姓名
	char num[20];			 //住院号
	char sex[20];             //性别 
	char age[20];           //年龄 
	char money[20];         //所交金额 
	char bed[20];           //床号 
	char date[20];         //住院日期 
};
int s_size;
struct patient s[1000];

void menu()                                         //菜单 
{   printf("\n");
	printf("     欢迎使用本住院管理系统\n");
	printf("*--------------------------------------*\n");
    printf("*       1,患者信息录入                 *\n");
    printf("*       2,患者查询                     *\n");
    printf("*       3,患者信息更改                 *\n");
    printf("*       4,保存信息                     *\n");
    printf("*       0,退出系统                     *\n");
    printf("*--------------------------------------*\n");
    printf("请选择: ");
}
void Add_patient()                                    //增加患者 
{
	char choose_2;
	printf("警告！！住院号输入后不可更改，请确认无误后再输入。") ;
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("请输入患者住院号: ");
	    scanf("%s",s[s_size].num);
	    printf("请输入患者姓名: ");
	    scanf("%s",s[s_size].name);
	    printf("请输入患者性别: ");
	    scanf("%s",s[s_size].sex);
	    printf("请输入患者年龄: ");
	    scanf("%s",s[s_size].age);
	    printf("请输入患者的床号: "); 
		scanf("%s",s[s_size].bed);
		printf("请输入患者所交费用: "); 
		scanf("%s",s[s_size].money);
	    printf("请输入患者的住院日期: ");
		scanf("%s",s[s_size].date); 
	    s_size++;
	    printf("录入患者信息成功!\n");
	}
}

void Search()                                  //查询患者 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.通过患者的住院号查询     B.通过患者的姓名查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入患者的住院号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入患者的姓名\n");
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
            printf("该患者的住院信息如下:\n");
            printf("住院号:%s\n",s[i].num);
            printf("姓名:%s\n",s[i].name);
            printf("性别:%s\n",s[i].sex);
            printf("年龄:%s\n",s[i].age);
            printf("床号:%s\n",s[i].bed);
            printf("所交费用:%s\n",s[i].money); 
            printf("住院日期:%s\n",s[i].date);
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
   	printf("请输入患者的住院号\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
		
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.姓名\n2.性别\n3.年龄\n4.床号\n5.所交费用\n6.住院日期\n");
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
	            printf("请输入更改后的床号\n");
	            scanf("%s",&s[i].bed);
	            printf("修改成功!\n") ;
				break; 
	        case 5:
	        	printf("请输入更改后的费用\n");
	            scanf("%s",&s[i].money);
	            printf("修改成功!\n") ;
	            break;
	        case 6: 
	        	printf("请输入更改后的住院日期\n");
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
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("Patient.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].bed,s[i].money,s[i].date);
	    }
	    fclose(fp);
	    printf("患者住院信息已经保存到文件Patient.txt中!\n");
	    
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
            Add_patient();
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
