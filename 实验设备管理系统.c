#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct equipment //ʵ���豸��Ϣ�ṹ��
{
	char name[20];            //�豸���� 
	char num[20];			 //�豸���
	char money[20];         //�豸�۸� 
	char date_1[20];         //�豸�������� 
	char status[20];		//�豸״̬���Ƿ񱨷�
	char date_2[20];        //�������� 
};
struct record //�豸ʹ�ü�¼�ṹ��
{
	char name[20];            //ʹ�ü�¼������
	char sex[20];              //ʹ�ü�¼���Ա� 
	char num[20];			 //ʹ�ü�¼�߱��
	char age[20];            //ʹ�ü�¼������ 
	char date[20];         //ʹ������ 
};

int s_size;
struct equipment s[1000];
int e_size;
struct record e[1000];
 

void menu()                                         //�˵� 
{   printf("\n");
	printf("     ��ӭʹ�ñ�ʵ���豸����ϵͳ\n");
	printf("*----------------------------------------- *\n");
    printf("*       1,ʵ���豸��Ϣ¼��                 *\n");
    printf("*       2,ʵ���豸��Ϣ��ѯ                 *\n");
    printf("*       3,ʵ���豸��Ϣ����                 *\n");
    printf("*       4,ʹ����Ϣ¼��                     *\n");
    printf("*       5,ʹ����Ϣ��ѯ                     *\n");
    printf("*       6,ʹ����Ϣ����                     *\n");
    printf("*       7,����ʵ���豸��Ϣ                 *\n");
    printf("*       8,����ʹ����Ϣ                     *\n");
    printf("*       0,�˳�ϵͳ                         *\n");
    printf("*----------------------------------------- *\n");
    printf("��ѡ��: ");
}
void Add_equipment()                                    //����ʵ���豸 
{
	char choose_2;
	printf("���棡��ʵ���豸�������󲻿ɸ��ģ���ȷ������������롣\n");
	printf("ȷ���밴T�������밴�����\n");
	scanf("%c",&choose_2);                           //��ȡ�س� 
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
	    printf("������ʵ���豸���: ");
	    scanf("%s",s[s_size].num);
	    printf("������ʵ���豸����: ");
	    scanf("%s",s[s_size].name);
	    printf("������ʵ���豸�۸�: ");
	    scanf("%s",s[s_size].money);
	    printf("������ʵ���豸��������: ");
		scanf("%s",s[s_size].date_1);
		printf("������ʵ���豸״̬: ");
		scanf("%s",s[s_size].status);
		printf("������ʵ���豸��������:(��δ��������Ҫ����)"); 
		scanf("%s",s[s_size].date_2);
	    s_size++;
	    printf("¼��ʵ���豸��Ϣ�ɹ�!\n");
	}
}

void Search()                                  //��ѯʵ���豸 
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
	    printf("A.ͨ��ʵ���豸��Ų�ѯ     B.ͨ��ʵ���豸���Ʋ�ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("������ʵ���豸���\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("������ʵ���豸����\n");
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
            printf("��ʵ���豸����ϸ��Ϣ����:\n");
            printf("ʵ���豸���:%s\n",s[i].num);
            printf("ʵ���豸����:%s\n",s[i].name); 
            printf("ʵ���豸�۸�:%s\n",s[i].money); 
            printf("ʵ���豸��������:%s\n",s[i].date_1);
            printf("ʵ���豸״̬:%s\n",s[i].status);
            printf("ʵ���豸��������:%s\n",s[i].date_2);
            flag=0;
            break;
        }
    }

}

