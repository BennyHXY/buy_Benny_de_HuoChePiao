#ifndef user_account_operation_h
#define user_account_operation_h

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>



#include "user_management.h"

#define Hsb hs[i].begin_time
#define Hse hs[i].begin_time 
using namespace std;

void print_record(int x)
{
	printf("\t*-----------------------------------------------------------------------------------------------*\n");
	printf("\t|                                                                                               |\n");
	printf("\t|                                            历史订单                                           |\n");
	printf("\t|                                                                                               |\n");
	printf("\t*---------------*-------------------------------------------------------------------------------*\n");
	printf("\t|   订单数量    |                                    %3d  张                                    |\n",duser[x].num_ticket);
	printf("\t*---------------*-------------------------------------------------------------------------------*\n");
	printf("\t|********************************************车票信息*******************************************|\n");
	printf("\t|--------*----------------------*---------------------*--------------*------------*-------------|\n");
	printf("\t|  车次  |       出发时间  	|        达到时间     |  出发地点    | 到达地点   | 车厢-座位号 |\n"); 
	printf("\t|--------*----------------------*---------------------*--------------*------------*-------------|\n");
	for(int i = 1;i <= duser[x].num_ticket;i ++)//n is the number of order
	{
	printf("\t| %4s  |   %d-%02d-%02d-%02d:%02d   |   %d-%02d-%02d-%02d:%02d  | %10s   |%10s  |    %02d-%02d    |\n",hs[i].number,Hsb.year,Hsb.month,Hsb.day,Hsb.h,Hsb.m,Hse.year,Hse.month,Hse.day,Hse.h,Hse.m,hs[i].begin,hs[i].end,hs[i].coach,hs[i].seat_num); 
	printf("\t|--------*----------------------*---------------------*--------------*------------*-------------|\n");
		
	}
	
	
}

