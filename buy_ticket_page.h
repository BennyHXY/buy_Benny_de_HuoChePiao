#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#include "my_struct.h"
#include "user_management.h"
#include "ticket_detail_page.h"
#include "user_management.h"
#include "add_train_page.h"


int random (int n)
{
	n=n*3;
	n=n+n/2;
	n=n*4;
	n=n+6;
	n=(n%20+1);
	return n;
}
void add(history a)
{
	dU.num_ticket++;
	int num=dU.num_ticket;
	hs[num]=a;
}
int buy()
{
	printf("\t\t\t\t\t You selected ticket information\n\n");
	print(inf[open_id]);
	char seat[4][60]={"特等座","一等座","二等座"};
	printf("\n\t\t座位类型选择:\n");
	printf("\n\t\t1-特等座");
	printf("\t\t4-返回主界面");
	printf("\n\t\t2-一等座");
	printf("\t\t5-返回查询界面");
	printf("\n\t\t3-二等座");
	printf("\t\t6-返回上一界面");
	printf("\n\t\t0-退出程序\n");
	int ok=0;
	int choice,p,seat_nu;
	do{
		ok=0;
		printf("\n请选择座次: ");
		scanf("%d",&seat_nu);
		if(seat_nu==0) return 0;
		else if(seat_nu==4) return 9;
		else if(seat_nu==5) return 2;
		else if(seat_nu==6) return 3;
		if(seat_nu==1){
			if(inf[open_id].remainder1<=0) ok=2;
			else p=inf[open_id].price1,ok=0;
		}
		else if(seat_nu==2) {
			if(inf[open_id].remainder2<=0) ok=2;
			else p=inf[open_id].price3,ok=0;
		}
		else if(seat_nu==3){
			if(inf[open_id].remainder3<=0) ok=2;
			else p=inf[open_id].price3,ok=0;
		}
		else if(ok==0) ok=1,printf("按要求输入，重输或退出(0): ");
		if(ok==2) printf("余票不足，请重新选择或返回(0): ");
	}while(ok); 
	printf("\n请选择座位号(1~50): ");
	int numb;
	scanf("%d",&numb);
	int train_num=random(numb);
	printf("\n您选择的座位是:%s%d号",seat[seat_nu-1],numb);
	if(dU.age<18){
		printf("\n检测到你是未成年用户可以享受折扣优惠！！！");
		p=(int)(p*0.7);
	}
	printf("\n票价是 :%d \n",p);
	printf("\n您确认支付吗?\n");
	printf("\n1-yes\n0-no\n");
	scanf("%d",&choice);
	if(choice==1){
		if(dU.money<p){
			system("cls");
			printf("\t\t\t\t\t You selected ticket infoemation\n\n");
			print(inf[open_id]);
			printf("\n\t\t*---------------------*----- 余额不足!!! -----*------------------------*\n");
			printf("\t\t*--------------------------- 1-去充值 -----------------------------------*\n");
			printf("\t\t*--------------------------- 2-返回上一界面 -----------------------------*\n");
			printf("\t\t*--------------------------- 3-返回查询界面 -----------------------------*\n");
			printf("\t\t*--------------------------- 4-返回主界面 -------------------------------*\n");
			printf("\t\t*--------------------------- 5-前往个人界面 -----------------------------*\n");
			printf("\t\t*--------------------------- 0-结束程序 ---------------------------------*\n");
			printf("\n请输入: ");
			int k;
			int ok=0;
			do{
				ok=0;
				scanf("%d",&k);
				if(k==1) return 6;
				else if(k==2) return 3;
				else if(k==3) return 2;
				else if(k==4) return 9;
				else if(k==5) return 5; 
				else if(k==0) return 0;
				else ok=1,printf("\n按要求输入，重输或退出(0)"); 
			}while(ok);
		}
		dU.money-=p;
		history a;
		if(seat_nu==1) inf[open_id].remainder1--;
		else if(seat_nu==2) inf[open_id].remainder2--;
		else inf[open_id].remainder3--;
		sort(train+1,train+num+1,cmp6);
		cpy(open_id);
		strcpy(a.number,inf[open_id].number);a.begin_time=inf[open_id].begin_time;strcpy(a.begin,inf[open_id].begin);
		a.coach=train_num;a.seat_num=numb;
		strcpy(a.end,inf[open_id].end);a.end_time=inf[open_id].end_time;
		add(a);
		system("cls");
		printf("\t\t\t\t\t You selected ticket infoemation\n\n");
		print(inf[open_id]);
		printf("\n\t\t\t\t\t 恭喜您，购买成功！\n");
		printf("\n\t\t\t\t\t 1-返回主界面"); 
		printf("\n\t\t\t\t\t 2-返回车票查询界面"); 
		printf("\n\t\t\t\t\t 3-返回车票信息界面");
		printf("\n\t\t\t\t\t 0-退出程序"); 
		int c;
		int ok=0;
		do{
			ok=0;
			printf("\n请输入："); 
			scanf("%d",&c);
			if(c==1) return 9;
			else if(c==2) return 2;
			else if(c==3) return 4;
			else if(c==0) return 0;
			else ok=1,printf("按要求输入，重输或退出(0): "); 
		}while(ok);
	}
	else {
		return 3;
	}
	
}
int buy_ticket_page()
{
	if(dU.st<=0){
		printf("未登录, 请先登录\n");
		printf("tips:\n1-登录\n其他-退出\n");
		printf("请选择: ");
		int choice;
		cin>>choice;
		if(choice==1) return 1;
		else return 9;
	}
	else {
		int ret=buy();
		return ret;
	}
	return 9;
}
