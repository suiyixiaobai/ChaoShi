#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"ChaoShi.h"


void interface1(void)//����������ʱ��һ������
{
    float y, x, z, f;
    for (y = 1.5f; y > -1.5f; y-=0.1f)
    {
        for (x = -1.5f; x < 1.5f; x += 0.05f)
        {
            z = x*x + y*y -1;
            f = z*z*z - x*x*y*y*y;
            putchar(f <= 0.0f ? "*********"[(int)(f*-8.0f)]:' ');
        }
        putchar('\n');
    }
    printf("��ӭʹ��С�ͳ�����Ʒ����ϵͳ���밴Enter������.......)");
    getchar();
    system("cls");
}
void interface2(void)//����������ʱ�ڶ�������
{
    int i;
    char ch='*';
    for(i=1;i<20;i++)
    {
        putchar(ch);
    }
    printf("С�ͳ�����Ʒ����ϵͳ");
    for(i=1;i<20;i++)
    {
        putchar(ch);
    }

}
void set_account(void)//��ʼ���˺�����
{
    int a;
    struct Account account_neu;
    struct Account nnnn;
    //scanf("%ld",&nnnn.ID_g);
    //struct Account account_cse;
    struct FILF *fp;
    if((fp=fopen("account.dat","wb+"))==NULL)//�򿪴����ļ�
    {
        printf("ϵͳ����!!!!!!!!!\n");
        exit(0);//��������
    }
    printf("�������ʼ�����˺�����\n");
    printf("��ʼ������Ա�˺ţ�");
    scanf("%ld",&account_neu.ID_s);
    printf("��ʼ������Ա���룺");
    scanf("%ld",&account_neu.password_s);
    printf("��ʼ������Ա�˺ţ�");
    scanf("%ld",&account_neu.ID_g);
    printf("��ʼ������Ա���룺");
    scanf("%ld",&account_neu.password_g);
    //printf("%ld %ld %ld %ld\n",account_neu.ID_s,account_neu.password_s,account_neu.ID_g,account_neu.password_g);
    fwrite(&account_neu,sizeof(account_neu),1,fp);//���˺���������ļ�
    rewind(fp);
    //fread(&account_cse,sizeof(account_cse),1,fp);
    //printf("%ld %ld %ld %ld\n",account_cse.ID_s,account_cse.password_s,account_cse.ID_g,account_cse.password_g);

    printf("�˺������������");
    printf("�ٴ������˺������¼\n");
    printf("����ǹ�����������1�����������Ա������2��\n");
    scanf("%d",&a);
    log_in_s(a);//����Ա�ĵ�¼����
    log_in_g(a);//�����ߵĵ�¼����
}
void log_in_s(int x)//����Ա��½����
{
    if(x==2)
    {
     struct Account* account1;
     account1=read_account();
     struct Account account_t;
     account_t.ID_s=account1->ID_s;
     account_t.password_s=account1->password_s;
     account_t.ID_g=account1->ID_g;
     account_t.password_g=account1->password_g;
     //printf("%ld %ld %ld %ld\n",account_t.ID_s,account_t.password_s,account_t.ID_g,account_t.password_g);
    long int ID,password;
    printf("�������Ա������������˺ţ�����\n");
    printf("�˺ţ�");
    scanf("%ld",&ID);
     printf("\n");
    printf("���룺");
    scanf("%ld",&password);
     printf("\n");
    if((ID==account_t.ID_s)&&(password==account_t.password_s))
    {

        system("cls");
        printf("��¼�ɹ�\n��ӭ�������õ�����ʱ��\n");
        selled();
    }
    else
    {
        printf("�˺��������ϵͳ�Զ��˳�\n");
        exit(0);

    }
    }
}
struct Account* read_account(void)//�����˺�����
{
    struct FILF *fp;
    struct Account account_cse;
    struct Account  *pp;
    pp=&account_cse;
    if((fp=fopen("account.dat","ab+"))==NULL)//�򿪴����ļ�
    {
        printf("ϵͳ����!!!!!!!!!\n");
        return 0;//��������
    }
    fread(pp,sizeof(account_cse),1,fp);
    //printf("%ld %ld %ld %ld\n",account_cse.ID_s,account_cse.password_s,account_cse.ID_g,account_cse.password_g);
    return pp;
}
void log_in_g(int x)//����Ա��½����
{
    if(x==1)
    {
    struct Account* account1;
     account1=read_account();
     struct Account account_t;
     account_t.ID_s=account1->ID_s;
     account_t.password_s=account1->password_s;
     account_t.ID_g=account1->ID_g;
     account_t.password_g=account1->password_g;
    // printf("%ld %ld %ld %ld\n",account_t.ID_s,account_t.password_s,account_t.ID_g,account_t.password_g);
    long int ID,password;
    printf("��ù���Ա������������˺ţ�����\n");
    printf("�˺ţ�");
    scanf("%ld",&ID);
     printf("\n");
    printf("���룺");
    scanf("%ld",&password);
     printf("\n");
     //printf("%ld %ld %ld %ld\n",account1->ID_s,account1->password_s,account1->ID_g,account1->password_g);
    if((ID==account_t.ID_g)&&(password==account_t.password_g))
    {
        printf("��¼�ɹ�\n");
        user();
    }
    else printf("�˺������������ϵͳ�Զ��˳�\n");
    exit(0);
    //user();
    }
    system("cls");
}
void user(void)
{
    int choice;
    printf(" \n\n                    \n\n");
	printf(" ******************************************************\n\n");
	printf(" *                    ����ϵͳ                        *\n \n");
	printf(" ******************************************************\n\n");
	printf("*********************ϵͳ���ܲ˵�***********************       \n");
	printf("    -----------------------   ---------------------   \n");
	printf("     **********************************************     \n");
	printf("     * 0.�˳���ϵͳ       * *  1.�޸ĵ�¼�˺����� *     \n");
	printf("     **********************************************     \n");
	printf("     * 2.�˿͹���ϵͳ     * *  3.��Ʒ����ϵͳ     *     \n");
	printf("     **********************************************     \n");
	printf("     * 4.��ѯ������Ʒ                             *     \n");
	printf("     **********************************************     \n");
	//printf("     * 6. * *  7.    *     \n");
	//printf("     **********************************************     \n");
	printf("    -----------------------   ---------------------   \n");
	printf("********************************************************       \n");
	//printf("��ѡ��˵����:");
    //scanf("%d",&choice);

    while(1)
    {
        printf("��ѡ��Ҫʹ�ù��ܣ�");
        scanf("%d",&choice);
        if((((choice==0||choice==1)||choice==2)||choice==3)||choice==4)break;
        else printf("��������밴�չ�����������\n");
    }
    system("cls");
    switch(choice)
    {
    case 1:
        change_account();
        //system("cls");
        break;
    case 2:
        showorchange_customer();
        break;
    case 3:
        goods_message();
        //system("cls");
        break;
    case 4:
        search_selled();
        break;
    case 0:
        return 0;
        break;
    default:
        printf("��������û�иù���\n");
        break;
    }
    //system("cls");
}
void change_account(void)
{
    struct FILF *fp;

    struct Account account_neucse;
    if((fp=fopen("account.dat","ab"))==NULL)//�򿪴����ļ�
    {
        printf("ϵͳ����!!!!!!!!!\n");
        return 0;//��������
    }
    printf("�������޸ĺ���˺�����\n");
    printf("�޸ĺ�����Ա�˺ţ�");
    scanf("%ld",&account_neucse.ID_s);
    printf("�޸ĺ�����Ա���룺");
    scanf("%ld",&account_neucse.password_s);
    printf("�޸ĺ����Ա�˺ţ�");
    scanf("%ld",&account_neucse.ID_g);
    printf("�޸ĺ����Ա���룺");
    scanf("%ld",&account_neucse.password_g);

    fwrite(&account_neucse,sizeof(account_neucse),1,fp);//���˺���������ļ�

    printf("�˺������޸����\n");
    int a;
    printf(" ******************************************************\n");
    printf(" * �������ʹ�ø�ϵͳ������1                      *\n");
    printf(" ******************************************************\n");
    printf(" * ������˳���ϵͳ������2                            *\n");
    printf(" ******************************************************\n");
    printf(" ��ѡ��Ҫ���õĹ��ܣ�\n");
    scanf("%d",&a);
    if(a==1)user();
    else if(a==2) exit(0);
}
void showorchange_customer(void)
{
    /*void save_Customer(void);//��һ��¼��˿���Ϣ1
    void add_customer(void);//��ӹ˿���Ϣ1
    void revise(void);//�޸Ĺ˿���Ϣ1
    void del(void);//ɾ���˿�����1
    struct Customer_list *look_customer(void);//�鿴�˿���Ϣ�����˿���Ϣ�������������ͷ1
    void show_customer(void);//չʾ�˿���Ϣ1*/
    int a;
    printf(" \n\n                    \n\n");
	printf(" ******************************************************\n\n");
	printf(" *                    �˿͹���ϵͳ                    *\n \n");
	printf(" ******************************************************\n\n");
	printf("*********************ϵͳ���ܲ˵�***********************       \n");
	printf("    -----------------------   ---------------------   \n");
	printf("     **********************************************     \n");
	printf("     * 0.������һ��       * *  1. ʹ�ð���        *     \n");
	printf("     **********************************************     \n");
	printf("     * 2.¼��˿���Ϣ     * *  3.��ӹ˿���Ϣ     *     \n");
	printf("     **********************************************     \n");
	printf("     * 4.�޸Ĺ˿���Ϣ     * *  5.ɾ���˿���Ϣ     *     \n");
	printf("     **********************************************     \n");
	printf("     * 6.��ʾ�˿���Ϣ     * *  7.��ѯ�˿���Ϣ     *     \n");
	printf("     **********************************************     \n");
	printf("     * 8.ģ����ѯ����     * *   -------------------   \n");
	printf("********************************************************       \n");
	//��ѯ�˿���Ϣ������
	printf("��ѡ��˵����:");
    scanf("%d",&a);
    printf("\n");
    system("cls");
    switch(a)
    {
    case 1:
        {
            int ss;
            printf("1.�밴����ʾʹ�øù���\n 2.���������벦����ѯ����15294748920\n 3.лл���Ը�ϵͳ��֧��\n\n\n\n\n");
            printf("���������һ��������1\n���ֱ���˳�ϵͳ������2\n");
            printf("��ѡ���ܣ�");
            scanf("%d",&ss);
            system("cls");
    if(ss==1)showorchange_customer();
    else if(ss==2)exit(0);
        }
        break;
    case 2:
        save_Customer();
        break;
    case 3:
        add_customer();
        break;
    case 4:
        revise1();
        break;
    case 5:
        del1();
        break;
    case 6:
        show_customer();
        break;
    case 7:
        search_customer_message();
        break;
    case 0:
        user();
        break;
    case 8:
        search_customer_mohu();
        break;
    default:
        printf("��������û�иù���\n");
        int a;
        printf("��������ʹ�ñ�ϵͳ������1");
        scanf("%d",&a);
        if(a==1)showorchange_customer();
        //user();
        break;
    }
    //system("cls");
}
void search_customer_message(void)
{
    struct Customer_list *head_cust,*p;
    int i,temp,num_cust,a,grade,ss,nn=0;//tempΪҪ�����˿���Ŀ��num_custΪҪ�����Ĺ˿ͱ��
    char name_cust[20];//Ҫ�����˿�����
    head_cust=look_customer();
    p=NULL;
    printf("��ѡ��������ʽ�������������򰴹˿ͱ������");
    printf("����������������1�����˿ͱ������������2):");
    scanf("%d",&a);
    printf("������Ҫ����������");
    scanf("%d",&temp);
    if(a==1)
    {
        for(i=0;i<temp;i++)
        {
            printf("������Ҫ�����˿�������");
            scanf("%s",name_cust);
            if(head_cust!=NULL)
           {
            p=head_cust;
            do
            {
            if(strcmp(name_cust,p->god.name)== 0)
            {
                nn++;
                printf("|�˿ͱ��|�˿�����|�˿����ѵȼ�|�˿����۶�|\n");
                if(p->god.sale_amount<100)
                {
                    grade=0;
                }
                else if((p->god.sale_amount>=100)&&(p->god.sale_amount<1000))
                {
                    grade=1;
                }
                else if((p->god.sale_amount>=1000)&&(p->god.sale_amount<2000))
                {
                    grade=2;
                }
                else grade=3;
                printf("|%8d|%8s|%12d|%10ld|\n",p->god.number,p->god.name,grade,p->god.sale_amount);
            }
                p=p->next;
            }
            while(p!=NULL);
           }
       }

     }
     else if(a==2)
    {
        for(i=0;i<temp;i++)
        {
            printf("������Ҫ�����˿ͱ�ţ�");
            scanf("%d",&num_cust);
            if(head_cust!=NULL)
           {
            p=head_cust;
            do
            {
            if(p->god.number==num_cust)
            {
                nn++;
                printf("|�˿ͱ��|�˿�����|�˿����ѵȼ�|�˿����۶�|\n");
                if(p->god.sale_amount<100)
                {
                    grade=0;
                }
                else if((p->god.sale_amount>=100)&&(p->god.sale_amount<1000))
                {
                    grade=1;
                }
                else if((p->god.sale_amount>=1000)&&(p->god.sale_amount<2000))
                {
                    grade=2;
                }
                else grade=3;
                printf("|%8d|%8s|%12d|%10ld|\n",p->god.number,p->god.name,grade,p->god.sale_amount);
            }
                p=p->next;
            }
            while(p!=NULL);
           }
        }
    }
    else printf("δ���涨����\n");
    if(nn==0)printf("δ��ѯ��������Ĺ˿�\n\n\n");
    printf("���������һ��������1\n���ֱ���˳�ϵͳ������2\n");
    printf("��ѡ���ܣ�");
    scanf("%d",&ss);
    system("cls");
    if(ss==1)showorchange_customer();
    else if(ss==2)exit(0);
}
void search_customer_mohu() {
    struct Customer_list* head_cust, * p;
    int i, temp, a, grade,tmp, ss, nn = 0;//tempΪҪ�����˿���Ŀ��num_custΪҪ�����Ĺ˿ͱ��
    char name_cust[20];//Ҫ�����˿�����
    char shortname[20];
    head_cust = look_customer();
    printf("������Ҫ����������");
    scanf("%d", &temp);
    for (i = 0; i < temp; i++)
    {
        printf("������Ҫ�����˿�������");
        scanf("%s", name_cust);
        int n = strlen(name_cust);
        if (head_cust != NULL)
        {
            p = head_cust;
            int m = strlen(p->god.name);
            for (int item = 0; item <= m - n;item+=2) {
                tmp = 0;
                for (int t = item; t < item + n; t++) {
                    shortname[tmp] = p->god.name[t];
                    tmp += 1;
                }
                shortname[tmp] = '\0';
                if (strcmp(name_cust, shortname) == 0)
                {
                    printf("1");
                    printf("|�˿ͱ��|�˿�����|�˿����ѵȼ�|�˿����۶�|\n");
                    if (p->god.sale_amount < 100)
                    {
                        grade = 0;
                    }
                    else if ((p->god.sale_amount >= 100) && (p->god.sale_amount < 1000))
                    {
                        grade = 1;
                    }
                    else if ((p->god.sale_amount >= 1000) && (p->god.sale_amount < 2000))
                    {
                        grade = 2;
                    }
                    else grade = 3;
                    printf("|%8d|%8s|%12d|%10ld|\n", p->god.number, p->god.name, grade, p->god.sale_amount);
                    break;
                }
            }
            p = p->next;
        }
    }
}
void save_Customer(void)//�û���һ�ν�������¼��
{
      //�ó���Ϊ��һ��¼��˿���Ϣʱ��ʹ�õĺ���
    struct FILF *fp;//�����ļ�ָ��
    struct Customer cust[100];//�����˿���Ϣ�ṹ�����飬����Ϣ�����ļ�֮���ڶ����������������
    //Customer cust1[5];
    int i,num_cust,ss;//����Ϊ�˿���Ŀ
    printf("������Ҫ¼��Ĺ˿���Ŀ��");
    scanf("%d",&num_cust);//����˿���Ŀ
    printf("������Ҫ¼��Ĺ˿���Ϣ���밴�չ˿ͱ�ţ����������۶�������룬�����1001��1002����");
    printf("\n");
    for(i=0;i<num_cust;i++)//����ѭ��
    {
        scanf("%d%s%ld",&cust[i].number,cust[i].name,&cust[i].sale_amount);//¼��˿���Ϣ
    }

    //����Ϣ�����ļ�
    if((fp=fopen("customer_information.dat","ab"))==NULL)//�򿪴����ļ�
    {
        printf("ϵͳ����!!!!!!!!!\n");
        return 0;//��������
    }
    for(i=0;i<num_cust;i++)
    {
        fwrite(&cust[i],sizeof(cust[i]),1,fp);//���ļ��ж�������
    }
    memset(cust,0,sizeof(cust));//��cust�����е�������գ��ٴ�����
    fclose(fp);
    printf("¼��ɹ�\n");
    printf("******************************************************      \n");
    printf("*���������һ��������1                               *      \n");
    printf("******************************************************      \n");
    printf("*���ֱ���˳�ϵͳ������2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("��ѡ��Ҫʹ�ù��ܣ�");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("��������밴�չ�����������\n");
    }
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void add_customer()//���ļ����������
{
    struct FILF *fp;
    struct Customer cust[50];
    int i,num,ss;
    printf("������Ҫ��ӵĹ˿���Ŀ��");
    scanf("%d",&num);//����˿���Ŀ
    printf("������Ҫ��ӵĹ˿���Ϣ���밴�չ˿ͱ�ţ����������۶�������룬�����1001��1002����");
    printf("\n");
    for(i=0;i<num;i++)//����ѭ��
    {
        scanf("%d%s%ld",&cust[i].number,cust[i].name,&cust[i].sale_amount);//¼��˿���Ϣ
    }
        if((fp=fopen("customer_information.dat","ab"))==NULL)//�򿪴����ļ�
    {
        printf("ϵͳ����!!!!!!!!!\n");
        return 0;//��������
    }
    for(i=0;i<num;i++)
    {
        fwrite(&cust[i],sizeof(cust[i]),1,fp);//���ļ��ж�������
    }
    memset(cust,0,sizeof(cust));//��cust�����е�������գ��ٴ�����
    fclose(fp);
    printf("��ӳɹ�\n");
    printf("******************************************************      \n");
    printf("*���������һ��������1                               *      \n");
    printf("******************************************************      \n");
    printf("*���ֱ���˳�ϵͳ������2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("��ѡ��Ҫʹ�ù��ܣ�");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("��������밴�չ�����������\n");
    }
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void revise1()//�޸��û���Ϣ
{
    FILE* fp;
    int ss;
    //char name[20];
    int num_cha;
    struct Customer cust_t;
    fp = fopen("customer_information.dat","rb+");
    printf("��������Ҫ�޸ĵ��û��ı��:\n");
    scanf("%d",&num_cha);
    //printf("11111");
    while(fread(&cust_t,sizeof(cust_t),1,fp) != 0)
    {
        //printf("11111");
        if(cust_t.number==num_cha){
            fseek(fp,0-sizeof(cust_t),SEEK_CUR);
            printf("�������޸ĺ�Ĺ˿���Ϣ���밴�չ˿ͱ�ţ����������۶�������룬�����1001��1002��:");//����
            scanf("%d%s%ld",&cust_t.number,cust_t.name,&cust_t.sale_amount);//�����
            fwrite(&cust_t,sizeof(cust_t),1,fp);
            break;
        }
    }
    fclose(fp);
    printf("******************************************************      \n");
    printf("*���������һ��������1                               *      \n");
    printf("******************************************************      \n");
    printf("*���ֱ���˳�ϵͳ������2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("��ѡ��Ҫʹ�ù��ܣ�");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("��������밴�չ�����������\n");
    }
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void del1(void)//ɾ���û�����
{
    FILE *fp,*fq;
    int ss;
    fp = fopen("customer_information.dat","rb");
    fq = fopen("data.dat", "wb");
    char name[20];
    struct Customer cust_t;
    printf("������Ҫɾ���˿͵�����\n");
    scanf("%s", name);
    while(fread(&cust_t,sizeof(cust_t),1,fp) != 0)
    {
        if(strcmp(cust_t.name,name) != 0){
            fwrite(&cust_t, sizeof(cust_t), 1, fq);
        }
    }
        fclose(fp);
        fclose(fq);
        remove("customer_information.dat");
        rename("data.dat", "customer_information.dat");
        printf("�˿���Ϣɾ�����\n");
        printf("******************************************************      \n");
    printf("*���������һ��������1                               *      \n");
    printf("******************************************************      \n");
    printf("*���ֱ���˳�ϵͳ������2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("��ѡ��Ҫʹ�ù��ܣ�");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("��������밴�չ�����������\n");
    }
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void show_customer(void)
{
    struct Customer_list *look,*p;
    int ss;
    look=NULL;
    look=look_customer();
    int grade=0;
    p=NULL;
    if(look!=NULL)
    {
        p=look;
        printf("|�˿ͱ��|�˿�����|�˿����ѵȼ�|�˿����۶�|\n");
        do
        {
            if(p->god.sale_amount<100)
            {
                grade=0;
            }
            else if((p->god.sale_amount>=100)&&(p->god.sale_amount<1000))
            {
                grade=1;
            }
            else if((p->god.sale_amount>=1000)&&(p->god.sale_amount<2000))
            {
                grade=2;
            }
            else grade=3;
            printf("|%8d|%8s|%12d|%10ld|\n",p->god.number,p->god.name,grade,p->god.sale_amount);
            p=p->next;
        }
      while(p!=NULL);
    }
    printf("******************************************************      \n");
    printf("*���������һ��������1                               *      \n");
    printf("******************************************************      \n");
    printf("*���ֱ���˳�ϵͳ������2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("��ѡ��Ҫʹ�ù��ܣ�");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("��������밴�չ�����������\n");
    }
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
struct Customer_list *look_customer()//�鿴�û���Ϣ�����û���Ϣ�������������ͷ
{
    struct FILF *fp;//�����ļ�ָ��
    struct Customer cust[50];//�����˿���Ϣ�ṹ�����飬����Ϣ�����ļ�֮���ڶ����������������
    //Customer cust1[5];
    struct Customer_list *head;//����ͷָ��
    struct Customer_list *p1,*p2;//���������еĹ���ָ��
    struct Customer cust_t;
    int temp,i,k;
    if((fp=fopen("customer_information.dat","rb"))==NULL)//���ļ��������ݶ���ṹ������
    {
        printf("ϵͳ����!!!!!!!!!\n");
        return 0;
    }
    i=0;//��i��ֵ
    while(fread(&cust[i],sizeof(cust[i]),1,fp)==1)i++;//�����ݶ���ṹ������
    temp=i;
    fclose(fp);
    for(i=0;i<temp;i++)
    {
        for(k=1;k<temp-i;k++)
           {
               if(cust[k].sale_amount<cust[k-1].sale_amount)
               {
                   cust_t=cust[k];
                   cust[k]=cust[k-1];
                   cust[k-1]=cust_t;
               }
           }
    }
    i=0;//��i���¸�ֵΪ0
    k=0;
    head=NULL;
    p1=p2=(struct Customer_list *)malloc(sizeof(struct Customer_list));//�������������ݴ�������
    p1->god=cust[k];
    for(i=0;i<temp;i++)
    {
        k++;
        if(k==1)head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct Customer_list *)malloc(sizeof(struct Customer_list));
        p1->god=cust[k];
    }
    p2->next=NULL;//���������
    memset(cust,0,sizeof(cust));//��cust�����е�������գ��ٴ�����
    //p=head;//��������Ƿ���ȷ
    /*if(head!=NULL)
    {
        do
        {
            printf("%d,%s,%ld\n",p->god.number,p->god.name,p->god.sale_amount);
            p=p->next;
        }
        while(p!=NULL);
    }*/
    /*for(i=0;i<2;i++)
    {
        printf("%d,%s,%d,%ld\n",cust[i].number,cust[i].name,cust[i].sale_amount);
    }*/
    return head;
}
void goods_message()
{
    int num, nu;
    struct comm_buy* w;
    pr();
	while(scanf("%d", &num) != EOF)
    {
        if(num == 0||num == 1||num == 2||num == 3||num ==4||num ==5||num == 6|| num == 7)
            break;
        else printf("������0~7\n");
    }
    switch (num)
	{
        case 0:help();back();break;
        case 1: printf("     *********************************************     \n");
                      printf("     * 1.��¼����Ʒ��Ϣ       2.����             *     \n");//note
                      printf("     *********************************************     \n");
                        while(scanf("%d", &nu) != EOF)
                        {
                            if(nu == 1 || nu == 2)
                                break;
                            else printf("������1��2\n");
                        }
                        switch(nu)
                            {
                                case 1:
                                w = creat();
                                save(w);
                                break;
                                case 2: w = buy();sav(w);back();break;
                            }break;
        case 2:revise();back();break;
        case 3: del();back();break;
        case 4: cu();back(); break;
        case 5: google();back();break;
        case 6:printf("     ******************************************************     \n");
                      printf("     * 1.���������   2.���ۼ���������   3.���ۼ۽������� *     \n");//note
                      printf("     ******************************************************     \n");
                        while(scanf("%d", &nu) != EOF)
                        {
                            if(nu == 1 || nu == 2 ||nu == 3)//system("cls");
                                break;
                            else printf("������1~3\n");
                        }
                        switch(nu)
                            {
                                case 1: order_num();back();break;
                                case 2: order_sell1();back();break;
                                case 3: order_sell2();back();break;
                            }
                      break;
        case 7:
            system("cls");
            user();
            break;
	}
}
struct sale* sp()
{
    struct sale* head=NULL;
    struct sale* p1, * p2;
    int n = 0, a, d;
    long long t;
    double b;
    char c[20];
    p1 = p2 = (struct sale* ) malloc(sizeof(struct sale));
    printf("�����������Ʒ����š����ơ��ۼۡ��������ϼ�ʱ�䣺 \n");
    while(scanf("%d %s %lf %d %lld", &a, c, &b,&d,&t) != EOF)
        {
            if(a < 0 || b < 0)
                {
                    printf("�����ʽ��������������\n");
                }
            else
                {
                    break;
                }
        }
    p1->num = a;
    strcpy(p1->name, c);
    p1->sell = b;
    p1->amount = d;
    p1->time = t;
    while(p1->num != 0)//ѭ��¼��
        {
            n = n+1;
            if(n == 1) head = p1;
            else p2->next = p1;
            p2 = p1;
            p1 = (struct sale*)malloc(sizeof(struct sale));
            printf("�����¼����Ʒ��Ϣ����0 0 0����\n");
            while(scanf("%d %s %lf %d %lld", &a, c, &b, &d, &t) != EOF)//������
                {
                    if(a < 0 || b < 0)
                        {
                            printf("�����ʽ��������������\n");
                        }
                    else
                        {
                            break;
                        }
                }
            p1->num = a;
            strcpy(p1->name, c);
            p1->sell = b;
            p1->amount = d;
            p1->time = t;
            if(p1->num == 0) printf("������Ʒ¼�����\n");
            else printf("������Ʒ¼��ɹ���");
        }
    p2 ->next = NULL;
    return head;
}
//�������ļ�(����)
void sale(struct sale* m)//����ͷָ����ʵ�Σ��ڴ���������Ϣ�Զ����ƴ����"databa.dat"
{
    FILE* fp;
    if((fp = fopen("sale.dat","ab"))== NULL)//�պ��Ϊab
    {
        printf("ERROR!\n");
        return;
    }
    while(m != NULL)
    {
        fwrite(m,sizeof(struct sale),1,fp);
        m = m->next;
    }
    fclose(fp);
    fp = NULL;
}
/*��Ʒ������Ϣ*/
struct messages_buy* buy(void)//��������ͷָ��
{
    FILE* fp;
    fp = fopen("databa.dat", "rb+");
    struct comm_buy comm;
    struct messages_buy* head;
    struct messages_buy* p1, * p2;
    int n = 0;
    int a, b, x;
    long long c;
    char y[15];
    p1 = p2 = (struct messages_buy*) malloc(lon);
    printf("��������Ʒ����š����ơ������۸�����������ʱ�䣨��202102011400,Ϊ2021��2��1������2ʱ��\n");
    while(scanf("%d %s %d %d %lld", &x, y,&a, &b, &c) != EOF)//¼����
    {
        if(a < 0 || b < 0||c<0)
        {
        printf("�����ʽ��������������\n");
        }
        else {
                    break;
                 }
    }
    while(fread(&comm,LEN,1,fp) != 0)
        {
            if(strcmp(comm.name, y) == 0)
            {
                comm.amount = comm.amount + b;
                comm.time = c;
                fseek(fp, 0-LEN, SEEK_CUR);
               // kk++;
                fwrite(&comm,LEN,1,fp);

                break;
            }
        }
       // printf("%d",kk);
    p1->num = x;
    strcpy(p1->name, y);
    p1->amount = b;
    p1->price = a;
    p1->time = c;
    printf("������Ϣ¼��ɹ���\n");
    head = NULL;
    while(p1->amount != 0)//����¼��
    {
        printf("��������Ʒ����š����ơ������۸�����������ʱ�����0 0 0 0 0����\n");
        n = n+1;
        if(n == 1)
            head = p1;
            else p2->next = p1;
        p2 = p1;
        p1 = (struct messages_buy*) malloc(lon);
        while(scanf("%d %s %d %d %d", &x, y,&a, &b, &c) != EOF)//¼����
        {
            if(a < 0 || b < 0)
            {
                printf("�����ʽ��������������\n");
            }
            else
                {
                        while(fread(&comm,LEN,1,fp) != 0)
                        {
                            if(strcmp(comm.name, y) == 0)
                            {
                                comm.amount = comm.amount + b;
                                comm.time = c;
                                fseek(fp, 0-LEN, SEEK_CUR);
                                fwrite(&comm,LEN,1,fp);
                                break;
                            }
                        }
                    p1->num = x;
                    strcpy(p1->name, y);
                    p1->amount = b;
                    p1->price = a;
                    p1->time = c;
                    if(p1->amount == 0) printf("������Ϣ¼�����\n");
                    else printf("������Ϣ¼��ɹ���");
                    break;
                }
        }
    }
    p2->next = NULL;
    fclose(fp);
    return head;

};
//�������ļ�(����)
void sav(struct messages_buy* m)//����ͷָ����ʵ�Σ��ڴ���������Ϣ�Զ����ƴ����"databa.dat"
{
    FILE* fp;
    if((fp = fopen("database.dat","wb"))== NULL)//�պ��Ϊab
    {
        printf("ERROR!\n");
        return;
    }
    while(m != NULL)
    {
        fwrite(m,sizeof(struct messages_buy),1,fp);
        m = m->next;
    }
    fclose(fp);
    fp = NULL;
}
//¼����Ʒ��Ϣ
struct comm_buy* creat(void)//��������ͷָ��
{
    struct comm_buy* head=NULL;
    struct comm_buy* p1, * p2;
    int n = 0, a,am;
    long long t;
    double b;
    char c[20];
    p1 = p2 = (struct comm_buy* ) malloc(sizeof(struct comm_buy));
    printf("��������Ʒ����š����ơ��ۼۡ�����������ʱ��(��202203061518)�� \n");
    while(scanf("%d %s %lf %d %lld", &a, c, &b,&am,&t) != EOF)
        {
            if(a < 0 || b < 0||am<0||t<0)
                {
                    printf("�����ʽ��������������\n");
                }
            else
                {
                    break;
                }
        }
    p1->num = a;
    strcpy(p1->name, c);
    p1->sell = b;
    p1->amount = am;
    p1->time = t;
    while(p1->num != 0)//ѭ��¼��
        {
            n = n+1;
            if(n == 1) head = p1;
            else p2->p = p1;
            p2 = p1;
            p1 = (struct comm_buy*)malloc(sizeof(struct comm_buy));
            printf("�����¼����Ʒ��Ϣ����0 0 0 0 0����\n");
            while(scanf("%d %s %lf %d %d", &a, c, &b,&am,&t) != EOF)//������
                {
                    if(a < 0 || b < 0||am<0||t<0)
                        {
                            printf("�����ʽ��������������\n");
                        }
                    else
                        {
                            break;
                        }
                }
            p1->num = a;
            strcpy(p1->name, c);
            p1->sell = b;
            p1 ->amount = am;
            p1->time = t;
            if(p1->num == 0) printf("��Ʒ��Ϣ¼�����\n");
            else printf("��Ʒ��Ϣ¼��ɹ���");
        }
    p2 ->p = NULL;
    return head;
}
//�������ļ�(��Ʒ)
void save(struct comm_buy* m)//����ͷָ����ʵ�Σ��ڴ���������Ϣ�Զ����ƴ����"databa.dat"
{
    FILE* fp;
    if((fp = fopen("databa.dat","wb"))== NULL)//�պ��Ϊab
    {
        printf("ERROR!\n");
        return;
    }
    while(m != NULL)
    {
        fwrite(m,sizeof(struct comm_buy),1,fp);
        m = m->p;
    }
    fclose(fp);
    fp = NULL;
    back();
}
//��Ʒ��Ϣ�޸�
void revise()//�޸���������ۼ�
{
    FILE* fp;
    int  t = 0;
    char name[20];
    struct comm_buy comm;
    fp = fopen("databa.dat","rb+");
    printf("��������Ҫ�޸ĵ���Ʒ������\n");
    scanf("%s", name);
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(strcmp(comm.name,name) == 0)
            {
                t = 1;
                fseek(fp, 0-sizeof(struct comm_buy), SEEK_CUR);
                printf("��������Ʒ�µ���š����ơ��ۼ�\n");
                while(scanf("%d %s %lf", &comm.num, comm.name, &comm.sell) != EOF)
                    {
                        if(comm.num < 0 || comm.sell <= 0)
                        {
                            printf("�����ʽ��������������\n");
                        }
                        else
                        {
                            printf("�޸ĳɹ���\n");
                            break;
                        }
                    }
                fwrite(&comm,sizeof(struct comm_buy),1,fp);
                break;
            }
    }
    if(t == 0) printf("�����޴���Ʒ\n");
    fclose(fp);
}
//��Ʒ��Ϣɾ��
void del()
{
    FILE* fp, *fq;
    fp = fopen("databa.dat","rb");
    fq = fopen("data.dat", "wb");
    char name[15];
    int t = 0;
    struct comm_buy comm;
    printf("������Ҫɾ����Ʒ������\n");
    scanf("%s", name);
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(strcmp(comm.name,name) != 0)
            fwrite(&comm, sizeof(struct comm_buy), 1, fq);
        else t = 1;
    }
    if(t == 0)
        printf("�������Ʒ������\n");
    else  printf("��Ʒ��Ϣɾ�����\n");
        fclose(fp);
        fclose(fq);
        remove("databa.dat");
        rename("data.dat", "databa.dat");
}
//��Ʒ��Ϣ��ѯ
void google()
{
    FILE* fp;
    int t = 0, m, n;
    char name[20];
    struct comm_buy comm;
    fp = fopen("databa.dat","rb+");
    printf("��ѡ���ѯ��ʽ1.���Ʋ�ѯ 2.��Ų�ѯ 3.ģ����ѯ����Ʒ���֣�4.�۸������ѯ\n");
    while(scanf("%d", &m) != EOF)
    {
        if(m == 1 || m == 2|| m==3||m==4) break;
        else printf("������1~3\n");
    }
    switch(m)
    {
        case 1:
            printf("��������Ҫ��������Ʒ������\n");
            scanf("%s", name);
            while(fread(&comm,LEN,1,fp) != 0)
            {
                if(strcmp(comm.name,name) == 0)
                {
                    t = 1;
                    printf("������������Ʒ����:%s\n\t������������Ʒ����š��ۼۡ�����������ʱ��:%d��%f��%d��%lld\n",comm.name, comm.num, comm.sell,comm.amount,comm.time);
                       break;
               }
            }
            if(t == 0)
               printf("��Ʒ����δ��������������Ʒ\n���������밴1 �����밴2\n");
            else
                printf("������ɣ�������ϡ�\n���������밴1 �����밴2\n");//note
            fclose(fp);
            t=0;
            break;
        case 2:
            printf("��������Ҫ��������Ʒ�����\n");
            scanf("%d",  &n);
            while(fread(&comm,LEN,1,fp) != 0){
                if(comm.num==n)
                {
                    t = 1;
                    printf("������������Ʒ����:%s\n\t������������Ʒ����š��ۼۡ�����������ʱ��:%d��%f��%d��%lld\n", comm.name, comm.num, comm.sell, comm.amount, comm.time);
                    break;
                }
            }
             if(t == 0)
                printf("��Ʒ����δ��������������Ʒ\n���������밴1 �����밴2\n");
             else
                printf("������ɣ�������ϡ�\n���������밴1 �����밴2\n");//note
            fclose(fp);
            break;
        case 3:
            printf("��������Ҫ��������Ʒ������\n");
            scanf("%s", name);
            printf("�����\n�� �� �� �� ʱ\n");
            char shortname[15];
            int n = strlen(name);
            int m = 0;
            int temp = 0;
            while (fread(&comm, LEN, 1, fp) != 0) {
                m = strlen(comm.name);
                for (int item = 0; item <= m-n; item+=2) {
                    temp = 0;
                    for (int t = item; t < item+n; t++) {
                        shortname[temp] = comm.name[t];
                        temp += 1;
                    }
                    shortname[temp] = '\0';
                    if (strcmp(shortname, name) == 0) {
                        printf("%d  %s  %f  %d  %lld\n",comm.num,comm.name,comm.sell,comm.amount,comm.time );
                        break;
                    }
                }
            }
            break;
        case 4:
            printf("�����ѯ�۸�ķ�Χ��\n");
            float low;
            float high;
            scanf("%f %f", &low, &high);
            printf("%f,%f\n", low, high);
            printf("\n������������Ʒ\n");
            while (fread(&comm, LEN, 1, fp) != 0) {
                if (comm.sell<high && low<comm.sell) {
                    printf("2\n");
                    printf("��Ʒ�����ơ���š��ۼۡ�����������ʱ��:%s��%d��%f��%d��%lld\n", comm.name, comm.num, comm.sell, comm.amount, comm.time);
                }
            }
    }
}
/*����_���С����*/
void order_num()
{
    FILE* fp;
    int t=0;
    struct comm_buy e;
    struct comm_buy od[200];//note
    fp = fopen("databa.dat","rb");
    while(fread(&od[t], LEN, 1, fp) != 0)
    {
        t++;
    }
    for(int i = 0;i < t; i++){
        for(int j = i+1; j < t; j++){
            if(od[i].num > od[j].num){
                e = od[i];
                od[i] = od[j];
                od[j] = e;
            }
        }
    }
    for(int i = 0; i < t; i++)//note
    {
        if(od[i].num!=0)
        {
            printf("��ţ�%5d   ���ƣ�%8s   �ۼۣ�%5.2f  ������%6d\n", od[i].num, od[i].name, od[i].sell, od[i].amount);
        }

    }
    fclose(fp);
}
//����_�ۼ�С����
void order_sell1()
{
    FILE* fp;
    int t=0;
    struct comm_buy e;
    struct comm_buy od[200];//note
    fp = fopen("databa.dat","rb");
    while(fread(&od[t],sizeof(struct comm_buy), 1, fp) != 0)
    {
        t++;
    }
    for(int i = 0;i < t; i++){
        for(int j = i+1; j < t; j++){
            if(od[i].sell > od[j].sell){
                e = od[i];
                od[i] = od[j];
                od[j] = e;
            }
        }
    }
    for(int i = 0; i < t; i++)//note
    {
        printf("��ţ�%5d���ƣ�%8s�ۼۣ�%5.2f\n", od[i].num, od[i].name, od[i].sell);
    }
    fclose(fp);
}
//����_�ۼ۴�С
void order_sell2()
{
    FILE* fp;
    int t=0;
    struct comm_buy e;
    struct comm_buy od[200];//note
    fp = fopen("databa.dat","rb");
    while(fread(&od[t],sizeof(struct comm_buy), 1, fp) != 0)
    {
        t++;
    }
    for(int i = 0;i < t; i++){
        for(int j = i+1; j < t; j++){
            if(od[i].sell < od[j].sell){
                e = od[i];
                od[i] = od[j];
                od[j] = e;
            }
        }
    }
    for(int i = 0; i < t; i++)//note
    {
        printf("��ţ�%5d���ƣ�%8s�ۼۣ�%5.2f\n", od[i].num, od[i].name, od[i].sell);
    }
    fclose(fp);
}
//test
void test()
{
    FILE* fp;
    int t = 0;
    struct sale od[200];//note
    fp = fopen("sale.dat","rb");
    while(fread(&od[t],sizeof(struct sale), 1, fp) != 0)
    {
        t++;
    }
    for(int i = 0; i < t; i++)
    {
        printf("��ţ�%5d   ���ƣ�%6s   �ۼۣ�%5.2f\n", od[i].num, od[i].name, od[i].sell);
    }
    fclose(fp);
}
//����
void pr(void)
{
    printf(" \n\n                    \n\n");
	printf("******************************************************\n\n");
	printf("*                    ��Ʒ����ϵͳ                    *\n \n");
	printf("******************************************************\n\n");
	printf("*********************ϵͳ���ܲ˵�*********************       \n");
	printf("    ---------------------   -----------------------   \n");
	printf("     *********************************************     \n");
	printf("     * 0.ϵͳ������˵��  * *  1.¼����Ʒ��Ϣ     *     \n");
	printf("     *********************************************     \n");
	printf("     * 2.�޸���Ʒ��Ϣ    * *  3.ɾ����Ʒ��Ϣ     *     \n");
	printf("     *********************************************     \n");
	printf("     * 4.���������Ʒ    * *  5.��ѯ��Ʒ��Ϣ     *     \n");
	printf("     *********************************************     \n");
	printf("     * 6.ͳ����Ʒ��Ϣ    * *  7.�˻���һ��       *     \n");
	printf("     *********************************************     \n");
	printf("    ---------------------   -----------------------   \n");
	printf("******************************************************      \n");
	printf("��ѡ��˵����:");
}
void back()
{
    int nu;
    printf("     *********************************************     \n");
    printf("     * 1.�������˵�          2.�˳�����          *     \n");//note
    printf("     *********************************************     \n");
    printf("��ѡ��˵���ţ�");
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2)
            break;
        else printf("�����ʽ����������1��2\n");
    }
    switch(nu)
    {
        case 1: system("cls");bac();break;
        case 2:exit(0);
    }
}
void bac()
{
    int num, nu;
    struct comm_buy* w;
    pr();
	while(scanf("%d", &num) != EOF)
    {
        if(num == 0||num == 1||num == 2||num == 3||num ==4||num ==5||num == 6|| num == 7)
            break;
        else printf("������0~7\n");
    }
    switch (num)
	{
        case 0:help();back();break;
        case 1: printf("     *********************************************     \n");
                      printf("     * 1.��¼����Ʒ��Ϣ       2.����             *     \n");//note
                      printf("     *********************************************     \n");
                        while(scanf("%d", &nu) != EOF)
                        {
                            if(nu == 1 || nu == 2)
                                break;
                            else printf("������1��2\n");
                        }
                        switch(nu)
                            {
                                case 1:
                                w = creat();
                                save(w);
                                break;
                                case 2: w = buy();sav(w);back();break;
                            }break;
        case 2:revise();back();break;
        case 3: del();back();break;
        case 4: cu();back(); break;
        case 5: google();back();break;
        case 6:       printf("     ******************************************************     \n");
                      printf("     * 1.���������   2.���ۼ���������   3.���ۼ۽������� *     \n");//note
                      printf("     ******************************************************     \n");
                        while(scanf("%d", &nu) != EOF)
                        {
                            if(nu == 1 || nu == 2 ||nu == 3)//system("cls");
                                break;
                            else printf("������1~3\n");
                        }
                        switch(nu)
                            {
                                case 1: order_num();back();break;
                                case 2: order_sell1();back();break;
                                case 3: order_sell2();back();break;
                            }
                      break;
        case 7:
            system("cls");
            user();
            break;
	}
}

