#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student //ѧ����Ϣ�ṹ��
{
	char name[20];            //����
	char num[20];			 //ѧ�ź�
	char sex[20];             //�Ա� 
	char age[20];           //���� 
	char money[20];         //�񽱽�� 
	char moneyname[20];           //������ 
	char date[20];         //������ 
};
int s_size;
struct student s[1000];

void menu()                                         //�˵� 
{   printf("\n");
	printf("     ��ӭʹ�ñ���ѧ�����ϵͳ\n");
	printf("*--------------------------------------*\n");
    printf("*       1,��ѧ����Ϣ¼��             *\n");
    printf("*       2,��ѧ����ѯ                 *\n");
    printf("*       3,��ѧ����Ϣ����             *\n");
    printf("*       4,������Ϣ                     *\n");
    printf("*       0,�˳�ϵͳ                     *\n");
    printf("*--------------------------------------*\n");
    printf("��ѡ��: ");
}
void Add_student()                                    //���ӻ��� 
{
	char choose_2;
	printf("���棡��������������󲻿ɸ��ģ���ȷ������������롣") ;
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("�������ѧ��ѧ��: ");
    scanf("%s",s[s_size].num);
    printf("�������ѧ������: ");
    scanf("%s",s[s_size].name);
    printf("�������ѧ���Ա�: ");
    scanf("%s",s[s_size].sex);
    printf("�������ѧ������: ");
    scanf("%s",s[s_size].age);
    printf("�������ѧ���Ļ񽱽��: "); 
	scanf("%s",s[s_size].money);
	printf("�������ѧ���Ļ�����: "); 
	scanf("%s",s[s_size].moneyname);
    printf("�������ѧ���Ļ�����: ");
	scanf("%s",s[s_size].date); 
    s_size++;
    printf("¼���ѧ����Ϣ�ɹ�!\n");
	}
}

void Search()                                  //��ѯ���� 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.ͨ����ѧ����ѧ�Ų�ѯ     B.ͨ����ѧ���������Ĳ�ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("�������ѧ����ѧ��\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("�������ѧ��������\n");
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
            printf("�û�ѧ����ס������Ϣ����:\n");
            printf("ѧ��:%s\n",s[i].num);
            printf("����:%s\n",s[i].name);
            printf("�Ա�:%s\n",s[i].sex);
            printf("����:%s\n",s[i].age);
            printf("�񽱽��:%s\n",s[i].money); 
            printf("������:%s\n",s[i].moneyname); 
            printf("������:%s\n",s[i].date);
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
   	printf("�������ѧ����ѧ��\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
		
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.����\n2.�Ա�\n3.����\n4.�񽱽��\n5.������\n6.������\n");
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
	            printf("��������ĺ�Ļ񽱽��\n");
	            scanf("%s",&s[i].money);
	            printf("�޸ĳɹ�!\n") ;
				break; 
	        case 5:
	        	printf("��������ĺ�Ļ�����\n");
	            scanf("%s",&s[s_size].moneyname);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 6: 
	        	printf("��������ĺ�Ļ�����\n");
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
	    fp=fopen("Student.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].money,s[i].moneyname,s[i].date);
	    }
	    fclose(fp);
	    printf("��ѧ����Ϣ�Ѿ����浽�ļ�Student.txt��!\n");
	
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
            Add_student();
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
