#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct fruit //ˮ����Ϣ�ṹ��
{
	char name[20];            //ˮ������ 
	char num[20];			 //ˮ�����
	char money[20];         //ˮ���ۼ� 
	char num_1[20];         //ˮ����� 
	char date_1[20];         //ˮ���������� 
	char date_2[20]; 		//ˮ�������� 
};
struct supplier //��Ӧ����Ϣ�ṹ��
{
	char name[20];             //��Ӧ�̹�˾����
	char num[20];            //��Ӧ�̱�� 
	char num_2[20];			 //��Ӧ����ϵ�绰 
	char place[20];            //��Ӧ�̵�ַ 
	char money[20];         //�������� 
	char date[20];         //�������� 
};

int s_size;
struct fruit s[1000];
int e_size;
struct supplier e[1000];
 

void menu()                                         //�˵� 
{   printf("\n");
	printf("    ��ӭʹ�ñ�ˮ��������ϵͳ\n");
	printf("*--------------------------------------*\n");
    printf("*       1,ˮ����Ϣ¼��                 *\n");
    printf("*       2,ˮ����Ϣ��ѯ                 *\n");
    printf("*       3,ˮ����Ϣ����                 *\n");
    printf("*       4,��Ӧ����Ϣ¼��               *\n");
    printf("*       5,��Ӧ����Ϣ��ѯ               *\n");
    printf("*       6,��Ӧ����Ϣ����               *\n");
    printf("*       7,����ˮ����Ϣ                 *\n");
    printf("*       8,���湩Ӧ����Ϣ               *\n");
    printf("*       0,�˳�ϵͳ                     *\n");
    printf("*--------------------------------------*\n");
    printf("��ѡ��: ");
}
void Add_fruit()                                    //����ˮ�� 
{
	char choose_2;
	printf("���棡��ˮ���������󲻿ɸ��ģ���ȷ������������롣");
	printf("ȷ���밴T�������밴�����\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("������ˮ�����: ");
	    scanf("%s",s[s_size].num);
	    printf("������ˮ������: ");
	    scanf("%s",s[s_size].name);
	    printf("������ˮ�����: ");
	    scanf("%s",s[s_size].money);
	    printf("������ˮ������: ");
	    scanf("%s",s[s_size].num_1);
	    printf("������ˮ���Ľ�������: ");
		scanf("%s",s[s_size].date_1);
		printf("������ˮ���ı�����: ");
		scanf("%s",s[s_size].date_2);
	    s_size++;
	    printf("¼��ˮ����Ϣ�ɹ�!\n");
	}
}

void Search()                                  //��ѯˮ�� 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.ͨ��ˮ����Ų�ѯ     B.ͨ��ˮ�����Ʋ�ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("������ˮ�����\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("������ˮ������\n");
	    	scanf("%s",&name_1);
	    	break;
		}
	    else
	    	printf("�����������������\n"); 
    }	
    for(i=0;i<s_size;i++)
    {
        if(strcmp(id,s[i].num)==0||strcmp(name_1,s[i].name)==0)
        {
            printf("��ˮ������ϸ��Ϣ����:\n");
            printf("ˮ�����:%s\n",s[i].num);
            printf("ˮ������:%s\n",s[i].name); 
            printf("ˮ���ۼ�:%s\n",s[i].money);
            printf("ˮ�����:%s\n",s[i].num_1);
            printf("��������:%s\n",s[i].date_1); 
            printf("������:%s\n",s[i].date_2);
            break;
        }
        else{
        	printf("���޴�ˮ��\n");
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
   	printf("������ˮ�����\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.ˮ������\n2.ˮ�����\n3.ˮ�����\n4.��������\n5.������\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("��������ĺ��ˮ������\n");
	            	scanf("%s",&s[i].name);
	            	printf("�޸ĳɹ�!\n") ;
	        	break;
	        	
	        case 2:
	            printf("��������ĺ��ˮ�����\n");
	            scanf("%s",&s[i].money);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 3:
	        	printf("��������ĺ��ˮ�����n");
	            scanf("%s",&s[i].num_1);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 4:
	            printf("��������ĺ�Ľ�������\n");
	            scanf("%s",&s[i].date_1);
	            printf("�޸ĳɹ�!\n") ;
				break; 
	        case 5:
	        	printf("��������ĺ�ı�����\n");
	            scanf("%s",&s[i].date_2);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        default:
	            printf("�������!\n");
	            break;
	
	        }
		}
		else
			printf("���޴�ˮ��\n");

	}
} 

