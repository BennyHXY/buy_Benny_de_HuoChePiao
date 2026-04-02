#ifndef Ticket_query_H
#define Ticket_query_H


#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_function.h"
//#include "add_train_page.h" 
#include "my_struct.h"


using namespace std;
#define Format_in "%s %s %s %s %d-%d-%d-%d:%d %d-%d-%d-%d:%d %d %d %d %d"
#define Format_out "|%-7s| %-6s| %-10s| %-10s| %d-%02d-%02d-%02d:%-5d| %d-%02d-%02d-%02d:%-5d|  %-6d| (特)%-3d (一)%-3d (二)%-3d  |\n"
#define Begin_time_in &train[i].begin_time.year,&train[i].begin_time.month,&train[i].begin_time.day,&train[i].begin_time.h,&train[i].begin_time.m
#define End_time_in &train[i].end_time.year,&train[i].end_time.month,&train[i].end_time.day,&train[i].end_time.h,&train[i].end_time.m
#define Begin_time_out train[i].begin_time.year,train[i].begin_time.month,train[i].begin_time.day,train[i].begin_time.h,train[i].begin_time.m
#define End_time_out train[i].end_time.year,train[i].end_time.month,train[i].end_time.day,train[i].end_time.h,train[i].end_time.m
#define Begin_time &inf[i].begin_time.year,&inf[i].begin_time.month,&inf[i].begin_time.day,&inf[i].begin_time.h,&inf[i].begin_time.m
#define End_time &inf[i].end_time.year,&inf[i].end_time.month,&inf[i].end_time.day,&inf[i].end_time.h,&inf[i].end_time.m


int ismodel(int n,int x)
{
	while(n){
		if(n%10==x) return 1;
		n/=10;
	}
	return 0;
}
int time_equal(struct time a,struct time b)
{
	if(a.year!=b.year) return 0;
	if(a.month!=b.month) return 0;
	if(a.day!=b.day) return 0;
	if(a.h!=b.h) return 0;
	if(a.m!=b.m) return 0;
	return 1;
}
int way=1;
int cmp1(struct train a,struct train b)
{
	if(a.begin_time.year!=b.begin_time.year) return a.begin_time.year<b.begin_time.year==way;
	else if(a.begin_time.month!=b.begin_time.month) return a.begin_time.month<b.begin_time.month==way;
	else if(a.begin_time.day!=b.begin_time.day) return a.begin_time.day<b.begin_time.day==way;
	else if(a.begin_time.h!=b.begin_time.h) return a.begin_time.h<b.begin_time.h==way;
	else return a.begin_time.m<b.begin_time.m==way;
}
int cmp2(struct train a,struct train b)
{
	if(a.end_time.year!=b.end_time.year) return a.end_time.year<b.end_time.year==way;
	else if(a.end_time.month!=b.end_time.month) return a.end_time.month<b.end_time.month==way;
	else if(a.end_time.day!=b.end_time.day) return a.end_time.day<b.end_time.day==way;
	else if(a.end_time.h!=b.end_time.h) return a.end_time.h<b.end_time.h==way;
	else return a.end_time.m<b.end_time.m==way;
}
int cmp3(struct train a,struct train b)
{
	return a.price<b.price==way;
}
int cmp4(struct train a,struct train b)
{
	return a.remainder1<b.remainder1==way;
}
int cmp5(struct train a,struct train b)
{
	return a.remainder2<b.remainder2==way;
}
int cmp7(struct train a,struct train b)
{
	return a.remainder3<b.remainder3==way;
}

