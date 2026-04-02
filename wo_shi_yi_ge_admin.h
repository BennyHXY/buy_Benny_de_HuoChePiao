#ifndef wo_shi_yi_ge_admin_h
#define wo_shi_yi_ge_admin_h

#include <iostream>
#include <cstdio>

#include "user_management.h"
#include "user_account_operation.h"

using namespace std;

int reset_yonghu_password();
int yonghu_batch_check();

int batchCup[10065];

void cheche_admin_header()
{
	printf("\t\t--------------------------------------------------------------\n");
	printf("\n");
	printf("                                           车次管理                             \n");
	printf("\n"); 
	printf("\t\t--------------------------------------------------------------\n");
	
}

int cheche_admin()
{
	
	printf("尊敬的admin，您好呀！\n");
	
	cheche_admin_header();
	
	printf("\n\t\t 请选择以下选项:\n");
	printf("\n\t\t\t\t 29 添加车次\n");
	printf("\n\t\t\t\t 28 车次信息修改\n");
	printf("\n\t\t\t\t 27 车次信息删除"); 
	printf("\n\t\t\t\t 5  返回个人信息界面\n");
	printf("\n\t\t\t\t 9  返回主界面\n");
	printf("\n\t\t\t\t 0  退出软件\n");
	printf("\n\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 29:
			case 28:
			case 27: 
			case 5: 
			case 9: 
			case 0:  return opt; break;
			default: 
				printf("??\n\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}

void yonghu_admin_header()
{
//	printf("\t\t\t--------------------------------------------------------------\n");
//	printf("\n");
//	printf("\t                                           用户管理                             \n");
//	printf("\n"); 
//	printf("\t\t\t--------------------------------------------------------------\n");
	printf("尊敬的admin，您好呀！\n\n");
	
	printf("\n        ----------------------------------------  普通用户管理  ------------------------------------------\n");
	printf("\n");
	printf("\t\t*--------*------------*------*------------------------*------------*-----------*\n");
	printf("\t\t| 序列号 |   用户名   | 年龄 |       证件类型         | 历史订单量 |    余额   |\n");
	printf("\t\t*--------*------------*------*------------------------*------------*-----------*\n");	
	
}

void yonghu_data_print()
{
//	int userVec[10065];  //序列号为i的用户在duser中的编号 
	ni = 0;
	for(int i = 1; i <= userNum; ++i) if(duser[i].st == 1)
	{
		++ni;
		userVec[ni] = duser[i].p;
		printf("\t\t|   %02d   | %10s | %3d  |	    第二代身份证      |%6d      | %9d |\n", ni, duser[i].name, duser[i].age, duser[i].num_ticket, duser[i].money);
//		printf("\t\t*--------*------------*------*------------------------*------------*-----------*\n");	
	}
	
	printf("\t\t*--------*------------*------*------------------------*------------*-----------*\n");
	
}

void print_yonghu_profile()
{
//	printf("\t\t")
	printf("尊敬的admin，您好呀！\n\n");
	printf("\t\t*------------------------------------------*\n");
	printf("\t\t|                                          |\n");
	printf("\t\t*\t\t  个人信息                 *\n");
	printf("\t\t|                                          |\n"); 
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|  姓名  |          %9s              |\n", dB.name); 
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|国家地区|           中国China             |\n");
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|证件类型|         中国居民身份证          |\n");
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|证件号码|        %18lld       |\n", dB.id);
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|  身份  |       %12s              |\n", UserStatus[dB.st]);
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|订单数量|        %8d                 |\n", dB.num_ticket);
	printf("\t\t*--------*---------------------------------*\n");
	printf("\t\t|账户余额|        %8d                 |\n", dB.money);
	printf("\t\t*--------*---------------------------------*\n");
	
	
	
}

int yonghu_money_modify()
{
	printf("\n\t\t 输入修改后余额：");
	scanf("%d", &dB.money);
	printf("\n\t\t 修改成功！用户余额为：%d !\n", dB.money);
	printf("\n\t\t 请选择：\n");
	printf("\n\t\t 1-重置密码		2-刷新当前页面		3-查看历史购票记录");
	printf("\n\t\t 4-返回用户管理界面	9-返回主界面		0-退出程序\n");
	
	int opt; 
	printf("\nplease choose(0~9)：");
	cin >> opt;
	
	while(1)
	{
		switch(opt)
		{
			case 1: reset_yonghu_password();
				break;
			case 2: return 15;	break;
			case 3: return 14;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}

int reset_yonghu_password()
{
	
	strcpy(dB.password, "123456");
	
	printf("\n\t\t 密码重置成功！ 请选择：\n");
	printf("\n\t\t 1-返回用户管理界面	2-修改用户余额		3-查看历史购票记录");
	printf("\n\t\t 9-返回主界面			0-退出程序\n");
	
	int opt; 
	printf("\nplease choose(0~9)：");
	cin >> opt;
	
	while(1)
	{
		switch(opt)
		{
			case 1: return 10;	break;
			case 2: return yonghu_money_modify();
					break;
			case 3: return 14;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}


int yonghu_profile()
{
	print_yonghu_profile();
	
	printf("\n\t\t 请选择：\n");
	printf("\n\t\t 1-重置密码		2-修改用户余额		3-查看历史购票记录");
	printf("\n\t\t 4-返回用户管理界面	9-返回主界面		0-退出程序\n");
	
	int opt; 
	printf("\nplease choose(0~9)：");
	cin >> opt;
	
	while(1)
	{
		switch(opt)
		{
			case 1: return reset_yonghu_password();
					break;
			case 2: return yonghu_money_modify();
					break;
			case 3: return 14;	break;
			case 4: return 10;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
	
}

int get_obuser()
{
	
	printf("\n\t\t 输入用户序列号:");
	int ob;
	cin >> ob;
	
	if(ob <= ni)
	{
		obuser = userVec[ob];
		return 15;
	}
	
	printf("\n\t\t invalid input!\n");
	printf("\n\t\t 1-重试			2-取消选择		3-返回个人主页");
	printf("\n\t\t 9-返回主界面		0-退出程序\n");
	
	int opt; 
	printf("\nplease choose(0~9)：");
	cin >> opt;
	
	while(1)
	{
		switch(opt)
		{
			case 1: return get_obuser();
					break;
			case 2: return 10;  break;
			case 3: return 5;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}


//int yonghu_batch_processing()
//{
//	printf("\n\t\t 请选择以下选项:\n");
//	printf("\n\t\t 1-批量重置密码		2-批量重置余额		3-取消选择");
//	printf("\n\t\t 	9-返回主界面		0-退出程序\n");
//	printf("\n\t\t 请选择：");
//	int opt;	//nt
//	cin >> opt;
//	
//	
//}



int batch_invalid()
{
	printf("\n\t\t invalid input!\n");
	printf("\n\t\t 1-重试			2-取消选择		3-返回个人主页");
	printf("\n\t\t 9-返回主界面		0-退出程序\n");
	printf("\n\t\t 请选择：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return yonghu_batch_check();
				break;
			case 2: return 10;	break;
				break;
			case 3: return 5;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
	
}

int yonghu_batch_operation(int c)
{
	int mo;
	 
	if(c == 2)
	{
		printf("\n\t\t 请输入重置后金额：");
		scanf("%d", &mo);
		printf("\n");
	}
	
	if(c == 3)
	{
		printf("\n\t\t 请输入充值金额：");
		scanf("%d", &mo);
		printf("\n");
	}
	
	for(int i = 1; i <= nt; ++i)
	{
		if(c == 1) strcpy(duser[batchCup[i]].password, "123456");
		if(c == 2) duser[batchCup[i]].money = mo; 
		if(c == 3) duser[batchCup[i]].money += mo;
	}
	
	printf("\n\t\t 操作成功！\n");
	printf("\n\t\t 1-刷新页面		2-返回个人主页");
	printf("\n\t\t 4-取消选择		9-返回主界面		0-退出程序\n");
	printf("\n\t\t 请选择：");
	int opt;
	cin >> opt;
	
	while(1)
	{
		switch(opt)
		{
			case 1: return 10; 
			case 2: return 5;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
	
	
}

int choose_batch_type()
{
	
	printf("\n\t\t 请选择批量操作类型！\n");
	printf("\n\t\t 1-重置密码		2-账户余额重置		3-账户余额充值");
	printf("\n\t\t 4-取消选择		9-返回主界面		0-退出程序\n");
	printf("\n\t\t 请选择：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: 
			case 2: 
			case 3: return yonghu_batch_operation(opt);
				break;
			case 4: return 10;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
	
	
	
	
}

int yonghu_batch_check()
{
	
	int p = 1;	//数据合法 
	printf("\n\t\t 请输入要操作的用户数量: " );
	scanf("%d", &nt);
	printf("\n\t\t 请输入要操作的用户序列号: " );
	for(int i = 1; i <= nt; ++i)
	{
		cin >> batchCup[i];
		if(batchCup[i] > ni || batchCup[i] == 0) p = 0;
		else batchCup[i] = userVec[batchCup[i]];
	}
	if(!p) return batch_invalid();
	else return choose_batch_type();
	
}

int yonghu_admin()
{
	yonghu_admin_header();
	yonghu_data_print();
	
	printf("\n\t\t *menu:\n");
	printf("\n\t\t 1-选择用户对象		2-批量操作		3-返回个人主页");
	printf("\n\t\t 9-返回主界面		0-退出程序\n");
	printf("\n\t\t 请选择：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return get_obuser();
				break;
			case 2: return yonghu_batch_check();
				break;
			case 3: return 5;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}

/*void open_yonghu_hs()
{
	char file[100] = ".\\user_information\\";
	char name[100] = "";
	strcpy(name,dB.name);
	strcat(name,".txt");
	strcat(file,name);
	FILE *f_hs = fopen(file,"r");
	if(f_hs == NULL) return ;
	int t_num;
	fscanf(f_hs,"%d\n",&t_num);
	dB.num_ticket=t_num;
	for(int i=1;i<=t_num;i++){
		fscanf(f_hs,"%s %d-%d-%d-%d:%d %s %d-%d",hs[i].number,&ti.year,&ti.month,&ti.day,&ti.h,&ti.m,hs[i].begin,&hs[i].coach,&hs[i].seat_num);
		//printf("%s %d-%d-%d-%d:%d %s %d-%d\n",hs[i].number,ti.day,ti.month,ti.day,ti.h,ti.m,hs[i].begin,hs[i].coach,hs[i].seat_num);
	}
	fclose(f_hs);
}*/

/*void print_yonghu_record()
{
	printf("尊敬的admin，您好呀！\n\n");
	printf("\t*-----------------------------------------------------------------------------------------------*\n");
	printf("\t|                                                                                               |\n");
	printf("\t|                                            历史订单                                           |\n");
	printf("\t|                                                                                               |\n");
	printf("\t*---------------*-------------------------------------------------------------------------------*\n");
	printf("\t|   订单数量    |                                    %3d  张                                    |\n",dU.num_ticket);
	printf("\t*---------------*-------------------------------------------------------------------------------*\n");
	printf("\t|********************************************车票信息*******************************************|\n");
	printf("\t|--------*----------------------*---------------------*--------------*------------*-------------|\n");
	printf("\t|  车次  |       出发时间  	|        达到时间     |  出发地点    | 到达地点   | 车厢-座位号 |\n"); 
	printf("\t|--------*----------------------*---------------------*--------------*------------*-------------|\n");
		for(int i = 1;i <= dB.num_ticket;i ++)//n is the number of order
	{
	printf("\t| %4s  |   %d-%02d-%02d-%02d:%02d   |   %d-%02d-%02d-%02d:%02d  | %10s   |%10s  |    %02d-%02d    |\n",hs[i].number,Hsb.year,Hsb.month,Hsb.day,Hsb.h,Hsb.m,Hse.year,Hse.month,Hse.day,Hse.h,Hse.m,hs[i].begin,hs[i].end,hs[i].coach,hs[i].seat_num); 
	printf("\t|--------*----------------------*---------------------*--------------*------------*-------------|\n");
		
	}
	
	
}
*/
int yonghu_record()
{
	open_hs(obuser);
	print_record(obuser);
	
	printf("\n\t\t 请选择：\n");
	printf("\n\t\t 1-返回用户信息页面	2-返回用户管理界面");
	printf("\n\t\t 9-返回主界面		0-退出程序\n");
	
	printf("\n\t\t 请选择：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return 15;	break; 
			case 2: return 10;  break;
			case 3: return 5;	break;
			case 9: return 9;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
}





#endif
