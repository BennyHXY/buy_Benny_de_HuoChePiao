#ifndef My_struct_h
#define My_struct_h


#include<stdio.h>

int num;
int my_num=0;
char ma_id[20] = "000";
int max_id=0;
int open_id=0;

struct time{
	int year,month,day,h,m;
};

struct train{
	char id[5];
	char number[20];
	char begin[50];
	char end[50];
	struct time begin_time,end_time;
	int price;
	int remainder1,remainder2,remainder3;
}train[100],my_train[100],ne_train[100];

struct ticket{
	char id[5];
	char number[20];
	char chek[5];
	char begin[50];
	char end[50];
	struct time begin_time,end_time;
	int price1,price2,price3;
	int remainder1,remainder2,remainder3;
}inf[100],ne_inf[100];

struct User
{
	char name[55], password[55];
	int age, p, st = 0; //年龄 数组中的位置 身份（0-未登录 1-普通用户 2-管理员） 
	long long id;
	int num_ticket=0;
	int money;
};

struct history{
	char number[20];
	struct time begin_time;
	struct time end_time;
	char begin[50];
	char end[50];
	int coach;
	int seat_num;
}hs[100];

#endif
