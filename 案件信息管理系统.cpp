#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct lawcase //������Ϣ�ṹ��
{
	char name[20];            //�������� 
	char num[20];			 //������ź�
	char personname[20];         //���������� 
	char sex[20];             //�������������� 
	char age[20];           //�������������� 
	char status[20];           //����״̬ 
	char date[20];         //�ӹܰ�����Ϣ���� 
};
int s_size;
struct lawcase s[1000];

void menu()                                         //�˵� 
{   printf("\n");
	printf("     ��ӭʹ�ñ�������Ϣ����ϵͳ\n");
	printf("*--------------------------------------*\n");
    printf("*       1,������Ϣ¼��                 *\n");
    printf("*       2,������ѯ                     *\n");
    printf("*       3,������Ϣ����                 *\n");
    printf("*       4,���永����Ϣ                 *\n");
    printf("*       0,�˳�ϵͳ                     *\n");
    printf("*--------------------------------------*\n");
    printf("��ѡ��: ");
}
void Add_lawcase()                                    //���ӻ��� 
{
	int choose_2; 
	printf("���棡��������ź�����󲻿ɸ��ģ���ȷ������������롣") ;
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("�����밸����ź�: ");
    scanf("%s",s[s_size].num);
    printf("�����밸������: ");
    scanf("%s",s[s_size].name);
     printf("�����밸������������: ");
    scanf("%s",s[s_size].personname);
    printf("�����밸���������Ա�: ");
    scanf("%s",s[s_size].sex);
    printf("�����밸������������: ");
    scanf("%s",s[s_size].age);
    printf("������ӹܰ�������: ");
	scanf("%s",s[s_size].date); 
    printf("�����밸��״̬: "); 
	scanf("%s",s[s_size].status);
    s_size++;
    printf("¼�밸����Ϣ�ɹ�!\n");
	}
}

void Search()                                  //��ѯ���� 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.ͨ��������Ų�ѯ     B.ͨ���������Ʋ�ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("�����밸���ı��\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("�����밸��������\n");
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
            printf("�ð�������ϸ��Ϣ����:\n");
            printf("�������:%s\n",s[i].num);
            printf("��������:%s\n",s[i].name);
            printf("��������������:%s\n",s[i].personname);
            printf("�����������Ա�:%s\n",s[i].sex);
            printf("��������������:%s\n",s[i].age);
            printf("�ð��������˽ӹܰ�������:%s\n",s[i].date);
            printf("����״̬:%s\n",s[i].status); 
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
   	printf("�����밸�����\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
		
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.��������\n2.����������\n3.�����������Ա�\n4.��������������\n5.�ð��������˽ӹܰ���������\n6.����״̬\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        	printf("��������ĺ�İ�������\n");
	            scanf("%s",&s[i].name);
	            printf("�޸ĳɹ�!\n") ;
	        	break;
	        case 2:
				printf("��������ĺ�İ���������\n");
	            scanf("%s",&s[i].name);
	            printf("�޸ĳɹ�!\n") ;
	        	break;	
	        case 3:
	            printf("��������ĺ�İ����������Ա�\n");
	            scanf("%s",&s[i].sex);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 4:
	        	printf("��������ĺ�İ�������������\n");
	            scanf("%s",&s[i].age);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 5:
	            printf("��������ĺ�Ľӹ�����\n");
	            scanf("%s",&s[i].date);
	            printf("�޸ĳɹ�!\n") ;
				break; 
	        case 6:
	        	printf("��������ĺ�İ���״̬\n");
	            scanf("%s",&s[i].status);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        default:
	            printf("�������!\n");
	            break;
	
	        }
		}
		else
			printf("���޴˰���\n");

	}
} 

void Save()                                 //������Ϣ 
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
	    printf("����סԺ��Ϣ�Ѿ����浽�ļ�lawcase.txt��!\n");
	    
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
            printf("�������!\n");
            break;

        }
    }

    return 0;
}
