#pragma once
#ifndef JM_H_INCLUDED
#define JM_H_INCLUDED
#define lon sizeof(struct sale)
#define LEN sizeof(struct comm_buy)
#define Ui sizeof(struct comm_sell)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS


struct Account//
{
    long int ID_s;//����Ա�˺�
    long int password_s;//����Ա����
    long int ID_g;//����Ա�˺�
    long int password_g;//����Ա����
};
struct Customer//�˿���Ϣ��һ��95�ۣ�����9�ۣ�����85��
{
    int number;//�˿ͱ��
    wchar_t name[20];//�˿�����
    //�˿͵ȼ������Ǽ���Ϊ0��һ�Ǽ�Ϊ1�����Ǽ�Ϊ2�����Ǽ�Ϊ3,������Ա����ʱ����ù˿�Ϊʲô�Ǽ��Ĺ˿�
    int sale_amount;//�˿����۶0-99Ϊ0�ǣ�100-999Ϊ1��,1000-1999Ϊ���ǣ�����2000Ϊ����
};
struct Customer_list//�˿������ڶԹ˿���Ϣ�����Ѷ��������֮���ٽ����ݴ�������ʵ��������
{
   struct Customer god;//�������ļ����ϴ��Ĺ��̽ṹ��
   struct Customer_list *next;
};
struct messages_buy//�ṹ��-��Ʒ�����۸�������ʱ�䣩
{
    int num;
    wchar_t name[15];
    double price;
    int amount;
    int time;
    struct messages_buy* next;
};
struct comm_buy//�ṹ��-��Ʒ
{
    int num;//���
    wchar_t name[15];//����
    double sell;//�����۸�
    int amount;//����
    long long time;//����ʱ��
    struct comm_buy*p;
};
struct sale//�ṹ��-����
{
    int num;//���
    wchar_t name[15];//����
    double sell;//�۸�
    int amount;//����
    long long time;
    struct sale* next;
};
struct comm_sell//�����ṹ��
{
    wchar_t name[20];
    int num;
    int time;
    double amount;//ʵ���ۼ�
};

struct Account* read_account(void);
void interface1(void);
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
void cu();
double price(wchar_t c[20]);
double price_1(wchar_t c[20]);
int comm_sale(wchar_t c[20]);
void  selled(void);
void search_selled();
void show_rank(struct comm_sell pp[],int temp1);
void show_best(struct comm_sell pp[],int temp1);
void add_s();
int  comm_qus_1(wchar_t c[20]);
void comm_qus_2(wchar_t str[20], int k);
void search_sale_name();
void search_sale_sell();
void search_customer_mohu();
void UI_denglu();
int click_denglu();
int click_user();
int click_change_account();
int click_showorchange_customer();
int click_goods_message();
void Ui_cu();
int click_cu();
#endif // JM_H_INCLUDED


