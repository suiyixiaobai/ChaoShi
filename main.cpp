#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"ChaoShi.h"




int main()
{
    int k,a,b;
    //interface1();//进入时第一个爱心界面
    for(k=1;k<3;k++)
    {
        interface2();//进入时第二个界面
        printf("\n");
    }
    
    //printf(" ********************************************************\n");
    //printf(" *如果第一次使用该系统或密码忘记请输入1                 *\n");
    //printf(" ********************************************************\n");
    //printf(" *如果选择账号密码登录请输入2                           *\n");
    //printf(" ********************************************************\n");
    //printf(" *退出请输入3                                           *\n");
    //printf(" ********************************************************\n");
    UI_denglu();
    wchar_t ss[15];
    int axisx = 140;
    int axisy = 80;
    while(1)
    {
        //printf("请选择要使用功能：");
        b = click_denglu();
        //scanf("%d",&b);
        if((b==1||b==2)||b==3)break;
        //else printf("输入错误，请按照规则重新输入\n");
    }
    if(b==1)
    {
        set_account();//初始化账号密码
    }
    else if(b==2)
    {
    printf("\n\n\n\n\n");
    printf(" ********************************************************\n");
    printf(" *如果为管理者请输入1                                   *\n");
    outtextxy(axisx,axisy,L"如果为管理者请输入1");
    axisy += 40;
    printf(" ********************************************************\n");
    printf(" *如果为收银员请输入2                                   *\n");
    outtextxy(axisx, axisy, L"如果为收银员请输入2");
    axisy += 40;
    printf(" ********************************************************\n");
    printf(" *退出请输入3                                           *\n");
    outtextxy(axisx, axisy, L"退出请输入3");
    axisy += 40;
    printf(" ********************************************************\n");
    InputBox(ss,10);
    a = _wtoi(ss);
    while(1)
    {
        if(a==3)exit(0);
        if((a==1||a==2)||a==3)break;
        else printf("输入错误，请按照规则重新输入\n");

    }
    log_in_s(a);//收银员的登录界面
    log_in_g(a);//管理者的登录界面

    }
    else if(b==3)exit(0);
    return 0;
}
