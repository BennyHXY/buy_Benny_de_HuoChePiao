#ifndef your_profile_h
#define your_profile_h

#include <iostream>

#include "user_management.h"

using namespace std;

void print_profile()
{
	printf("\t\t*------------------------------------------*\n");
	printf("\t\t|                                          |\n");
	printf("\t\t*\t\t  个人信息                 *\n");
	printf("\t\t|                                          |\n"); 
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|  姓名  |          %9s              |\n", dU.name); 
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|国家地区|           中国China             |\n");
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|证件类型|         中国居民身份证          |\n");
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|证件号码|        %18lld       |\n", dU.id);
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|  身份  |       %12s              |\n", UserStatus[dU.st]);
	printf("\t\t*--------*---------------------------------*\n");
	
	if(dU.st == 1)
	{
		
		printf("\t\t|订单数量|        %8d                 |\n", dU.num_ticket);
		printf("\t\t*--------*---------------------------------*\n");
		printf("\t\t|账户余额|        %8d                 |\n", dU.money);
		printf("\t\t*--------*---------------------------------*\n");
	}
	
	
}

int not_have_profile()
{
		printf("\t\t--------------------------------------------------------------\n");
		printf("\n");
		printf("                                         你还没有登录                             \n");
		printf("\n"); 
		printf("\t\t--------------------------------------------------------------\n");
		
		printf("\n\t\t 请选择以下选项:\n");
		printf("\t\t\t\t 1 转入登录界面\n");
		printf("\t\t\t\t 2 前往注册\n");
		printf("\t\t\t\t 3 转入车票查询界面\n");
		printf("\t\t\t\t 9 返回主界面\n");
		printf("\t\t\t\t 0 退出软件\n");
		
		printf("\nplease choose(0~9)：");
		
		int opt;
		cin >> opt;
		
		while(1)
		{
			switch(opt)
			{
				case 1:	return 1;	break;
				case 2: return 19;	break;
				case 3: return 2;	break;
				case 9: return 9;	break;
				case 0: return 0;	break;
				default:
					printf("??\n\nplease choose(0~9)：");
					cin >> opt;
					break;
			}
			
		}
		
}

int nomal_user_profile()
{
	print_profile();
	
	printf("\n\t\t 请选择以下选项:\n");
	printf("\t\t\t\t 1 切换账号\n");
	printf("\t\t\t\t 2 转入车票查询界面\n");
	printf("\t\t\t\t 3 查询购票记录\n");
	printf("\t\t\t\t 4 修改密码\n");
	printf("\t\t\t\t 5 账户充值\n");
	printf("\t\t\t\t 9 返回主界面\n");
	printf("\t\t\t\t 0 退出软件\n");
	
	printf("\nplease choose(0~9)：");
	
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return 1;	break;
			case 2: return 2;	break;
			case 3: return 54;	break;
			case 4: return 55;	break;
			case 5: return 6;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default:
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}


int admin_profile()
{
	print_profile();
	
	printf("\n\t\t 请选择以下选项:\n");
	printf("\t\t\t\t 1 切换账号\n");
	printf("\t\t\t\t 2 转入车票查询界面\n");
	printf("\t\t\t\t 3 用户管理入口\n");
	printf("\t\t\t\t 4 车次管理入口\n");
	printf("\t\t\t\t 5 修改密码\n");
	printf("\t\t\t\t 9 返回主界面\n");
	printf("\t\t\t\t 0 退出软件\n");
	
	printf("\nplease choose(0~9)：");
	
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return 1;	break;
			case 2: return 2;	break;
			case 3:	return 10;	break;
			case 4: return 20;	break;
			case 5: return 55;	break;
			case 9: return 9;	break;
			case 0: return opt; break;
			default:
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
	
}

int your_profile()
{
	
	switch(dU.st)
	{
		case 0: return not_have_profile();
			break;
		case 1: return nomal_user_profile();
			break;
		case 2: return admin_profile();
			break;
	}
	
}



#endif
