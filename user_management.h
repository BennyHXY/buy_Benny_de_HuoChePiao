
//user_management.h
#ifndef user_management_h
#define user_management_h

#include <cstdio>
#include <unistd.h>
#include <string.h>

#include "my_struct.h"

#define User_Scan "%s%d%s%lld%d%d%d"			//name age password id st
#define UserWrite "%s %d %s %lld %d %d %d\n"

#define UserInfo ".\\user_information\\"
#define AllUserInfo ".\\user_information\\allInfo.txt"
#define TestWriteInfo ".\\user_information\\TestWriteInfo.txt"
#define tib hs[i].begin_time
#define tie hs[i].end_time
#define dU duser[dquser] 
#define dB duser[obuser]

User duser[10005];
int userVec[10065];		//暂存,普通用户序列号在duser对应的的位置 
int ni, nt;	//普通用户数， 批量操作用户数 
char UserStatus[5][55] = {"未登录", "nomal user", "admin"};

int userNum; // 用户总数 
int dquser = 0; //当前用户编号 
int obuser = 0; //对象用户编号 

void open_hs(int x)
{
	char file[100] = ".\\user_information\\";
	char name[100] = "";
	strcpy(name,duser[x].name);
	strcat(name,".txt");
	strcat(file,name);
	FILE *f_hs = fopen(file,"r");
	if(f_hs == NULL) return ;
	int t_num;
	fscanf(f_hs,"%d\n",&t_num);
	dU.num_ticket=t_num;
	for(int i=1;i<=t_num;i++){
		fscanf(f_hs,"%s %d-%d-%d-%d:%d %d-%d-%d-%d:%d %s %s %d-%d",hs[i].number,&tib.year,&tib.month,&tib.day,&tib.h,&tib.m,&tie.year,&tie.month,&tie.day,&tie.h,&tie.m,hs[i].begin,hs[i].end,&hs[i].coach,&hs[i].seat_num);
		//printf("%s %d-%d-%d-%d:%d %s %d-%d\n",hs[i].number,ti.day,ti.month,ti.day,ti.h,ti.m,hs[i].begin,hs[i].coach,hs[i].seat_num);
	}
	fclose(f_hs);
}
void write_hs(int x)
{
	char file[100] = ".\\user_information\\";
	char name[100] = "";
	strcpy(name,duser[x].name);
	strcat(name,".txt");
	strcat(file,name);
	FILE *f_hs = fopen(file,"w");
	fprintf(f_hs,"%d\n",duser[x].num_ticket);
	for(int i=1;i<=	duser[x].num_ticket;i++){
		fprintf(f_hs,"%s %d-%02d-%02d-%02d:%02d %d-%02d-%02d-%02d:%02d %s %s %02d-%02d\n",hs[i].number,tib.year,tib.month,tib.day,tib.h,tib.m,tie.year,tie.month,tie.day,tie.h,tie.m,hs[i].begin,hs[i].end,hs[i].coach,hs[i].seat_num);
	}
	fclose(f_hs);
}

void write_user_info()
{
	
//	FILE *fo = fopen(TestWriteInfo, "w");
	FILE *fo = fopen(AllUserInfo, "w");
	
	if(fo == NULL)
	{
		printf("User Information error.");
		return ;
	}
	
	for(int dquser = 1; dquser <= userNum; ++dquser)
	{
//		open_hs();
		fprintf(fo, UserWrite, dU.name, dU.age, dU.password, dU.id, dU.st, dU.money, dU.num_ticket);
	}
	
	fclose(fo);
}

void load_user_info()
{
	FILE *fi = fopen(AllUserInfo, "r");
	if(fi == NULL)
	{
		printf("User Information error.");
		return ; 
	}
	userNum = 0;
	User dq;
	while(fscanf(fi, User_Scan, &dq.name, &dq.age, &dq.password, &dq.id, &dq.st, &dq.money, &dq.num_ticket) != EOF)
	{
		duser[++userNum] = dq;
		duser[userNum].p = userNum;
	}
	fclose(fi);
	
}



int user_exist(char s[])
{
	for(int i = 1; i <= userNum; ++i)
	{
		if(strcmp(duser[i].name, s) == 0) return i;
		
	}
	return 0;
}

#endif
