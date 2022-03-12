#pragma once
#ifndef JM_H_INCLUDED
#define JM_H_INCLUDED
#define lon sizeof(struct sale)
#define LEN sizeof(struct comm_buy)
#define ui sizeof(struct comm_sell)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct FILF
{
    short level;
    unsigned flags;
    char fd;
    unsigned char hold;
    short bsize;
    unsigned char *buffer;
    unsigned char *curp;
    unsigned istemp;
    short token;
};
struct Account//
{
    long int ID_s;//收银员账号
    long int password_s;//收银员密码
    long int ID_g;//管理员账号
    long int password_g;//管理员密码
};
struct Customer//顾客信息，一星95折，二星9折，三星85折
{
    int number;//顾客编号
    char name[20];//顾客姓名
    //顾客等级，无星级记为0，一星记为1，二星记为2，三星记为3,在收银员结账时计算该顾客为什么星级的顾客
    long sale_amount;//顾客销售额，0-99为0星，100-999为1星,1000-1999为两星，高于2000为三星
};
struct Customer_list//顾客链表，在对顾客信息按消费额进行排序之后再将数据传入链表实现排序功能
{
   struct Customer god;//数据向文件中上传的过程结构体
   struct Customer_list *next;
};
struct messages_buy//结构体-商品进货价格、数量（时间）
{
    int num;
    char name[15];
    int price;
    int amount;
    int time;
    struct messages_buy* next;
};
struct comm_buy//结构体-商品
{
    int num;//编号
    char name[15];//名称
    double sell;//售卖价格
    int amount;//数量
    long long time;//进货时间
    struct comm_buy*p;
};
struct sale//结构体-促销
{
    int num;//编号
    char name[15];//名称
    double sell;//价格
    int amount;//数量
    long long time;
    struct sale* next;
};
struct comm_sell//卖货结构体
{
    char name[20];
    int num;
    int time;
    double amount;//实际售价
};

struct Account* read_account(void);
void interface2(void);
void set_account(void);
void log_in_s(int x);
void log_in_g(int x);
void user(void);
void change_account(void);
void showorchange_customer(void);
void search_customer_message(void);
void save_Customer(void);
void add_customer(void);
void revise1(void);
void del1(void);
void show_customer(void);
struct Customer_list *look_customer();
void goods_message();
struct sale* sp();
void sale(struct sale* m);
struct messages_buy* buy(void);
void sav(struct messages_buy* m);
struct comm_buy* creat(void);
void save(struct comm_buy* m);
void revise();
void del();
void google();
void order_num();
void order_sell1();
void order_sell2();
void test();
void pr(void);
void back();
void bac();
void help();
void order_num1();
void revise_1();
void del_1();
void back_1();
void bac_1();
void back_2();
void bac_2();
void cu();
double price(char c[20]);
double price_1(char c[20]);
int comm_sale(char c[20]);
void  selled(void);
void search_selled();
void show_rank(struct comm_sell pp[],int temp1);
void show_best(struct comm_sell pp[],int temp1);
void add_s();
int  comm_qus_1(char c[20]);
void comm_qus_2(char str[20], int k);
void search_sale_name();
void search_sale_sell();
void search_customer_mohu();
#endif // JM_H_INCLUDED


