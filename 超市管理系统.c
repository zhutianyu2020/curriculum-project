#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct goods //��Ʒ��Ϣ�ṹ��
{
	char name[20];            //��Ʒ��
	char num[20];			 //��Ʒ���
	char money[20];         //��Ʒ��� 
	char num_1[20];         //��Ʒ���� 
	char date_1[20];         //��Ʒ�������� 
	char date_2[20]; 		//��Ʒ����/������ 
};
struct employee //Ա����Ϣ�ṹ��
{
	char name[20];            //Ա������
	char sex[20];              //Ա���Ա� 
	char num[20];			 //Ա�����
	char age[20];            //Ա������ 
	char money[20];         //Ա��ÿ�¹��� 
	char date[20];         //Ա����ְ���� 
};

int s_size;
struct goods s[1000];
int e_size;
struct employee e[1000];
 

void menu()                                         //�˵� 
{   printf("\n");
	printf("     ��ӭʹ�ñ����й���ϵͳ\n");
	printf("*--------------------------------------*\n");
    printf("*       1,��Ʒ��Ϣ¼��                 *\n");
    printf("*       2,��Ʒ��ѯ                     *\n");
    printf("*       3,��Ʒ��Ϣ����                 *\n");
    printf("*       4,Ա����Ϣ¼��                 *\n");
    printf("*       5,Ա����Ϣ��ѯ                 *\n");
    printf("*       6,Ա����Ϣ����                 *\n");
    printf("*       7,������Ʒ��Ϣ                 *\n");
    printf("*       8,����Ա����Ϣ                   *\n");
    printf("*       0,�˳�ϵͳ                     *\n");
    printf("*--------------------------------------*\n");
    printf("��ѡ��: ");
}
void Add_goods()                                    //���ӻ��� 
{
	char choose_2;
	printf("���棡����Ʒ������󲻿ɸ��ģ���ȷ������������롣");
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("��������Ʒ���: ");
	    scanf("%s",s[s_size].num);
	    printf("��������Ʒ����: ");
	    scanf("%s",s[s_size].name);
	    printf("��������Ʒ���: ");
	    scanf("%s",s[s_size].money);
	    printf("��������Ʒ����: ");
	    scanf("%s",s[s_size].num_1);
	    printf("��������Ʒ����������: ");
		scanf("%s",s[s_size].date_1);
		printf("��������Ʒ�ı���/������: ");
		scanf("%s",s[s_size].date_2);
	    s_size++;
	    printf("¼����Ʒ��Ϣ�ɹ�!\n");
	}
}

void Search()                                  //��ѯ��Ʒ 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.ͨ����Ʒ��źŲ�ѯ     B.ͨ����Ʒ�����Ʋ�ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("��������Ʒ��ź�\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("��������Ʒ����\n");
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
            printf("����Ʒ����ϸ��Ϣ����:\n");
            printf("��Ʒ���:%s\n",s[i].num);
            printf("��Ʒ����:%s\n",s[i].name); 
            printf("��Ʒ���:%s\n",s[i].money);
            printf("��Ʒ���:%s\n",s[i].num_1);
            printf("��������:%s\n",s[i].date_1); 
            printf("����/������:%s\n",s[i].date_2);
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
   	printf("��������Ʒ���\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.��Ʒ����\n2.��Ʒ���\n3.��Ʒ���\n4.��������\n5.����/������\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("��������ĺ����Ʒ����\n");
	            	scanf("%s",&s[i].name);
	            	printf("�޸ĳɹ�!\n") ;
	        	break;
	        	
	        case 2:
	            printf("��������ĺ����Ʒ���\n");
	            scanf("%s",&s[i].money);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 3:
	        	printf("��������ĺ����Ʒ���n");
	            scanf("%s",&s[i].num_1);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 4:
	            printf("��������ĺ����������\n");
	            scanf("%s",&s[i].date_1);
	            printf("�޸ĳɹ�!\n") ;
				break; 
	        case 5:
	        	printf("��������ĺ�ı���/������\n");
	            scanf("%s",&s[i].date_2);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        default:
	            printf("�������!\n");
	            break;
	
	        }
		}
		else
			printf("���޴���Ʒ\n");

	}
} 

void Add_employee()                                    //����ְԱ 
{
	char choose_2;
	printf("���棡��Ա��������󲻿ɸ��ģ���ȷ������������롣") ;
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("������Ա����: ");
    scanf("%s",e[e_size].num);
    printf("������Ա������: ");
    scanf("%s",e[e_size].name);
    printf("������Ա���Ա�: ");
    scanf("%s",e[e_size].sex);
    printf("������Ա������: ");
    scanf("%s",e[e_size].age);
	printf("������Ա����ÿ�¹���: "); 
	scanf("%s",e[e_size].money);
    printf("������Ա������ְ����: ");
	scanf("%s",e[e_size].date); 
    e_size++;
    printf("¼��Ա������Ϣ�ɹ�!\n");
	}
}

void Searchemployee()                                  //��ѯְԱ 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.ͨ��Ա����Ա���Ų�ѯ     B.ͨ��Ա��������ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("������Ա����Ա����\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("������Ա��������\n");
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
            printf("��Ա���ĸ�����Ϣ����:\n");
            printf("Ա����:%s\n",e[i].num);
            printf("����:%s\n",e[i].name);
            printf("�Ա�:%s\n",e[i].sex);
            printf("����:%s\n",e[i].age);
            printf("ÿ�¹���:%s\n",e[i].money); 
            printf("��ְ����:%s\n",e[i].date);
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
   	printf("������Ա����Ա����\n");
   	scanf("%s",&id);
	for(i=0;i<e_size;i++){
		
	
	 	if(strcmp(id,e[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.����\n2.�Ա�\n3.����\n4.ÿ�¹���\n5.��ְ����\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("��������ĺ������\n");
	            	scanf("%s",&e[i].name);
	            	printf("�޸ĳɹ�!\n") ;
	        	break;
	        	
	        case 2:
	            printf("��������ĺ���Ա�\n");
	            scanf("%s",&e[i].sex);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 3:
	        	printf("��������ĺ������\n");
	            scanf("%s",&e[i].age);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 4:
	        	printf("��������ĺ��ÿ�¹���\n");
	            scanf("%s",&e[i].money);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 5: 
	        	printf("��������ĺ����ְ����\n");
	            scanf("%s",&e[i].date);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        default:
	            printf("�������!\n");
	            break;
	
	        }
		}
		else
			printf("���޴���\n");

	}
} 


void Save()                                 //������Ϣ 
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
	    printf("��Ʒ��Ϣ�Ѿ����浽�ļ�Goods.txt��!\n");
	    
}
void Saveemployee()                                 //������Ϣ 
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
	    printf("Ա����Ϣ�Ѿ����浽�ļ�employee.txt��!\n");
	    
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
            printf("�������!\n");
            break;

        }
    }

    return 0;
}