void Add_supplier()                                    //���ӹ�Ӧ�� 
{
	char choose_2;
	printf("���棡����Ӧ�̱������󲻿ɸ��ģ���ȷ������������롣") ;
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("�����빩Ӧ�̱��: ");
    scanf("%s",e[e_size].num);
    printf("�����빩Ӧ������: ");
    scanf("%s",e[e_size].name);
    printf("�����빩Ӧ����ϵ�绰: ");
    scanf("%s",e[e_size].num_2);
    printf("�����빩Ӧ�̵�ַ: ");
    scanf("%s",e[e_size].place);
	printf("�������������: "); 
	scanf("%s",e[e_size].money);
    printf("�������������: ");
	scanf("%s",e[e_size].date); 
    e_size++;
    printf("¼�빩Ӧ�̹���Ϣ�ɹ�!\n");
	}
}

void Searchsupplier()                                  //��ѯ��Ӧ��
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i;
    while(1){
	    printf("A.ͨ����Ӧ�̵ı�Ų�ѯ     B.ͨ����Ӧ�����Ʋ�ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("�����빩Ӧ�̵ı��\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("�����빩Ӧ�̵�����\n");
	    	scanf("%s",&name_1);
	    	break;
		}
	    else
	    	printf("�����������������\n"); 
    }	
    for(i=0;i<e_size;i++)
    {
        if(strcmp(id,e[i].num)==0||strcmp(name_1,e[i].name)==0)
        {
            printf("�ù�Ӧ�̵���ϸ��Ϣ����:\n");
            printf("��Ӧ�̱��:%s\n",e[i].num);
            printf("��Ӧ������:%s\n",e[i].name);
            printf("��Ӧ����ϵ�绰:%s\n",e[i].num_2);
            printf("��Ӧ�̵�ַ:%s\n",e[i].place);
            printf("��������:%s\n",e[i].money); 
            printf("��������:%s\n",e[i].date); 
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
   	printf("�����빩Ӧ�̵ı��\n");
   	scanf("%s",&id);
	for(i=0;i<e_size;i++){
		
	
	 	if(strcmp(id,e[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.��Ӧ������\n2.��ϵ�绰\n3��ַ.\n4.��������\n5.��������\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("��������ĺ�Ĺ�Ӧ������\n");
	            	scanf("%s",&e[i].name);
	            	printf("�޸ĳɹ�!\n") ;
	        	break;
	        	
	        case 2:
	            printf("��������ĺ�Ĺ�Ӧ����ϵ�绰\n");
	            scanf("%s",&e[i].num_2);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 3:
	        	printf("��������ĺ�Ĺ�Ӧ�̵�ַ\n");
	            scanf("%s",&e[i].place);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 4:
	        	printf("��������ĺ�Ľ�������\n");
	            scanf("%s",&e[i].money);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 5: 
	        	printf("��������ĺ�Ľ�������\n");
	            scanf("%s",&e[i].date);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        default:
	            printf("�������!\n");
	            break;
	
	        }
		}
		else
			printf("���޴˹�Ӧ��\n");

	}
} 


void Save()                                 //������Ϣ 
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
	    printf("ˮ����Ϣ�Ѿ����浽�ļ�fruit.txt��!\n");
	    
}
void Savesupplier()                                 //������Ϣ 
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
	    printf("��Ӧ����Ϣ�Ѿ����浽�ļ�supplier.txt��!\n");
	    
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
            printf("�������!\n");
            break;

        }
    }

    return 0;
}
