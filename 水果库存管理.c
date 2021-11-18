#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct fruit //水果信息结构体
{
	char name[20];            //水果名称 
	char num[20];			 //水果编号
	char money[20];         //水果售价 
	char num_1[20];         //水果库存 
	char date_1[20];         //水果进货日期 
	char date_2[20]; 		//水果保质期 
};
struct supplier //供应商信息结构体
{
	char name[20];             //供应商公司名称
	char num[20];            //供应商编号 
	char num_2[20];			 //供应商联系电话 
	char place[20];            //供应商地址 
	char money[20];         //进货花费 
	char date[20];         //进货日期 
};

int s_size;
struct fruit s[1000];
int e_size;
struct supplier e[1000];
 

void menu()                                         //菜单 
{   printf("\n");
	printf("    欢迎使用本水果库存管理系统\n");
	printf("*--------------------------------------*\n");
    printf("*       1,水果信息录入                 *\n");
    printf("*       2,水果信息查询                 *\n");
    printf("*       3,水果信息更改                 *\n");
    printf("*       4,供应商信息录入               *\n");
    printf("*       5,供应商信息查询               *\n");
    printf("*       6,供应商信息更改               *\n");
    printf("*       7,保存水果信息                 *\n");
    printf("*       8,保存供应商信息               *\n");
    printf("*       0,退出系统                     *\n");
    printf("*--------------------------------------*\n");
    printf("请选择: ");
}
void Add_fruit()                                    //增加水果 
{
	char choose_2;
	printf("警告！！水果编号输入后不可更改，请确认无误后再输入。");
	printf("确认请按T，返回请按任意键\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("请输入水果编号: ");
	    scanf("%s",s[s_size].num);
	    printf("请输入水果名称: ");
	    scanf("%s",s[s_size].name);
	    printf("请输入水果金额: ");
	    scanf("%s",s[s_size].money);
	    printf("请输入水果数量: ");
	    scanf("%s",s[s_size].num_1);
	    printf("请输入水果的进货日期: ");
		scanf("%s",s[s_size].date_1);
		printf("请输入水果的保质期: ");
		scanf("%s",s[s_size].date_2);
	    s_size++;
	    printf("录入水果信息成功!\n");
	}
}

void Search()                                  //查询水果 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.通过水果编号查询     B.通过水果名称查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入水果编号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入水果名称\n");
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
            printf("该水果的详细信息如下:\n");
            printf("水果编号:%s\n",s[i].num);
            printf("水果名称:%s\n",s[i].name); 
            printf("水果售价:%s\n",s[i].money);
            printf("水果库存:%s\n",s[i].num_1);
            printf("进货日期:%s\n",s[i].date_1); 
            printf("保质期:%s\n",s[i].date_2);
            break;
        }
        else{
        	printf("查无此水果\n");
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
   	printf("请输入水果编号\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.水果名称\n2.水果金额\n3.水果库存\n4.进货日期\n5.保质期\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("请输入更改后的水果名称\n");
	            	scanf("%s",&s[i].name);
	            	printf("修改成功!\n") ;
	        	break;
	        	
	        case 2:
	            printf("请输入更改后的水果金额\n");
	            scanf("%s",&s[i].money);
	            printf("修改成功!\n") ;
	            break;
	        case 3:
	        	printf("请输入更改后的水果库存n");
	            scanf("%s",&s[i].num_1);
	            printf("修改成功!\n") ;
	            break;
	        case 4:
	            printf("请输入更改后的进货日期\n");
	            scanf("%s",&s[i].date_1);
	            printf("修改成功!\n") ;
				break; 
	        case 5:
	        	printf("请输入更改后的保质期\n");
	            scanf("%s",&s[i].date_2);
	            printf("修改成功!\n") ;
	            break;
	        default:
	            printf("命令错误!\n");
	            break;
	
	        }
		}
		else
			printf("查无此水果\n");

	}
} 

void Add_supplier()                                    //增加供应商 
{
	char choose_2;
	printf("警告！！供应商编号输入后不可更改，请确认无误后再输入。") ;
	printf("确认请按T，返回请按F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("请输入供应商编号: ");
    scanf("%s",e[e_size].num);
    printf("请输入供应商名称: ");
    scanf("%s",e[e_size].name);
    printf("请输入供应商联系电话: ");
    scanf("%s",e[e_size].num_2);
    printf("请输入供应商地址: ");
    scanf("%s",e[e_size].place);
	printf("请输入进货花费: "); 
	scanf("%s",e[e_size].money);
    printf("请输入进货日期: ");
	scanf("%s",e[e_size].date); 
    e_size++;
    printf("录入供应商工信息成功!\n");
	}
}

void Searchsupplier()                                  //查询供应商
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i;
    while(1){
	    printf("A.通过供应商的编号查询     B.通过供应商名称查询:\n");
	    scanf("%c",&choose_1);               //读取回车键 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("请输入供应商的编号\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("请输入供应商的名称\n");
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
            printf("该供应商的详细信息如下:\n");
            printf("供应商编号:%s\n",e[i].num);
            printf("供应商名称:%s\n",e[i].name);
            printf("供应商联系电话:%s\n",e[i].num_2);
            printf("供应商地址:%s\n",e[i].place);
            printf("进货花费:%s\n",e[i].money); 
            printf("进货日期:%s\n",e[i].date); 
            break;
        }
    }

}

void Changesupplier()
{
	char id[20];
    char name_2[20];
    char choice_2;
    int i,flag=1; 
   	printf("请输入供应商的编号\n");
   	scanf("%s",&id);
	for(i=0;i<e_size;i++){
		
	
	 	if(strcmp(id,e[i].num)==0){
	    printf("请选择修改项\n");
	    printf("1.供应商名称\n2.联系电话\n3地址.\n4.进货花费\n5.进货日期\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("请输入更改后的供应商名称\n");
	            	scanf("%s",&e[i].name);
	            	printf("修改成功!\n") ;
	        	break;
	        	
	        case 2:
	            printf("请输入更改后的供应商联系电话\n");
	            scanf("%s",&e[i].num_2);
	            printf("修改成功!\n") ;
	            break;
	        case 3:
	        	printf("请输入更改后的供应商地址\n");
	            scanf("%s",&e[i].place);
	            printf("修改成功!\n") ;
	            break;
	        case 4:
	        	printf("请输入更改后的进货花费\n");
	            scanf("%s",&e[i].money);
	            printf("修改成功!\n") ;
	            break;
	        case 5: 
	        	printf("请输入更改后的进货日期\n");
	            scanf("%s",&e[i].date);
	            printf("修改成功!\n") ;
	            break;
	        default:
	            printf("命令错误!\n");
	            break;
	
	        }
		}
		else
			printf("查无此供应商\n");

	}
} 


void Save()                                 //保存信息 
{  
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("fruit.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].money,s[i].num_1,s[i].date_1,s[i].date_2);
	    }
	    fclose(fp);
	    printf("水果信息已经保存到文件fruit.txt中!\n");
	    
}
void Savesupplier()                                 //保存信息 
{  
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("supplier.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",e[i].num,e[i].name,e[i].num_2,e[i].place,e[i].money,e[i].date);
	    }
	    fclose(fp);
	    printf("供应商信息已经保存到文件supplier.txt中!\n");
	    
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
            Add_fruit();
            break;
        case 2:
            Search();
            break;
        case 3:
			Change();
			break; 
		case 4:
			Add_supplier();
			break; 
		case 5:
			 Searchsupplier() ;
			 break; 
		case 6:
			Changesupplier();
			break; 	
        case 7:
            Save();
            break;
        case 8:
        	Savesupplier();
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
