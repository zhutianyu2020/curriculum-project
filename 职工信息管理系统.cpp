#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee //ְ����Ϣ�ṹ��
{
	char name[20];            //����
	char num[20];			 //ְ����
	char sex[20];             //�Ա� 
	char age[20];           //���� 
	char money[20];         //ÿ�¹��� 
	char date[20];         //��ְ���� 
};
int s_size;
struct employee s[1000];

void menu()                                         //�˵� 
{   printf("\n");
	printf("     ��ӭʹ�ñ�ְ������ϵͳ\n");
	printf("****************************************\n");
    printf("*       1,ְ����Ϣ¼��                 *\n");
    printf("*       2,ְ����ѯ                     *\n");
    printf("*       3,ְ����Ϣ����                 *\n");
    printf("*       4,������Ϣ                     *\n");
    printf("*       0,�˳�ϵͳ                     *\n");
    printf("****************************************\n");
    printf("��ѡ��: ");
}
void Add_employee()                                    //����ְԱ 
{
	char choose_2;
	printf("���棡��ְ��������󲻿ɸ��ģ���ȷ������������롣") ;
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("������ְ����: ");
    scanf("%s",s[s_size].num);
    printf("������ְ������: ");
    scanf("%s",s[s_size].name);
    printf("������ְ���Ա�: ");
    scanf("%s",s[s_size].sex);
    printf("������ְ������: ");
    scanf("%s",s[s_size].age);
	printf("������ְ����ÿ�¹���: "); 
	scanf("%s",s[s_size].money);
    printf("������ְ������ְ����: ");
	scanf("%s",s[s_size].date); 
    s_size++;
    printf("¼��ְ����Ϣ�ɹ�!\n");
	}
}

void Search()                                  //��ѯְԱ 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.ͨ��ְ����ְ���Ų�ѯ     B.ͨ��ְ�������Ĳ�ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("������ְ����ְ����\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("������ְ��������\n");
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
            printf("��ְ���ĸ�����Ϣ����:\n");
            printf("ְ����:%s\n",s[i].num);
            printf("����:%s\n",s[i].name);
            printf("�Ա�:%s\n",s[i].sex);
            printf("����:%s\n",s[i].age);
            printf("ÿ�¹���:%s\n",s[i].money); 
            printf("��ְ����:%s\n",s[i].date);
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
   	printf("������ְ����ְ����\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
		
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.����\n2.�Ա�\n3.����\n4.ÿ�¹���\n6.��ְ����\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("��������ĺ������\n");
	            	scanf("%s",&s[i].name);
	            	printf("�޸ĳɹ�!\n") ;
	        	break;
	        	
	        case 2:
	            printf("��������ĺ���Ա�\n");
	            scanf("%s",&s[i].sex);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 3:
	        	printf("��������ĺ������\n");
	            scanf("%s",&s[i].age);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 4:
	        	printf("��������ĺ��ÿ�¹���\n");
	            scanf("%s",&s[i].money);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 5: 
	        	printf("��������ĺ����ְ����\n");
	            scanf("%s",&s[i].date);
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
	
	    FILE *fp;
	    int i;
	    fp=fopen("Patient.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].money,s[i].date);
	    }
	    fclose(fp);
	    printf("ְ����Ϣ�Ѿ����浽�ļ�.txt��!\n");
	    
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
            Add_employee();
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
            printf("�������!\n");
            break;

        }
    }

    return 0;
}