void help()//����
{
	printf("\n1.��ӭʹ��ϵͳ������\n");
	printf("\n2.���ղ˵���ʾ�������ִ���;\n");
	printf("\n3.�����ɻ����µ�15294748920��\n");
	printf("\n4.лл����ʹ�ã�\n");
}

void del_1()
{
    FILE* fp, *fq;
    fp = fopen("sale.dat","rb");
    fq = fopen("sa.dat", "wb");
    char name[15];
    int t = 0;
    struct comm_buy comm;
    printf("������Ҫɾ����Ʒ������\n");
    scanf("%s", name);
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(strcmp(comm.name,name) != 0)
            fwrite(&comm,sizeof(struct comm_buy), 1, fq);
        else t = 1;
    }
    if(t == 0)
        printf("�������Ʒ������\n");
    else  printf("��Ʒ��Ϣɾ�����\n");
        fclose(fp);
        fclose(fq);
        remove("sale.dat");
        rename("sa.dat", "sale.dat");
}
/*����_1*/
void back_1()
{
    int nu;
    printf("     *********************************************     \n");
    printf("     * 1.���ش�����Ʒ�˵�       2.�������˵�        *     \n");//note
    printf("     *********************************************     \n");
    printf("��ѡ��˵���ţ�");
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2)
            break;
        else printf("�����ʽ����������1��2\n");
    }
    switch(nu)
    {
        case 1: system("cls");cu();break;
        case 2:back();break;
    }
}
void bac_1()
{
    int nu;
    struct sale* w;
    printf("     *********************************************     \n");
	printf("     * 1.��ʾ������Ʒ    * *  2.���Ӵ�����Ʒ     *     \n");
	printf("     *********************************************     \n");
	printf("     * 3.�޸Ĵ�����Ʒ    * *  4.ɾ��������Ʒ     *     \n");
	printf("     *********************************************     \n");
	printf("     * 5.ͳ�ƴ�����Ʒ    * *  6.����             *     \n");
	printf("     *********************************************     \n");
	printf("     ��ѡ���ܣ�");
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2 ||nu == 3|| nu == 4|| nu == 5|| nu == 6)
            break;
        else printf("������1~6\n");
    }
    switch(nu)
    {
        case 1: test();back_1();break;
        case 2: w = sp();sale(w);back_1(); break;
        case 3: revise_1();back_1();break;
        case 4:del_1();back_1();break;
        case 5:order_num1();back_1();break;
        case 6:back();
    }
}
/*������Ʒ*/
void cu()
{
    int nu;
    struct sale* w;
    printf("     *********************************************     \n");
	printf("     * 1.��ʾ������Ʒ    * *  2.���Ӵ�����Ʒ     *     \n");
	printf("     *********************************************     \n");
	printf("     * 3.�޸Ĵ�����Ʒ    * *  4.ɾ��������Ʒ     *     \n");
	printf("     *********************************************     \n");
	printf("     * 5.ͳ�ƴ�����Ʒ    * *  6.��ѯ������Ʒ(����)     \n");
	printf("     *********************************************     \n");
    printf("     * 7.�۸������ѯ    * *  8.����             *     \n");
    printf("     *********************************************     \n");
	printf("     ��ѡ���ܣ�");
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2 ||nu == 3|| nu == 4|| nu == 5|| nu == 6||nu==7||nu==8)
            break;
        else printf("������1~6\n");
    }
    switch(nu)
    {
        case 1: test();back_1();break;
        case 2: w = sp();sale(w);back_1(); break;
        case 3: revise_1();back_1();break;
        case 4:del_1();back_1();break;
        case 5:order_num1();back_1();break;
        case 6:search_sale_name(); back_1(); break;
        case 7:search_sale_sell(); back_1(); break;
        case 8:back();
    }
}
void search_sale_name() {
    char sale_name[20];
    char shortname[15];
    FILE* fp;
    fp = fopen("sale.dat", "rb");
    struct sale od;//note
    printf("�������ѯ������Ʒ�Ĳ�������:\n");
    scanf("%s",sale_name );
    int n = strlen(sale_name);
    int m;
    int temp;
    while (fread(&od, sizeof(struct sale), 1, fp) != 0) {
        m = strlen(od.name);
        for (int item = 0; item <= m - n;item+=2) 
        {
            temp = 0;
            for (int t = item; t < item + n; t++) {
                shortname[temp] = od.name[t];
                temp += 1;
            }
            shortname[temp] = '\0';
            if (strcmp(shortname, sale_name) == 0) {
                printf("��ѯ��Ʒ��š����ơ��۸��������ϼ�ʱ��Ϊ��\n");
                printf("%d  %s  %f  %d  %lld\n", od.num, od.name, od.sell, od.amount, od.time);
                break;
            }
        }
    }
}
void search_sale_sell() {
    FILE* fp;
    fp = fopen("sale.dat", "rb");
    struct sale od;
    printf("�������ѯ������Ʒ�ļ۸�����:\n");
    double low,high;
    scanf("%lf %lf", &low, &high);
    int temp;
    while (fread(&od, sizeof(struct sale), 1, fp) != 0) 
    {
        if (od.sell>low && od.sell<high) {
            printf("��Ʒ�����ơ���š��ۼۡ��������ϼ�ʱ��:%s��%d��%f��%d��%lld\n", od.name, od.num, od.sell, od.amount, od.time);
        }
    }
}
void order_num1()
{
    FILE* fp;
    int t=0;
    struct comm_buy e;
    struct comm_buy od[200];//note
    fp = fopen("sale.dat","rb");
    while(fread(&od[t],sizeof(struct sale), 1, fp) != 0)
    {
        t++;
    }
    for(int i = 0;i < t; i++){
        for(int j = i+1; j < t; j++){
            if(od[i].sell > od[j].sell){
                e = od[i];
                od[i] = od[j];
                od[j] = e;
            }
        }
    }
    for(int i = 0; i < t; i++)//note
    {
        printf("��ţ�%d   ���ƣ�%s   �ۼۣ�%f\n", od[i].num, od[i].name, od[i].sell);
    }
    fclose(fp);
}
/*������Ʒ�޸�*/
void revise_1()//�޸���������ۼ�
{
    FILE* fp;
    int  t = 0;
    char name[20];
    struct sale comm;
    fp = fopen("sale.dat","rb+");
    printf("��������Ҫ�޸ĵĴ�����Ʒ������\n");
    scanf("%s", name);
    while(fread(&comm,sizeof(struct sale),1,fp) != 0)
    {
        if(strcmp(comm.name,name) == 0)
            {
                t = 1;
                fseek(fp, 0-sizeof(struct sale), SEEK_CUR);
                printf("�����������Ʒ�µ���š����ơ��ۼ�\n");
                while(scanf("%d %s %lf", &comm.num, comm.name, &comm.sell) != EOF)
                    {
                        if(comm.num < 0 || comm.sell <= 0)
                        {
                            printf("�����ʽ��������������\n");
                        }
                        else
                        {
                            printf("�޸ĳɹ���\n");
                            break;
                        }
                    }
                fwrite(&comm,sizeof(struct sale),1,fp);
                break;
            }
    }
    if(t == 0) printf("�����޴���Ʒ\n");
    fclose(fp);
}

