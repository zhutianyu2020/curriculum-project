#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct competitor //����ѡ����Ϣ�ṹ��
{
	char name[20];            //����
	char num[20];			 //�������� 
	char sex[20];             //�Ա� 
	char age[20];           //���� 
	char sport[20];         //������Ŀ 
	char date[20];         //�������� 
};
int s_size;
struct competitor s[1000];

void menu()                                         //�˵� 
{   printf("\n");
	printf("     ��ӭʹ�ñ��˶������ϵͳ\n");
	printf("*--------------------------------------*\n");
    printf("*       1,����ѡ����Ϣ¼��             *\n");
    printf("*       2,����ѡ����Ϣ��ѯ             *\n");
    printf("*       3,����ѡ����Ϣ����             *\n");
    printf("*       4,������Ϣ                     *\n");
    printf("*       0,�˳�ϵͳ                     *\n");
    printf("*--------------------------------------*\n");
    printf("��ѡ��: ");
}
void Add_competitor()                                    //���ӻ��� 
{
	char choose_2;
	printf("���棡��������������󲻿ɸ��ģ���ȷ������������롣") ;
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("���������ѡ�ֵĲ�������: ");
    scanf("%s",s[s_size].num);
    printf("���������ѡ������: ");
    scanf("%s",s[s_size].name);
    printf("���������ѡ���Ա�: ");
    scanf("%s",s[s_size].sex);
    printf("���������ѡ������: ");
    scanf("%s",s[s_size].age);
    printf("���������ѡ�ֵĲ�����Ŀ: "); 
	scanf("%s",s[s_size].sport);
    printf("���������ѡ�ֵĲ�������: ");
	scanf("%s",s[s_size].date); 
    s_size++;
    printf("¼�����ѡ����Ϣ�ɹ�!\n");
	}
}

void Search()                                  //��ѯ���� 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.ͨ������ѡ�ֵĲ����Ų�ѯ     B.ͨ������ѡ�ֵ�������ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("����������Ĳ�������\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("���������ѡ�ֵ�����\n");
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
            printf("�ò���ѡ�ֵĲ�����Ϣ����:\n");
            printf("��������:%s\n",s[i].num);
            printf("����:%s\n",s[i].name);
            printf("�Ա�:%s\n",s[i].sex);
            printf("����:%s\n",s[i].age);
            printf("������Ŀ:%s\n",s[i].sport);
            printf("��������:%s\n",s[i].date);
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
   	printf("����������Ĳ�������\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
		
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.����\n2.�Ա�\n3.����\n4.������Ŀ\n5.��������\n");
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
	            printf("��������ĺ�Ĳ�����Ŀ\n");
	            scanf("%s",&s[i].sport);
	            printf("�޸ĳɹ�!\n") ;
				break; 
	        case 5: 
	        	printf("��������ĺ�Ĳ�������\n");
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
	    fp=fopen("competitor.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].sport,s[i].date);
	    }
	    fclose(fp);
	    printf("����ѡ����Ϣ�Ѿ����浽�ļ�competitor.txt��!\n");
	   
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
            Add_competitor();
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
