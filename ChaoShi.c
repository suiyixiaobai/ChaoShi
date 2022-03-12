#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"ChaoShi.h"


void interface1(void)//定义进入界面时第一个函数
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
    printf("欢迎使用小型超市商品管理系统（请按Enter键进入.......)");
    getchar();
    system("cls");
}
void interface2(void)//定义进入界面时第二个函数
{
    int i;
    char ch='*';
    for(i=1;i<20;i++)
    {
        putchar(ch);
    }
    printf("小型超市商品管理系统");
    for(i=1;i<20;i++)
    {
        putchar(ch);
    }

}
void set_account(void)//初始化账号密码
{
    int a;
    struct Account account_neu;
    struct Account nnnn;
    //scanf("%ld",&nnnn.ID_g);
    //struct Account account_cse;
    struct FILF *fp;
    if((fp=fopen("account.dat","wb+"))==NULL)//打开磁盘文件
    {
        printf("系统出错!!!!!!!!!\n");
        exit(0);//结束函数
    }
    printf("请输入初始化的账号密码\n");
    printf("初始化收银员账号：");
    scanf("%ld",&account_neu.ID_s);
    printf("初始化收银员密码：");
    scanf("%ld",&account_neu.password_s);
    printf("初始化管理员账号：");
    scanf("%ld",&account_neu.ID_g);
    printf("初始化管理员密码：");
    scanf("%ld",&account_neu.password_g);
    //printf("%ld %ld %ld %ld\n",account_neu.ID_s,account_neu.password_s,account_neu.ID_g,account_neu.password_g);
    fwrite(&account_neu,sizeof(account_neu),1,fp);//将账号密码读入文件
    rewind(fp);
    //fread(&account_cse,sizeof(account_cse),1,fp);
    //printf("%ld %ld %ld %ld\n",account_cse.ID_s,account_cse.password_s,account_cse.ID_g,account_cse.password_g);

    printf("账号密码设置完成");
    printf("再次输入账号密码登录\n");
    printf("如果是管理者请输入1，如果是收银员请输入2：\n");
    scanf("%d",&a);
    log_in_s(a);//收银员的登录界面
    log_in_g(a);//管理者的登录界面
}
void log_in_s(int x)//收银员登陆界面
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
    printf("你好收银员，请输入你的账号，密码\n");
    printf("账号：");
    scanf("%ld",&ID);
     printf("\n");
    printf("密码：");
    scanf("%ld",&password);
     printf("\n");
    if((ID==account_t.ID_s)&&(password==account_t.password_s))
    {

        system("cls");
        printf("登录成功\n欢迎进入美好的收银时间\n");
        selled();
    }
    else
    {
        printf("账号密码错误，系统自动退出\n");
        exit(0);

    }
    }
}
struct Account* read_account(void)//读出账号密码
{
    struct FILF *fp;
    struct Account account_cse;
    struct Account  *pp;
    pp=&account_cse;
    if((fp=fopen("account.dat","ab+"))==NULL)//打开磁盘文件
    {
        printf("系统出错!!!!!!!!!\n");
        return 0;//结束函数
    }
    fread(pp,sizeof(account_cse),1,fp);
    //printf("%ld %ld %ld %ld\n",account_cse.ID_s,account_cse.password_s,account_cse.ID_g,account_cse.password_g);
    return pp;
}
void log_in_g(int x)//管理员登陆界面
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
    printf("你好管理员，请输入你的账号，密码\n");
    printf("账号：");
    scanf("%ld",&ID);
     printf("\n");
    printf("密码：");
    scanf("%ld",&password);
     printf("\n");
     //printf("%ld %ld %ld %ld\n",account1->ID_s,account1->password_s,account1->ID_g,account1->password_g);
    if((ID==account_t.ID_g)&&(password==account_t.password_g))
    {
        printf("登录成功\n");
        user();
    }
    else printf("账号密码输入错误，系统自动退出\n");
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
	printf(" *                    管理系统                        *\n \n");
	printf(" ******************************************************\n\n");
	printf("*********************系统功能菜单***********************       \n");
	printf("    -----------------------   ---------------------   \n");
	printf("     **********************************************     \n");
	printf("     * 0.退出该系统       * *  1.修改登录账号密码 *     \n");
	printf("     **********************************************     \n");
	printf("     * 2.顾客管理系统     * *  3.商品管理系统     *     \n");
	printf("     **********************************************     \n");
	printf("     * 4.查询畅销商品                             *     \n");
	printf("     **********************************************     \n");
	//printf("     * 6. * *  7.    *     \n");
	//printf("     **********************************************     \n");
	printf("    -----------------------   ---------------------   \n");
	printf("********************************************************       \n");
	//printf("请选择菜单编号:");
    //scanf("%d",&choice);

    while(1)
    {
        printf("请选择要使用功能：");
        scanf("%d",&choice);
        if((((choice==0||choice==1)||choice==2)||choice==3)||choice==4)break;
        else printf("输入错误，请按照规则重新输入\n");
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
        printf("输入有误，没有该功能\n");
        break;
    }
    //system("cls");
}
void change_account(void)
{
    struct FILF *fp;

    struct Account account_neucse;
    if((fp=fopen("account.dat","ab"))==NULL)//打开磁盘文件
    {
        printf("系统出错!!!!!!!!!\n");
        return 0;//结束函数
    }
    printf("请输入修改后的账号密码\n");
    printf("修改后收银员账号：");
    scanf("%ld",&account_neucse.ID_s);
    printf("修改后收银员密码：");
    scanf("%ld",&account_neucse.password_s);
    printf("修改后管理员账号：");
    scanf("%ld",&account_neucse.ID_g);
    printf("修改后管理员密码：");
    scanf("%ld",&account_neucse.password_g);

    fwrite(&account_neucse,sizeof(account_neucse),1,fp);//将账号密码读入文件

    printf("账号密码修改完成\n");
    int a;
    printf(" ******************************************************\n");
    printf(" * 如果继续使用该系统请输入1                      *\n");
    printf(" ******************************************************\n");
    printf(" * 如果想退出该系统请输入2                            *\n");
    printf(" ******************************************************\n");
    printf(" 请选择要是用的功能：\n");
    scanf("%d",&a);
    if(a==1)user();
    else if(a==2) exit(0);
}
void showorchange_customer(void)
{
    /*void save_Customer(void);//第一次录入顾客信息1
    void add_customer(void);//添加顾客信息1
    void revise(void);//修改顾客信息1
    void del(void);//删除顾客数据1
    struct Customer_list *look_customer(void);//查看顾客信息，将顾客信息建成链表输出表头1
    void show_customer(void);//展示顾客信息1*/
    int a;
    printf(" \n\n                    \n\n");
	printf(" ******************************************************\n\n");
	printf(" *                    顾客管理系统                    *\n \n");
	printf(" ******************************************************\n\n");
	printf("*********************系统功能菜单***********************       \n");
	printf("    -----------------------   ---------------------   \n");
	printf("     **********************************************     \n");
	printf("     * 0.返回上一级       * *  1. 使用帮助        *     \n");
	printf("     **********************************************     \n");
	printf("     * 2.录入顾客信息     * *  3.添加顾客信息     *     \n");
	printf("     **********************************************     \n");
	printf("     * 4.修改顾客信息     * *  5.删除顾客信息     *     \n");
	printf("     **********************************************     \n");
	printf("     * 6.显示顾客信息     * *  7.查询顾客信息     *     \n");
	printf("     **********************************************     \n");
	printf("     * 8.模糊查询姓名     * *   -------------------   \n");
	printf("********************************************************       \n");
	//查询顾客信息，帮助
	printf("请选择菜单编号:");
    scanf("%d",&a);
    printf("\n");
    system("cls");
    switch(a)
    {
    case 1:
        {
            int ss;
            printf("1.请按照提示使用该功能\n 2.如有疑问请拨打咨询热线15294748920\n 3.谢谢您对该系统的支持\n\n\n\n\n");
            printf("如果返回上一级请输入1\n如果直接退出系统请输入2\n");
            printf("请选择功能：");
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
        printf("输入有误，没有该功能\n");
        int a;
        printf("如果想继续使用本系统请输入1");
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
    int i,temp,num_cust,a,grade,ss,nn=0;//temp为要搜索顾客数目，num_cust为要搜索的顾客标号
    char name_cust[20];//要搜索顾客姓名
    head_cust=look_customer();
    p=NULL;
    printf("请选择搜索方式（按姓名搜索或按顾客编号搜索");
    printf("按姓名搜索请输入1，按顾客编号搜索请输入2):");
    scanf("%d",&a);
    printf("请输入要搜索次数：");
    scanf("%d",&temp);
    if(a==1)
    {
        for(i=0;i<temp;i++)
        {
            printf("请输入要搜索顾客姓名：");
            scanf("%s",name_cust);
            if(head_cust!=NULL)
           {
            p=head_cust;
            do
            {
            if(strcmp(name_cust,p->god.name)== 0)
            {
                nn++;
                printf("|顾客编号|顾客姓名|顾客消费等级|顾客销售额|\n");
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
            printf("请输入要搜索顾客编号：");
            scanf("%d",&num_cust);
            if(head_cust!=NULL)
           {
            p=head_cust;
            do
            {
            if(p->god.number==num_cust)
            {
                nn++;
                printf("|顾客编号|顾客姓名|顾客消费等级|顾客销售额|\n");
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
    else printf("未按规定输入\n");
    if(nn==0)printf("未查询到所输入的顾客\n\n\n");
    printf("如果返回上一级请输入1\n如果直接退出系统请输入2\n");
    printf("请选择功能：");
    scanf("%d",&ss);
    system("cls");
    if(ss==1)showorchange_customer();
    else if(ss==2)exit(0);
}
void search_customer_mohu() {
    struct Customer_list* head_cust, * p;
    int i, temp, a, grade,tmp, ss, nn = 0;//temp为要搜索顾客数目，num_cust为要搜索的顾客标号
    char name_cust[20];//要搜索顾客姓名
    char shortname[20];
    head_cust = look_customer();
    printf("请输入要搜索人数：");
    scanf("%d", &temp);
    for (i = 0; i < temp; i++)
    {
        printf("请输入要搜索顾客姓名：");
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
                    printf("|顾客编号|顾客姓名|顾客消费等级|顾客销售额|\n");
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
void save_Customer(void)//用户第一次进行数据录入
{
      //该程序为第一次录入顾客信息时所使用的函数
    struct FILF *fp;//建立文件指针
    struct Customer cust[100];//建立顾客信息结构体数组，将信息读入文件之后在读出到数组进行排序
    //Customer cust1[5];
    int i,num_cust,ss;//后者为顾客数目
    printf("请输入要录入的顾客数目：");
    scanf("%d",&num_cust);//读入顾客数目
    printf("请输入要录入的顾客信息（请按照顾客编号，姓名，销售额进行输入，编号如1001，1002）：");
    printf("\n");
    for(i=0;i<num_cust;i++)//建立循环
    {
        scanf("%d%s%ld",&cust[i].number,cust[i].name,&cust[i].sale_amount);//录入顾客信息
    }

    //将信息导入文件
    if((fp=fopen("customer_information.dat","ab"))==NULL)//打开磁盘文件
    {
        printf("系统出错!!!!!!!!!\n");
        return 0;//结束函数
    }
    for(i=0;i<num_cust;i++)
    {
        fwrite(&cust[i],sizeof(cust[i]),1,fp);//向文件中读入数据
    }
    memset(cust,0,sizeof(cust));//将cust数组中的数据清空，再次利用
    fclose(fp);
    printf("录入成功\n");
    printf("******************************************************      \n");
    printf("*如果返回上一级请输入1                               *      \n");
    printf("******************************************************      \n");
    printf("*如果直接退出系统请输入2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("请选择要使用功能：");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("输入错误，请按照规则重新输入\n");
    }
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void add_customer()//在文件中添加数据
{
    struct FILF *fp;
    struct Customer cust[50];
    int i,num,ss;
    printf("请输入要添加的顾客数目：");
    scanf("%d",&num);//读入顾客数目
    printf("请输入要添加的顾客信息（请按照顾客编号，姓名，销售额进行输入，编号如1001，1002）：");
    printf("\n");
    for(i=0;i<num;i++)//建立循环
    {
        scanf("%d%s%ld",&cust[i].number,cust[i].name,&cust[i].sale_amount);//录入顾客信息
    }
        if((fp=fopen("customer_information.dat","ab"))==NULL)//打开磁盘文件
    {
        printf("系统出错!!!!!!!!!\n");
        return 0;//结束函数
    }
    for(i=0;i<num;i++)
    {
        fwrite(&cust[i],sizeof(cust[i]),1,fp);//向文件中读入数据
    }
    memset(cust,0,sizeof(cust));//将cust数组中的数据清空，再次利用
    fclose(fp);
    printf("添加成功\n");
    printf("******************************************************      \n");
    printf("*如果返回上一级请输入1                               *      \n");
    printf("******************************************************      \n");
    printf("*如果直接退出系统请输入2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("请选择要使用功能：");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("输入错误，请按照规则重新输入\n");
    }
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void revise1()//修改用户信息
{
    FILE* fp;
    int ss;
    //char name[20];
    int num_cha;
    struct Customer cust_t;
    fp = fopen("customer_information.dat","rb+");
    printf("请输入您要修改的用户的编号:\n");
    scanf("%d",&num_cha);
    //printf("11111");
    while(fread(&cust_t,sizeof(cust_t),1,fp) != 0)
    {
        //printf("11111");
        if(cust_t.number==num_cha){
            fseek(fp,0-sizeof(cust_t),SEEK_CUR);
            printf("请输入修改后的顾客信息（请按照顾客编号，姓名，销售额进行输入，编号如1001，1002）:");//增添
            scanf("%d%s%ld",&cust_t.number,cust_t.name,&cust_t.sale_amount);//输入给
            fwrite(&cust_t,sizeof(cust_t),1,fp);
            break;
        }
    }
    fclose(fp);
    printf("******************************************************      \n");
    printf("*如果返回上一级请输入1                               *      \n");
    printf("******************************************************      \n");
    printf("*如果直接退出系统请输入2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("请选择要使用功能：");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("输入错误，请按照规则重新输入\n");
    }
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void del1(void)//删除用户数据
{
    FILE *fp,*fq;
    int ss;
    fp = fopen("customer_information.dat","rb");
    fq = fopen("data.dat", "wb");
    char name[20];
    struct Customer cust_t;
    printf("请输入要删除顾客的名称\n");
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
        printf("顾客信息删除完成\n");
        printf("******************************************************      \n");
    printf("*如果返回上一级请输入1                               *      \n");
    printf("******************************************************      \n");
    printf("*如果直接退出系统请输入2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("请选择要使用功能：");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("输入错误，请按照规则重新输入\n");
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
        printf("|顾客编号|顾客姓名|顾客消费等级|顾客销售额|\n");
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
    printf("*如果返回上一级请输入1                               *      \n");
    printf("******************************************************      \n");
    printf("*如果直接退出系统请输入2                             *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("请选择要使用功能：");
        scanf("%d",&ss);
        if(ss==1||ss==2)break;
        else printf("输入错误，请按照规则重新输入\n");
    }
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
struct Customer_list *look_customer()//查看用户信息，将用户信息建成链表输出表头
{
    struct FILF *fp;//建立文件指针
    struct Customer cust[50];//建立顾客信息结构体数组，将信息读入文件之后在读出到数组进行排序
    //Customer cust1[5];
    struct Customer_list *head;//链表头指针
    struct Customer_list *p1,*p2;//建立链表中的过程指针
    struct Customer cust_t;
    int temp,i,k;
    if((fp=fopen("customer_information.dat","rb"))==NULL)//打开文件，将数据读入结构体数组
    {
        printf("系统出错!!!!!!!!!\n");
        return 0;
    }
    i=0;//将i赋值
    while(fread(&cust[i],sizeof(cust[i]),1,fp)==1)i++;//将数据读入结构体数组
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
    i=0;//将i重新赋值为0
    k=0;
    head=NULL;
    p1=p2=(struct Customer_list *)malloc(sizeof(struct Customer_list));//建立链表并将数据传入链表
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
    p2->next=NULL;//链表建立完成
    memset(cust,0,sizeof(cust));//将cust数组中的数据清空，再次利用
    //p=head;//检测链表是否正确
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
        else printf("请输入0~7\n");
    }
    switch (num)
	{
        case 0:help();back();break;
        case 1: printf("     *********************************************     \n");
                      printf("     * 1.请录入商品信息       2.进货             *     \n");//note
                      printf("     *********************************************     \n");
                        while(scanf("%d", &nu) != EOF)
                        {
                            if(nu == 1 || nu == 2)
                                break;
                            else printf("请输入1或2\n");
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
                      printf("     * 1.按序号排序   2.按售价升序排序   3.按售价降序排序 *     \n");//note
                      printf("     ******************************************************     \n");
                        while(scanf("%d", &nu) != EOF)
                        {
                            if(nu == 1 || nu == 2 ||nu == 3)//system("cls");
                                break;
                            else printf("请输入1~3\n");
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
    printf("请输入促销商品的序号、名称、售价、数量、上架时间： \n");
    while(scanf("%d %s %lf %d %lld", &a, c, &b,&d,&t) != EOF)
        {
            if(a < 0 || b < 0)
                {
                    printf("输入格式不对请重新输入\n");
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
    while(p1->num != 0)//循环录入
        {
            n = n+1;
            if(n == 1) head = p1;
            else p2->next = p1;
            p2 = p1;
            p1 = (struct sale*)malloc(sizeof(struct sale));
            printf("请继续录入商品信息或以0 0 0结束\n");
            while(scanf("%d %s %lf %d %lld", &a, c, &b, &d, &t) != EOF)//输入检查
                {
                    if(a < 0 || b < 0)
                        {
                            printf("输入格式不对请重新输入\n");
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
            if(p1->num == 0) printf("促销商品录入结束\n");
            else printf("促销商品录入成功！");
        }
    p2 ->next = NULL;
    return head;
}
//储存至文件(促销)
void sale(struct sale* m)//链表头指针作实参，内存中链表信息以二进制储存进"databa.dat"
{
    FILE* fp;
    if((fp = fopen("sale.dat","ab"))== NULL)//日后改为ab
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
/*商品进货信息*/
struct messages_buy* buy(void)//返回链表头指针
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
    printf("请输入商品的序号、名称、进货价格、数量、进货时间（如202102011400,为2021年2月1日下午2时）\n");
    while(scanf("%d %s %d %d %lld", &x, y,&a, &b, &c) != EOF)//录入检查
    {
        if(a < 0 || b < 0||c<0)
        {
        printf("输入格式不对请重新输入\n");
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
    printf("进货信息录入成功！\n");
    head = NULL;
    while(p1->amount != 0)//继续录入
    {
        printf("请输入商品的序号、名称、进货价格、数量、进货时间或以0 0 0 0 0结束\n");
        n = n+1;
        if(n == 1)
            head = p1;
            else p2->next = p1;
        p2 = p1;
        p1 = (struct messages_buy*) malloc(lon);
        while(scanf("%d %s %d %d %d", &x, y,&a, &b, &c) != EOF)//录入检查
        {
            if(a < 0 || b < 0)
            {
                printf("输入格式不对请重新输入\n");
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
                    if(p1->amount == 0) printf("进货信息录入结束\n");
                    else printf("进货信息录入成功！");
                    break;
                }
        }
    }
    p2->next = NULL;
    fclose(fp);
    return head;

};
//储存至文件(进货)
void sav(struct messages_buy* m)//链表头指针作实参，内存中链表信息以二进制储存进"databa.dat"
{
    FILE* fp;
    if((fp = fopen("database.dat","wb"))== NULL)//日后改为ab
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
//录入商品信息
struct comm_buy* creat(void)//返回链表头指针
{
    struct comm_buy* head=NULL;
    struct comm_buy* p1, * p2;
    int n = 0, a,am;
    long long t;
    double b;
    char c[20];
    p1 = p2 = (struct comm_buy* ) malloc(sizeof(struct comm_buy));
    printf("请输入商品的序号、名称、售价、数量、进货时间(如202203061518)： \n");
    while(scanf("%d %s %lf %d %lld", &a, c, &b,&am,&t) != EOF)
        {
            if(a < 0 || b < 0||am<0||t<0)
                {
                    printf("输入格式不对请重新输入\n");
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
    while(p1->num != 0)//循环录入
        {
            n = n+1;
            if(n == 1) head = p1;
            else p2->p = p1;
            p2 = p1;
            p1 = (struct comm_buy*)malloc(sizeof(struct comm_buy));
            printf("请继续录入商品信息或以0 0 0 0 0结束\n");
            while(scanf("%d %s %lf %d %d", &a, c, &b,&am,&t) != EOF)//输入检查
                {
                    if(a < 0 || b < 0||am<0||t<0)
                        {
                            printf("输入格式不对请重新输入\n");
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
            if(p1->num == 0) printf("商品信息录入结束\n");
            else printf("商品信息录入成功！");
        }
    p2 ->p = NULL;
    return head;
}
//储存至文件(商品)
void save(struct comm_buy* m)//链表头指针作实参，内存中链表信息以二进制储存进"databa.dat"
{
    FILE* fp;
    if((fp = fopen("databa.dat","wb"))== NULL)//日后改为ab
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
//商品信息修改
void revise()//修改序号名称售价
{
    FILE* fp;
    int  t = 0;
    char name[20];
    struct comm_buy comm;
    fp = fopen("databa.dat","rb+");
    printf("请输入您要修改的商品的名称\n");
    scanf("%s", name);
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(strcmp(comm.name,name) == 0)
            {
                t = 1;
                fseek(fp, 0-sizeof(struct comm_buy), SEEK_CUR);
                printf("请输入商品新的序号、名称、售价\n");
                while(scanf("%d %s %lf", &comm.num, comm.name, &comm.sell) != EOF)
                    {
                        if(comm.num < 0 || comm.sell <= 0)
                        {
                            printf("输入格式不对请重新输入\n");
                        }
                        else
                        {
                            printf("修改成功！\n");
                            break;
                        }
                    }
                fwrite(&comm,sizeof(struct comm_buy),1,fp);
                break;
            }
    }
    if(t == 0) printf("库中无此商品\n");
    fclose(fp);
}
//商品信息删除
void del()
{
    FILE* fp, *fq;
    fp = fopen("databa.dat","rb");
    fq = fopen("data.dat", "wb");
    char name[15];
    int t = 0;
    struct comm_buy comm;
    printf("请输入要删除商品的名称\n");
    scanf("%s", name);
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(strcmp(comm.name,name) != 0)
            fwrite(&comm, sizeof(struct comm_buy), 1, fq);
        else t = 1;
    }
    if(t == 0)
        printf("输入的商品不存在\n");
    else  printf("商品信息删除完成\n");
        fclose(fp);
        fclose(fq);
        remove("databa.dat");
        rename("data.dat", "databa.dat");
}
//商品信息查询
void google()
{
    FILE* fp;
    int t = 0, m, n;
    char name[20];
    struct comm_buy comm;
    fp = fopen("databa.dat","rb+");
    printf("请选择查询方式1.名称查询 2.序号查询 3.模糊查询（商品名字）4.价格区间查询\n");
    while(scanf("%d", &m) != EOF)
    {
        if(m == 1 || m == 2|| m==3||m==4) break;
        else printf("请输入1~3\n");
    }
    switch(m)
    {
        case 1:
            printf("请输入您要搜索的商品的名称\n");
            scanf("%s", name);
            while(fread(&comm,LEN,1,fp) != 0)
            {
                if(strcmp(comm.name,name) == 0)
                {
                    t = 1;
                    printf("你所搜索的商品名称:%s\n\t您所搜索的商品的序号、售价、数量、进货时间:%d、%f、%d、%lld\n",comm.name, comm.num, comm.sell,comm.amount,comm.time);
                       break;
               }
            }
            if(t == 0)
               printf("商品库中未发现您搜索的商品\n继续搜索请按1 返回请按2\n");
            else
                printf("检索完成，结果如上。\n继续搜索请按1 返回请按2\n");//note
            fclose(fp);
            t=0;
            break;
        case 2:
            printf("请输入您要搜索的商品的序号\n");
            scanf("%d",  &n);
            while(fread(&comm,LEN,1,fp) != 0){
                if(comm.num==n)
                {
                    t = 1;
                    printf("你所搜索的商品名称:%s\n\t您所搜索的商品的序号、售价、数量、进货时间:%d、%f、%d、%lld\n", comm.name, comm.num, comm.sell, comm.amount, comm.time);
                    break;
                }
            }
             if(t == 0)
                printf("商品库中未发现您搜索的商品\n继续搜索请按1 返回请按2\n");
             else
                printf("检索完成，结果如上。\n继续搜索请按1 返回请按2\n");//note
            fclose(fp);
            break;
        case 3:
            printf("请输入您要搜索的商品的名称\n");
            scanf("%s", name);
            printf("输出：\n序 名 价 量 时\n");
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
            printf("输入查询价格的范围：\n");
            float low;
            float high;
            scanf("%f %f", &low, &high);
            printf("%f,%f\n", low, high);
            printf("\n你所搜索的商品\n");
            while (fread(&comm, LEN, 1, fp) != 0) {
                if (comm.sell<high && low<comm.sell) {
                    printf("2\n");
                    printf("商品的名称、序号、售价、数量、进货时间:%s、%d、%f、%d、%lld\n", comm.name, comm.num, comm.sell, comm.amount, comm.time);
                }
            }
    }
}
/*排序_序号小到大*/
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
            printf("序号：%5d   名称：%8s   售价：%5.2f  数量：%6d\n", od[i].num, od[i].name, od[i].sell, od[i].amount);
        }

    }
    fclose(fp);
}
//排序_售价小到大
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
        printf("序号：%5d名称：%8s售价：%5.2f\n", od[i].num, od[i].name, od[i].sell);
    }
    fclose(fp);
}
//排序_售价大到小
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
        printf("序号：%5d名称：%8s售价：%5.2f\n", od[i].num, od[i].name, od[i].sell);
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
        printf("序号：%5d   名称：%6s   售价：%5.2f\n", od[i].num, od[i].name, od[i].sell);
    }
    fclose(fp);
}
//界面
void pr(void)
{
    printf(" \n\n                    \n\n");
	printf("******************************************************\n\n");
	printf("*                    商品管理系统                    *\n \n");
	printf("******************************************************\n\n");
	printf("*********************系统功能菜单*********************       \n");
	printf("    ---------------------   -----------------------   \n");
	printf("     *********************************************     \n");
	printf("     * 0.系统帮助及说明  * *  1.录入商品信息     *     \n");
	printf("     *********************************************     \n");
	printf("     * 2.修改商品信息    * *  3.删除商品信息     *     \n");
	printf("     *********************************************     \n");
	printf("     * 4.管理促销商品    * *  5.查询商品信息     *     \n");
	printf("     *********************************************     \n");
	printf("     * 6.统计商品信息    * *  7.退回上一级       *     \n");
	printf("     *********************************************     \n");
	printf("    ---------------------   -----------------------   \n");
	printf("******************************************************      \n");
	printf("请选择菜单编号:");
}
void back()
{
    int nu;
    printf("     *********************************************     \n");
    printf("     * 1.返回主菜单          2.退出程序          *     \n");//note
    printf("     *********************************************     \n");
    printf("请选择菜单编号：");
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2)
            break;
        else printf("输入格式错误！请输入1或2\n");
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
        else printf("请输入0~7\n");
    }
    switch (num)
	{
        case 0:help();back();break;
        case 1: printf("     *********************************************     \n");
                      printf("     * 1.请录入商品信息       2.进货             *     \n");//note
                      printf("     *********************************************     \n");
                        while(scanf("%d", &nu) != EOF)
                        {
                            if(nu == 1 || nu == 2)
                                break;
                            else printf("请输入1或2\n");
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
                      printf("     * 1.按序号排序   2.按售价升序排序   3.按售价降序排序 *     \n");//note
                      printf("     ******************************************************     \n");
                        while(scanf("%d", &nu) != EOF)
                        {
                            if(nu == 1 || nu == 2 ||nu == 3)//system("cls");
                                break;
                            else printf("请输入1~3\n");
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

void help()//帮助
{
	printf("\n1.欢迎使用系统帮助！\n");
	printf("\n2.按照菜单提示键入数字代号;\n");
	printf("\n3.如有疑惑敬请致电15294748920！\n");
	printf("\n4.谢谢您的使用！\n");
}

void del_1()
{
    FILE* fp, *fq;
    fp = fopen("sale.dat","rb");
    fq = fopen("sa.dat", "wb");
    char name[15];
    int t = 0;
    struct comm_buy comm;
    printf("请输入要删除商品的名称\n");
    scanf("%s", name);
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(strcmp(comm.name,name) != 0)
            fwrite(&comm,sizeof(struct comm_buy), 1, fq);
        else t = 1;
    }
    if(t == 0)
        printf("输入的商品不存在\n");
    else  printf("商品信息删除完成\n");
        fclose(fp);
        fclose(fq);
        remove("sale.dat");
        rename("sa.dat", "sale.dat");
}
/*返回_1*/
void back_1()
{
    int nu;
    printf("     *********************************************     \n");
    printf("     * 1.返回促销商品菜单       2.返回主菜单        *     \n");//note
    printf("     *********************************************     \n");
    printf("请选择菜单编号：");
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2)
            break;
        else printf("输入格式错误！请输入1或2\n");
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
	printf("     * 1.显示促销商品    * *  2.增加促销商品     *     \n");
	printf("     *********************************************     \n");
	printf("     * 3.修改促销商品    * *  4.删除促销商品     *     \n");
	printf("     *********************************************     \n");
	printf("     * 5.统计促销商品    * *  6.返回             *     \n");
	printf("     *********************************************     \n");
	printf("     请选择功能：");
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2 ||nu == 3|| nu == 4|| nu == 5|| nu == 6)
            break;
        else printf("请输入1~6\n");
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
/*促销商品*/
void cu()
{
    int nu;
    struct sale* w;
    printf("     *********************************************     \n");
	printf("     * 1.显示促销商品    * *  2.增加促销商品     *     \n");
	printf("     *********************************************     \n");
	printf("     * 3.修改促销商品    * *  4.删除促销商品     *     \n");
	printf("     *********************************************     \n");
	printf("     * 5.统计促销商品    * *  6.查询促销商品(名称)     \n");
	printf("     *********************************************     \n");
    printf("     * 7.价格区间查询    * *  8.返回             *     \n");
    printf("     *********************************************     \n");
	printf("     请选择功能：");
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2 ||nu == 3|| nu == 4|| nu == 5|| nu == 6||nu==7||nu==8)
            break;
        else printf("请输入1~6\n");
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
    printf("请输入查询促销商品的部分名称:\n");
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
                printf("查询商品序号、名称、价格、数量、上架时间为：\n");
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
    printf("请输入查询促销商品的价格区间:\n");
    double low,high;
    scanf("%lf %lf", &low, &high);
    int temp;
    while (fread(&od, sizeof(struct sale), 1, fp) != 0) 
    {
        if (od.sell>low && od.sell<high) {
            printf("商品的名称、序号、售价、数量、上架时间:%s、%d、%f、%d、%lld\n", od.name, od.num, od.sell, od.amount, od.time);
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
        printf("序号：%d   名称：%s   售价：%f\n", od[i].num, od[i].name, od[i].sell);
    }
    fclose(fp);
}
/*促销商品修改*/
void revise_1()//修改序号名称售价
{
    FILE* fp;
    int  t = 0;
    char name[20];
    struct sale comm;
    fp = fopen("sale.dat","rb+");
    printf("请输入您要修改的促销商品的名称\n");
    scanf("%s", name);
    while(fread(&comm,sizeof(struct sale),1,fp) != 0)
    {
        if(strcmp(comm.name,name) == 0)
            {
                t = 1;
                fseek(fp, 0-sizeof(struct sale), SEEK_CUR);
                printf("请输入促销商品新的序号、名称、售价\n");
                while(scanf("%d %s %lf", &comm.num, comm.name, &comm.sell) != EOF)
                    {
                        if(comm.num < 0 || comm.sell <= 0)
                        {
                            printf("输入格式不对请重新输入\n");
                        }
                        else
                        {
                            printf("修改成功！\n");
                            break;
                        }
                    }
                fwrite(&comm,sizeof(struct sale),1,fp);
                break;
            }
    }
    if(t == 0) printf("库中无此商品\n");
    fclose(fp);
}

double  price(char c[20])//返回预设售价
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
/*调取促销商品售价*/
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
/*促销商品查询*/

int comm_sale(char c[20])//判断是否是促销商品，是为1，否为0
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
/*查询商品是否存在*/
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
/*录入卖货信息*/
void  selled(void)//返回链表头指针
{
    FILE* fq,  *fp;
    struct Customer cust_t,tt;
    struct comm_sell comm;
    int star, sold_1, a,nn=0,hao, wzz = 0, oj,cse=0,cj;
    double b, sold, sell;
    char c[20];
    char cus[20];
    printf("请输入顾客会员号：");
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
        printf(" *会员号输入错误，请输入1后重新输入                   *\n" );
        printf(" ******************************************************\n");
        printf(" *若该顾客不为会员，请输入2后进行添加                 *\n");
        printf(" ******************************************************\n");
        printf(" *若该顾客没有创建加入会员意向，请输入3后进行操作     *\n");
        printf(" ******************************************************\n");
        while(1)
        {
            printf("请选择功能：\n");
            scanf("%d",&a);
            if((a==1||a==2)||a==3)break;
            else printf("输入错误，请重新选择功能\n");
        }
        if(a==1)selled();
        else if(a==2)add_s();
        else
        {
            star=0;
            cse++;
            strcpy(cus,"某某");
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
    printf("请输入商品名称和数量（以0 0结束输入）：");
    scanf("%s %d", c, &a);
    if(a == 0) break;
    wzz =  comm_qus(c);
    if(wzz == 0) {printf("商品不存在，请重新输入\n");continue;}
       cj = comm_qus_1(c);
        if(cj < a) {printf("所售数量大于库存数量！请检查输入\n");continue;}
    comm_qus_2(c, a);

    printf("请输入卖货时间（如20210308为2021年3月8日）\n");
    scanf("%d", &comm.time);
     sold_1 = comm_sale(c);//判断是否是促销商品，是为1，否为0
     sell = price(c);//预设售价
     sold = price_1(c);//促销售价
     switch(star)
     {
         case 0: if(sold_1) {b = a*sold;oj = sold;printf("顾客%s并非会员，所购商品为促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        else {b = a*sell;oj = sell;printf("顾客%s并非会员，所购商品非促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        break;
         case 1: if(sold_1) {b = a*sold*0.95;oj = sold;printf("顾客%s是一星级会员享受95折优惠，所购商品为促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        else {b = a*sell*0.95;oj = sell;printf("顾客%s是一星级会员享受95折优惠，所购商品非促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        break;
         case 2: if(sold_1) {oj = sold;b = a*sold*0.9;printf("顾客%s是二星级会员享受9折优惠，所购商品为促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.9;printf("顾客%s是二星级会员享受9折优惠，所购商品非促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        break;
         case 3: if(sold_1) {oj = sold;b = a*sold*0.85;printf("顾客%s是三星级会员享受85折优惠，所购商品为促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.85;printf("顾客%s是三星级会员享受85折优惠，所购商品非促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        break;
     }
     if(cse!=1)
     {
    fseek(fq,0-sizeof(cust_t),SEEK_CUR);
    cust_t.sale_amount=cust_t.sale_amount+(int)b;//本次消费金额;
    fwrite(&cust_t,sizeof(cust_t),1,fq);
    fclose(fq);
     }

     strcpy(comm.name, c);
     comm.amount = oj;
     comm.num = a;
    fp = fopen("sell.dat", "wb");
    fwrite(&comm,ui, 1, fp);
}
    printf("售货结束！\n");
    back_2();
}

 void back_2()
{
    printf("     *********************************************     \n");
	printf("     * 1.继续售货       * * 2.退出系统           *     \n");
	printf("     *********************************************     \n");
	printf("请选择菜单编号：");
	int nu;
    while(scanf("%d", &nu) != EOF)
    {
        if(nu == 1 || nu == 2)
            break;
        else printf("输入格式错误！请输入1或2\n");
    }
    switch(nu)
    {
        case 1: system("cls");bac_2();break;
        case 2:exit(0);
    }
 }
void  bac_2(void)//返回链表头指针
{
   FILE* fq,  *fp;
    struct Customer cust_t,tt;
    struct comm_sell comm;
    int star;
    double sold_1, a,nn=0,hao, wzz = 0, oj,cse=0,cj;
    double b, sold, sell;
    char c[20];
    char cus[20];
    printf("请输入顾客会员号：");
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
        printf(" *会员号输入错误，请输入1后重新输入                   *\n" );
        printf(" ******************************************************\n");
        printf(" *若该顾客不为会员，请输入2后进行添加                 *\n");
        printf(" ******************************************************\n");
        printf(" *若该顾客没有创建加入会员意向，请输入3后进行操作     *\n");
        printf(" ******************************************************\n");
        while(1)
        {
            printf("请选择功能：\n");
            scanf("%d",&a);
            if((a==1||a==2)||a==3)break;
            else printf("输入错误，请重新选择功能\n");
        }
        if(a==1)selled();
        else if(a==2)add_s();
        else
        {
            star=0;
            cse++;
            strcpy(cus,"某某");
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
    printf("请输入商品名称和数量（以0 0结束输入）：");
    scanf("%s %d", c, &a);
    if(a == 0) break;
    wzz =  comm_qus(c);
    if(wzz == 0) {printf("商品不存在，请重新输入\n");continue;}
       cj = comm_qus_1(c);
        if(cj < a) {printf("所售数量大于库存数量！请检查输入\n");continue;}
    comm_qus_2(c, a);
    printf("请输入卖货时间（如20210308为2021年3月8日）\n");
    scanf("%d", &comm.time);
     sold_1 = comm_sale(c);//判断是否是促销商品，是为1，否为0
     sell = price(c);//预设售价
     sold = price_1(c);//促销售价
     switch(star)
     {
         case 0: if(sold_1) {b = a*sold;oj = sold;printf("顾客%s并非会员，所购商品为促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        else {b = a*sell;oj = sell;printf("顾客%s并非会员，所购商品非促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        break;
         case 1: if(sold_1) {b = a*sold*0.95;oj = sold;printf("顾客%s是一星级会员享受95折优惠，所购商品为促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        else {b = a*sell*0.95;oj = sell;printf("顾客%s是一星级会员享受95折优惠，所购商品非促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        break;
         case 2: if(sold_1) {oj = sold;b = a*sold*0.9;printf("顾客%s是二星级会员享受9折优惠，所购商品为促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.9;printf("顾客%s是二星级会员享受9折优惠，所购商品非促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        break;
         case 3: if(sold_1) {oj = sold;b = a*sold*0.85;printf("顾客%s是三星级会员享受85折优惠，所购商品为促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.85;printf("顾客%s是三星级会员享受85折优惠，所购商品非促销商品，购买数量%3d，应付%5.2f。\n", cus, a, b);}
                        break;
     }
     if(cse!=1)
     {
    fseek(fq,0-sizeof(cust_t),SEEK_CUR);
    cust_t.sale_amount=cust_t.sale_amount+(int)b;//本次消费金额;
    fwrite(&cust_t,sizeof(cust_t),1,fq);
    fclose(fq);
     }

     comm.amount = oj;
    fp = fopen("sell.dat", "wb");
    fwrite(&comm,ui, 1, fp);
}
    printf("售货结束！\n");
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
        printf("系统错误！！！！");
    }
    printf("请输入你要查询的时间（形式为某年某月某天如20210101）：");
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
    printf("输入错误，或没有该商品\n");
    printf("******************************************************      \n");
    printf("*退出至主界面请输入1                                 *      \n");
    printf("******************************************************      \n");
    printf("*继续搜索请输入2                                     *      \n");
    printf("******************************************************      \n");
    printf("*退出系统请输入3                                     *      \n ");
    printf("******************************************************      \n");
    while(1)
    {
        printf("请选择要使用功能：");
        scanf("%d",&ss);
        if((ss==1||ss==2)||ss==3)break;
        else printf("输入错误，请按照规则重新输入\n");
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
    printf("*如果想查询该日已售商品排序请输入1                   *  \n");
    printf("******************************************************      \n");
    printf("*如果想查询该日销量最好的商品请输入2                 *    \n");
    printf("******************************************************      \n");
    printf("请选择要使用功能：");
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
    printf("该日已售商品排序列表如下：\n");
    printf("|  商品名称  |商品单价|商品数目|商品售出时间|\n");
    for(i=0;i<temp1;i++)
    {
        printf("|%12s|%8.2lf|%8d|%12d|\n",pp[i].name,pp[i].amount,pp[i].num,pp[i].time);
    }
    printf("******************************************************      \n");
    printf("*继续查找请输入1                                     *      \n");
    printf("******************************************************      \n");
    printf("*退回管理者主界面请输入2                             *      \n");
    printf("******************************************************      \n");
    printf("*退出系统请输入3                                     *      \n");
    printf("******************************************************      \n");

    while(1)
    {
        printf("请选择要使用功能：");
        scanf("%d",&ss);
        if(ss==1||ss==2||ss==3)break;
        else printf("输入错误，请按照规则重新输入\n");
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
    printf("该日销量最好商品如下：\n");
    printf("|  商品名称  |商品单价|商品数目|商品售出时间|\n");
    printf("|%12s|%8.2lf|%8d|%12d|\n",pp[temp1-1].name,pp[temp1-1].amount,pp[temp1-1].num,pp[temp1-1].time);

    printf("******************************************************      \n");
    printf("*继续查找请输入1                                     *      \n");
    printf("******************************************************      \n");
    printf("*退回管理者主界面请输入2                             *      \n");
    printf("******************************************************      \n");
    printf("*退出系统请输入3                                     *      \n");
    printf("******************************************************      \n");
    while(1)
    {
        printf("请选择要使用功能：");
        scanf("%d",&ss);
        if((ss==1||ss==2)||ss==3)break;
        else printf("输入错误，请按照规则重新输入\n");
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
    printf("请输入要添加的顾客信息（请按照顾客编号，姓名,销售额（在创建时指定为0）进行输入，编号如1001，1002）：");
    scanf("%d%s%ld",&cust.number,cust.name,&cust.sale_amount);//录入顾客信息
    if((fp=fopen("customer_information.dat","ab"))==NULL)//打开磁盘文件
    {
        printf("系统出错!!!!!!!!!\n");
        exit(0);//结束函数
    }
    fwrite(&cust,sizeof(cust),1,fp);//向文件中读入数据
    fclose(fp);
    printf("添加成功,继续进行销售\n");
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
