#ifndef Ticket_detail_page_H
#define Ticket_detail_page_H


#include <stdio.h>
#include <string.h>

#include "user_management.h"
#include "my_function.h"
#include "my_struct.h"
#include "ticket_query_page.h"

#define out_Begin_time inf.begin_time.year,inf.begin_time.month,inf.begin_time.day,inf.begin_time.h,inf.begin_time.m
#define out_End_time inf.end_time.year,inf.end_time.month,inf.end_time.day,inf.end_time.h,inf.end_time.m
#define m_Begin_time_out my_train[i].begin_time.year,my_train[i].begin_time.month,my_train[i].begin_time.day,my_train[i].begin_time.h,my_train[i].begin_time.m
#define m_End_time_out my_train[i].end_time.year,my_train[i].end_time.month,my_train[i].end_time.day,my_train[i].end_time.h,my_train[i].end_time.m


int chek(char str[])
{
	int n=str_to_int(str);
	if(n<=0||n>num) return 0;
	return 1;
}
void print(struct ticket inf)
{
	printf("\t\t*---------*-----------------------*-----------*-----------------------------*\n");
	printf("\t\t|  车次   |        %s          |  检票口   |            %2s               |\n",inf.number,inf.chek);
	printf("\t\t*---------*-----------------------*-----------*-----------------------------*\n");
	printf("\t\t|出发地点 |      %10s       |  到达地点 |         %10s          |\n",inf.begin,inf.end);
	printf("\t\t*---------*-----------------------*-----------*-----------------------------*\n");
	printf("\t\t|出发时间 |    %02d-%02d-%02d-%02d:%02d   |  到达时间 |       %02d-%02d-%02d-%02d:%02d      |\n",out_Begin_time,out_End_time);
	printf("\t\t*---------*-----------------------*-----------*-----------------------------*\n");
 	printf("\t\t|                                座位信息                                   |\n");
 	printf("\t\t*---------------------*----------------------------*------------------------*\n");
 	printf("\t\t|     座位类型        |          票价              |           余票         |\n"); 
 	printf("\t\t*---------------------*----------------------------*------------------------*\n");
 	printf("\t\t|       特等          |            %3d             |           %3d          |\n",inf.price1,inf.remainder1);
 	printf("\t\t*---------------------*----------------------------*------------------------*\n");
 	printf("\t\t|       一等          |            %3d             |           %3d          |\n",inf.price2,inf.remainder2);
 	printf("\t\t*---------------------*----------------------------*------------------------*\n");
 	printf("\t\t|       二等          |            %3d             |           %3d          |\n",inf.price3,inf.remainder3);
 	printf("\t\t*---------------------*----------------------------*------------------------*\n");
}
int ticket_detail_page()
{
	printf("\n\t\t************************ticket information system****************************\n");
	header();
	for(int i=1;i<=my_num;i++){
		printf(Format_out,my_train[i].id,my_train[i].number,my_train[i].begin,my_train[i].end,m_Begin_time_out,m_End_time_out,my_train[i].price,my_train[i].remainder1,my_train[i].remainder2,my_train[i].remainder3);
	}
	ender();
	printf("\n\t\t\t\t\t q1-返回查询\n");
	printf("\t\t\t\t\t q2-返回主界面\n");
	printf("\t\t\t\t\t q0-结束程序\n");
	printf("\n请选择：");
	int c;
	char id[5];
	int ok=0;
	do{
		ok=0;
		printf("请输入需要查看的列车的序列号(000~%s):\n",ma_id);
		scanf("%s",id);
		if(chek(id)) ok=0;
		else if(!strcmp(id,"q1")) return 2;
		else if(!strcmp(id,"q2")) return 9;
		else if(!strcmp(id,"q0")) return 0;
		else if(!chek(id)) ok=1,printf("序列号错误，请重试\n");
		else ok=1,printf("请按要求输入，重输");
	}while(ok);
	open_id=str_to_int(id);
	system("cls");
	printf("\n\t\t************************ticket information system****************************\n");
	print(inf[open_id]);
	printf("\t\t\t\t 选项: \n");
	printf("\t\t\t 1-重新查询");
	if(dU.st<2) printf("\t\t\t 2-购买车票\n");
	else if(dU.st==2) printf("\t\t\t 2-修改车次信息");
	if(dU.st==2) printf("\t\t\t\ 3-返回上一界面\n");
	else printf("\t\t\t 3-返回上一界面");
	printf("\t\t\t 9-返回主界面\n");
	printf("\t\t\t 0-退出程序"); 
	printf("\n\t\t\t 请选择:\n");
	int choice;
	scanf("%d",&choice);
	if(choice==1) return 2;
	else if(choice==0) return 0;
	else if(choice==2&&dU.st<2) return 4;
	else if(choice==2&&dU.st==2) return 28;
	else if(choice==3) return 3;
	else return 9;
} 


#endif
