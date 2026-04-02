
#ifndef login_h
#define login_h

#include <iostream>
#include <cstring>
#include <cstdio>

#include "user_management.h"
#include "add_train_page.h"

using namespace std;

void login_header()
{
	printf("\t\t--------------------------------------------------------------\n");
	printf("\n");
	printf("                                           欢迎登陆                             \n");
	printf("\n"); 
	printf("\t\t--------------------------------------------------------------\n");
	
}

int login_failed()
{
//	printf("\t\t 请选择以下选项:\n");
//	printf("\n\t\t\t\t 1 重新输入");
//	printf("\n\t\t\t\t 2 注册\n");
//	printf("\t\t\t\t 9 返回主界面\n");
//	printf("\t\t\t\t 0 退出软件\n");
//	
//	printf("\nplease choose(0~9)：");
	
	printf("\n\n\t\t--------------------------* 菜单栏 *--------------------------\n");
	printf("\n\t\t    1-重试			2-转入注册界面	");
	printf("\n");
	printf("\n\t\t    9-返回主界面		0-退出程序\n");
	printf("\n\t\t--------------------------------------------------------------\n");
	printf("\n\t\t 请选择：");
	
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1:  return 1; break;
			case 2:  return 19; break;
			case 9:  return 9; break;
			case 0:  return 0; break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
	
//	return opt;
}

int login_successed()
{
	open_hs(dquser);
	printf("\n\t\t 登录成功！您的身份是: %s !\n", UserStatus[dU.st]);
//	printf("\n\t\t 请选择以下选项:\n");
//	printf("\t\t\t\t 9 返回主界面\n");
//	printf("\t\t\t\t 0 退出软件\n");
//	
//	printf("\nplease choose(0~9)：");
	
	
	printf("\n\n\t\t-------------------------* 菜单栏 *---------------------------\n");
	printf("\n\t\t    1-转入车票查询界面		2-转入用户个人界面	");
	printf("\n");
	printf("\n\t\t    9-返回主界面		0-退出程序\n");
	printf("\n\t\t--------------------------------------------------------------\n");
	printf("\n\t\t 请选择：");
	
	
//	load_in_dquser();
	
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1:	return 2; break;
			case 2:	return 5; break;
			case 9:	return 9; break;
			case 0: return 0; break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
	}
}

int have_loged()
{
	printf("\t\t--------------------------------------------------------------\n");
	printf("\n");
	printf("                                   你已登入！是否登出？                             \n");
	printf("\n"); 
	printf("\t\t--------------------------------------------------------------\n");
	
	printf("\n\t\t\t\t 1 是（切换账号）\n");
	printf("\n\t\t\t\t 9 否（返回主界面）\n");
	printf("\n\t\t\t\t 0 退出软件\n");
	printf("\n\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: if(dU.st == 1) write_hs(dquser);
					dquser = 0;
					return 1; break; 
			case 9: return 9; break;
			case 0: return 0; break;
			default: 
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
	return opt;
}

#endif
