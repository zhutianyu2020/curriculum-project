#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct company //��˾��Ϣ�ṹ��
{
	char name[20];            //��˾���� 
	char num[20];			 //��˾���
	char money[20];         //ÿ�¹���
	char num_1[20];         //��Ƹ���� 
	char needs[20];        //��Ƹ���� 
	char request[20]; 		//����Ҫ��
};
struct jobhunter //��ְ����Ϣ�ṹ��
{
	char name[20];            //��ְ����
	char sex[20];              //��ְ���Ա� 
	char num[20];			 //��ְ�߱��
	char age[20];            //��ְ������ 
	char nation[20];         //��ְ������ 
	char num_2[20];         //��ְ����ϵ�绰 
	char status[20];        //��ְ��״̬���Ƿ�¼�ã� 
};

int s_size;
struct company s[1000];
int e_size;
struct jobhunter e[1000];
 

void menu()                                         //�˵� 
{   printf("\n");
	printf("     ��ӭʹ�ñ���Ƹ����ϵͳ\n");
	printf("*--------------------------------------*\n");
    printf("*       1,��˾��Ϣ¼��                 *\n");
    printf("*       2,��˾��Ϣ��ѯ                 *\n");
    printf("*       3,��˾��Ϣ����                 *\n");
    printf("*       4,��˾��Ϣ¼��                 *\n");
    printf("*       5,��ְ����Ϣ��ѯ               *\n");
    printf("*       6,��ְ����Ϣ����               *\n");
    printf("*       7,���湫˾��Ϣ                 *\n");
    printf("*       8,������ְ��Ա��Ϣ             *\n");
    printf("*       0,�˳�ϵͳ                     *\n");
    printf("*--------------------------------------*\n");
    printf("��ѡ��: ");
}
void Add_company()                                    //���ӹ�˾ 
{
	char choose_2;
	printf("���棡����˾��ź�����󲻿ɸ��ģ���ȷ������������롣\n");
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("�����빫˾���: ");
	    scanf("%s",s[s_size].num);
	    printf("�����빫˾����: ");
	    scanf("%s",s[s_size].name);
	    printf("��������Ƹ����: ");
	    scanf("%s",s[s_size].needs);
	    printf("��������Ƹ����: ");
	    scanf("%s",s[s_size].num_1);
	    printf("�����빫˾����н: ");
		scanf("%s",s[s_size].money);
		printf("�����빫˾������Ҫ��: ");
		scanf("%s",s[s_size].request);
	    s_size++;
	    printf("¼�빫˾��Ϣ�ɹ�!\n");
	}
}

void Search()                                  //��ѯ��˾ 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i;
    while(1){
	    printf("A.ͨ����˾��Ų�ѯ     B.ͨ����˾�����Ʋ�ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("�����빫˾���\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("�����빫˾����\n");
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
            printf("�ù�˾����ϸ��Ϣ����:\n");
            printf("��˾���:%s\n",s[i].num);
            printf("��˾����:%s\n",s[i].name); 
            printf("��Ƹ����:%s\n",s[i].needs);
            printf("��Ƹ����:%s\n",s[i].num_1);
            printf("��˾��н:%s\n",s[i].money); 
            printf("����Ҫ��:%s\n",s[i].request);
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
   	printf("�����빫˾���\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.��˾����\n2.��Ƹ����\n3.��Ƹ����\n4.��˾��н\n5.����Ҫ��\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("��������ĺ�Ĺ�˾����\n");
	            	scanf("%s",&s[i].name);
	            	printf("�޸ĳɹ�!\n") ;
	        	break;
	        	
	        case 2:
	            printf("��������ĺ����Ƹ����\n");
	            scanf("%s",&s[i].needs);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 3:
	        	printf("��������ĺ����Ƹ����n");
	            scanf("%s",&s[i].num_1);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 4:
	            printf("��������ĺ�Ĺ�˾��н\n");
	            scanf("%s",&s[i].money);
	            printf("�޸ĳɹ�!\n") ;
				break; 
	        case 5:
	        	printf("��������ĺ������Ҫ��\n");
	            scanf("%s",&s[i].request);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        default:
	            printf("�������!\n");
	            break;
	
	        }
		}
		else
			printf("���޴˹�˾\n");

	}
} 

void Add_jobhunter()                                    //������ְ��
{
	char choose_2;
	printf("���棡����ְ�߱������󲻿ɸ��ģ���ȷ������������롣\n") ;
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("��������ְ�߱��: ");
    scanf("%s",e[e_size].num);
    printf("��������ְ������: ");
    scanf("%s",e[e_size].name);
    printf("��������ְ���Ա�: ");
    scanf("%s",e[e_size].sex);
    printf("��������ְ������: ");
    scanf("%s",e[e_size].age);
	printf("��������ְ�ߵ�����: "); 
	scanf("%s",e[e_size].nation);
    printf("��������ְ�ߵ���ϵ�绰: ");
	scanf("%s",e[e_size].num_2); 
	printf("��������ְ��¼��״̬: ");
	scanf("%s",e[e_size].status);  
    e_size++;
    printf("¼����ְ����Ϣ�ɹ�!\n");
	}
}

void Searchjobhunter()                                  //��ѯ��ְ��
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i; 
    while(1){
    	printf("\n");
	    printf("A.ͨ����ְ�ߵı�Ų�ѯ     B.ͨ����ְ��������ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("��������ְ�ߵı��\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("��������ְ�ߵ�����\n");
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
            printf("����ְ�ߵĸ�����Ϣ����:\n");
            printf("��ְ�߱��:%s\n",e[i].num);
            printf("����:%s\n",e[i].name);
            printf("�Ա�:%s\n",e[i].sex);
            printf("����:%s\n",e[i].age);
            printf("����:%s\n",e[i].nation); 
            printf("��ϵ�绰:%s\n",e[i].num_2);
            printf("¼��״̬:%s\n",e[i].status);
            break;
        }
    }

}

void Changejobhunter()
{
	char id[20];
    char name_2[20];
    char choice_2;
    int i,flag=1; 
   	printf("��������ְ�ߵı��\n");
   	scanf("%s",&id);
	for(i=0;i<e_size;i++){
		
	
	 	if(strcmp(id,e[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.����\n2.�Ա�\n3.����\n4.����\n5.��ϵ�绰\n6.¼��״̬");
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
	        	printf("��������ĺ������\n");
	            scanf("%s",&e[i].nation);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 5: 
	        	printf("��������ĺ����ϵ�绰\n");
	            scanf("%s",&e[i].num_2);
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
	    fp=fopen("company.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].needs,s[i].num_1,s[i].money,s[i].request);
	    }
	    fclose(fp);
	    printf("��˾��Ϣ�Ѿ����浽�ļ�company.txt��!\n");
	    
}
void Savejobhunter()                                 //������Ϣ 
{  
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("jobhunter.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s %s\n",e[i].num,e[i].name,e[i].sex,e[i].age,e[i].nation,e[i].num_2,e[i].status);
	    }
	    fclose(fp);
	    printf("��ְ����Ϣ�Ѿ����浽�ļ�jobhunter.txt��!\n");
	    
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
            Add_company();
            break;
        case 2:
            Search();
            break;
        case 3:
			Change();
			break; 
		case 4:
			Add_jobhunter();
			break; 
		case 5:
			 Searchjobhunter() ;
			 break; 
		case 6:
			Changejobhunter();
			break; 	
        case 7:
            Save();
            break;
        case 8:
        	Savejobhunter();
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
