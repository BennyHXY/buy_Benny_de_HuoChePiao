//register.h


#ifndef register_h
#define register_h

#include <iostream>
#include <cstring>
#include <cstdio>

#include "user_management.h"
#include "login.h"

using namespace std; 

void register_header()
{
	printf("\t\t--------------------------------------------------------------\n");
	printf("\n");
	printf("                                           欢迎注册                             \n");
	printf("\n"); 
	printf("\t\t--------------------------------------------------------------\n");
	
}

int register_home()		//page_id = 19
{
	
	if(dU.st)
	{
		return have_loged();
	}
	
	register_header();
	
	printf("\n\t\t 请选择以下选项:\n");
	
	printf("\n\t\t\t\t 1 注册普通账户\n");
	printf("\n\t\t\t\t 2 注册管理员账户\n");
	printf("\n\t\t\t\t 9 返回主界面\n");
	printf("\n\t\t\t\t 0 退出软件\n");
	printf("\n\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1:  return 18; break;
			case 2:  return 17; break;
			case 9:  return 9;  break;
			case 0:  return 0;  break;
			default: 
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}


int register_exist(int rst) //要注册的账户名已存在 
{
		printf("\n\t\t 账户名已存在！ 请选择：");
		printf("\n\t\t\t\t 1 重试\n");
		printf("\n\t\t\t\t 2 忘记密码？\n");
		printf("\n\t\t\t\t 9 返回主界面\n");
		printf("\n\t\t\t\t 0 退出软件\n");
		printf("\n\nplease choose(0~9)：");
		int opt;
		cin >> opt;
		while(1)
		{
			switch(opt)
			{
				case 1:  return 19-rst; break;
				case 9:  return 9;  	break;
				case 0:  return 0;  	break;
				default: 
					printf("??\n\nplease choose(0~9)：");
					cin >> opt;
					break;
			}
			
		}
	
	
	
}

int register_successed()
{
	printf("\n\t\t 注册成功！您的身份是: %s !\n", UserStatus[dU.st]);
	printf("\n\t\t 请选择以下选项:\n");
	
	printf("\t\t\t\t 1 转入车票查询界面\n");
	printf("\t\t\t\t 2 前往用户个人界面\n");
	printf("\t\t\t\t 9 返回主界面\n");
	printf("\t\t\t\t 0 退出软件\n");
	
	printf("\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1:  return 2;	break;
			case 2:  return 5;	break;
			case 9:  return 9;  break;
			case 0:  return 0;  break;
			default: 
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
	
	
}

int register_page(int rst) //注册 注册账户类型 (1 / 2) page_id = 18(putong) / 17(admin)
{
	
	register_header();
	char user_name[55];
	printf("\n\t\t please input your name:");
	scanf("%s", user_name);
	if(user_exist(user_name))  return register_exist(rst);
	dquser = ++userNum;
	strcpy(dU.name, user_name);
	char xxxxxx[55];
	printf("\n\t\t please input your password:");
	scanf("%s", dU.password);
	printf("\n\t\t please input your age:");
	cin >> dU.age;
	printf("\n\t\t please input your identity number:");
	cin >> dU.id;
	dU.st = rst;
	dU.p = userNum;
	return register_successed();
	
}



#endif
