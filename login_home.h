#include <iostream>
#include <cstring>
#include <cstdio>

#include "user_management.h"
#include "login.h"
//#include "register.h"

#define UserInfo ".\\user_information\\"
#define TrainInfo ".\\train_information\\"

using namespace std;

int login_page()		//page_id = 1
{
//	cout << "this is the log_in page." << endl << endl
//		 << "please tap in you user_name." << endl << endl
//		 << endl;
	
	if(dU.st)
	{
		return have_loged();
	}
	
	
	login_header();
	
	char user_name[55];
	
	
	printf("\n\t\t please input your name:");
	scanf("%s", user_name);
	
	char xxxxxx[55];
	printf("\n\t\t please input your password:");
	scanf("%s", xxxxxx);
	
	if(dquser = user_exist(user_name))
	{
		if(strcmp(xxxxxx, duser[dquser].password) == 0)
		{
			printf("\n\t\t login in successed! you stutus is %s !\n", UserStatus[duser[dquser].st]);
			return login_successed();
		}
		else
		{
			printf("\n\t\t password doesn't match!\n");
			dquser = 0;
			return login_failed();
		}
		
	}
	else 
	{
		printf("\n\t\t user name dosen't exist!\n");
		return login_failed();
	}
	
}

//int login_home()		//page_id = 1
//{
//	
//	login_header();
//	
//	printf("\n\t\t 请选择以下选项:\n");
//	
//	printf("\n\t\t\t\t 11 登录\n");
//	printf("\n\t\t\t\t 19 注册\n");
//	printf("\n\t\t\t\t 9 返回主界面\n");
//	printf("\n\t\t\t\t 0 退出软件\n");
//	printf("\n\nplease choose(0~9)：");
//	int opt;
//	cin >> opt;
//	while(1)
//	{
//		switch(opt)
//		{
//			case 11:
//			case 19:
//			case 9: 
//			case 0:  return opt; break;
//			default: 
//				printf("??\n\nplease choose(0~9)：");
//				cin >> opt;
//				break;
//		}
//		
//	}
//	
//}