int record_query_page()
{
	// == begin == 
	print_record(dquser);
	// == end == 
	printf("\n\t\t 请选择以下选项:\n");
	printf("\n\t\t\t\t 1 返回个人信息界面\n");
	printf("\n\t\t\t\t 9 返回主界面\n");
	printf("\n\t\t\t\t 0 退出软件\n");
	printf("\n\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return 5;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: 
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}

void password_change_header()
{
	printf("\t********************************************************\n");	
	printf("\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t 修改密码\n"); 
	printf("\t\t\t\t\t\t\t\n");
	printf("\t********************************************************\n");
}

int old_password_check_failed()
{
	printf("\n\t\t 原密码输入不正确！请选择以下选项:\n");
	printf("\n\t\t\t\t 1 重试\n");
	printf("\n\t\t\t\t 2 返回个人信息界面\n");
	printf("\n\t\t\t\t 9 返回主界面\n");
	printf("\n\t\t\t\t 0 退出软件\n");
	printf("\n\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return 55;	break;
			case 2: return 5;	break; 
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: 
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}

int human_confirm(char xxxxxx_new[])
{
	srand((unsigned)time(NULL));
	printf("\t请等待验证码 \n");
	int ret = rand();
	int bet = rand();
	printf("\t%d+%d=?\n",ret,bet);
	printf("\t请输入你的验证码： ");
	printf("\t");
	int code;
	scanf("%d",&code);
	if(code == ret+bet)
	{
		strcpy(dU.password, xxxxxx_new);
		printf("\t修改密码成功, 请选择\n");
		
		printf("\n\t\t\t\t 1 返回个人信息界面\n");
		printf("\n\t\t\t\t 9 返回主界面\n");
		printf("\n\t\t\t\t 0 退出软件\n");
		printf("\n\nplease choose(0~9)：");
		int opt;
		cin >> opt;
		while(1)
		{
			switch(opt)
			{
				case 1: return 5;	break; 
				case 9: return 9;	break;
				case 0: return 0;	break;
				default: 
					printf("??\n\nplease choose(0~9)：");
					cin >> opt;
					break;
			}
			
		}
		
		
	}
	else{
	
		printf("\t验证码校验失败, 请选择\n");
		
		printf("\n\t\t\t\t 1 重试\n");
		printf("\n\t\t\t\t 2 返回个人信息界面\n");
		printf("\n\t\t\t\t 9 返回主界面\n");
		printf("\n\t\t\t\t 0 退出软件\n");
		printf("\n\nplease choose(0~9)：");
		int opt;
		cin >> opt;
		while(1)
		{
			switch(opt)
			{
				case 1: return human_confirm(xxxxxx_new);	break;
				case 2: return 5;	break; 
				case 9: return 9;	break;
				case 0: return 0;	break;
				default: 
					printf("??\n\nplease choose(0~9)：");
					cin >> opt;
					break;
			}
			
		}
		
	
	}
	
}

int new_password_set()
{
	char xxxxxx_new1[55], xxxxxx_new2[55];
	
	int nk = 0;
	
	printf("\t请输入你的新密码： ");
	scanf("%s", xxxxxx_new1);
	printf("\n");
	
	printf("\t请再次输入你的新密码： ");
	scanf("%s", xxxxxx_new2);
	printf("\n");
	
	if(strcmp(xxxxxx_new1, xxxxxx_new2) == 0) return human_confirm(xxxxxx_new1);
	else
	{
		printf("\n\t\t 两次输入不一致！请选择以下选项:\n");
		printf("\n\t\t\t\t 1 重试\n");
		printf("\n\t\t\t\t 2 返回个人信息界面\n");
		printf("\n\t\t\t\t 9 返回主界面\n");
		printf("\n\t\t\t\t 0 退出软件\n");
		printf("\n\nplease choose(0~9)：");
		int opt;
		cin >> opt;
		while(1)
		{
			switch(opt)
			{
				case 1: return new_password_set();	break;
				case 2: return 5;	break; 
				case 9: return 9;	break;
				case 0: return 0;	break;
				default: 
					printf("??\n\nplease choose(0~9)：");
					cin >> opt;
					break;
			}
			
		}
		
	}
	
}


int account_password_change() //page_id = 55
{
	
	password_change_header();
	 
	
	char xxxxxx_old[55];
	
	printf("\t请输入你的原密码： ");
	scanf("%s", xxxxxx_old);
	printf("\n");
	if(strcmp(xxxxxx_old, dU.password) != 0) return old_password_check_failed();
	else return new_password_set();
	/*
	printf("\n\t\t 请选择以下选项:\n");
	printf("\n\t\t\t\t 5 返回个人信息界面\n");
	printf("\n\t\t\t\t 9 返回主界面\n");
	printf("\n\t\t\t\t 0 退出软件\n");
	printf("\n\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return 5; break; 
			case 9: return 9; break;
			case 0: return 0; break;
			default: 
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	*/
	return 9;
}

void chongzhi_header()
{
	printf("\t\t--------------------------------------------------------------\n");
	printf("\n");
	printf("                                           欢迎充值                             \n");
	printf("\n"); 
	printf("\t\t--------------------------------------------------------------\n");
	
}



int chongzhi_successed()
{
	
	printf("\n\t\t请选择充值金额\n");
	printf("\t\t--------------------------------------------------------------\n");
	printf("\n\t\t 1. 600				2. 1200\n");
	printf("\n\t\t 3. 1800			4. 2400\n");
	printf("\n\t\t 5. 3000			6. 自定义\n");
	printf("\t\t--------------------------------------------------------------\n");
	int det,bet,money;
	cin >> det;
	bet=600;
	switch(det)
	{
		case 1: dU.money += 600;	break;
		case 2: dU.money += 1200;	break;
		case 3: dU.money += 1800;	break;
		case 4: dU.money += 2400;	break;
		case 5: dU.money += 3000;	break;
		case 6: printf("请输入您要充值的余额：\n");
				cin >> money;
				dU.money += money;  break;
	}
	if(det!=6){
	printf("\n\t\t 充值成功！礼品卡金额为 %d ！ 你的账户余额为: %d !\n\n",bet*det, dU.money);
	}
	else{
			printf("\n\t\t 充值成功！礼品卡金额为 %d ！ 你的账户余额为: %d !\n\n",money, dU.money);
	
			}
	printf("\n\t\t 请选择以下选项:\n");
	printf("\t\t------------------------------------------------------------\n"); 
	printf("\n\t\t 1 前往车票查询界面");
	printf("\t\t\t 2 返回个人信息界面\n");
	printf("\n\t\t 9 返回主界面");
	printf("\t\t\t\t 0 退出软件\n");
	printf("\n\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return 2;	break;
			case 2: return 5;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: 
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}

int chongzhi_failed()
{
	printf("\n\t\t 卡号不存在！是否重试？ ");
	
	printf("\n\t\t 请选择以下选项:\n");
	printf("\n\t\t\t\t 1 重试\n");
	printf("\n\t\t\t\t 2 否（返回个人信息界面）\n");
	printf("\n\t\t\t\t 9 返回主界面\n");
	printf("\n\t\t\t\t 0 退出软件\n");
	printf("\n\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1:	return 6;	break; 
			case 2: return 5;	break;
			case 9:	return 9;	break;
			case 0: return 0;	break;
			default: 
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}

int account_chongzhi()
{
	
	chongzhi_header();
	
	printf("\n\t\t 请输入礼品卡卡号(测试版为666666)：\n");
	printf("\n\t\t");
	char xxxxxx[55]; 
	scanf("%s", xxxxxx);
	
	if(strcmp(xxxxxx, "666666") == 0) return chongzhi_successed();
	else return chongzhi_failed();
}


#endif