void open_inf()
{
	int i=1;
	num=0;
	char s[50]=".\\train_information\\information_of_train.txt";
	FILE *f_train=fopen(s,"r");
	if(f_train==NULL) printf("error\n");
	while(18==fscanf(f_train,Format_in,train[i].id,train[i].number,train[i].begin,train[i].end,Begin_time_in,End_time_in,&train[i].price,&train[i].remainder1,&train[i].remainder2,&train[i].remainder3)){
		if(strcmp(train[i].id,ma_id)) strcpy(ma_id,train[i].id);
		if(my_num<10) my_train[++my_num]=train[i];
		i++;
	}
	num=i-1;
	fclose(f_train);
	char id[20];
	char file[100] = ".\\detailed_train\\";
	for(int i=1;i<=num;i++){
		strcpy(id,train[i].id);
		strcpy(inf[i].id,id);
		strcat(id,".txt");
		strcpy(file,".\\detailed_train\\");
		strcat(file,id);
		FILE *f_ticket=fopen(file,"r");
		fscanf(f_ticket,"%s %s %s %s",inf[i].number,inf[i].chek,inf[i].begin,inf[i].end);
		fscanf(f_ticket,"%d-%d-%d-%d:%d %d-%d-%d-%d:%d",Begin_time,End_time);
		fscanf(f_ticket,"%d %d",&inf[i].price1,&inf[i].remainder1);
		fscanf(f_ticket,"%d %d",&inf[i].price2,&inf[i].remainder2);
		fscanf(f_ticket,"%d %d",&inf[i].price3,&inf[i].remainder3);
		fclose(f_ticket);
	}
}

void init1()
{
	printf("\t\t\t\t\t Ticket query system\n");
}

