#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct patient //������Ϣ�ṹ��
{
	char name[20];            //����
	char num[20];			 //סԺ��
	char sex[20];             //�Ա� 
	char age[20];           //���� 
	char money[20];         //������� 
	char bed[20];           //���� 
	char date[20];         //סԺ���� 
};
int s_size;
struct patient s[1000];

void menu()                                         //�˵� 
{   printf("\n");
	printf("     ��ӭʹ�ñ�סԺ����ϵͳ\n");
	printf("*--------------------------------------*\n");
    printf("*       1,������Ϣ¼��                 *\n");
    printf("*       2,���߲�ѯ                     *\n");
    printf("*       3,������Ϣ����                 *\n");
    printf("*       4,������Ϣ                     *\n");
    printf("*       0,�˳�ϵͳ                     *\n");
    printf("*--------------------------------------*\n");
    printf("��ѡ��: ");
}
void Add_patient()                                    //���ӻ��� 
{
	char choose_2;
	printf("���棡��סԺ������󲻿ɸ��ģ���ȷ������������롣") ;
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("�����뻼��סԺ��: ");
	    scanf("%s",s[s_size].num);
	    printf("�����뻼������: ");
	    scanf("%s",s[s_size].name);
	    printf("�����뻼���Ա�: ");
	    scanf("%s",s[s_size].sex);
	    printf("�����뻼������: ");
	    scanf("%s",s[s_size].age);
	    printf("�����뻼�ߵĴ���: "); 
		scanf("%s",s[s_size].bed);
		printf("�����뻼����������: "); 
		scanf("%s",s[s_size].money);
	    printf("�����뻼�ߵ�סԺ����: ");
		scanf("%s",s[s_size].date); 
	    s_size++;
	    printf("¼�뻼����Ϣ�ɹ�!\n");
	}
}

void Search()                                  //��ѯ���� 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.ͨ�����ߵ�סԺ�Ų�ѯ     B.ͨ�����ߵ�������ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("�����뻼�ߵ�סԺ��\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("�����뻼�ߵ�����\n");
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
            printf("�û��ߵ�סԺ��Ϣ����:\n");
            printf("סԺ��:%s\n",s[i].num);
            printf("����:%s\n",s[i].name);
            printf("�Ա�:%s\n",s[i].sex);
            printf("����:%s\n",s[i].age);
            printf("����:%s\n",s[i].bed);
            printf("��������:%s\n",s[i].money); 
            printf("סԺ����:%s\n",s[i].date);
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
   	printf("�����뻼�ߵ�סԺ��\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
		
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.����\n2.�Ա�\n3.����\n4.����\n5.��������\n6.סԺ����\n");
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
	            printf("��������ĺ�Ĵ���\n");
	            scanf("%s",&s[i].bed);
	            printf("�޸ĳɹ�!\n") ;
				break; 
	        case 5:
	        	printf("��������ĺ�ķ���\n");
	            scanf("%s",&s[i].money);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 6: 
	        	printf("��������ĺ��סԺ����\n");
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
	    printf("����סԺ��Ϣ�Ѿ����浽�ļ�Patient.txt��!\n");
	    
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
            printf("�������!\n");
            break;

        }
    }

    return 0;
}
