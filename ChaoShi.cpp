#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"ChaoShi.h"
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<cwchar>

void UI_denglu() {
    initgraph(640,480, EW_DBLCLKS | EW_SHOWCONSOLE);
    setbkcolor(WHITE);
    cleardevice();
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    settextcolor(RGB(21, 64, 234));
    setlinecolor(BLACK);
    fillrectangle(0,219,101,261);
    RECT r1 = { 1,220, 100,260 };
    drawtext(_T("���γ�ʼ�˻�"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    fillrectangle(538, 130, 640, 171);
    RECT r2 = { 539,131, 639,170 };
    drawtext(_T("��¼�����˻�"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    fillrectangle(538, 310, 640, 351);
    RECT r3 = { 539,311, 639, 350 };
    drawtext(_T("�˳�"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
int click_denglu() {
    ExMessage m;
    getmessage(&m,EM_MOUSE);
    switch (m.message) {
    case WM_LBUTTONDOWN:
        if (220 < m.y && m.y < 260 && 1 < m.x && m.x < 100) {
            return 1;
        }
        else if (131 < m.y && m.y < 170 && 539 < m.x && m.x < 640) {
            return 2;
        }
        else if (311 < m.y && m.y < 350 && 539 < m.x && m.x < 640) {
            return 3;
        }
        else { return 4; }
        break;
    default:
        return 0;
    }
    return 8;
}
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
    FILE *fp;
    if((fp=fopen("account.dat","wb+"))==NULL)//�򿪴����ļ�
    {
        //printf("ϵͳ����!!!!!!!!!\n");
        RECT r = { 140,160,400,320 };
        drawtext(_T("ϵͳ����!!!!!!!!!"),&r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        exit(0);//��������
    }
    //printf("�������ʼ�����˺�����\n");
    fillrectangle(200, 139, 441, 341);
    RECT r1 = { 201,140,440,340 };
    drawtext(_T("�������ʼ���˺�����"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //printf("��ʼ������Ա�˺ţ�");
    wchar_t s[10];
    InputBox(s, 10, L"��ʼ������Ա�˺�");
    //scanf("%ld",&account_neu.ID_s);
    account_neu.ID_s = _wtoi(s);
    //printf("��ʼ������Ա���룺");
    InputBox(s, 10, L"��ʼ������Ա����");
    //scanf("%ld",&account_neu.password_s);
    account_neu.password_s = _wtoi(s);
    InputBox(s, 10, L"��ʼ������Ա�˺�");
    account_neu.ID_g = _wtoi(s);
    InputBox(s, 10, L"��ʼ������Ա����");
    account_neu.password_g = _wtoi(s);
    //printf("��ʼ������Ա�˺ţ�");
    //scanf("%ld",&account_neu.ID_g);
    //printf("��ʼ������Ա���룺");
    //scanf("%ld",&account_neu.password_g);
    //printf("%ld %ld %ld %ld\n",account_neu.ID_s,account_neu.password_s,account_neu.ID_g,account_neu.password_g);
    fwrite(&account_neu,sizeof(account_neu),1,fp);//���˺���������ļ�
    rewind(fp);
    //fread(&account_cse,sizeof(account_cse),1,fp);
    //printf("%ld %ld %ld %ld\n",account_cse.ID_s,account_cse.password_s,account_cse.ID_g,account_cse.password_g);

    //printf("�˺������������");
    //printf("�ٴ������˺������¼\n");
    clearrectangle(101,61,538,419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    fillrectangle(200, 79, 441, 221);
    fillrectangle(200, 259, 441, 401);
    r1 = { 201,80,440,220};
    RECT r2 = { 201,260,440,400};
    drawtext(_T("�˺������������"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("�ٴ������˺������¼"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //printf("����ǹ�����������1�����������Ա������2��\n");
    InputBox(s, 10, L"����ǹ�����������1�����������Ա������2");
    a = _wtoi(s);
    clearrectangle(101, 61, 538, 419);
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
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    //printf("�������Ա������������˺ţ�����\n");
    fillrectangle(200, 80, 441, 182);
    RECT r1 = { 201,81,440,181 };
    drawtext(_T("�������Ա������������˺ţ�����"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //printf("�˺ţ�");
    wchar_t s[10];
    InputBox(s, 10, L"�˺�");
    ID = _wtoi(s);
    //scanf("%ld",&ID);
    //printf("���룺");
    //scanf("%ld",&password);
     InputBox(s, 10, L"����");
     password = _wtoi(s);
     printf("\n");
    if((ID==account_t.ID_s)&&(password==account_t.password_s))
    {

        system("cls");
        //printf("��¼�ɹ�\n��ӭ�������õ�����ʱ��\n");
        clearrectangle(0, 61, 640, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        //printf("�������Ա������������˺ţ�����\n");
        drawtext(_T("��¼�ɹ�,��ӭ�������õ�����ʱ��"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        selled();
    }
    else
    {
        //printf("�˺��������ϵͳ�Զ��˳�\n");
        clearrectangle(0, 61, 640, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        drawtext(_T("�˺��������ϵͳ�Զ��˳�"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        exit(0);

    }
    }
}
struct Account* read_account(void)//�����˺�����
{
    FILE *fp;
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
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    //printf("�������Ա������������˺ţ�����\n");
    fillrectangle(200, 80, 441, 180);
    RECT r1 = { 201,81,440,181 };
    drawtext(_T("��ù���Ա������������˺ţ�����"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //printf("�˺ţ�");
    wchar_t s[10];
    InputBox(s, 10, L"�˺�");
    ID = _wtoi(s);
    //scanf("%ld",&ID);
    printf("\n");
    //printf("���룺");
    //scanf("%ld",&password);
    InputBox(s, 10, L"����");
    password = _wtoi(s);
     printf("\n");
     //printf("%ld %ld %ld %ld\n",account1->ID_s,account1->password_s,account1->ID_g,account1->password_g);
    if((ID==account_t.ID_g)&&(password==account_t.password_g))
    {
        clearrectangle(0, 61, 640, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        drawtext(_T("��½�ɹ�"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        user();
    }
    else {
        clearrectangle(0, 61, 640, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        drawtext(_T("�˺��������ϵͳ�Զ��˳�"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        }
    exit(0);
    //user();
    }
    system("cls");
}
void user(void)
{
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    int choice;
    /*printf(" \n\n                    \n\n");
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
    */
    fillrectangle(0, 130, 101, 171);
    fillrectangle(0, 310, 101, 351);
    fillrectangle(538, 126, 640, 168);
    fillrectangle(538, 233, 640, 274);
    fillrectangle(538, 340, 640, 382);
    RECT r1 = { 1,131, 100,170 };
    drawtext(_T("�˳�ϵͳ"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r2 = { 1,311, 100,350 };
    drawtext(_T("�޸��˻�"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r3 = { 539,127, 639,167 };
    drawtext(_T("�˿͹���"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r4 = { 539,234, 639,274 };
    drawtext(_T("��Ʒ����"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r5 = { 539,341, 639,381 };
    drawtext(_T("������Ʒ����"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    while(1)
    {
        choice = click_user();
        if(choice==0||choice==1||choice==2||choice==3||choice==4)break;
    }
    switch(choice)
    {
    case 1:
        change_account();
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
        return ;
        break;
    default:
        printf("��������û�иù���\n");
        break;
    }
    //system("cls");
}
int click_user() {
    ExMessage m;
    getmessage(&m, EM_MOUSE);
    switch (m.message) {
    case WM_LBUTTONDOWN:
        if (131 < m.y && m.y < 171 && 1 < m.x && m.x < 100) {
            return 0;
        }
        else if (311 < m.y && m.y < 350 && 1 < m.x && m.x < 100) {
            return 1;
        }
        else if (127 < m.y && m.y < 167 && 539 < m.x && m.x < 640) {
            return 2;
        }
        else if (234 < m.y && m.y < 274 && 539 < m.x && m.x < 640) {
            return 3;
        }
        else if (341 < m.y && m.y < 380 && 539 < m.x && m.x < 640) {
            return 4;
        }
        else { return 5; }
        break;
    default:
        return 5;
    }
    return 8;
}
int click_change_account() {
    ExMessage m;
    getmessage(&m, EM_MOUSE);
    switch (m.message) {
    case WM_LBUTTONDOWN:
        if (221 < m.y && m.y < 260 && 1 < m.x && m.x < 100) {
            return 1;
        }
        else if (221 < m.y && m.y < 260 && 539 < m.x && m.x < 640) {
            return 2;
        }
        else { return 5; }
        break;
    default:
        return 5;
    }
    return 8;
}
void change_account(void)
{
    FILE *fp;

    struct Account account_neucse;
    RECT r1 = { 201,81,440,181 };
    if((fp=fopen("account.dat","ab"))==NULL)//�򿪴����ļ�
    {
        clearrectangle(0, 61, 640, 419);
        drawtext(_T("ϵͳ����"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        exit(0);
    }
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    fillrectangle(200, 80, 441, 182);
    drawtext(_T("�������޸ĺ���˺�����"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    wchar_t s[10];
    InputBox(s, 10, L"����Ա�˺�");
    //scanf("%ld",&account_neucse.ID_s);
    account_neucse.ID_s = _wtoi(s);
    //printf("�޸ĺ�����Ա���룺");
    InputBox(s, 10, L"����Ա����");
    account_neucse.password_s = _wtoi(s);
    //scanf("%ld",&account_neucse.password_s);
    InputBox(s, 10, L"����Ա�˺�");
    account_neucse.ID_g = _wtoi(s);
    InputBox(s, 10, L"����Ա����");
    account_neucse.password_g = _wtoi(s);
    fwrite(&account_neucse,sizeof(account_neucse),1,fp);//���˺���������ļ�
    clearrectangle(0, 61, 640, 419);
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    fillrectangle(200, 80, 441, 182);
    drawtext(_T("�޸����"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    int a;
    RECT r2 = {1,221,100,260};
    fillrectangle(0, 220, 101, 261);
    drawtext(_T("���ع���Աϵͳ"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r3 = { 539,221,639,260 };
    fillrectangle(538, 220, 640, 261);
    drawtext(_T("�˳�"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    while (1) { 
        a = click_change_account();
        if (a == 1 || a == 2) {
            break;
        }
    }
    if(a==1)user();
    else if(a==2) exit(0);
}
int click_showorchange_customer() {
    ExMessage m;
    getmessage(&m, EM_MOUSE);
    switch (m.message) {
    case WM_LBUTTONDOWN:
        if (85 < m.y && m.y < 125 && 539 < m.x && m.x < 639) {
            return 0;
        }
        else if (92 < m.y && m.y < 132 && 1 < m.x && m.x < 640) {
            return 1;
        }
        else if (165 < m.y && m.y < 205 && 1 < m.x && m.x < 100) {
            return 2;
        }
        else if (238 < m.y && m.y < 278 && 1 < m.x && m.x < 100) {
            return 3;
        }
        else if (311 < m.y && m.y < 351 && 1 < m.x && m.x < 100) {
            return 4;
        }
        else if (150 < m.y && m.y < 190 && 539 < m.x && m.x < 640) {
            return 5;
        }
        else if (215 < m.y && m.y < 255 && 539 < m.x && m.x < 640) {
            return 6;
        }
        else if (280 < m.y && m.y < 320 && 539 < m.x && m.x < 640) {
            return 7;
        }
        else if (345 < m.y && m.y < 385 && 539 < m.x && m.x < 640) {
            return 8;
        }
        else { return 9; }
        break;
    default:
        return 9;
    }
    return 9;
}
void showorchange_customer(void)
{
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    int a;
    fillrectangle(0,91,101,133);
    RECT r1 = { 1,92,100,132 };
    fillrectangle(0,164, 101,206);
    RECT r2 = { 1,165,100,205 };
    fillrectangle(0,237, 101,279);
    RECT r3 = { 1,238,100,278 };
    fillrectangle(0,310, 101, 352);
    RECT r4 = { 1,311,100,351 };
    fillrectangle(538, 84, 640, 126);
    RECT r0 = { 539,85,639,125 };
    fillrectangle(538,149, 640, 191);
    RECT r5 = { 539,150,639,190 };
    fillrectangle(538, 214, 640, 256);
    RECT r6 = { 539,215,639,255 };
    fillrectangle(538, 279, 640, 321);
    RECT r7 = { 539,280,639,320 };
    fillrectangle(538, 344, 640, 386);
    RECT r8 = { 539,345,639,385 };
    drawtext(_T("�����ϼ�"), &r0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("�����ĵ�"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("¼��˿�"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("��ӹ˿�"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("�޸Ĺ˿�"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("ɾ���˿�"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("��ʾ�˿�"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("��ѯ�˿�"), &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("ģ����ѯ"), &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//��ѯ�˿���Ϣ������
    while (1) {
        a = click_showorchange_customer();
        if (a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8) {
            break;
        }
    }
    switch(a)
    {
    case 1:
        {
            int ss;
            clearrectangle(0, 61, 640, 419);
            loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
            putimage(0, 0, &background);
            setbkmode(TRANSPARENT);
            RECT r1 = { 201,101,440,161 };
            drawtext(_T("1.�밴����ʾʹ�øù���"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            RECT r2 = { 201,181,440,241 };
            drawtext(_T("2.���������벦����ѯ����15294748920"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            RECT r3 = { 201,261,440,321 };
            drawtext(_T("3.лл���Ը�ϵͳ��֧��"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            RECT r4 = { 201,341,440,401 };
            drawtext(_T("���������һ��������1,���ֱ���˳�ϵͳ������2"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            wchar_t s[10];
            InputBox(s, 10);
            ss = _wtoi(s);
            if (ss == 1) {
                clearrectangle(0, 61, 640, 419);
                loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
                putimage(0, 0, &background);
                setbkmode(TRANSPARENT);
                showorchange_customer();
            }
            else if (ss == 2) {
                clearrectangle(0, 61, 640, 419);
                loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
                putimage(0, 0, &background);
                setbkmode(TRANSPARENT);
                exit(0);
            }
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
        int ss;
        wchar_t sss[15];
        InputBox(sss,10,L"��������ʹ�ñ�ϵͳ������1");
        ss = _wtoi(sss);
        if(ss==1)showorchange_customer();
        //user();
        break;
    }
    //system("cls");
}
void search_customer_message(void)
{
    struct Customer_list *head_cust,*p;
    int i,temp,num_cust,a,grade,ss,nn=0;//tempΪҪ�����˿���Ŀ��num_custΪҪ�����Ĺ˿ͱ��
    wchar_t name_cust[15];//Ҫ�����˿�����
    head_cust=look_customer();
    p=NULL;
    //printf("��ѡ��������ʽ�������������򰴹˿ͱ������");
    //printf("����������������1�����˿ͱ������������2):");
    wchar_t s[15];
    wchar_t num[15];
    wchar_t grades[15];
    wchar_t salemount[15];
    int axisy=80;
    int axisx = 140;
    InputBox(s, 10, L"����������������1�����˿ͱ������������2");
    a = _wtoi(s);
    //scanf("%d",&a);
    //printf("������Ҫ����������");
    InputBox(s, 10, L"������Ҫ��������");
    temp = _wtoi(s);
    if(a==1)
    {
        for(i=0;i<temp;i++)
        {
            InputBox(name_cust, 10, L"�����������˿�����");
            if(head_cust!=NULL)
           {
            p=head_cust;
            clearrectangle(0, 61, 640, 419);
            do
            {
            if(wcscmp(name_cust,p->god.name)== 0)
            {
                nn++;
                outtextxy(axisx,axisy,_T("|�˿����|�˿�����|�˿͵ȼ�|���׶�"));
                axisy += 25;
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
                wsprintf(num,_T("%d"),p->god.number);
                wsprintf(grades, _T("%d"), grade);
                wsprintf(salemount, _T("%d"), p->god.sale_amount);
                outtextxy(axisx, axisy, num);
                axisx += 30;
                outtextxy(axisx, axisy, p->god.name);
                axisx += 100;
                outtextxy(axisx, axisy, grades);
                axisx += 30;
                outtextxy(axisx, axisy, salemount);
                axisx += 50;
                axisy += 25;
                axisx = 140;
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
            InputBox(name_cust, 10, L"�����������˿�����");
            num_cust = _wtoi(name_cust);
            if(head_cust!=NULL)
           {
            p=head_cust;
            clearrectangle(0, 61, 640, 419);
            IMAGE background;
            loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
            putimage(0, 0, &background);
            setbkmode(TRANSPARENT);
            do
            {
            if(p->god.number==num_cust)
            {
                nn++;
                outtextxy(axisx, axisy, _T("|�˿����|�˿�����|�˿͵ȼ�|���׶�"));
                axisy += 25;
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
                wsprintf(num, _T("%d"), p->god.number);
                wsprintf(grades, _T("%d"), grade);
                wsprintf(salemount, _T("%d"), p->god.sale_amount);
                outtextxy(axisx, axisy, num);
                axisx += 15;
                outtextxy(axisx, axisy, p->god.name);
                axisx += 15;
                outtextxy(axisx, axisy, grades);
                axisx += 15;
                outtextxy(axisx, axisy, salemount);
                axisx += 15;
                axisy += 25;
            }
                p=p->next;
            }
            while(p!=NULL);
           }
        }
    }
    if (nn == 0) {
        clearrectangle(0, 61, 640, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        RECT r1 = { 140,160,400,320 };
        drawtext(_T("δ��ѯ���û�!!!"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    InputBox(s, 10,L"���������һ��������1,���ֱ���˳�ϵͳ������2");
    ss = _wtoi(s);
    if(ss==1)showorchange_customer();
    else if(ss==2)exit(0);
}
void search_customer_mohu() {
    struct Customer_list* head_cust, * p;
    int i, temp, a, grade,tmp, ss, nn = 0;//tempΪҪ�����˿���Ŀ��num_custΪҪ�����Ĺ˿ͱ��
    wchar_t name_cust[20];//Ҫ�����˿�����
    wchar_t shortname[20];
    wchar_t s[15];
    wchar_t num[15];
    wchar_t grades[15];
    wchar_t salemount[15];
    int axisy = 80;
    int axisx = 140;
    head_cust = look_customer();
    InputBox(s, 10, L"������Ҫ����������");
    temp = _wtoi(s);
    for (i = 0; i < temp; i++)
    {
        InputBox(name_cust, 10, L"������Ҫ�����Ĳ�������");
        int n = wcslen(name_cust);
        if (head_cust != NULL)
        {
            p = head_cust;
            int m = wcslen(p->god.name);
            for (int item = 0; item <= m - n;item+=2) {
                tmp = 0;
                for (int t = item; t < item + n; t++) {
                    shortname[tmp] = p->god.name[t];
                    tmp += 1;
                }
                shortname[tmp] = '\0';
                if (wcscmp(name_cust, shortname) == 0)
                {
                    outtextxy(axisx, axisy, _T("|�˿����|�˿�����|�˿͵ȼ�|���׶�"));
                    axisy += 40;
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
                    wsprintf(num, _T("%d"), p->god.number);
                    wsprintf(grades, _T("%d"), grade);
                    wsprintf(salemount, _T("%d"), p->god.sale_amount);
                    outtextxy(axisx, axisy, num);
                    axisx += 30;
                    outtextxy(axisx, axisy, p->god.name);
                    axisx += 100;
                    outtextxy(axisx, axisy, grades);
                    axisx += 30;
                    outtextxy(axisx, axisy, salemount);
                    axisx += 50;
                    axisy += 40;
                    axisx = 140;
                    break;
                }
            }
            p = p->next;
        }
    }
    InputBox(s, 10, L"���������һ��������1,���ֱ���˳�ϵͳ������2");
    ss = _wtoi(s);
    if (ss == 1)showorchange_customer();
    else if (ss == 2) exit(0);
}
void save_Customer(void)//�û���һ�ν�������¼��
{
      //�ó���Ϊ��һ��¼��˿���Ϣʱ��ʹ�õĺ���
    FILE *fp;//�����ļ�ָ��
    struct Customer cust[100];//�����˿���Ϣ�ṹ�����飬����Ϣ�����ļ�֮���ڶ����������������
    //Customer cust1[5];
    int i,num_cust,ss;//����Ϊ�˿���Ŀ
    wchar_t name_cust[20];
    wchar_t s[15];
    wchar_t num[15];
    wchar_t salemount[15];
    InputBox(s, 10, L"������Ҫ¼�������");
    num_cust = _wtoi(s);
    for(i=0;i<num_cust;i++)//����ѭ��
    {
        InputBox(cust[i].name, 10, L"������˿�����");
        InputBox(num, 10, L"������˿͵ı��");
        InputBox(salemount, 10, L"������˿͵Ľ��׶�");
        cust[i].number = _wtoi(num);
        cust[i].sale_amount = _wtoi(salemount);
    }

    //����Ϣ�����ļ�
    if((fp=fopen("customer_information.dat","ab"))==NULL)//�򿪴����ļ�
    {
        clearrectangle(101, 61, 538, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        RECT r = { 140,160,400,320 };
        drawtext(_T("ϵͳ����!!!!!!!!!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        exit(0);
    }
    for(i=0;i<num_cust;i++)
    {
        fwrite(&cust[i],sizeof(cust[i]),1,fp);//���ļ��ж�������
    }
    memset(cust,0,sizeof(cust));//��cust�����е�������գ��ٴ�����
    fclose(fp);
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r = { 140,160,400,320 };
    drawtext(_T("¼��ɹ�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(s, 10, L"���������һ��������1,���ֱ���˳�ϵͳ������2");
    ss = _wtoi(s);
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void add_customer()//���ļ����������
{
    FILE *fp;
    struct Customer cust[50];
    int i,num_cust,ss;
    wchar_t name_cust[20];
    wchar_t s[15];
    wchar_t num[15];
    wchar_t salemount[15];
    InputBox(s, 10, L"������Ҫ¼�������");
    num_cust = _wtoi(s);
    for(i=0;i<num_cust;i++)//����ѭ��
    {
        InputBox(cust[i].name, 10, L"������˿�����");
        InputBox(num, 10, L"������˿͵ı��");
        InputBox(salemount, 10, L"������˿͵Ľ��׶�");
        cust[i].number = _wtoi(num);
        cust[i].sale_amount = _wtoi(salemount);
    }
        if((fp=fopen("customer_information.dat","ab"))==NULL)//�򿪴����ļ�
    {
            clearrectangle(101, 61, 538, 419);
            IMAGE background;
            loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
            putimage(0, 0, &background);
            setbkmode(TRANSPARENT);
            RECT r = { 140,160,400,320 };
            drawtext(_T("ϵͳ����!!!!!!!!!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            exit(0);
    }
    for(i=0;i<num_cust;i++)
    {
        fwrite(&cust[i],sizeof(cust[i]),1,fp);//���ļ��ж�������
    }
    memset(cust,0,sizeof(cust));//��cust�����е�������գ��ٴ�����
    fclose(fp);
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r = { 140,160,400,320 };
    drawtext(_T("¼��ɹ�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(s, 10, L"���������һ��������1,���ֱ���˳�ϵͳ������2");
    ss = _wtoi(s);
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
    wchar_t name_cust[20];
    wchar_t s[15];
    wchar_t num[15];
    wchar_t salemount[15];
    InputBox(s, 10, L"������Ҫ�޸Ĺ˿͵ı��");
    num_cha = _wtoi(s);
    //printf("11111");
    while(fread(&cust_t,sizeof(cust_t),1,fp) != 0)
    {
        //printf("11111");
        if(cust_t.number==num_cha){
            fseek(fp,0-sizeof(cust_t),SEEK_CUR);
            InputBox(cust_t.name, 10, L"������˿�����");
            InputBox(num, 10, L"������˿͵ı��");
            InputBox(salemount, 10, L"������˿͵Ľ��׶�");
            cust_t.number = _wtoi(num);
            cust_t.sale_amount = _wtoi(salemount);
            fwrite(&cust_t,sizeof(cust_t),1,fp);
            break;
        }
    }
    fclose(fp);
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r = { 140,160,400,320 };
    drawtext(_T("¼��ɹ�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(s, 10, L"���������һ��������1,���ֱ���˳�ϵͳ������2");
    ss = _wtoi(s);
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void del1(void)//ɾ���û�����
{
    FILE *fp,*fq;
    int ss;
    fp = fopen("customer_information.dat","rb");
    fq = fopen("data.dat", "wb");
    wchar_t name[20];
    wchar_t s[15];
    struct Customer cust_t;
    InputBox(name, 10, L"������Ҫɾ���Ĺ˿�����");
    while(fread(&cust_t,sizeof(cust_t),1,fp) != 0)
    {
        if(wcscmp(cust_t.name,name) != 0){
            fwrite(&cust_t, sizeof(cust_t), 1, fq);
        }
    }
    fclose(fp);
    fclose(fq);
    remove("customer_information.dat");
    rename("data.dat", "customer_information.dat");
    clearrectangle(101, 61, 538, 419);
    RECT r = { 140,160,400,320 };
    drawtext(_T("¼��ɹ�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(s, 10, L"���������һ��������1,���ֱ���˳�ϵͳ������2");
    ss = _wtoi(s);
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
    wchar_t num[15];
    wchar_t s[15];
    wchar_t grades[15];
    wchar_t salemount[15];
    int axisy = 80;
    int axisx = 140;
    p=NULL;
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    if(look!=NULL)
    {
        p=look;
        outtextxy(axisx, axisy, _T("|�˿����|�˿�����|�˿͵ȼ�|���׶�"));
        axisy += 25;
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
            wsprintf(num, _T("%d"), p->god.number);
            wsprintf(grades, _T("%d"), grade);
            wsprintf(salemount, _T("%d"), p->god.sale_amount);
            outtextxy(axisx, axisy, num);
            axisx += 30;
            outtextxy(axisx, axisy, p->god.name);
            axisx += 100;
            outtextxy(axisx, axisy, grades);
            axisx += 30;
            outtextxy(axisx, axisy, salemount);
            axisx += 50;
            axisy += 40;
            axisx = 140;
            p=p->next;
        }while(p!=NULL);
    }
    InputBox(s, 10, L"���������һ��������1,���ֱ���˳�ϵͳ������2");
    ss = _wtoi(s);
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
struct Customer_list *look_customer()//�鿴�û���Ϣ�����û���Ϣ�������������ͷ
{
    FILE *fp;//�����ļ�ָ��
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
int click_goods_message() {
    ExMessage m;
    getmessage(&m, EM_MOUSE);
    switch (m.message) {
    case WM_LBUTTONDOWN:
        if (92 < m.y && m.y < 132 && 1 < m.x && m.x < 100) {
            return 0;
        }
        else if (165 < m.y && m.y < 205 && 1 < m.x && m.x < 100) {
            return 1;
        }
        else if (238 < m.y && m.y < 278 && 1 < m.x && m.x < 100) {
            return 2;
        }
        else if (311< m.y && m.y < 351 && 1 < m.x && m.x < 100) {
            return 3;
        }
        else if (92 < m.y && m.y < 132 && 539 < m.x && m.x < 639) {
            return 4;
        }
        else if (165 < m.y && m.y < 205 && 539 < m.x && m.x < 639) {
            return 5;
        }
        else if (238 < m.y && m.y < 278 && 539 < m.x && m.x < 639) {
            return 6;
        }
        else if (311 < m.y && m.y < 351 && 539 < m.x && m.x < 639) {
            return 7;
        }
        else { return 8; }
        break;
    default:
        return 8;
    }
    return 8;
}
void pr(void)
{
    /*printf(" \n\n                    \n\n");
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
    printf("��ѡ��˵����:");*/
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    fillrectangle(0, 91, 101, 133);
    RECT r1 = { 1,92,100,132 };
    fillrectangle(0, 164, 101, 206);
    RECT r2 = { 1,165,100,205 };
    fillrectangle(0, 237, 101, 279);
    RECT r3 = { 1,238,100,278 };
    fillrectangle(0, 310, 101, 352);
    RECT r4 = { 1,311,100,351 };
    fillrectangle(538, 91, 640, 133);
    RECT r5 = { 539,92,639,132 };
    fillrectangle(538, 164, 640, 206);
    RECT r6 = { 539,165,639,205 };
    fillrectangle(538, 237, 640, 279);
    RECT r7 = { 539,238,639,278 };
    fillrectangle(538, 310, 640, 352);
    RECT r8 = { 539,311,639,351 };
    drawtext(_T("�����ĵ�"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("����¼����Ʒ"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("�޸���Ʒ��Ϣ"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("ɾ����Ʒ��Ϣ"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("���������Ʒ"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("��ѯ��Ʒ��Ϣ"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("ͳ����Ʒ��Ϣ"), &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("�˻���һ��"), &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void goods_message()
{
    int num, nu;
    struct messages_buy* w;
    struct comm_buy* m;
    pr();
    wchar_t name[15];
    RECT r1 = { 121,81,520,181 };
	while(1)
    {
        num = click_goods_message();
        if(num == 0||num == 1||num == 2||num == 3||num ==4||num ==5||num == 6|| num == 7)
            break;
    }
    switch (num)
	{
        case 0:help();back();break;
        case 1:
                      wchar_t s[10];
                      InputBox(s, 20, L"1.��¼����Ʒ��Ϣ   2.����");
                      nu = _wtoi(s);
                      while(1)
                      {
                          if(nu == 1 || nu == 2)
                                break;
                          else printf("������1��2\n");
                      }
                      switch(nu)
                      {
                                case 1:
                                m = creat();
                                save(m);
                                break;
                                case 2: w = buy();sav(w);back();break;
                      }
                      break;
        case 2:revise();back();break;
        case 3: del();back();break;
        case 4: cu();back(); break;
        case 5: google();back();break;
        case 6:
               drawtext(_T("ͳ�Ʒ�ʽ1.���ͳ�� 2.�ۼ�ͳ�� 3.�ۼ�ͳ��(�Ӵ�С)"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
               InputBox(name, 10, L"������Ҫͳ�Ʒ�ʽ");
               nu = _wtoi(name);
               while(1)
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
    wchar_t name[20];
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    wchar_t time[15];
    p1 = p2 = (struct sale* ) malloc(sizeof(struct sale));
    InputBox(name, 10, L"������Ҫ��ӵ���Ʒ����");
    InputBox(num, 10, L"������Ҫ��ӵ���Ʒ���");
    InputBox(sell, 10, L"������Ҫ��ӵ���Ʒ�ۼ�");
    InputBox(amount, 10, L"������Ҫ��ӵ���Ʒ����");
    InputBox(time, 10, L"��������Ʒ���ϼ�ʱ��");
    a = _wtoi(num);
    b = _wtof(sell);
    d = _wtoi(amount);
    t = _wtoi(time);
    while(1)
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
    wcscpy(p1->name, name);
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
            InputBox(name, 10, L"������Ҫ��ӵ���Ʒ����");
            InputBox(num, 10, L"������Ҫ��ӵ���Ʒ��Ż�����0����");
            InputBox(sell, 10, L"������Ҫ��ӵ���Ʒ�ۼۻ�����0����");
            InputBox(amount, 10, L"������Ҫ��ӵ���Ʒ����������0����");
            InputBox(time, 10, L"��������Ʒ���ϼ�ʱ�������0����");
            a = _wtoi(num);
            b = _wtof(sell);
            d = _wtoi(amount);
            t = _wtoi(time);
            while(1)//������
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
            wcscpy(p1->name, name);
            p1->sell = b;
            p1->amount = d;
            p1->time = t;
            if (p1->num == 0) {
                RECT r1 = { 201,81,440,181 };
                drawtext(_T("������Ʒ¼�����"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            }
            else {
                RECT r1 = { 201,81,440,181 };
                drawtext(_T("¼�������Ʒ�ɹ�"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            }
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
    double a;
    int  b, x;
    long long c;
    wchar_t y[15];
    wchar_t num[20];
    wchar_t sell[20];
    wchar_t amount[20];
    wchar_t time[20];
    p1 = p2 = (struct messages_buy*)malloc(sizeof(struct messages_buy));
    //printf("��������Ʒ����š����ơ��ۼۡ�����������ʱ��(��202203061518)�� \n");
    InputBox(num, 10, L"��������Ʒ���");
    InputBox(y, 10, L"��������Ʒ����");
    InputBox(sell, 10, L"��������Ʒ�ۼ�");
    InputBox(amount, 10, L"��������Ʒ����");
    InputBox(time, 10, L"���������ʱ��(��202203061518)");
    x = _wtoi(num);
    b = _wtoi(amount);
    a = _wtoi(sell);
    c = _wtoi(time);
    while(1)//¼����
    {
        if(a < 0 || b < 0||c<0||x<0)
        {
        printf("�����ʽ��������������\n");
        }
        else {
                    break;
                 }
    }
    while(fread(&comm,LEN,1,fp) != 0)
        {
            if(wcscmp(comm.name, y) == 0)
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
    wcscpy(p1->name, y);
    p1->amount = b;
    p1->price = a;
    p1->time = c;
    printf("������Ϣ¼��ɹ���\n");
    head = NULL;
    while(p1->amount != 0)//����¼��
    {
        InputBox(num, 10, L"��������Ʒ���,������0����");
        InputBox(y, 10, L"��������Ʒ����");
        InputBox(sell, 10, L"��������Ʒ�ۼ�,������0����");
        InputBox(amount, 10, L"��������Ʒ����,������0����");
        InputBox(time, 10, L"���������ʱ��(��202203061518),������0����");
        x = _wtoi(num);
        b = _wtoi(amount);
        a = _wtoi(sell);
        c = _wtoi(time);
        n = n+1;
        if(n == 1)
            head = p1;
            else p2->next = p1;
        p2 = p1;
        p1 = (struct messages_buy*) malloc(lon);
        while(1)//¼����
        {
            if(a < 0 || b < 0)
            {
                printf("�����ʽ��������������\n");
            }
            else
                {
                    while(fread(&comm,LEN,1,fp) != 0)
                    {
                        if(wcscmp(comm.name, y) == 0)
                        {
                            comm.amount = comm.amount + b;
                            comm.time = c;
                            fseek(fp, 0-LEN, SEEK_CUR);
                            fwrite(&comm,LEN,1,fp);
                            break;
                        }
                    }
                    p1->num = x;
                    wcscpy(p1->name, y);
                    p1->amount = b;
                    p1->price = a;
                    p1->time = c;
                    if (p1->amount == 0) { printf("������Ϣ¼�����\n"); break; }
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
    wchar_t c[20];
    wchar_t num[20];
    wchar_t sell[20];
    wchar_t amount[20];
    wchar_t time[20];
    p1 = p2 = (struct comm_buy* ) malloc(sizeof(struct comm_buy));
    //printf("��������Ʒ����š����ơ��ۼۡ�����������ʱ��(��202203061518)�� \n");
    InputBox(num,10,L"��������Ʒ���");
    InputBox(c, 10, L"��������Ʒ����");
    InputBox(sell, 10, L"��������Ʒ�ۼ�");
    InputBox(amount, 10, L"��������Ʒ����");
    InputBox(time, 10, L"�������ϼ�ʱ��");
    a = _wtoi(num);
    b = _wtof(sell);
    am = _wtoi(amount);
    t = _wtoi(time);
    while(1)
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
    wcscpy(p1->name, c);
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
            InputBox(num, 10, L"��������Ʒ���,������0����");
            InputBox(c, 10, L"��������Ʒ����");
            InputBox(sell, 10, L"��������Ʒ�ۼ�,������0����");
            InputBox(amount, 10, L"��������Ʒ����,������0����");
            InputBox(time, 10, L"��������Ʒʱ��,������0����");
            a = _wtoi(num);
            b = _wtof(sell);
            am = _wtoi(amount);
            t = _wtoi(time);
            while(1)//������
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
            wcscpy(p1->name, c);
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
    wchar_t name[20];
    wchar_t num[20];
    wchar_t sell[20];
    wchar_t amount[20];
    wchar_t time[20];
    struct comm_buy comm;
    fp = fopen("databa.dat","rb+");
    InputBox(name, 10, L"������Ҫ���ҵ���Ʒ����");
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(wcscmp(comm.name,name) == 0)
            {
                t = 1;
                fseek(fp, 0-sizeof(struct comm_buy), SEEK_CUR);
                InputBox(num, 10, L"����������Ʒ���");
                InputBox(name, 10, L"����������Ʒ����");
                InputBox(sell, 10, L"����������Ʒ�ۼ�");
                InputBox(amount, 10, L"����������Ʒ����");
                InputBox(time, 10, L"���������ϼ�ʱ��");
                comm.amount = _wtoi(amount);
                wcscpy(comm.name, name);
                comm.num = _wtoi(num);
                comm.sell = _wtoi(sell);
                comm.time = _wtoi(time);
                while(1)
                    {
                        if(comm.num < 0 || comm.sell <= 0)
                        {
                            printf("�����ʽ��������������\n");
                        }
                        else
                        {
                            RECT r1 = { 201,81,440,181 };
                            drawtext(_T("�޸ĳɹ���"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                            break;
                        }
                    }
                fwrite(&comm,sizeof(struct comm_buy),1,fp);
                break;
            }
    }
    if (t == 0) {
       RECT r1 = { 201,81,440,181 };
       drawtext(_T("û�и���Ʒ"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    fclose(fp);
}
//��Ʒ��Ϣɾ��
void del()
{
    FILE* fp, *fq;
    fp = fopen("databa.dat","rb");
    fq = fopen("data.dat", "wb");
    wchar_t name[15];
    int t = 0;
    struct comm_buy comm;
    InputBox(name, 10, L"������Ҫɾ������Ʒ����");
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(wcscmp(comm.name,name) != 0)
            fwrite(&comm, sizeof(struct comm_buy), 1, fq);
        else t = 1;
    }
    if (t == 0) {
        RECT r1 = { 201,81,440,181 };
        drawtext(_T("û�и���Ʒ"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    else {
        RECT r1 = { 201,81,440,181 };
        drawtext(_T("��Ʒɾ�����"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
        fclose(fp);
        fclose(fq);
        remove("databa.dat");
        rename("data.dat", "databa.dat");
}
//��Ʒ��Ϣ��ѯ
void google()
{
    FILE* fp;
    int t = 0, m=0, n=0,temp=0;
    wchar_t name[20];
    struct comm_buy comm;
    fp = fopen("databa.dat","rb+");
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r1 = { 81,81,560,181 };
    drawtext(_T("��ѡ���ѯ��ʽ1.���Ʋ�ѯ 2.��Ų�ѯ 3.ģ����ѯ����Ʒ���֣�4.�۸������ѯ"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(name, 10, L"������Ҫ���ҷ�ʽ");
    m = _wtoi(name);
    clearrectangle(101, 61, 538, 419);
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    while(1)
    {
        if(m == 1 || m == 2|| m==3||m==4) break;
        else printf("������1~3\n");
    }
    int axisy = 80;
    int axisx = 140;
    switch(m)
    {
        case 1:
            InputBox(name,10,L"��������Ҫ��������Ʒ������");
            axisy = 80;
            axisx = 140;
            outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
            axisy += 40;
            while(fread(&comm,LEN,1,fp) != 0)
            {
                
                if(wcscmp(comm.name,name) == 0)
                {
                    t = 1;
                    wsprintf(num, _T("%d"), comm.num);
                    wsprintf(sell, _T("%d"), comm.sell);
                    wsprintf(amount, _T("%d"), comm.amount);
                    outtextxy(axisx, axisy, num);
                    axisx += 30;
                    outtextxy(axisx, axisy, comm.name);
                    axisx += 100;
                    outtextxy(axisx, axisy, sell);
                    axisx += 30;
                    outtextxy(axisx, axisy, amount);
                    axisx += 50;
                    axisy += 40;axisx = 140;
                    break;
               }
            }
            if(t == 0)
                outtextxy(axisx, axisy, _T("��Ʒ����δ��������������Ʒ"));
            else
                outtextxy(axisx, axisy, _T("������ɣ�������ϡ�"));
            fclose(fp);
            t=0;
            break;
        case 2:
            InputBox(name, 10, L"��������Ҫ��������Ʒ�����");
            axisy = 80;
            axisx = 140;
            outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
            axisy += 40;
            n = _wtoi(name);
            while(fread(&comm,LEN,1,fp) != 0){
                if(comm.num==n)
                {
                    t = 1;
                    wsprintf(num, _T("%d"), comm.num);
                    wsprintf(sell, _T("%d"), comm.sell);
                    wsprintf(amount, _T("%d"), comm.amount);
                    outtextxy(axisx, axisy, num);
                    axisx += 30;
                    outtextxy(axisx, axisy, comm.name);
                    axisx += 100;
                    outtextxy(axisx, axisy, sell);
                    axisx += 30;
                    outtextxy(axisx, axisy, amount);
                    axisx += 50;
                    axisy += 40; axisx = 140;
                    break;
                }
            }
             if(t == 0)
                 outtextxy(axisx, axisy, _T("��Ʒ����δ��������������Ʒ"));
             else
                 outtextxy(axisx, axisy, _T("������ɣ�������ϡ�"));
            fclose(fp);
            break;
        case 3:
            InputBox(name, 10, L"��������Ҫ��������Ʒ������");
            axisy = 80;
            axisx = 140;
            outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
            axisy += 40;
            wchar_t shortname[15];
            n = wcslen(name);
            m = 0;
            temp = 0;
            while (fread(&comm, LEN, 1, fp) != 0) {
                m = wcslen(comm.name);
                for (int item = 0; item <= m-n; item+=2) {
                    temp = 0;
                    for (int t = item; t < item+n; t++) {
                        shortname[temp] = comm.name[t];
                        temp += 1;
                    }
                    shortname[temp] = '\0';
                    if (wcscmp(shortname, name) == 0) {
                        wsprintf(num, _T("%d"), comm.num);
                        wsprintf(sell, _T("%d"), comm.sell);
                        wsprintf(amount, _T("%d"), comm.amount);
                        outtextxy(axisx, axisy, num);
                        axisx += 30;
                        outtextxy(axisx, axisy, comm.name);
                        axisx += 100;
                        outtextxy(axisx, axisy, sell);
                        axisx += 30;
                        outtextxy(axisx, axisy, amount);
                        axisx += 50;
                        axisy += 40; axisx = 140;
                        break;
                    }
                }
            }
            break;
        case 4:
            wchar_t wcslow[10];
            wchar_t wcshigh[10];
            InputBox(wcslow, 10, L"�������ѯ����ͼ۸�");
            InputBox(wcshigh, 10, L"�������ѯ����߼۸�");
            double low, high;
            low = _wtof(wcslow);
            high = _wtof(wcshigh);
            axisy = 80;
            axisx = 140;
            outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
            axisy += 40;
            while (fread(&comm, LEN, 1, fp) != 0) {
                if (comm.sell<high && low<comm.sell) {
                    wsprintf(num, _T("%d"), comm.num);
                    wsprintf(sell, _T("%d"), comm.sell);
                    wsprintf(amount, _T("%d"), comm.amount);
                    outtextxy(axisx, axisy, num);
                    axisx += 30;
                    outtextxy(axisx, axisy, comm.name);
                    axisx += 100;
                    outtextxy(axisx, axisy, sell);
                    axisx += 30;
                    outtextxy(axisx, axisy, amount);
                    axisx += 50;
                    axisy += 40; axisx = 140;
                }
            }
    }
}
/*����_���С����*/
void order_num()
{
    clearrectangle(0, 0, 640, 480);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    FILE* fp;
    int t=0;
    struct comm_buy e;
    struct comm_buy od[200];//note
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    int axisy = 80;
    int axisx = 140;
    outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
    axisy += 40;
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
            wsprintf(num, _T("%d"), od[i].num);
            wsprintf(sell, _T("%d"), od[i].sell);
            wsprintf(amount, _T("%d"), od[i].amount);
            outtextxy(axisx, axisy, num);
            axisx += 30;
            outtextxy(axisx, axisy, od[i].name);
            axisx += 100;
            outtextxy(axisx, axisy, sell);
            axisx += 30;
            outtextxy(axisx, axisy, amount);
            axisx += 50;
            axisy += 40; axisx = 140;
        }

    }
    fclose(fp);
}
//����_�ۼ�С����
void order_sell1()
{
    clearrectangle(0, 0, 640, 480);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    FILE* fp;
    int t=0;
    struct comm_buy e;
    struct comm_buy od[200];//note
    fp = fopen("databa.dat","rb");
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    int axisy = 80;
    int axisx = 140;
    outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
    axisy += 40;
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
        wsprintf(num, _T("%d"), od[i].num);
        wsprintf(sell, _T("%d"), od[i].sell);
        wsprintf(amount, _T("%d"), od[i].amount);
        outtextxy(axisx, axisy, num);
        axisx += 30;
        outtextxy(axisx, axisy, od[i].name);
        axisx += 100;
        outtextxy(axisx, axisy, sell);
        axisx += 30;
        outtextxy(axisx, axisy, amount);
        axisx += 50;
        axisy += 40; axisx = 140;
    }
    fclose(fp);
}
//����_�ۼ۴�С
void order_sell2()
{
    clearrectangle(0, 0, 640, 480);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    FILE* fp;
    int t=0;
    struct comm_buy e;
    struct comm_buy od[200];//note
    fp = fopen("databa.dat","rb");
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    int axisy = 80;
    int axisx = 140;
    outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
    axisy += 40;
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
        wsprintf(num, _T("%d"), od[i].num);
        wsprintf(sell, _T("%d"), od[i].sell);
        wsprintf(amount, _T("%d"), od[i].amount);
        outtextxy(axisx, axisy, num);
        axisx += 30;
        outtextxy(axisx, axisy, od[i].name);
        axisx += 100;
        outtextxy(axisx, axisy, sell);
        axisx += 30;
        outtextxy(axisx, axisy, amount);
        axisx += 50;
        axisy += 40; axisx = 140;
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
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    wchar_t time[15];
    int axisy = 80;
    int axisx = 140;
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    while(fread(&od[t],sizeof(struct sale), 1, fp) != 0)
    {
        t++;
    }
    outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
    axisy += 25;
    for(int i = 0; i < t; i++)
    {
        wsprintf(num, _T("%d"), od[i].num);
        wsprintf(sell, _T("%d"), od[i].sell);
        wsprintf(amount, _T("%d"), od[i].amount);
        wsprintf(time, _T("%d"), od[i].time);
        outtextxy(axisx, axisy, num);
        axisx += 30;
        outtextxy(axisx, axisy, od[i].name);
        axisx += 100;
        outtextxy(axisx, axisy, sell);
        axisx += 30;
        outtextxy(axisx, axisy, amount);
        axisx += 50;
        axisy += 40;
        axisx = 140;
    }
    fclose(fp);
}
//����

void back()
{
    int nu;
    wchar_t s[10];
    InputBox(s, 10,L"1.�������˵�  2.�˳����� ");
    nu = _wtoi(s);
    switch(nu)
    {
        case 1: system("cls");goods_message();break;
        case 2:exit(0);
    }
}
void bac()
{
    int num, nu;
    struct messages_buy* w;
    struct comm_buy *m;
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
                                m = creat();
                                save(m);
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
    clearrectangle(0, 61, 640, 419);
    // printf("\n1.��ӭʹ��ϵͳ������\n");
    //printf("\n2.���ղ˵���ʾ�������ִ���;\n");
    //printf("\n3.�����ɻ����µ�15294748920��\n");
    //printf("\n4.лл����ʹ�ã�\n");
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r1 = { 201,101,440,161 };
    drawtext(_T("1.��ӭʹ��ϵͳ������"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r2 = { 201,181,440,241 };
    drawtext(_T("2.���ղ˵���ʾ�������ִ���"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r3 = { 201,261,440,321 };
    drawtext(_T("3.�����ɻ����µ�15294748920��"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r4 = { 201,341,440,401 };
    drawtext(_T("лл����ʹ�ã�"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void del_1()
{
    FILE* fp, *fq;
    fp = fopen("sale.dat","rb");
    fq = fopen("sa.dat", "wb");
    wchar_t name[15];
    int t = 0;
    struct comm_buy comm;
    InputBox(name, 10, L"������Ҫɾ������Ʒ����");
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(wcscmp(comm.name,name) != 0)
            fwrite(&comm,sizeof(struct comm_buy), 1, fq);
        else t = 1;
    }
    if (t == 0) {
        RECT r1 = { 201,81,440,181 };
        drawtext(_T("��Ʒ������"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    else {
        RECT r1 = { 201,81,440,181 };
        drawtext(_T("ɾ���ɹ���"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
        fclose(fp);
        fclose(fq);
        remove("sale.dat");
        rename("sa.dat", "sale.dat");
}
/*����_1*/
void back_1()
{
    int nu;
    wchar_t s[10];
    InputBox(s, 10, L"1.�������˵�  2.������һ�� ");
    nu = _wtoi(s);
    while(1)
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
void Ui_cu() {
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    fillrectangle(0, 91, 101, 133);
    RECT r1 = { 1,92,100,132 };
    fillrectangle(0, 164, 101, 206);
    RECT r2 = { 1,165,100,205 };
    fillrectangle(0, 237, 101, 279);
    RECT r3 = { 1,238,100,278 };
    fillrectangle(0, 310, 101, 352);
    RECT r4 = { 1,311,100,351 };
    fillrectangle(538, 91, 640, 133);
    RECT r5 = { 539,92,639,132 };
    fillrectangle(538, 164, 640, 206);
    RECT r6 = { 539,165,639,205 };
    fillrectangle(538, 237, 640, 279);
    RECT r7 = { 539,238,639,278 };
    fillrectangle(538, 310, 640, 352);
    RECT r8 = { 539,311,639,351 };
    drawtext(_T("��ʾ������Ʒ"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("���Ӵ�����Ʒ"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("�޸Ĵ�����Ʒ"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("ɾ��������Ʒ"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("ͳ�ƴ�����Ʒ"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("��ѯ��Ʒ����"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("��ѯ��Ʒ�۸�"), &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("�˻���һ��"), &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
int click_cu() {
    ExMessage m;
    getmessage(&m, EM_MOUSE);
    switch (m.message) {
    case WM_LBUTTONDOWN:
        if (92 < m.y && m.y < 132 && 1 < m.x && m.x < 100) {
            return 1;
        }
        else if (165 < m.y && m.y < 205 && 1 < m.x && m.x < 100) {
            return 2;
        }
        else if (238 < m.y && m.y < 278 && 1 < m.x && m.x < 100) {
            return 3;
        }
        else if (311 < m.y && m.y < 351 && 1 < m.x && m.x < 100) {
            return 4;
        }
        else if (92 < m.y && m.y < 132 && 539 < m.x && m.x < 639) {
            return 5;
        }
        else if (165 < m.y && m.y < 205 && 539 < m.x && m.x < 639) {
            return 6;
        }
        else if (238 < m.y && m.y < 278 && 539 < m.x && m.x < 639) {
            return 7;
        }
        else if (311 < m.y && m.y < 351 && 539 < m.x && m.x < 639) {
            return 8;
        }
        else { return 0; }
        break;
    default:
        return 0;
    }
    return 8;
}
void cu()
{
    int nu;
    struct sale* w;
    Ui_cu();
    while(1)
    {
        nu = click_cu();
        if(nu == 1 || nu == 2 ||nu == 3|| nu == 4|| nu == 5|| nu == 6||nu==7||nu==8)
            break;
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
    wchar_t sale_name[20];
    wchar_t shortname[15];
    FILE* fp;
    fp = fopen("sale.dat", "rb");
    struct sale od;
    InputBox(sale_name,10,L"�������ѯ������Ʒ�Ĳ�������:");
    int n = wcslen(sale_name);
    int m;
    int temp;
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    int axisy = 80;
    int axisx = 140;
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
    axisy += 40;
    while (fread(&od, sizeof(struct sale), 1, fp) != 0) {
        m = wcslen(od.name);
        for (int item = 0; item <= m - n;item+=2) 
        {
            temp = 0;
            for (int t = item; t < item + n; t++) {
                shortname[temp] = od.name[t];
                temp += 1;
            }
            shortname[temp] = '\0';
            if (wcscmp(shortname, sale_name) == 0) {
                wsprintf(num, _T("%d"), od.num);
                wsprintf(sell, _T("%d"), od.sell);
                wsprintf(amount, _T("%d"), od.amount);
                outtextxy(axisx, axisy, num);
                axisx += 30;
                outtextxy(axisx, axisy, od.name);
                axisx += 100;
                outtextxy(axisx, axisy, sell);
                axisx += 30;
                outtextxy(axisx, axisy, amount);
                axisx += 50;
                axisy += 40;
                axisx = 140;
                break;
            }
        }
    }
}
void search_sale_sell() {
    FILE* fp;
    fp = fopen("sale.dat", "rb");
    struct sale od;
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    wchar_t wcslow[10];
    wchar_t wcshigh[10];
    InputBox(wcslow,10,L"�������ѯ����ͼ۸�");
    InputBox(wcshigh, 10, L"�������ѯ����߼۸�");
    double low,high;
    low = _wtof(wcslow);
    high = _wtof(wcshigh);
    int temp;
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    int axisy = 80;
    int axisx = 140;
    outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
    axisy += 40;
    while (fread(&od, sizeof(struct sale), 1, fp) != 0) 
    {
        axisx = 140;
        if (od.sell>low && od.sell<high) {
            wsprintf(num, _T("%d"), od.num);
            wsprintf(sell, _T("%d"), od.sell);
            wsprintf(amount, _T("%d"), od.amount);
            outtextxy(axisx, axisy, num);
            axisx += 30;
            outtextxy(axisx, axisy, od.name);
            axisx += 100;
            outtextxy(axisx, axisy, sell);
            axisx += 30;
            outtextxy(axisx, axisy, amount);
            axisx += 50;
            axisy += 40; axisx = 140;
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
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    int axisy = 80;
    int axisx = 140;
    outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|��Ʒ����"));
    axisy += 40;
    for(int i = 0; i < t; i++)//note
    {
        wsprintf(num, _T("%d"), od[i].num);
        wsprintf(sell, _T("%d"), od[i].sell);
        wsprintf(amount, _T("%d"), od[i].amount);
        outtextxy(axisx, axisy, num);
        axisx += 30;
        outtextxy(axisx, axisy, od[i].name);
        axisx += 100;
        outtextxy(axisx, axisy, sell);
        axisx += 30;
        outtextxy(axisx, axisy, amount);
        axisx += 50;
        axisy += 40; axisx = 140;
    }
    fclose(fp);
}
/*������Ʒ�޸�*/
void revise_1()//�޸���������ۼ�
{
    FILE* fp;
    int  t = 0;
    wchar_t name[20];
    wchar_t num[20];
    wchar_t sell[20];
    wchar_t amount[20];
    wchar_t time[20];
    struct sale comm;
    fp = fopen("sale.dat","rb+");
    InputBox(name, 10, L"������Ҫ�޸ĵ���Ʒ����");
    while(fread(&comm,sizeof(struct sale),1,fp) != 0)
    {
        if(wcscmp(comm.name,name) == 0)
            {
                t = 1;
                fseek(fp, 0-sizeof(struct sale), SEEK_CUR);
                InputBox(num, 10, L"����������Ʒ���");
                InputBox(name, 10, L"����������Ʒ����");
                InputBox(sell, 10, L"����������Ʒ�ۼ�");
                InputBox(amount, 10, L"����������Ʒ����");
                InputBox(time, 10, L"���������ϼ�ʱ��");
                comm.amount = _wtoi(amount);
                wcscpy(comm.name, name);
                comm.num = _wtoi(num);
                comm.sell = _wtoi(sell);
                comm.time = _wtoi(time);
                while(1)
                    {
                        if(comm.num < 0 || comm.sell <= 0)
                        {
                            printf("�����ʽ��������������\n");
                        }
                        else
                        {
                            RECT r1 = { 201,81,440,181 };
                            drawtext(_T("�޸ĳɹ���"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                            break;
                        }
                    }
                fwrite(&comm,sizeof(struct sale),1,fp);
                break;
            }
    }
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    if(t == 0) {
        RECT r1 = { 201,81,440,181 };
        drawtext(_T("�ֿ���û�и���Ʒ"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    fclose(fp);
}

double  price(wchar_t c[20])//����Ԥ���ۼ�
{
    FILE* fp;
    double t;
    struct comm_buy comm;
    fp = fopen("databa.dat","rb");
    while(fread(&comm,LEN,1,fp) != 0)
    {
        if(wcscmp(comm.name, c) == 0)
            {
                t = comm.sell;
                break;
            }
    }
    fclose(fp);
    return t;
}
/*��ȡ������Ʒ�ۼ�*/
double price_1(wchar_t c[20])
{
    FILE* fp;
    double t=-1;
    struct sale comm;
    fp = fopen("sale.dat","rb");
    while(fread(&comm,lon,1,fp) != 0)
    {
        if(wcscmp(comm.name, c) == 0)
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
            if (wcscmp(comm.name, c) == 0)
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

int comm_sale(wchar_t c[20])//�ж��Ƿ��Ǵ�����Ʒ����Ϊ1����Ϊ0
{
    FILE* fp;
    int t = 0;
    struct sale comm;
    fp = fopen("sale.dat","rb+");
    while(fread(&comm,lon,1,fp) != 0)
    {
        if(wcscmp(comm.name, c) == 0)
            {
                t = 1;
            }
    }
    fclose(fp);
    if(t == 0) return 0;
    else return 1;
}
/*��ѯ��Ʒ�Ƿ����*/
int comm_qus(wchar_t c[20])
{
    FILE* fp, *fq;
    int t = 0;
    struct sale comm;
    fp = fopen("sale.dat","rb+");

    while(fread(&comm,lon,1,fp) != 0)
    {
        if(wcscmp(comm.name, c) == 0)
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
        if(wcscmp(comm.name, c) == 0)
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
    clearrectangle(0, 0, 640, 480);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    FILE* fq,  *fp;
    struct Customer cust_t,tt;
    struct comm_sell comm;
    int star, sold_1, a,nn=0,hao, wzz = 0,cse=0,cj;
    double oj;
    double b, sold, sell;
    wchar_t c[20];
    wchar_t cus[20];
    wchar_t num[20];
    InputBox(num, 10, L"������˿ͻ�Ա��");
    printf("������˿ͻ�Ա�ţ�");
    hao = _wtoi(num);
    while(1)
    {
    wzz = 0;
    struct Customer cust_t,tt;
    fq = fopen("customer_information.dat","rb+");
    //printf("11111");
    while (fread(&cust_t, sizeof(cust_t), 1, fq) != 0)
    {
        //printf("11111");
        if (cust_t.number == hao)
        {
            nn++;
            tt = cust_t;
            break;
        }
    }
    if(nn==0)
    {
        int ss;
        int axisy = 80;
        int axisx = 140;
        outtextxy(axisx, axisy, _T("��Ա���������������1����������"));
        axisy += 40;
        outtextxy(axisx, axisy, _T("���ù˿Ͳ�Ϊ��Ա��������2��������"));
        axisy += 40;
        outtextxy(axisx, axisy, _T("���ù˿�û�д��������Ա����������3����в���"));
        InputBox(num, 10);
        a = _wtoi(num);
        while(1)
        {
            if((a==1||a==2)||a==3)break;
            else printf("�������������ѡ����\n");
        }
        if (a == 1) { selled(); back_2(); }
        else if (a == 2) { add_s(); clearrectangle(101, 61, 538, 419); }
        else
        {
            star=0;
            cse++;
            wcscpy(cus,L"ĳĳ");
        }

    }
    wcscpy(cus,cust_t.name);
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
    InputBox(c, 10, L"��������Ʒ����");
    InputBox(num, 10, L"��������Ʒ����������0��������");
    a = _wtoi(num);
    if(a == 0) break;
    wzz =  comm_qus(c);
    RECT r = { 140,160,400,320 };
    
    if(wzz == 0) { drawtext(_T("��Ʒ������"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);;continue;}
    cj = comm_qus_1(c);
    if(cj < a) { drawtext(_T("��治��"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);;continue;}
    clearrectangle(101, 61, 538, 419);
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    comm_qus_2(c, a);
    InputBox(num, 20, L"�����뽻��ʱ��");
    comm.time = _wtoi(num);
     sold_1 = comm_sale(c);//�ж��Ƿ��Ǵ�����Ʒ����Ϊ1����Ϊ0
     sell = price(c);//Ԥ���ۼ�
     sold = price_1(c);//�����ۼ�
     int axisx = 140;
     int axisy = 80;
     wchar_t sell_t[15];
     outtextxy(axisx,axisy,L"�˿�   �Ƿ�Ϊ��Ա   ��Ʒ�Ƿ����   ��������   Ӧ֧�����");
     axisy += 40;
     switch(star)
     {
         case 0: if(sold_1) {
                             b = a*sold;
                             oj = sold;
                             outtextxy(axisx,axisy,cus);
                             axisx += 80;
                             outtextxy(axisx, axisy, L"��");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"��");
                             axisx += 120;
                             wsprintf(num, _T("%d"), a);
                             outtextxy(axisx, axisy,num);
                             axisx += 100;
                             wsprintf(num, _T("%d"), b);
                             outtextxy(axisx,axisy,num);
                             axisy += 40;
                             axisx = 140;
                             }
                  else {
                             b = a*sell;
                             oj = sell;
                             outtextxy(axisx, axisy, cus);
                             axisx += 80;
                             outtextxy(axisx, axisy, L"��");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"��");
                             axisx += 120;
                             wsprintf(num, _T("%d"), a);
                             outtextxy(axisx, axisy, num);
                             axisx += 100;
                             wsprintf(num, _T("%d"), b);
                             outtextxy(axisx, axisy, num);
                             axisy += 40;
                             axisx = 140;
                        }
                        break;
         case 1: if(sold_1) {
                             b = a*sold*0.95;
                             oj = sold;
                             outtextxy(axisx, axisy, cus);
                             axisx += 80;
                             outtextxy(axisx, axisy, L"һ�ǻ�Ա");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"��");
                             axisx += 120;
                             wsprintf(num, _T("%d"), a);
                             outtextxy(axisx, axisy, num);
                             axisx += 100;
                             wsprintf(num, _T("%d"), b);
                             outtextxy(axisx, axisy, num);
                             axisy += 40;
                             axisx = 140;
                            }
                        else {
                              b = a*sell*0.95;
                              oj = sell;
                              outtextxy(axisx, axisy, cus);
                              axisx += 80;
                              outtextxy(axisx, axisy, L"һ�ǻ�Ա");
                              axisx += 100;
                              outtextxy(axisx, axisy, L"��");
                              axisx += 120;
                              wsprintf(num, _T("%d"), a);
                              outtextxy(axisx, axisy, num);
                              axisx += 100;
                              wsprintf(num, _T("%d"), b);
                              outtextxy(axisx, axisy, num);
                              axisy += 40;
                              axisx = 140;
                              }
                        break;
         case 2: if(sold_1) {
                             oj = sold;
                             b = a*sold*0.9;
                             outtextxy(axisx, axisy, cus);
                             axisx += 80;
                             outtextxy(axisx, axisy, L"���ǻ�Ա");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"��");
                             axisx += 120;
                             wsprintf(num, _T("%d"), a);
                             outtextxy(axisx, axisy, num);
                             axisx += 100;
                             wsprintf(num, _T("%d"), b);
                             outtextxy(axisx, axisy, num);
                             axisy += 40;
                             axisx = 140;
                            }
                        else {
                              oj = sell;
                              b = a*sell*0.9;
                              outtextxy(axisx, axisy, cus);
                              axisx += 80;
                              outtextxy(axisx, axisy, L"���ǻ�Ա");
                              axisx += 100;
                              outtextxy(axisx, axisy, L"��");
                              axisx += 120;
                              wsprintf(num, _T("%d"), a);
                              outtextxy(axisx, axisy, num);
                              axisx += 100;
                              wsprintf(num, _T("%d"), b);
                              outtextxy(axisx, axisy, num);
                              axisy += 40;
                              axisx = 140;
                             }
                        break;
         case 3: if(sold_1) {
                             oj = sold;
                             b = a*sold*0.85;
                             outtextxy(axisx, axisy, cus);
                             axisx += 80;
                             outtextxy(axisx, axisy, L"���ǻ�Ա");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"��");
                             axisx += 120;
                             wsprintf(num, _T("%d"), a);
                             outtextxy(axisx, axisy, num);
                             axisx += 100;
                             wsprintf(num, _T("%d"), b);
                             outtextxy(axisx, axisy, num);
                             axisy += 40;
                             axisx = 140;
                            }
                        else {
                              oj = sell;
                              b = a*sell*0.85;
                              outtextxy(axisx, axisy, cus);
                              axisx += 80;
                              outtextxy(axisx, axisy, L"���ǻ�Ա");
                              axisx += 100;
                              outtextxy(axisx, axisy, L"��");
                              axisx += 120;
                              wsprintf(num, _T("%d"), a);
                              outtextxy(axisx, axisy, num);
                              axisx += 100;
                              wsprintf(num, _T("%d"), b);
                              outtextxy(axisx, axisy, num);
                              axisy += 40;
                              axisx = 140;
                             }
                        break;
     }
     if(cse!=1)
     {
    fseek(fq,0-sizeof(cust_t),SEEK_CUR);
    cust_t.sale_amount=cust_t.sale_amount+(int)b;//�������ѽ��;
    fwrite(&cust_t,sizeof(cust_t),1,fq);
    fclose(fq);
     }

     wcscpy(comm.name, c);
     comm.amount = oj;
     comm.num = a;
    fp = fopen("sell.dat", "wb");
    fwrite(&comm,Ui, 1, fp);
}
    back_2();
}

 void back_2()
{
     clearrectangle(0, 0, 640, 480);
     IMAGE background;
     loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
     putimage(0, 0, &background);
     setbkmode(TRANSPARENT);
    wchar_t ss[15];
    InputBox(ss,10,L"1.�����ۻ�    2.�˳�ϵͳ");
	int nu;
    nu = _wtoi(ss);
    while(1)
    {
        if(nu == 1 || nu == 2)
            break;
        else printf("�����ʽ����������1��2\n");
    }
    switch(nu)
    {
        case 1: selled();break;
        case 2:exit(0);
    }
 }
/*void  bac_2(void)//��������ͷָ��
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
    scanf("%lf",&hao);
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
            scanf("%lf",&a);
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
    scanf("%s %lf", c, &a);
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
         case 0: if(sold_1) {b = a*sold;oj = sold;printf("�˿�%s���ǻ�Ա��������ƷΪ������Ʒ����������%3lf��Ӧ��%5.2lf��\n", cus, a, b);}
                        else {b = a*sell;oj = sell;printf("�˿�%s���ǻ�Ա��������Ʒ�Ǵ�����Ʒ����������%3lf��Ӧ��%5.2lf��\n", cus, a, b);}
                        break;
         case 1: if(sold_1) {b = a*sold*0.95;oj = sold;printf("�˿�%s��һ�Ǽ���Ա����95���Żݣ�������ƷΪ������Ʒ����������%3lf��Ӧ��%5.2lf��\n", cus, a, b);}
                        else {b = a*sell*0.95;oj = sell;printf("�˿�%s��һ�Ǽ���Ա����95���Żݣ�������Ʒ�Ǵ�����Ʒ����������%3lf��Ӧ��%5.2lf��\n", cus, a, b);}
                        break;
         case 2: if(sold_1) {oj = sold;b = a*sold*0.9;printf("�˿�%s�Ƕ��Ǽ���Ա����9���Żݣ�������ƷΪ������Ʒ����������%3lf��Ӧ��%5.2lf��\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.9;printf("�˿�%s�Ƕ��Ǽ���Ա����9���Żݣ�������Ʒ�Ǵ�����Ʒ����������%3lf��Ӧ��%5.2lf��\n", cus, a, b);}
                        break;
         case 3: if(sold_1) {oj = sold;b = a*sold*0.85;printf("�˿�%s�����Ǽ���Ա����85���Żݣ�������ƷΪ������Ʒ����������%3lf��Ӧ��%5.2lf��\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.85;printf("�˿�%s�����Ǽ���Ա����85���Żݣ�������Ʒ�Ǵ�����Ʒ����������%3lf��Ӧ��%5.2lf��\n", cus, a, b);}
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
    fwrite(&comm,Ui, 1, fp);
}
    printf("�ۻ�������\n");
    back_2();
}*/

void search_selled()
{
    int time,temp=0,i,k,p,ss;
    FILE *fp;
    struct comm_sell t,tt;
    struct comm_sell mm[50];
    wchar_t sss[15];
    int axisx = 140;
    int axisy = 80;
    if((fp = fopen("sell.dat","rb+"))==0)
    {
        printf("ϵͳ���󣡣�����");
    }
    printf("��������Ҫ��ѯ��ʱ�䣨��ʽΪĳ��ĳ��ĳ����20210101����");
    InputBox(sss,20,L"������Ҫ��ѯ��ʱ��(����ĳ��ĳ��ĳ����20210101)");
    time = _wtoi(sss);
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
        outtextxy(axisx, axisy, L"���󣬵���û�н���");
        axisy += 30;
        outtextxy(axisx,axisy,L"�˳���������������1 ");
        axisy += 30;
        outtextxy(axisx, axisy, L"��������������2 ");
        axisy += 30;
        outtextxy(axisx, axisy, L"�˳�ϵͳ������3 ");
        InputBox(sss,20,L"��ѡ��Ҫʹ�ù���");
        ss = _wtoi(sss);
    while(1)
    {
        if((ss==1||ss==2)||ss==3)break;
        else printf("��������밴�չ�����������\n");
    }
    if (ss == 2) { search_selled(); return; }
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
    clearrectangle(0, 0, 640, 480);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    axisy = 80;
    outtextxy(axisx, axisy, L"������ѯ����������Ʒ����������1 ");
    axisy += 30;
    outtextxy(axisx, axisy, L"������ѯ����������õ���Ʒ������2");
    axisy += 30;
    InputBox(sss, 20, L"��ѡ��Ҫʹ�ù���");
    p = _wtoi(sss);
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
    int ss; wchar_t nam[20];
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    wchar_t time[15];
    int axisy = 80;
    int axisx = 140;
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|�۳�ʱ��"));
    axisy += 25;
    for(i=0;i<temp1;i++)
    {
        wsprintf(num, _T("%d"), pp[i].num);
        wsprintf(sell, _T("%d"), pp[i].amount);
        wsprintf(time, _T("%d"), pp[i].time);
        outtextxy(axisx, axisy, num);
        axisx += 30;
        outtextxy(axisx, axisy, pp[i].name);
        axisx += 100;
        outtextxy(axisx, axisy, sell);
        axisx += 30;
        outtextxy(axisx, axisy, time);
        axisx += 50;
        axisy += 40;
        axisx = 140;
    }
    axisx = 0; axisy = 80;
    outtextxy(axisx, axisy,L"��������������1");
    axisy += 30;
    outtextxy(axisx, axisy, L"�������������2");
    axisy += 30;
    outtextxy(axisx, axisy, L"�˳�ϵͳ������3");
    axisy += 30;
    InputBox(nam,10,L"");
    ss = _wtoi(nam);
    while(1)
    {
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
    int ss; wchar_t nam[20];

    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    wchar_t time[15];
    int axisy = 80;
    int axisx = 140;
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\�������ϰ\\С�ͳ���\\����.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    outtextxy(axisx, axisy, _T("|��Ʒ���|��Ʒ����|��Ʒ�۸�|�۳�ʱ��"));
    axisy += 25;
    wsprintf(num, _T("%d"), pp[temp1-1].num);
    wsprintf(sell, _T("%d"), pp[temp1 - 1].amount);
    wsprintf(time, _T("%d"), pp[temp1 - 1].time);
    outtextxy(axisx, axisy, num);
    axisx += 30;
    outtextxy(axisx, axisy, pp[temp1 - 1].name);
    axisx += 100;
    outtextxy(axisx, axisy, sell);
    axisx += 30;
    outtextxy(axisx, axisy, time);
    axisx += 50;
    axisy += 40;
    axisx = 140;

    axisx = 0; axisy = 80;
    outtextxy(axisx, axisy, L"��������������1");
    axisy += 30;
    outtextxy(axisx, axisy, L"�������������2");
    axisy += 30;
    outtextxy(axisx, axisy, L"�˳�ϵͳ������3");
    axisy += 30;
    InputBox(nam, 10, L"");
    ss = _wtoi(nam);
    while(1)
    {
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
    FILE *fp;
    struct Customer cust;
    wchar_t name_cust[20];
    wchar_t num[15];
    wchar_t salemount[15];
    InputBox(cust.name, 10, L"������˿�����");
    InputBox(num, 10, L"������˿͵ı��");
    InputBox(salemount, 10, L"������˿͵Ľ��׶�");
    cust.number = _wtoi(num);
    cust.sale_amount = _wtoi(salemount);
    if((fp=fopen("customer_information.dat","ab"))==NULL)//�򿪴����ļ�
    {
        printf("ϵͳ����!!!!!!!!!\n");
        exit(0);//��������
    }
    fwrite(&cust,sizeof(cust),1,fp);//���ļ��ж�������
    fclose(fp);
    RECT r = { 140,160,400,320 };
    drawtext(_T("¼��ɹ�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

int  comm_qus_1(wchar_t c[20])
{
    FILE *fq;
    int am = 0;
    struct comm_buy com;
    fq = fopen("databa.dat","rb");
    while(fread(&com,LEN,1,fq) != 0)
    {
        if(wcscmp(com.name, c) == 0)
            {
                am = am + com.amount;
            }
    }
    fclose(fq);
    return am;
}
void comm_qus_2(wchar_t str[20], int k)
{
    FILE *fq;
    struct comm_buy com;

    fq = fopen("databa.dat","rb+");
    while((fread(&com,LEN,1,fq)) != 0)
    {
        if((wcscmp(com.name, str)) == 0)
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