void sparator()
{
	printf("*-------*-------*-----------*-----------*--------------------*--------------------*--------*--------------------------*\n");
}
int my_find(int num)
{
	sparator();
	int n;
	printf("\t\t\t 查找关键字: \n");
	printf("\t\t\t 1-车次");
	printf("\t\t\t 2-出发地点");
	printf("\t\t\t 3-到达地点\n");
	printf("\t\t\t 4-出发时间");
	printf("\t\t 5-到达时间");
	printf("\t\t\t 6-返回主页面\n");
	printf("\t\t\t 7-返回");
	printf("\t\t\t 0-退出程序"); 
	printf("\n请选择查找关键字(可多选)\n");
	scanf("%d",&n);
	char target1[20],target2[50],target3[50];
	struct time time1,time2;
	if(n==6) return 9;
	else if(n==7) return 2;
	else if(n==0) return 0;
	if(ismodel(n,1)){
		printf("请输入车次:\n");
		scanf("%s",target1);
	}
	if(ismodel(n,2)){
		printf("请输入出发地点:\n");
		scanf("%s",target2);
	}
	if(ismodel(n,3)){
		printf("请输入到达地点:\n");
		scanf("%s",target3);
	}
	if(ismodel(n,4)){
		printf("请输入出发时间(年 月 日 是分):\n");
		scanf("%d %d %d %d %d",&time1.year,&time1.month,&time1.day,&time1.h,&time1.m);
	}
	if(ismodel(n,5)){
		printf("请输入到达时间(年 月 日 是分):\n");
		scanf("%d %d %d %d %d",&time2.year,&time2.month,&time2.day,&time2.h,&time2.m);
	}
	int ok=0;
	system("cls");
	header();
	my_num=0;
	for(int i=1;i<=num;i++){
		if(ismodel(n,1)&&strcmp(train[i].number,target1)) continue;
		if(ismodel(n,2)&&strcmp(train[i].begin,target2)) continue;
		if(ismodel(n,3)&&strcmp(train[i].end,target3)) continue;
		if(ismodel(n,4)&&!time_equal(train[i].begin_time,time1)) continue;
		if(ismodel(n,5)&&!time_equal(train[i].end_time,time2)) continue;
		my_num++;
		my_train[my_num]=train[i];
		printf(Format_out,train[i].id,train[i].number,train[i].begin,train[i].end,Begin_time_out,End_time_out,train[i].price,train[i].remainder1,train[i].remainder2,train[i].remainder3);
		ok=1;
	}
	if(!ok) printf("\n\n*-------*-------*-----------*-----------*------not find------*--------------------*------------*----------*\n\n");
	else ender();
	return -1;
}
void print_train()
{
	system("cls");
	init1();
	header();
	my_num=0;
	for(int i=1;i<=10;i++){
		my_num++;
		my_train[my_num]=train[i];
		printf(Format_out,train[i].id,train[i].number,train[i].begin,train[i].end,Begin_time_out,End_time_out,train[i].price,train[i].remainder1,train[i].remainder2,train[i].remainder3);
	}
	ender();
}
int my_sort(int num)
{
	sparator();
	int n;
	printf("\t\t 排序关键字: \n\n");
	printf("\t\t 1-出发时间");
	printf("\t\t 2-到达时间");
	printf("\t\t 3-最低票价\n");
	printf("\t\t 4-特等余票");
	printf("\t\t 5-一等余票");
	printf("\t\t 6-二等余票\n");
	printf("\t\t 7-返回主页面");
	printf("\t\t 8-返回");
	printf("\t\t\t 0-退出程序\n");
	printf("请输入排序关键字\n");
	scanf("%d",&n);
	if(n==7) return 9;
	else if(n==8) return 2;
	else if(n==0) return 0;
	printf("\t\t\t\t\t 排序方式: \n");
	printf("\t\t\t 0-从大到小");
	printf("\t\t 1-从小到大\n");
	printf("请选择\n");
	scanf("%d",&way);
	if(n==1){
		sort(train+1,train+num+1,cmp1);
		print_train();
	}
	else if(n==2){
		sort(train+1,train+num+1,cmp2);
		print_train();
	}
	else if(n==3){
		sort(train+1,train+num+1,cmp3);
		print_train();
	}
	else if(n==4){
		sort(train+1,train+num+1,cmp4);
		print_train();
	}
	else if(n==5){
		sort(train+1,train+num+1,cmp5);
		print_train();
	}
	else if(n==6){
		sort(train+1,train+num+1,cmp7);
		print_train();
	}
	return -1;
}
int ticket_query_page()
{
	print_train();
	sparator();
	printf("\t\t\t 1-按关键词搜索");
	printf("\t\t\t 2-按关键词排序(默认按时间)\n");
	printf("\t\t\t 3-查看车次信息");
	if(dU.st==2) printf("\t\t\t 4-前往车次管理\n");
	if(dU.st==2) printf("\t\t\t 9-返回主界面");
	else printf("\t\t\t 9-返回主界面\n");
	printf("\t\t\t 0-退出软件\n"); 
	int choice;
	int ret=-1;
	int ok=0;
	do{
		ok=0;
		printf("请选择\n");
		scanf("%d",&choice);
		if(choice==1) ret=my_find(num);
		else if(choice==2) ret=my_sort(num);
		else if(choice==3) return 3;
		else if(choice==9) return 9;
		else if(choice==0) return 0;
		else if(dU.st==2&&choice==4) return 20;
		else ok=1,printf("你看看你输的对吗？重输或退出(0)!\n");
	}while(ok);
	if(ret!=-1) return ret;
	printf("\n\t\t\t 选项\n");
	printf("\t\t\t 1-重新查询");
	printf("\t\t\t 2-查看车次信息\n");
	if(dU.st==2) printf("\t\t\t 3-前往车次管理");
	if(dU.st==2) printf("\t\t\t 9-返回主界面\n");
	else printf("\t\t\t 9-返回主界面");
	printf("\t\t\t 0-退出软件\n");
	do{
		ok=0;
		printf("请选择\n");
		scanf("%d",&choice);
		if(choice==1) return 2;
		else if(choice==2) return 3;
		else if(choice==9) return 9;
		else if(dU.st==2&&choice==4) return 20;
		else if(choice==0) return 0;
		else ok=1,printf("你看看你输的对吗？重输或退出(0)!\n");
	}while(ok);
}

#endif