void Change()																				//����ʵ���豸 
{
	char id[20];
    char name_2[20];
    char choice_2;
    int i,flag=1; 
   	printf("������ʵ���豸���\n");
   	scanf("%s",&id);
	for(i=0;i<s_size;i++){
	
	 	if(strcmp(id,s[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.ʵ���豸����\n2.ʵ���豸�۸�\n3.ʵ���豸��������\n4.ʵ���豸״̬\n5.ʵ���豸��������\n");
		scanf("%d",&choice_2);
		switch(choice_2)
	        {
	        case 1:
	        		printf("��������ĺ��ʵ���豸����\n");
	            	scanf("%s",&s[i].name);
	            	printf("�޸ĳɹ�!\n") ;
	        	break;
	        	
	        case 2:
	            printf("��������ĺ��ʵ���豸�۸�\n");
	            scanf("%s",&s[i].money);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 3:
	        	printf("��������ĺ��ʵ���豸��������\n");
	            scanf("%s",&s[i].date_1);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        case 4:
	            printf("��������ĺ��ʵ���豸״̬\n");
	            scanf("%s",&s[i].status);
	            printf("�޸ĳɹ�!\n") ;
				break; 
	        case 5:
	        	printf("��������ĺ��ʵ���豸��������\n");
	            scanf("%s",&s[i].date_2);
	            printf("�޸ĳɹ�!\n") ;
	            break;
	        default:
	            printf("�������!\n");
	            break;
	
	        }
		}
		else
			printf("���޴��豸\n");

	}
} 

void Add_record()                                    //���Ӽ�¼
{
	char choose_2;
	printf("���棡��ʹ���߱������󲻿ɸ��ģ���ȷ������������롣\n") ;
	printf("ȷ���밴T�������밴F\n");
	scanf("%c",&choose_2);
	scanf("%c",&choose_2);
	if(choose_2=='T'){	
    printf("������ʹ���ߵı��: ");
    scanf("%s",e[e_size].num);
    printf("������ʹ��������: ");
    scanf("%s",e[e_size].name);
    printf("������ʹ�����Ա�: ");
    scanf("%s",e[e_size].sex);
    printf("������ʹ��������: ");
    scanf("%s",e[e_size].age);
    printf("������ʹ������: ");
	scanf("%s",e[e_size].date); 
    e_size++;
    printf("¼��ʹ������Ϣ�ɹ�!\n");
	}
}

void Searchrecord()                                  //��ѯ��¼
{
    char id[20];
    char name_1[20];
    char choose_1;
    int i,flag=1;
    while(1){
    	printf("\n");
	    printf("A.ͨ��ʹ���߱�Ų�ѯ     B.ͨ��ʹ����������ѯ:\n");
	    scanf("%c",&choose_1);               //��ȡ�س��� 
	    scanf("%c",&choose_1);
	    if(choose_1=='A'){
	    	printf("������ʹ���ߵı��\n");
	    	scanf("%s",&id);
	    	break;
		}
	    else if(choose_1=='B'){
	    	printf("������ʹ���ߵ�����\n");
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
            printf("��ʹ���ߵĸ�����Ϣ����:\n");
            printf("���:%s\n",e[i].num);
            printf("����:%s\n",e[i].name);
            printf("�Ա�:%s\n",e[i].sex);
            printf("����:%s\n",e[i].age); 
            printf("ʹ������:%s\n",e[i].date);
            flag=0;
            break;
        }
    }

}

void Changerecord()                                                            //���ļ�¼ 
{
	char id[20];
    char name_2[20];
    char choice_2;
    int i,flag=1; 
   	printf("������ʹ���ߵı��\n");
   	scanf("%s",&id);
	for(i=0;i<e_size;i++){
		
	
	 	if(strcmp(id,e[i].num)==0){
	    printf("��ѡ���޸���\n");
	    printf("1.����\n2.�Ա�\n3.����\n4ʹ������\n");
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
	        	printf("��������ĺ��ʹ������\n");
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
	    fp=fopen("equipment.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s %s %s\n",s[i].num,s[i].name,s[i].money,s[i].date_1,s[i].status,s[i].date_2);
	    }
	    fclose(fp);
	    printf("ʵ���豸��Ϣ�Ѿ����浽�ļ�equipment.txt��!\n");
	    
}
void Saverecord()                                 //������Ϣ 
{  
	char choice_3;	
	    FILE *fp;
	    int i;
	    fp=fopen("record.txt","w");
	    if(fp!=NULL)
	    {
	        for(i=0;i<s_size;i++)
	            fprintf(fp,"%s %s %s %s %s\n",e[i].num,e[i].name,e[i].sex,e[i].age,e[i].date);
	    }
	    fclose(fp);
	    printf("ʹ������Ϣ�Ѿ����浽�ļ�record.txt��!\n");
	    
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
            Add_equipment();
            break;
        case 2:
            Search();
            break;
        case 3:
			Change();
			break; 
		case 4:
			Add_record();
			break; 
		case 5:
			 Searchrecord() ;
			 break; 
		case 6:
			Changerecord();
			break; 	
        case 7:
            Save();
            break;
        case 8:
        	Saverecord();
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
