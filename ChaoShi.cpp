#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"ChaoShi.h"
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<cwchar>

void UI_denglu() {
    initgraph(640,480, EW_DBLCLKS | EW_SHOWCONSOLE);
    setbkcolor(WHITE);
    cleardevice();
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    settextcolor(RGB(21, 64, 234));
    setlinecolor(BLACK);
    fillrectangle(0,219,101,261);
    RECT r1 = { 1,220, 100,260 };
    drawtext(_T("初次初始账户"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    fillrectangle(538, 130, 640, 171);
    RECT r2 = { 539,131, 639,170 };
    drawtext(_T("登录已有账户"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    fillrectangle(538, 310, 640, 351);
    RECT r3 = { 539,311, 639, 350 };
    drawtext(_T("退出"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
    FILE *fp;
    if((fp=fopen("account.dat","wb+"))==NULL)//打开磁盘文件
    {
        //printf("系统出错!!!!!!!!!\n");
        RECT r = { 140,160,400,320 };
        drawtext(_T("系统出错!!!!!!!!!"),&r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        exit(0);//结束函数
    }
    //printf("请输入初始化的账号密码\n");
    fillrectangle(200, 139, 441, 341);
    RECT r1 = { 201,140,440,340 };
    drawtext(_T("请输入初始化账号密码"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //printf("初始化收银员账号：");
    wchar_t s[10];
    InputBox(s, 10, L"初始化收银员账号");
    //scanf("%ld",&account_neu.ID_s);
    account_neu.ID_s = _wtoi(s);
    //printf("初始化收银员密码：");
    InputBox(s, 10, L"初始化收银员密码");
    //scanf("%ld",&account_neu.password_s);
    account_neu.password_s = _wtoi(s);
    InputBox(s, 10, L"初始化管理员账号");
    account_neu.ID_g = _wtoi(s);
    InputBox(s, 10, L"初始化管理员密码");
    account_neu.password_g = _wtoi(s);
    //printf("初始化管理员账号：");
    //scanf("%ld",&account_neu.ID_g);
    //printf("初始化管理员密码：");
    //scanf("%ld",&account_neu.password_g);
    //printf("%ld %ld %ld %ld\n",account_neu.ID_s,account_neu.password_s,account_neu.ID_g,account_neu.password_g);
    fwrite(&account_neu,sizeof(account_neu),1,fp);//将账号密码读入文件
    rewind(fp);
    //fread(&account_cse,sizeof(account_cse),1,fp);
    //printf("%ld %ld %ld %ld\n",account_cse.ID_s,account_cse.password_s,account_cse.ID_g,account_cse.password_g);

    //printf("账号密码设置完成");
    //printf("再次输入账号密码登录\n");
    clearrectangle(101,61,538,419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    fillrectangle(200, 79, 441, 221);
    fillrectangle(200, 259, 441, 401);
    r1 = { 201,80,440,220};
    RECT r2 = { 201,260,440,400};
    drawtext(_T("账号密码设置完成"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("再次输入账号密码登录"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //printf("如果是管理者请输入1，如果是收银员请输入2：\n");
    InputBox(s, 10, L"如果是管理者请输入1，如果是收银员请输入2");
    a = _wtoi(s);
    clearrectangle(101, 61, 538, 419);
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
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    //printf("你好收银员，请输入你的账号，密码\n");
    fillrectangle(200, 80, 441, 182);
    RECT r1 = { 201,81,440,181 };
    drawtext(_T("你好收银员，请输入你的账号，密码"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //printf("账号：");
    wchar_t s[10];
    InputBox(s, 10, L"账号");
    ID = _wtoi(s);
    //scanf("%ld",&ID);
    //printf("密码：");
    //scanf("%ld",&password);
     InputBox(s, 10, L"密码");
     password = _wtoi(s);
     printf("\n");
    if((ID==account_t.ID_s)&&(password==account_t.password_s))
    {

        system("cls");
        //printf("登录成功\n欢迎进入美好的收银时间\n");
        clearrectangle(0, 61, 640, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        //printf("你好收银员，请输入你的账号，密码\n");
        drawtext(_T("登录成功,欢迎进入美好的收银时间"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        selled();
    }
    else
    {
        //printf("账号密码错误，系统自动退出\n");
        clearrectangle(0, 61, 640, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        drawtext(_T("账号密码错误，系统自动退出"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        exit(0);

    }
    }
}
struct Account* read_account(void)//读出账号密码
{
    FILE *fp;
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
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    //printf("你好收银员，请输入你的账号，密码\n");
    fillrectangle(200, 80, 441, 180);
    RECT r1 = { 201,81,440,181 };
    drawtext(_T("你好管理员，请输入你的账号，密码"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //printf("账号：");
    wchar_t s[10];
    InputBox(s, 10, L"账号");
    ID = _wtoi(s);
    //scanf("%ld",&ID);
    printf("\n");
    //printf("密码：");
    //scanf("%ld",&password);
    InputBox(s, 10, L"密码");
    password = _wtoi(s);
     printf("\n");
     //printf("%ld %ld %ld %ld\n",account1->ID_s,account1->password_s,account1->ID_g,account1->password_g);
    if((ID==account_t.ID_g)&&(password==account_t.password_g))
    {
        clearrectangle(0, 61, 640, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        drawtext(_T("登陆成功"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        user();
    }
    else {
        clearrectangle(0, 61, 640, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        drawtext(_T("账号密码错误，系统自动退出"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    int choice;
    /*printf(" \n\n                    \n\n");
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
    */
    fillrectangle(0, 130, 101, 171);
    fillrectangle(0, 310, 101, 351);
    fillrectangle(538, 126, 640, 168);
    fillrectangle(538, 233, 640, 274);
    fillrectangle(538, 340, 640, 382);
    RECT r1 = { 1,131, 100,170 };
    drawtext(_T("退出系统"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r2 = { 1,311, 100,350 };
    drawtext(_T("修改账户"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r3 = { 539,127, 639,167 };
    drawtext(_T("顾客管理"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r4 = { 539,234, 639,274 };
    drawtext(_T("商品管理"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r5 = { 539,341, 639,381 };
    drawtext(_T("畅销商品管理"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
        printf("输入有误，没有该功能\n");
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
    if((fp=fopen("account.dat","ab"))==NULL)//打开磁盘文件
    {
        clearrectangle(0, 61, 640, 419);
        drawtext(_T("系统出错"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        exit(0);
    }
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    fillrectangle(200, 80, 441, 182);
    drawtext(_T("请输入修改后的账号密码"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    wchar_t s[10];
    InputBox(s, 10, L"收银员账号");
    //scanf("%ld",&account_neucse.ID_s);
    account_neucse.ID_s = _wtoi(s);
    //printf("修改后收银员密码：");
    InputBox(s, 10, L"收银员密码");
    account_neucse.password_s = _wtoi(s);
    //scanf("%ld",&account_neucse.password_s);
    InputBox(s, 10, L"管理员账号");
    account_neucse.ID_g = _wtoi(s);
    InputBox(s, 10, L"管理员密码");
    account_neucse.password_g = _wtoi(s);
    fwrite(&account_neucse,sizeof(account_neucse),1,fp);//将账号密码读入文件
    clearrectangle(0, 61, 640, 419);
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    fillrectangle(200, 80, 441, 182);
    drawtext(_T("修改完成"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    int a;
    RECT r2 = {1,221,100,260};
    fillrectangle(0, 220, 101, 261);
    drawtext(_T("返回管理员系统"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r3 = { 539,221,639,260 };
    fillrectangle(538, 220, 640, 261);
    drawtext(_T("退出"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
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
    drawtext(_T("返回上级"), &r0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("帮助文档"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("录入顾客"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("添加顾客"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("修改顾客"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("删除顾客"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("显示顾客"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("查询顾客"), &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("模糊查询"), &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//查询顾客信息，帮助
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
            loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
            putimage(0, 0, &background);
            setbkmode(TRANSPARENT);
            RECT r1 = { 201,101,440,161 };
            drawtext(_T("1.请按照提示使用该功能"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            RECT r2 = { 201,181,440,241 };
            drawtext(_T("2.如有疑问请拨打咨询热线15294748920"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            RECT r3 = { 201,261,440,321 };
            drawtext(_T("3.谢谢您对该系统的支持"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            RECT r4 = { 201,341,440,401 };
            drawtext(_T("如果返回上一级请输入1,如果直接退出系统请输入2"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            wchar_t s[10];
            InputBox(s, 10);
            ss = _wtoi(s);
            if (ss == 1) {
                clearrectangle(0, 61, 640, 419);
                loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
                putimage(0, 0, &background);
                setbkmode(TRANSPARENT);
                showorchange_customer();
            }
            else if (ss == 2) {
                clearrectangle(0, 61, 640, 419);
                loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
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
        printf("输入有误，没有该功能\n");
        int ss;
        wchar_t sss[15];
        InputBox(sss,10,L"如果想继续使用本系统请输入1");
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
    int i,temp,num_cust,a,grade,ss,nn=0;//temp为要搜索顾客数目，num_cust为要搜索的顾客标号
    wchar_t name_cust[15];//要搜索顾客姓名
    head_cust=look_customer();
    p=NULL;
    //printf("请选择搜索方式（按姓名搜索或按顾客编号搜索");
    //printf("按姓名搜索请输入1，按顾客编号搜索请输入2):");
    wchar_t s[15];
    wchar_t num[15];
    wchar_t grades[15];
    wchar_t salemount[15];
    int axisy=80;
    int axisx = 140;
    InputBox(s, 10, L"按姓名搜索请输入1，按顾客编号搜索请输入2");
    a = _wtoi(s);
    //scanf("%d",&a);
    //printf("请输入要搜索次数：");
    InputBox(s, 10, L"请输入要搜索次数");
    temp = _wtoi(s);
    if(a==1)
    {
        for(i=0;i<temp;i++)
        {
            InputBox(name_cust, 10, L"请输入搜索顾客名称");
            if(head_cust!=NULL)
           {
            p=head_cust;
            clearrectangle(0, 61, 640, 419);
            do
            {
            if(wcscmp(name_cust,p->god.name)== 0)
            {
                nn++;
                outtextxy(axisx,axisy,_T("|顾客序号|顾客名称|顾客等级|交易额"));
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
            InputBox(name_cust, 10, L"请输入搜索顾客名称");
            num_cust = _wtoi(name_cust);
            if(head_cust!=NULL)
           {
            p=head_cust;
            clearrectangle(0, 61, 640, 419);
            IMAGE background;
            loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
            putimage(0, 0, &background);
            setbkmode(TRANSPARENT);
            do
            {
            if(p->god.number==num_cust)
            {
                nn++;
                outtextxy(axisx, axisy, _T("|顾客序号|顾客名称|顾客等级|交易额"));
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
        loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        RECT r1 = { 140,160,400,320 };
        drawtext(_T("未查询到用户!!!"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    InputBox(s, 10,L"如果返回上一级请输入1,如果直接退出系统请输入2");
    ss = _wtoi(s);
    if(ss==1)showorchange_customer();
    else if(ss==2)exit(0);
}
void search_customer_mohu() {
    struct Customer_list* head_cust, * p;
    int i, temp, a, grade,tmp, ss, nn = 0;//temp为要搜索顾客数目，num_cust为要搜索的顾客标号
    wchar_t name_cust[20];//要搜索顾客姓名
    wchar_t shortname[20];
    wchar_t s[15];
    wchar_t num[15];
    wchar_t grades[15];
    wchar_t salemount[15];
    int axisy = 80;
    int axisx = 140;
    head_cust = look_customer();
    InputBox(s, 10, L"请输入要搜索的人数");
    temp = _wtoi(s);
    for (i = 0; i < temp; i++)
    {
        InputBox(name_cust, 10, L"请输入要搜索的部分名称");
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
                    outtextxy(axisx, axisy, _T("|顾客序号|顾客名称|顾客等级|交易额"));
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
    InputBox(s, 10, L"如果返回上一级请输入1,如果直接退出系统请输入2");
    ss = _wtoi(s);
    if (ss == 1)showorchange_customer();
    else if (ss == 2) exit(0);
}
void save_Customer(void)//用户第一次进行数据录入
{
      //该程序为第一次录入顾客信息时所使用的函数
    FILE *fp;//建立文件指针
    struct Customer cust[100];//建立顾客信息结构体数组，将信息读入文件之后在读出到数组进行排序
    //Customer cust1[5];
    int i,num_cust,ss;//后者为顾客数目
    wchar_t name_cust[20];
    wchar_t s[15];
    wchar_t num[15];
    wchar_t salemount[15];
    InputBox(s, 10, L"请输入要录入的人数");
    num_cust = _wtoi(s);
    for(i=0;i<num_cust;i++)//建立循环
    {
        InputBox(cust[i].name, 10, L"请输入顾客姓名");
        InputBox(num, 10, L"请输入顾客的编号");
        InputBox(salemount, 10, L"请输入顾客的交易额");
        cust[i].number = _wtoi(num);
        cust[i].sale_amount = _wtoi(salemount);
    }

    //将信息导入文件
    if((fp=fopen("customer_information.dat","ab"))==NULL)//打开磁盘文件
    {
        clearrectangle(101, 61, 538, 419);
        IMAGE background;
        loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
        putimage(0, 0, &background);
        setbkmode(TRANSPARENT);
        RECT r = { 140,160,400,320 };
        drawtext(_T("系统出错!!!!!!!!!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        exit(0);
    }
    for(i=0;i<num_cust;i++)
    {
        fwrite(&cust[i],sizeof(cust[i]),1,fp);//向文件中读入数据
    }
    memset(cust,0,sizeof(cust));//将cust数组中的数据清空，再次利用
    fclose(fp);
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r = { 140,160,400,320 };
    drawtext(_T("录入成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(s, 10, L"如果返回上一级请输入1,如果直接退出系统请输入2");
    ss = _wtoi(s);
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void add_customer()//在文件中添加数据
{
    FILE *fp;
    struct Customer cust[50];
    int i,num_cust,ss;
    wchar_t name_cust[20];
    wchar_t s[15];
    wchar_t num[15];
    wchar_t salemount[15];
    InputBox(s, 10, L"请输入要录入的人数");
    num_cust = _wtoi(s);
    for(i=0;i<num_cust;i++)//建立循环
    {
        InputBox(cust[i].name, 10, L"请输入顾客姓名");
        InputBox(num, 10, L"请输入顾客的编号");
        InputBox(salemount, 10, L"请输入顾客的交易额");
        cust[i].number = _wtoi(num);
        cust[i].sale_amount = _wtoi(salemount);
    }
        if((fp=fopen("customer_information.dat","ab"))==NULL)//打开磁盘文件
    {
            clearrectangle(101, 61, 538, 419);
            IMAGE background;
            loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
            putimage(0, 0, &background);
            setbkmode(TRANSPARENT);
            RECT r = { 140,160,400,320 };
            drawtext(_T("系统出错!!!!!!!!!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            exit(0);
    }
    for(i=0;i<num_cust;i++)
    {
        fwrite(&cust[i],sizeof(cust[i]),1,fp);//向文件中读入数据
    }
    memset(cust,0,sizeof(cust));//将cust数组中的数据清空，再次利用
    fclose(fp);
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r = { 140,160,400,320 };
    drawtext(_T("录入成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(s, 10, L"如果返回上一级请输入1,如果直接退出系统请输入2");
    ss = _wtoi(s);
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
    wchar_t name_cust[20];
    wchar_t s[15];
    wchar_t num[15];
    wchar_t salemount[15];
    InputBox(s, 10, L"请输入要修改顾客的编号");
    num_cha = _wtoi(s);
    //printf("11111");
    while(fread(&cust_t,sizeof(cust_t),1,fp) != 0)
    {
        //printf("11111");
        if(cust_t.number==num_cha){
            fseek(fp,0-sizeof(cust_t),SEEK_CUR);
            InputBox(cust_t.name, 10, L"请输入顾客姓名");
            InputBox(num, 10, L"请输入顾客的编号");
            InputBox(salemount, 10, L"请输入顾客的交易额");
            cust_t.number = _wtoi(num);
            cust_t.sale_amount = _wtoi(salemount);
            fwrite(&cust_t,sizeof(cust_t),1,fp);
            break;
        }
    }
    fclose(fp);
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r = { 140,160,400,320 };
    drawtext(_T("录入成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(s, 10, L"如果返回上一级请输入1,如果直接退出系统请输入2");
    ss = _wtoi(s);
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
void del1(void)//删除用户数据
{
    FILE *fp,*fq;
    int ss;
    fp = fopen("customer_information.dat","rb");
    fq = fopen("data.dat", "wb");
    wchar_t name[20];
    wchar_t s[15];
    struct Customer cust_t;
    InputBox(name, 10, L"请输入要删除的顾客姓名");
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
    drawtext(_T("录入成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(s, 10, L"如果返回上一级请输入1,如果直接退出系统请输入2");
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
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    if(look!=NULL)
    {
        p=look;
        outtextxy(axisx, axisy, _T("|顾客序号|顾客名称|顾客等级|交易额"));
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
    InputBox(s, 10, L"如果返回上一级请输入1,如果直接退出系统请输入2");
    ss = _wtoi(s);
    if(ss==1)showorchange_customer();
    else if(ss==2) exit(0);
}
struct Customer_list *look_customer()//查看用户信息，将用户信息建成链表输出表头
{
    FILE *fp;//建立文件指针
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
    printf("请选择菜单编号:");*/
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
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
    drawtext(_T("帮助文档"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("初次录入商品"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("修改商品信息"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("删除商品信息"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("管理促销商品"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("查询商品信息"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("统计商品信息"), &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("退回上一级"), &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
                      InputBox(s, 20, L"1.请录入商品信息   2.进货");
                      nu = _wtoi(s);
                      while(1)
                      {
                          if(nu == 1 || nu == 2)
                                break;
                          else printf("请输入1或2\n");
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
               drawtext(_T("统计方式1.序号统计 2.售价统计 3.售价统计(从大到小)"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
               InputBox(name, 10, L"请输入要统计方式");
               nu = _wtoi(name);
               while(1)
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
    wchar_t name[20];
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    wchar_t time[15];
    p1 = p2 = (struct sale* ) malloc(sizeof(struct sale));
    InputBox(name, 10, L"请输入要添加的商品名称");
    InputBox(num, 10, L"请输入要添加的商品序号");
    InputBox(sell, 10, L"请输入要添加的商品售价");
    InputBox(amount, 10, L"请输入要添加的商品数量");
    InputBox(time, 10, L"请输入商品的上架时间");
    a = _wtoi(num);
    b = _wtof(sell);
    d = _wtoi(amount);
    t = _wtoi(time);
    while(1)
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
    wcscpy(p1->name, name);
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
            InputBox(name, 10, L"请输入要添加的商品名称");
            InputBox(num, 10, L"请输入要添加的商品序号或输入0结束");
            InputBox(sell, 10, L"请输入要添加的商品售价或输入0结束");
            InputBox(amount, 10, L"请输入要添加的商品数量或输入0结束");
            InputBox(time, 10, L"请输入商品的上架时间或输入0结束");
            a = _wtoi(num);
            b = _wtof(sell);
            d = _wtoi(amount);
            t = _wtoi(time);
            while(1)//输入检查
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
            wcscpy(p1->name, name);
            p1->sell = b;
            p1->amount = d;
            p1->time = t;
            if (p1->num == 0) {
                RECT r1 = { 201,81,440,181 };
                drawtext(_T("促销商品录入结束"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            }
            else {
                RECT r1 = { 201,81,440,181 };
                drawtext(_T("录入促销商品成功"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            }
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
    double a;
    int  b, x;
    long long c;
    wchar_t y[15];
    wchar_t num[20];
    wchar_t sell[20];
    wchar_t amount[20];
    wchar_t time[20];
    p1 = p2 = (struct messages_buy*)malloc(sizeof(struct messages_buy));
    //printf("请输入商品的序号、名称、售价、数量、进货时间(如202203061518)： \n");
    InputBox(num, 10, L"请输入商品序号");
    InputBox(y, 10, L"请输入商品名称");
    InputBox(sell, 10, L"请输入商品售价");
    InputBox(amount, 10, L"请输入商品数量");
    InputBox(time, 10, L"请输入进货时间(如202203061518)");
    x = _wtoi(num);
    b = _wtoi(amount);
    a = _wtoi(sell);
    c = _wtoi(time);
    while(1)//录入检查
    {
        if(a < 0 || b < 0||c<0||x<0)
        {
        printf("输入格式不对请重新输入\n");
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
    printf("进货信息录入成功！\n");
    head = NULL;
    while(p1->amount != 0)//继续录入
    {
        InputBox(num, 10, L"请输入商品序号,或者以0结束");
        InputBox(y, 10, L"请输入商品名称");
        InputBox(sell, 10, L"请输入商品售价,或者以0结束");
        InputBox(amount, 10, L"请输入商品数量,或者以0结束");
        InputBox(time, 10, L"请输入进货时间(如202203061518),或者以0结束");
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
        while(1)//录入检查
        {
            if(a < 0 || b < 0)
            {
                printf("输入格式不对请重新输入\n");
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
                    if (p1->amount == 0) { printf("进货信息录入结束\n"); break; }
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
    wchar_t c[20];
    wchar_t num[20];
    wchar_t sell[20];
    wchar_t amount[20];
    wchar_t time[20];
    p1 = p2 = (struct comm_buy* ) malloc(sizeof(struct comm_buy));
    //printf("请输入商品的序号、名称、售价、数量、进货时间(如202203061518)： \n");
    InputBox(num,10,L"请输入商品序号");
    InputBox(c, 10, L"请输入商品名称");
    InputBox(sell, 10, L"请输入商品售价");
    InputBox(amount, 10, L"请输入商品数量");
    InputBox(time, 10, L"请输入上架时间");
    a = _wtoi(num);
    b = _wtof(sell);
    am = _wtoi(amount);
    t = _wtoi(time);
    while(1)
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
    wcscpy(p1->name, c);
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
            InputBox(num, 10, L"请输入商品序号,或者以0结束");
            InputBox(c, 10, L"请输入商品名称");
            InputBox(sell, 10, L"请输入商品售价,或者以0结束");
            InputBox(amount, 10, L"请输入商品数量,或者以0结束");
            InputBox(time, 10, L"请输入商品时间,或者以0结束");
            a = _wtoi(num);
            b = _wtof(sell);
            am = _wtoi(amount);
            t = _wtoi(time);
            while(1)//输入检查
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
            wcscpy(p1->name, c);
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
    wchar_t name[20];
    wchar_t num[20];
    wchar_t sell[20];
    wchar_t amount[20];
    wchar_t time[20];
    struct comm_buy comm;
    fp = fopen("databa.dat","rb+");
    InputBox(name, 10, L"请输入要查找的商品名称");
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(wcscmp(comm.name,name) == 0)
            {
                t = 1;
                fseek(fp, 0-sizeof(struct comm_buy), SEEK_CUR);
                InputBox(num, 10, L"请输入新商品序号");
                InputBox(name, 10, L"请输入新商品名称");
                InputBox(sell, 10, L"请输入新商品售价");
                InputBox(amount, 10, L"请输入新商品数量");
                InputBox(time, 10, L"请输入新上架时间");
                comm.amount = _wtoi(amount);
                wcscpy(comm.name, name);
                comm.num = _wtoi(num);
                comm.sell = _wtoi(sell);
                comm.time = _wtoi(time);
                while(1)
                    {
                        if(comm.num < 0 || comm.sell <= 0)
                        {
                            printf("输入格式不对请重新输入\n");
                        }
                        else
                        {
                            RECT r1 = { 201,81,440,181 };
                            drawtext(_T("修改成功！"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                            break;
                        }
                    }
                fwrite(&comm,sizeof(struct comm_buy),1,fp);
                break;
            }
    }
    if (t == 0) {
       RECT r1 = { 201,81,440,181 };
       drawtext(_T("没有该商品"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    fclose(fp);
}
//商品信息删除
void del()
{
    FILE* fp, *fq;
    fp = fopen("databa.dat","rb");
    fq = fopen("data.dat", "wb");
    wchar_t name[15];
    int t = 0;
    struct comm_buy comm;
    InputBox(name, 10, L"请输入要删除的商品名称");
    while(fread(&comm,sizeof(struct comm_buy),1,fp) != 0)
    {
        if(wcscmp(comm.name,name) != 0)
            fwrite(&comm, sizeof(struct comm_buy), 1, fq);
        else t = 1;
    }
    if (t == 0) {
        RECT r1 = { 201,81,440,181 };
        drawtext(_T("没有该商品"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    else {
        RECT r1 = { 201,81,440,181 };
        drawtext(_T("商品删除完成"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
        fclose(fp);
        fclose(fq);
        remove("databa.dat");
        rename("data.dat", "databa.dat");
}
//商品信息查询
void google()
{
    FILE* fp;
    int t = 0, m=0, n=0,temp=0;
    wchar_t name[20];
    struct comm_buy comm;
    fp = fopen("databa.dat","rb+");
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r1 = { 81,81,560,181 };
    drawtext(_T("请选择查询方式1.名称查询 2.序号查询 3.模糊查询（商品名字）4.价格区间查询"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    InputBox(name, 10, L"请输入要查找方式");
    m = _wtoi(name);
    clearrectangle(101, 61, 538, 419);
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    while(1)
    {
        if(m == 1 || m == 2|| m==3||m==4) break;
        else printf("请输入1~3\n");
    }
    int axisy = 80;
    int axisx = 140;
    switch(m)
    {
        case 1:
            InputBox(name,10,L"请输入您要搜索的商品的名称");
            axisy = 80;
            axisx = 140;
            outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
                outtextxy(axisx, axisy, _T("商品库中未发现您搜索的商品"));
            else
                outtextxy(axisx, axisy, _T("检索完成，结果如上。"));
            fclose(fp);
            t=0;
            break;
        case 2:
            InputBox(name, 10, L"请输入您要搜索的商品的序号");
            axisy = 80;
            axisx = 140;
            outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
                 outtextxy(axisx, axisy, _T("商品库中未发现您搜索的商品"));
             else
                 outtextxy(axisx, axisy, _T("检索完成，结果如上。"));
            fclose(fp);
            break;
        case 3:
            InputBox(name, 10, L"请输入您要搜索的商品的名称");
            axisy = 80;
            axisx = 140;
            outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
            InputBox(wcslow, 10, L"请输入查询的最低价格");
            InputBox(wcshigh, 10, L"请输入查询的最高价格");
            double low, high;
            low = _wtof(wcslow);
            high = _wtof(wcshigh);
            axisy = 80;
            axisx = 140;
            outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
/*排序_序号小到大*/
void order_num()
{
    clearrectangle(0, 0, 640, 480);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
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
    outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
//排序_售价小到大
void order_sell1()
{
    clearrectangle(0, 0, 640, 480);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
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
    outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
//排序_售价大到小
void order_sell2()
{
    clearrectangle(0, 0, 640, 480);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
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
    outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    while(fread(&od[t],sizeof(struct sale), 1, fp) != 0)
    {
        t++;
    }
    outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
//界面

void back()
{
    int nu;
    wchar_t s[10];
    InputBox(s, 10,L"1.返回主菜单  2.退出程序 ");
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
    clearrectangle(0, 61, 640, 419);
    // printf("\n1.欢迎使用系统帮助！\n");
    //printf("\n2.按照菜单提示键入数字代号;\n");
    //printf("\n3.如有疑惑敬请致电15294748920！\n");
    //printf("\n4.谢谢您的使用！\n");
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    RECT r1 = { 201,101,440,161 };
    drawtext(_T("1.欢迎使用系统帮助！"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r2 = { 201,181,440,241 };
    drawtext(_T("2.按照菜单提示键入数字代号"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r3 = { 201,261,440,321 };
    drawtext(_T("3.如有疑惑敬请致电15294748920！"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r4 = { 201,341,440,401 };
    drawtext(_T("谢谢您的使用！"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void del_1()
{
    FILE* fp, *fq;
    fp = fopen("sale.dat","rb");
    fq = fopen("sa.dat", "wb");
    wchar_t name[15];
    int t = 0;
    struct comm_buy comm;
    InputBox(name, 10, L"请输入要删除的商品名称");
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
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
        drawtext(_T("商品不存在"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    else {
        RECT r1 = { 201,81,440,181 };
        drawtext(_T("删除成功！"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
        fclose(fp);
        fclose(fq);
        remove("sale.dat");
        rename("sa.dat", "sale.dat");
}
/*返回_1*/
void back_1()
{
    int nu;
    wchar_t s[10];
    InputBox(s, 10, L"1.返回主菜单  2.返回上一级 ");
    nu = _wtoi(s);
    while(1)
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
void Ui_cu() {
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
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
    drawtext(_T("显示促销商品"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("增加促销商品"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("修改促销商品"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("删除促销商品"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("统计促销商品"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("查询商品名称"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("查询商品价格"), &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("退回上一级"), &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
    InputBox(sale_name,10,L"请输入查询促销商品的部分名称:");
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
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    wchar_t wcslow[10];
    wchar_t wcshigh[10];
    InputBox(wcslow,10,L"请输入查询的最低价格");
    InputBox(wcshigh, 10, L"请输入查询的最高价格");
    double low,high;
    low = _wtof(wcslow);
    high = _wtof(wcshigh);
    int temp;
    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    int axisy = 80;
    int axisx = 140;
    outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
    outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|商品数量"));
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
/*促销商品修改*/
void revise_1()//修改序号名称售价
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
    InputBox(name, 10, L"请输入要修改的商品名称");
    while(fread(&comm,sizeof(struct sale),1,fp) != 0)
    {
        if(wcscmp(comm.name,name) == 0)
            {
                t = 1;
                fseek(fp, 0-sizeof(struct sale), SEEK_CUR);
                InputBox(num, 10, L"请输入新商品序号");
                InputBox(name, 10, L"请输入新商品名称");
                InputBox(sell, 10, L"请输入新商品售价");
                InputBox(amount, 10, L"请输入新商品数量");
                InputBox(time, 10, L"请输入新上架时间");
                comm.amount = _wtoi(amount);
                wcscpy(comm.name, name);
                comm.num = _wtoi(num);
                comm.sell = _wtoi(sell);
                comm.time = _wtoi(time);
                while(1)
                    {
                        if(comm.num < 0 || comm.sell <= 0)
                        {
                            printf("输入格式不对请重新输入\n");
                        }
                        else
                        {
                            RECT r1 = { 201,81,440,181 };
                            drawtext(_T("修改成功！"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                            break;
                        }
                    }
                fwrite(&comm,sizeof(struct sale),1,fp);
                break;
            }
    }
    clearrectangle(0, 61, 640, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    if(t == 0) {
        RECT r1 = { 201,81,440,181 };
        drawtext(_T("仓库中没有该商品"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    fclose(fp);
}

double  price(wchar_t c[20])//返回预设售价
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
/*调取促销商品售价*/
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
/*促销商品查询*/

int comm_sale(wchar_t c[20])//判断是否是促销商品，是为1，否为0
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
/*查询商品是否存在*/
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
/*录入卖货信息*/
void  selled(void)//返回链表头指针
{
    clearrectangle(0, 0, 640, 480);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
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
    InputBox(num, 10, L"请输入顾客会员号");
    printf("请输入顾客会员号：");
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
        outtextxy(axisx, axisy, _T("会员号输入错误，请输入1后重新输入"));
        axisy += 40;
        outtextxy(axisx, axisy, _T("若该顾客不为会员，请输入2后进行添加"));
        axisy += 40;
        outtextxy(axisx, axisy, _T("若该顾客没有创建加入会员意向，请输入3后进行操作"));
        InputBox(num, 10);
        a = _wtoi(num);
        while(1)
        {
            if((a==1||a==2)||a==3)break;
            else printf("输入错误，请重新选择功能\n");
        }
        if (a == 1) { selled(); back_2(); }
        else if (a == 2) { add_s(); clearrectangle(101, 61, 538, 419); }
        else
        {
            star=0;
            cse++;
            wcscpy(cus,L"某某");
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
    InputBox(c, 10, L"请输入商品名称");
    InputBox(num, 10, L"请输入商品数量或输入0结束交易");
    a = _wtoi(num);
    if(a == 0) break;
    wzz =  comm_qus(c);
    RECT r = { 140,160,400,320 };
    
    if(wzz == 0) { drawtext(_T("商品不存在"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);;continue;}
    cj = comm_qus_1(c);
    if(cj < a) { drawtext(_T("库存不足"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);;continue;}
    clearrectangle(101, 61, 538, 419);
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    comm_qus_2(c, a);
    InputBox(num, 20, L"请输入交易时间");
    comm.time = _wtoi(num);
     sold_1 = comm_sale(c);//判断是否是促销商品，是为1，否为0
     sell = price(c);//预设售价
     sold = price_1(c);//促销售价
     int axisx = 140;
     int axisy = 80;
     wchar_t sell_t[15];
     outtextxy(axisx,axisy,L"顾客   是否为会员   商品是否促销   购买数量   应支付金额");
     axisy += 40;
     switch(star)
     {
         case 0: if(sold_1) {
                             b = a*sold;
                             oj = sold;
                             outtextxy(axisx,axisy,cus);
                             axisx += 80;
                             outtextxy(axisx, axisy, L"否");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"是");
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
                             outtextxy(axisx, axisy, L"否");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"否");
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
                             outtextxy(axisx, axisy, L"一星会员");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"是");
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
                              outtextxy(axisx, axisy, L"一星会员");
                              axisx += 100;
                              outtextxy(axisx, axisy, L"否");
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
                             outtextxy(axisx, axisy, L"二星会员");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"是");
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
                              outtextxy(axisx, axisy, L"二星会员");
                              axisx += 100;
                              outtextxy(axisx, axisy, L"否");
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
                             outtextxy(axisx, axisy, L"三星会员");
                             axisx += 100;
                             outtextxy(axisx, axisy, L"是");
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
                              outtextxy(axisx, axisy, L"三星会员");
                              axisx += 100;
                              outtextxy(axisx, axisy, L"否");
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
    cust_t.sale_amount=cust_t.sale_amount+(int)b;//本次消费金额;
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
     loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
     putimage(0, 0, &background);
     setbkmode(TRANSPARENT);
    wchar_t ss[15];
    InputBox(ss,10,L"1.继续售货    2.退出系统");
	int nu;
    nu = _wtoi(ss);
    while(1)
    {
        if(nu == 1 || nu == 2)
            break;
        else printf("输入格式错误！请输入1或2\n");
    }
    switch(nu)
    {
        case 1: selled();break;
        case 2:exit(0);
    }
 }
/*void  bac_2(void)//返回链表头指针
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
        printf(" *会员号输入错误，请输入1后重新输入                   *\n" );
        printf(" ******************************************************\n");
        printf(" *若该顾客不为会员，请输入2后进行添加                 *\n");
        printf(" ******************************************************\n");
        printf(" *若该顾客没有创建加入会员意向，请输入3后进行操作     *\n");
        printf(" ******************************************************\n");
        while(1)
        {
            printf("请选择功能：\n");
            scanf("%lf",&a);
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
    scanf("%s %lf", c, &a);
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
         case 0: if(sold_1) {b = a*sold;oj = sold;printf("顾客%s并非会员，所购商品为促销商品，购买数量%3lf，应付%5.2lf。\n", cus, a, b);}
                        else {b = a*sell;oj = sell;printf("顾客%s并非会员，所购商品非促销商品，购买数量%3lf，应付%5.2lf。\n", cus, a, b);}
                        break;
         case 1: if(sold_1) {b = a*sold*0.95;oj = sold;printf("顾客%s是一星级会员享受95折优惠，所购商品为促销商品，购买数量%3lf，应付%5.2lf。\n", cus, a, b);}
                        else {b = a*sell*0.95;oj = sell;printf("顾客%s是一星级会员享受95折优惠，所购商品非促销商品，购买数量%3lf，应付%5.2lf。\n", cus, a, b);}
                        break;
         case 2: if(sold_1) {oj = sold;b = a*sold*0.9;printf("顾客%s是二星级会员享受9折优惠，所购商品为促销商品，购买数量%3lf，应付%5.2lf。\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.9;printf("顾客%s是二星级会员享受9折优惠，所购商品非促销商品，购买数量%3lf，应付%5.2lf。\n", cus, a, b);}
                        break;
         case 3: if(sold_1) {oj = sold;b = a*sold*0.85;printf("顾客%s是三星级会员享受85折优惠，所购商品为促销商品，购买数量%3lf，应付%5.2lf。\n", cus, a, b);}
                        else {oj = sell;b = a*sell*0.85;printf("顾客%s是三星级会员享受85折优惠，所购商品非促销商品，购买数量%3lf，应付%5.2lf。\n", cus, a, b);}
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
    fwrite(&comm,Ui, 1, fp);
}
    printf("售货结束！\n");
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
        printf("系统错误！！！！");
    }
    printf("请输入你要查询的时间（形式为某年某月某天如20210101）：");
    InputBox(sss,20,L"请输入要查询的时间(形如某年某月某天如20210101)");
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
        outtextxy(axisx, axisy, L"错误，当天没有交易");
        axisy += 30;
        outtextxy(axisx,axisy,L"退出至主界面请输入1 ");
        axisy += 30;
        outtextxy(axisx, axisy, L"继续搜索请输入2 ");
        axisy += 30;
        outtextxy(axisx, axisy, L"退出系统请输入3 ");
        InputBox(sss,20,L"请选择要使用功能");
        ss = _wtoi(sss);
    while(1)
    {
        if((ss==1||ss==2)||ss==3)break;
        else printf("输入错误，请按照规则重新输入\n");
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
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    axisy = 80;
    outtextxy(axisx, axisy, L"如果想查询该日已售商品排序请输入1 ");
    axisy += 30;
    outtextxy(axisx, axisy, L"如果想查询该日销量最好的商品请输入2");
    axisy += 30;
    InputBox(sss, 20, L"请选择要使用功能");
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
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|售出时间"));
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
    outtextxy(axisx, axisy,L"继续查找请输入1");
    axisy += 30;
    outtextxy(axisx, axisy, L"管理界面请输入2");
    axisy += 30;
    outtextxy(axisx, axisy, L"退出系统请输入3");
    axisy += 30;
    InputBox(nam,10,L"");
    ss = _wtoi(nam);
    while(1)
    {
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
    int ss; wchar_t nam[20];

    wchar_t num[15];
    wchar_t sell[15];
    wchar_t amount[15];
    wchar_t time[15];
    int axisy = 80;
    int axisx = 140;
    clearrectangle(101, 61, 538, 419);
    IMAGE background;
    loadimage(&background, _T("E:\\计算机练习\\小型超市\\背景.jpg"));
    putimage(0, 0, &background);
    setbkmode(TRANSPARENT);
    outtextxy(axisx, axisy, _T("|商品序号|商品名称|商品价格|售出时间"));
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
    outtextxy(axisx, axisy, L"继续查找请输入1");
    axisy += 30;
    outtextxy(axisx, axisy, L"管理界面请输入2");
    axisy += 30;
    outtextxy(axisx, axisy, L"退出系统请输入3");
    axisy += 30;
    InputBox(nam, 10, L"");
    ss = _wtoi(nam);
    while(1)
    {
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
    FILE *fp;
    struct Customer cust;
    wchar_t name_cust[20];
    wchar_t num[15];
    wchar_t salemount[15];
    InputBox(cust.name, 10, L"请输入顾客姓名");
    InputBox(num, 10, L"请输入顾客的编号");
    InputBox(salemount, 10, L"请输入顾客的交易额");
    cust.number = _wtoi(num);
    cust.sale_amount = _wtoi(salemount);
    if((fp=fopen("customer_information.dat","ab"))==NULL)//打开磁盘文件
    {
        printf("系统出错!!!!!!!!!\n");
        exit(0);//结束函数
    }
    fwrite(&cust,sizeof(cust),1,fp);//向文件中读入数据
    fclose(fp);
    RECT r = { 140,160,400,320 };
    drawtext(_T("录入成功"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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