double  price(char c[20])//����Ԥ���ۼ�
{
    FILE* fp;
    double t;
    struct comm_buy comm;
    fp = fopen("databa.dat","rb");
    while(fread(&comm,LEN,1,fp) != 0)
    {
        if(strcmp(comm.name, c) == 0)
            {
                t = comm.sell;
                break;
            }
    }
    fclose(fp);
    return t;
}
/*��ȡ������Ʒ�ۼ�*/
double price_1(char c[20])
{
    FILE* fp;
    double t=-1;
    struct sale comm;
    fp = fopen("sale.dat","rb");
    while(fread(&comm,lon,1,fp) != 0)
    {
        if(strcmp(comm.name, c) == 0)
            {
                t = comm.sell;
                break;
            }
    }
    fclose(fp);
    if (t == -1) {
        fp = fopen("databa.dat", "rb");
        while (fread(&comm, lon, 1, fp) != 0)
        {
            if (strcmp(comm.name, c) == 0)
            {
                t = comm.sell;
                break;
            }
        }
        fclose(fp);
    }
    return t;
}
/*������Ʒ��ѯ*/

int comm_sale(char c[20])//�ж��Ƿ��Ǵ�����Ʒ����Ϊ1����Ϊ0
{
    FILE* fp;
    int t = 0;
    struct sale comm;
    fp = fopen("sale.dat","rb+");
    while(fread(&comm,lon,1,fp) != 0)
    {
        if(strcmp(comm.name, c) == 0)
            {
                t = 1;
            }
    }
    fclose(fp);
    if(t == 0) return 0;
    else return 1;
}
/*��ѯ��Ʒ�Ƿ����*/
int comm_qus(char c[20])
{
    FILE* fp, *fq;
    int t = 0;
    struct sale comm;
    fp = fopen("sale.dat","rb+");

    while(fread(&comm,lon,1,fp) != 0)
    {
        if(strcmp(comm.name, c) == 0)
            {
                t = 1;
                break;
            }
    }
    fclose(fp);
    struct comm_buy com;
    fq = fopen("databa.dat","rb");
    while(fread(&com,LEN,1,fq) != 0)
    {
        if(strcmp(com.name, c) == 0)
            {
                t = 1;
                break;
            }
    }
    fclose(fq);
    if(t == 0) return 0;
    else return 1;
}
/*¼��������Ϣ*/
void  selled(void)//��������ͷָ��
{
    FILE* fq,  *fp;
    struct Customer cust_t,tt;
    struct comm_sell comm;
    int star, sold_1, a,nn=0,hao, wzz = 0, oj,cse=0,cj;
    double b, sold, sell;
    char c[20];
    char cus[20];
    printf("������˿ͻ�Ա�ţ�");
    scanf("%d",&hao);
    while(1)
    {
    wzz = 0;
    struct Customer cust_t,tt;
    fq = fopen("customer_information.dat","rb+");
    //printf("11111");
    while(fread(&cust_t,sizeof(cust_t),1,fq) != 0)
    {
        //printf("11111");
        if(cust_t.number==hao)
        {
            nn++;
            tt=cust_t;
            break;
        }
    }
    if(nn==0)
    {
        int ss;
        printf(" ******************************************************\n");
        printf(" *��Ա���������������1����������                   *\n" );
        printf(" ******************************************************\n");
        printf(" *���ù˿Ͳ�Ϊ��Ա��������2��������                 *\n");
        printf(" ******************************************************\n");
        printf(" *���ù˿�û�д��������Ա����������3����в���     *\n");
        printf(" ******************************************************\n");
        while(1)
        {
            printf("��ѡ���ܣ�\n");
            scanf("%d",&a);
            if((a==1||a==2)||a==3)break;
            else printf("�������������ѡ����\n");
        }
        if(a==1)selled();
        else if(a==2)add_s();
        else
        {
            star=0;
            cse++;
            strcpy(cus,"ĳĳ");
        }

    }
    strcpy(cus,cust_t.name);
    if(cse!=1)
    {
        if(tt.sale_amount<100)
        {
            star=0;
        }
        else if((tt.sale_amount>=100)&&(tt.sale_amount<1000))
        {
           star=1;
        }
        else if((tt.sale_amount>=1000)&&(tt.sale_amount<2000))
        {
            star=2;
        }
        else star=3;
    }

    //printf("%d,%s,%ld",cust_t.number,cust_t.name,cust_t.sale_amount);
    printf("��������Ʒ���ƺ���������0 0�������룩��");
    scanf("%s %d", c, &a);
    if(a == 0) break;
    wzz =  comm_qus(c);
    if(wzz == 0) {printf("��Ʒ�����ڣ�����������\n");continue;}
       cj = comm_qus_1(c);
        if(cj < a) {printf("�����������ڿ����������������\n");continue;}
    comm_qus_2(c, a);

    printf("����������ʱ�䣨��20210308Ϊ2021��3��8�գ�\n");
    scanf("%d", &comm.time);
     sold_1 = comm_sale(c);//�ж��Ƿ��Ǵ�����Ʒ����Ϊ1����Ϊ0
     sell = price(c);//Ԥ���ۼ�
     sold = price_1(c);//�����ۼ�
     switch(star)
     {
         case 0: if(sold_1) {b = a*sold;oj = sold;printf("�˿�%s���ǻ�Ա��������ƷΪ������Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        else {b = a*sell;oj = sell;printf("�˿�%s���ǻ�Ա��������Ʒ�Ǵ�����Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        break;
         case 1: if(sold_1) {b = a*sold*0.95;oj = sold;printf("�˿�%s��һ�Ǽ���Ա����95���Żݣ�������ƷΪ������Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        else {b = a*sell*0.95;oj = sell;printf("�˿�%s��һ�Ǽ���Ա����95���Żݣ�������Ʒ�Ǵ�����Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        break;
         case 2: if(sold_1) {oj = sold;b = a*sold*0.9;printf("�˿�%s�Ƕ��Ǽ���Ա����9���Żݣ�������ƷΪ������Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.9;printf("�˿�%s�Ƕ��Ǽ���Ա����9���Żݣ�������Ʒ�Ǵ�����Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        break;
         case 3: if(sold_1) {oj = sold;b = a*sold*0.85;printf("�˿�%s�����Ǽ���Ա����85���Żݣ�������ƷΪ������Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.85;printf("�˿�%s�����Ǽ���Ա����85���Żݣ�������Ʒ�Ǵ�����Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        break;
     }
     if(cse!=1)
     {
    fseek(fq,0-sizeof(cust_t),SEEK_CUR);
    cust_t.sale_amount=cust_t.sale_amount+(int)b;//�������ѽ��;
    fwrite(&cust_t,sizeof(cust_t),1,fq);
    fclose(fq);
     }

     strcpy(comm.name, c);
     comm.amount = oj;
     comm.num = a;
    fp = fopen("sell.dat", "wb");
    fwrite(&comm,ui, 1, fp);
}
    printf("�ۻ�������\n");
    back_2();
}

 void back_2()
{
    printf("     *********************************************     \n");
	printf("     * 1.�����ۻ�       * * 2.�˳�ϵͳ           *     \n");
	printf("     *********************************************     \n");
	printf("��ѡ��˵���ţ�");
	int nu;
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2)
            break;
        else printf("�����ʽ����������1��2\n");
    }
    switch(nu)
    {
        case 1: system("cls");bac_2();break;
        case 2:exit(0);
    }
 }
void  bac_2(void)//��������ͷָ��
{
   FILE* fq,  *fp;
    struct Customer cust_t,tt;
    struct comm_sell comm;
    int star;
    double sold_1, a,nn=0,hao, wzz = 0, oj,cse=0,cj;
    double b, sold, sell;
    char c[20];
    char cus[20];
    printf("������˿ͻ�Ա�ţ�");
    scanf("%d",&hao);
    while(1)
    {
    wzz = 0;
    struct Customer cust_t,tt;
    fq = fopen("customer_information.dat","rb+");
    printf("11111");
    while(fread(&cust_t,sizeof(cust_t),1,fq) != 0)
    {
        //printf("11111");
        if(cust_t.number==hao)
        {
            nn++;
            tt=cust_t;
            break;
        }
    }
    if(nn==0)
    {
        int ss;
        printf(" ******************************************************\n");
        printf(" *��Ա���������������1����������                   *\n" );
        printf(" ******************************************************\n");
        printf(" *���ù˿Ͳ�Ϊ��Ա��������2��������                 *\n");
        printf(" ******************************************************\n");
        printf(" *���ù˿�û�д��������Ա����������3����в���     *\n");
        printf(" ******************************************************\n");
        while(1)
        {
            printf("��ѡ���ܣ�\n");
            scanf("%d",&a);
            if((a==1||a==2)||a==3)break;
            else printf("�������������ѡ����\n");
        }
        if(a==1)selled();
        else if(a==2)add_s();
        else
        {
            star=0;
            cse++;
            strcpy(cus,"ĳĳ");
        }

    }
   strcpy(cus,cust_t.name);
    if(cse!=1)
    {
        if(tt.sale_amount<100)
        {
            star=0;
        }
        else if((tt.sale_amount>=100)&&(tt.sale_amount<1000))
        {
           star=1;
        }
        else if((tt.sale_amount>=1000)&&(tt.sale_amount<2000))
        {
            star=2;
        }
        else star=3;
    }

    //printf("%d,%s,%ld",cust_t.number,cust_t.name,cust_t.sale_amount);
    printf("��������Ʒ���ƺ���������0 0�������룩��");
    scanf("%s %d", c, &a);
    if(a == 0) break;
    wzz =  comm_qus(c);
    if(wzz == 0) {printf("��Ʒ�����ڣ�����������\n");continue;}
       cj = comm_qus_1(c);
        if(cj < a) {printf("�����������ڿ����������������\n");continue;}
    comm_qus_2(c, a);
    printf("����������ʱ�䣨��20210308Ϊ2021��3��8�գ�\n");
    scanf("%d", &comm.time);
     sold_1 = comm_sale(c);//�ж��Ƿ��Ǵ�����Ʒ����Ϊ1����Ϊ0
     sell = price(c);//Ԥ���ۼ�
     sold = price_1(c);//�����ۼ�
     switch(star)
     {
         case 0: if(sold_1) {b = a*sold;oj = sold;printf("�˿�%s���ǻ�Ա��������ƷΪ������Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        else {b = a*sell;oj = sell;printf("�˿�%s���ǻ�Ա��������Ʒ�Ǵ�����Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        break;
         case 1: if(sold_1) {b = a*sold*0.95;oj = sold;printf("�˿�%s��һ�Ǽ���Ա����95���Żݣ�������ƷΪ������Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        else {b = a*sell*0.95;oj = sell;printf("�˿�%s��һ�Ǽ���Ա����95���Żݣ�������Ʒ�Ǵ�����Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        break;
         case 2: if(sold_1) {oj = sold;b = a*sold*0.9;printf("�˿�%s�Ƕ��Ǽ���Ա����9���Żݣ�������ƷΪ������Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.9;printf("�˿�%s�Ƕ��Ǽ���Ա����9���Żݣ�������Ʒ�Ǵ�����Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        break;
         case 3: if(sold_1) {oj = sold;b = a*sold*0.85;printf("�˿�%s�����Ǽ���Ա����85���Żݣ�������ƷΪ������Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.85;printf("�˿�%s�����Ǽ���Ա����85���Żݣ�������Ʒ�Ǵ�����Ʒ����������%3d��Ӧ��%5.2f��\n", cus, a, b);}
                        break;
     }
     if(cse!=1)
     {
    fseek(fq,0-sizeof(cust_t),SEEK_CUR);
    cust_t.sale_amount=cust_t.sale_amount+(int)b;//�������ѽ��;
    fwrite(&cust_t,sizeof(cust_t),1,fq);
    fclose(fq);
     }

     comm.amount = oj;
    fp = fopen("sell.dat", "wb");
    fwrite(&comm,ui, 1, fp);
}
    printf("�ۻ�������\n");
    back_2();
}

void search_selled()
{
    int time,temp=0,i,k,p,ss;
    FILE *fp;
    struct comm_sell t,tt;
    struct comm_sell mm[50];
    if((fp = fopen("sell.dat","rb+"))==0)
    {
        printf("ϵͳ���󣡣�����");
    }
    printf("��������Ҫ��ѯ��ʱ�䣨��ʽΪĳ��ĳ��ĳ����20210101����");
    scanf("%d",&time);
    while((fread(&t,sizeof(struct comm_sell),1,fp))!=0)

    {
        if(t.time==time)
        {
            mm[temp]=t;
            temp++;
        }
    }
    if(temp==0)
    {
    printf("������󣬻�û�и���Ʒ\n");
    printf("******************************************************      \n");
    printf("*�˳���������������1                                 *      \n");
    printf("******************************************************      \n");
    printf("*��������������2                                     *      \n");
    printf("******************************************************      \n");
    printf("*�˳�ϵͳ������3                                     *      \n ");
    printf("******************************************************      \n");
    while(1)
    {
        printf("��ѡ��Ҫʹ�ù��ܣ�");
        scanf("%d",&ss);
        if((ss==1||ss==2)||ss==3)break;
        else printf("��������밴�չ�����������\n");
    }
    if(ss==2)search_selled();
    else if(ss==1)
    {
        system("cls");
        user();
    }
    else if(ss==3)exit(0);
    }
    fclose(fp);

    for(i=0;i<temp;i++)
    {
        for(k=1;k<temp-i;k++)
           {
               if(mm[k].num<mm[k-1].num)
               {
                   tt=mm[k];
                   mm[k]=mm[k-1];
                   mm[k-1]=tt;
               }
           }
    }

    printf("******************************************************      \n");
    printf("*������ѯ����������Ʒ����������1                   *  \n");
    printf("******************************************************      \n");
    printf("*������ѯ����������õ���Ʒ������2                 *    \n");
    printf("******************************************************      \n");
    printf("��ѡ��Ҫʹ�ù��ܣ�");
    scanf("%d",&p);
    if(p==1)
    {
        show_rank(mm,temp);
    }
    else
    {
        show_best(mm,temp);
    }
    memset(mm,0,sizeof(mm[50]));

}
void show_rank(struct comm_sell pp[],int temp1)
{
    int i;
    int ss;
    printf("����������Ʒ�����б����£�\n");
    printf("|  ��Ʒ����  |��Ʒ����|��Ʒ��Ŀ|��Ʒ�۳�ʱ��|\n");
    for(i=0;i<temp1;i++)
    {
        printf("|%12s|%8.2lf|%8d|%12d|\n",pp[i].name,pp[i].amount,pp[i].num,pp[i].time);
    }
    printf("******************************************************      \n");
    printf("*��������������1                                     *      \n");
    printf("******************************************************      \n");
    printf("*�˻ع�����������������2                             *      \n");
    printf("******************************************************      \n");
    printf("*�˳�ϵͳ������3                                     *      \n");
    printf("******************************************************      \n");

    while(1)
    {
        printf("��ѡ��Ҫʹ�ù��ܣ�");
        scanf("%d",&ss);
        if(ss==1||ss==2||ss==3)break;
        else printf("��������밴�չ�����������\n");
    }

    if(ss==1)search_selled();
    else if(ss==2)
    {
        system("cls");
        user();
    }
    else if(ss==3)exit(0);

}
void show_best(struct comm_sell pp[],int temp1)
{
    int ss;
    printf("�������������Ʒ���£�\n");
    printf("|  ��Ʒ����  |��Ʒ����|��Ʒ��Ŀ|��Ʒ�۳�ʱ��|\n");
    printf("|%12s|%8.2lf|%8d|%12d|\n",pp[temp1-1].name,pp[temp1-1].amount,pp[temp1-1].num,pp[temp1-1].time);

    printf("******************************************************      \n");
    printf("*��������������1                                     *      \n");
    printf("******************************************************      \n");
    printf("*�˻ع�����������������2                             *      \n");
    printf("******************************************************      \n");
    printf("*�˳�ϵͳ������3                                     *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("��ѡ��Ҫʹ�ù��ܣ�");
        scanf("%d",&ss);
        if((ss==1||ss==2)||ss==3)break;
        else printf("��������밴�չ�����������\n");
    }
    if(ss==1)search_selled();
    else if(ss==2)
    {
        system("cls");
        user();
    }
    else if(ss==3)exit(0);
}

void add_s()
{
    struct FILF *fp;
    struct Customer cust;
    printf("������Ҫ��ӵĹ˿���Ϣ���밴�չ˿ͱ�ţ�����,���۶�ڴ���ʱָ��Ϊ0���������룬�����1001��1002����");
    scanf("%d%s%ld",&cust.number,cust.name,&cust.sale_amount);//¼��˿���Ϣ
    if((fp=fopen("customer_information.dat","ab"))==NULL)//�򿪴����ļ�
    {
        printf("ϵͳ����!!!!!!!!!\n");
        exit(0);//��������
    }
    fwrite(&cust,sizeof(cust),1,fp);//���ļ��ж�������
    fclose(fp);
    printf("��ӳɹ�,������������\n");
    selled();
}

int  comm_qus_1(char c[20])
{
    FILE *fq;
    int am = 0;
    struct comm_buy com;
    fq = fopen("databa.dat","rb");
    while(fread(&com,LEN,1,fq) != 0)
    {
        if(strcmp(com.name, c) == 0)
            {
                am = am + com.amount;
            }
    }
    fclose(fq);
    return am;
}
void comm_qus_2(char str[20], int k)
{
    FILE *fq;
    struct comm_buy com;

    fq = fopen("databa.dat","rb+");
    while((fread(&com,LEN,1,fq)) != 0)
    {
        if((strcmp(com.name, str)) == 0)
            {
                com.amount = com.amount - k;
                fseek(fq, 0-LEN, SEEK_CUR);
                fwrite(&com, LEN, 1, fq);
                //y++;
                break;
            }
    }
    //printf("%d", y);
    fclose(fq);
}
