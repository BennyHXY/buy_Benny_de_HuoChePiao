#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include <cstdio>
 
#include "user_management.h"
#include "home_page.h"				// 主界面 page_id = 9
#include "ticket_query_page.h"	 	// 车票查询界面 page_id = 2
#include "ticket_detail_page.h" 	// 车次详细信息页 page_id = 3
#include "buy_ticket_page.h"		// 买票界面 page_id = 4 
#include "your_profile.h"			// 你的个人主页 page_id = 5
#include "add_train_page.h"
#include "login_home.h" 
#include "register.h" 
#include "user_account_operation.h"
#include "wo_shi_yi_ge_admin.h"		//管理员界面入口 

#define TrainInfo ".\\train_information\\"

using namespace std;

int dq_page = 9;	//当前所在界面 
char x;
void init()  //初始化
{
	load_user_info();
	open_inf();
	
}

void file_update()
{
	
	write_user_info();
	write_hs(dquser);
	
	write_inf();
}

int main()
{
	
	init(); //初始化
	
	//调试页面 
//	dq_page = 10;
	
	
	while(dq_page != 0)
	{
		system("cls");
		
		switch(dq_page)
		{
			case 1:  dq_page = login_page();
				break;
			case 19: dq_page = register_home();
				break;
			case 18: dq_page = register_page(1);
				break;
			case 17: dq_page = register_page(2);
				break;
			case 2:  dq_page = ticket_query_page();
				break;
			case 3:  dq_page = ticket_detail_page();
				break;
			case 4:  dq_page = buy_ticket_page();
				break;
			case 5:  dq_page = your_profile();
				break;
			case 54: dq_page = record_query_page();
				break;
			case 55: dq_page = account_password_change();
				break;
			case 6:  dq_page = account_chongzhi();
				break;
			case 10: dq_page = yonghu_admin();
				break;
			case 15: dq_page = yonghu_profile();
				break;
			case 14: dq_page = yonghu_record();
				break;
			case 20: dq_page = cheche_admin();
				break;
			case 29: dq_page = add_train();		//add_train
				break;
			case 28: dq_page = chang_train();
				break;
			case 27: dq_page = del_train();
				break;
			case 9:  dq_page = home_page();
				break;
			default: dq_page = 9;
				break;
		}
	}
	file_update();
//	printf("dq_page = %d\n", dq_page);
	
	return 0;
}
