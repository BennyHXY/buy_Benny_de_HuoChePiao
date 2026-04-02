#ifndef Add_ticket_H
#define Add_ticket_H

#include <stdio.h>
#include <string.h>
#include <algorithm>

#include "ticket_detail_page.h"
#include "ticket_query_page.h"
#include "my_function.h"
#include "my_struct.h"


#define Neb ne.begin_time
#define Nee ne.end_time
#define train_out "%s %s %s %s %d-%02d-%02d-%02d:%02d %d-%02d-%02d-%02d:%02d %d %d %d %d\n"
#define B_ti train[i].begin_time
#define E_ti train[i].end_time 
#define T train[i]
#define MT my_train[j]
#define I inf[i]
#define I_bt inf[i].begin_time
#define I_et inf[i].end_time

using namespace std;


int cmp6(struct train a,struct train b)
{
	return strcmp(a.id,b.id)<0;
}

long long num_ti(struct time t)
{
	int da[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	long long num_t=(t.year-1)*365;
	for(int i=1;i<t.month;i++) num_t+=da[i];
	num_t+=t.day;
	return num_t;
}
int chek_t(struct time t1,struct time t2)
{
	int nt1=num_ti(t1),nt2=num_ti(t2);
	if(nt1>nt2) return 1;
	if(nt2-nt1>10) return 2;
	int t11=t1.h*60+t1.m,t22=(nt2-nt1)*(24*60)+t2.h*60+t2.m;
	if(t11>t22) return 1;
	if(t22-t11<20) return 3;
	return 0;
}
void cpy(int i)
{
	strcpy(T.id,I.id);strcpy(T.number,I.number);
	strcpy(T.begin,	I.begin);strcpy(T.end, I.end);
	T.begin_time=I.begin_time;T.end_time=I.end_time;
	T.price=I.price3;T.remainder1=I.remainder1;
	T.remainder2=I.remainder2;T.remainder3=I.remainder3;
}
void cp(int i,int j)
{
	strcpy(MT.id,I.id);strcpy(MT.number,I.number);
	strcpy(MT.begin,I.begin);strcpy(MT.end, I.end);
	MT.begin_time=I.begin_time;MT.end_time=I.end_time;
	MT.price=I.price3;MT.remainder1=I.remainder1;
	MT.remainder2=I.remainder2;MT.remainder3=I.remainder3;
}
void write_inf()
{
	char s[50]=".\\train_information\\information_of_train.txt";
	FILE *f_train=fopen(s,"w");
	sort(train+1,train+num+1,cmp6);
	char file[100] = ".\\detailed_train\\";
	char id[5];
	for(int i=1;i<=num;i++){
		cpy(i);
		if(!strcmp(train[i].id,"-1")) continue;
		int_to_str(id,i);
		fprintf(f_train,train_out,train[i].id,train[i].number,train[i].begin,train[i].end,B_ti.year,B_ti.month,B_ti.day,B_ti.h,B_ti.m,E_ti.year,E_ti.month,E_ti.day,E_ti.h,E_ti.m,train[i].price,train[i].remainder1,train[i].remainder2,train[i].remainder3);
		strcat(id,".txt");
		strcpy(file,".\\detailed_train\\");
		strcat(file,id);
		FILE *f_ticket=fopen(file,"w");
		fprintf(f_ticket,"%s %s %s %s\n",I.number,I.chek,I.begin,I.end);
		fprintf(f_ticket,"%d-%02d-%02d-%02d:%02d %d-%02d-%02d-%02d:%02d\n",I_bt.year,I_bt.month,I_bt.day,I_bt.h,I_bt.m,I_et.year,I_et.month,I_et.day,I_et.h,I_et.m);
		fprintf(f_ticket,"%d %d\n",I.price1,I.remainder1);
		fprintf(f_ticket,"%d %d\n",I.price2,I.remainder2);
		fprintf(f_ticket,"%d %d\n",I.price3,I.remainder3);
		fclose(f_ticket);
	}
	fclose(f_train);
} 
int add_train()
{
	printf("\n\n---------------------------------- 您确定要增加车次吗？-------------------------------\n"); 
	printf("\n\t\t\t\t\t 1--是\n");
	printf("\t\t\t\t\t 2--返回上一界面\n");
	printf("\t\t\t\t\t 3--返回主界面\n");
	printf("\t\t\t\t\t 0--结束程序\n");
	int c;
	int choice;
	int ok1=0;
	do{
		ok1=0;
		printf("请输入：");
		scanf("%d",&c);
		if(c==1) ok1=0; 
		else if(c==2) return 20;
		else if(c==3) return 9;
		else if(c==0) return 0;
		else ok1=1,printf("按要求输入，重输：");
	}while(ok1);
	struct ticket ne;
	system("cls");
	printf("\n\n---------------------------------------* 车次增加中 ----------------------------------\n");printf("\n"); 
	printf("\n请输入车次: ");
	scanf("%s",ne.number);
	printf("\n请输入检票口：");
	scanf("%s",ne.chek);
	//system
	printf("\n请输入出发地与目的地(以空格分隔): ");
	scanf("%s %s",ne.begin,ne.end);
	int ok=0;
	do{
		ok=0;
		if(!strcmp(ne.begin,ne.end)){
			printf("\n出发地与目的地不能相同请重新输入或返回(0): ");
			scanf("%s",ne.begin);
			if(!strcmp(ne.begin,"0"));
			scanf("%s",ne.end);
			ok=1;
		}	
	}while(ok);
	printf("\n请输入出发时间(年 月 日 时 分): ");
	scanf("%d%d%d%d%d",&Neb.year,&Neb.month,&Neb.day,&Neb.h,&Neb.m);
	ok=0;
	do{
		ok=0;
		if(!chek_time(Neb)){
			ok=1;
			printf("\n你输入时间的不合法，请从新输入或返回(-1)");
			scanf("%d",&Neb.year);
			if(Neb.year==-1) return 20;
			scanf("%d%d%d%d",&Neb.month,&Neb.day,&Neb.h,&Neb.m);
		}
	}while(ok);
	printf("\n请输入到达时间(年 月 日 时 分): ");
	scanf("%d%d%d%d%d",&Nee.year,&Nee.month,&Nee.day,&Nee.h,&Nee.m);
	ok=0;
	do{
		ok=0;
		if(!chek_time(Nee)){
			ok=1;
			printf("\n你输入时间的不合法，请从新输入或返回(-1)");
			scanf("%d",&Nee.year);
			if(Nee.year==-1) return 20;
			scanf("%d%d%d%d",&Nee.month,&Nee.day,&Nee.h,&Nee.m);
			ok=1;
		}
		int ck=chek_t(Neb,Nee);
		if(!ok&&ck){
			int cho; 
			if(ck==1){
				printf("\n出发时间不能晚于到达时间，请重新输入或返回(-1)");
				scanf("%d",&Nee.year);
				scanf("%d",&Nee.year);
				if(Nee.year==-1) return 20;
				scanf("%d%d%d%d",&Nee.month,&Nee.day,&Nee.h,&Nee.m);
				ok=1;
			}
			else if(ck==2) {
				printf("\n出发与到达时间间隔过大,确认修改吗(1-是,2-重输,0-返回): ");
				scanf("%d",&cho);
				if(cho==1) ok=0;
	 			else if(cho==2){
	 				printf("\n请输入: "); 
	 				scanf("%d%d%d%d%d",&Nee.year,&Nee.month,&Nee.day,&Nee.h,&Nee.m);
	 				ok=1;
				}
				else return 20;
			}
			else if(ck==3) {
				printf("\n出发与到达时间间隔过小,确认修改吗(1-是,2-重输,0-返回): ");
				scanf("%d",&cho);
				if(cho==1) ok=0;
				else if(cho==2){
					printf("\n请输入: "); 
					scanf("%d%d%d%d%d",&Nee.year,&Nee.month,&Nee.day,&Nee.h,&Nee.m);
					ok=1;
				}
				else return 20;
			}
		}
	}while(ok); 
	
	printf("\n请输入票价与余票(以空格分隔)\n");
	printf("\n特等座: ");
	scanf("%d %d",&ne.price1,&ne.remainder1);
	ok=0;
	do{
		ok=0;
		if(ne.price1<=0||ne.remainder1<0){
			printf("\n你输入的票价或余票不合法请重新输入或返回(-1): ");
			scanf("%d",&ne.price1);
			if(ne.price1==-1) return 20;
			scanf("%d",&ne.remainder1);
			ok=1;
		}
	}while(ok);
	printf("\n一等座: ");
	scanf("%d %d",&ne.price2,&ne.remainder2);
	ok=0;
	do{
		ok=0;
		if(ne.price2<=0||ne.remainder2<0){
			printf("\n你输入的票价或余票不合法请重新输入或返回(-1): ");
			scanf("%d",&ne.price2);
			if(ne.price2==-1) return 20;
			scanf("%d",&ne.remainder2);
			ok=1;
		}
	}while(ok);
	printf("\n二等座: ");
	scanf("%d %d",&ne.price3,&ne.remainder3);
	ok=0;
	do{
		ok=0;
		if(ne.price3<=0||ne.remainder3<0){
			printf("\n你输入的票价不合法请重新输入或返回(-1): ");
			scanf("%d",&ne.price3);
			if(ne.price3==-1) return 20;
			scanf("%d",&ne.remainder3);
			ok=1;
		}
	}while(ok);
	num++;
	inf[num]=ne;
	max_id=num;
	int_to_str(ma_id,max_id);
	strcpy(ne.id,ma_id);
	strcpy(train[num].id,ma_id);
	cpy(num);
	system("cls");
	print(inf[num]);
	printf("\n\t\t\t\t\t 增加成功!!\n");
	printf("\n\t\t\t\t\t 1-继续修改");
	printf("\n\t\t\t\t\t 2-返回车次管理界面");
	printf("\n\t\t\t\t\t 9-返回主界面"); 
	printf("\n\t\t\t\t\t 0-退出软件"); 
	do{
		printf("请输入："); 
		scanf("%d",&choice);
		if(choice==1) return 29;
		else if(choice==2) return 20;
		else if(choice==9) return 9;
		else if(choice==0) return 0;
		else printf("听话,按提示输哦！\n"); 
	}while(1);
}
int chang_train()
{
	int ok=0;
	do{
		ok=0;
		system("cls");
		header();
		if(my_num<1) my_num=10;
		for(int i=1;i<=my_num;i++){
			printf(Format_out,my_train[i].id,my_train[i].number,my_train[i].begin,my_train[i].end,m_Begin_time_out,m_End_time_out,my_train[i].price,my_train[i].remainder1,my_train[i].remainder2,my_train[i].remainder3);
		}
		ender();
		printf("\n\n请输入需要更改的车次序列号: ");
		char id[5];
		scanf("%s",id);
		int ok1=0;
		if(!chek(id)){
			do{
				ok1=0;
				printf("\n\t\t*---------------------* invalid intput,try again*-------------------------------*\n");
				scanf("%s",id);
				if(!chek(id)) ok1=1;
				
			}while(ok1);
		}
		int _id=str_to_int(id);
		system("cls");
		printf("\t\t\t\t\t You selected train infoemation\n\n");
		print(inf[_id]);
		printf("\n\t\t*---------------------------* You can choice *-------------------------------*\n");
		printf("\t\t*--- 1-车次 ----------*------- 2 检票口 -----------*----- 3- 出发时间-------*\n");
		printf("\t\t*--- 4-到达时间 ------*------- 5-出发地点 ---------*----- 6-到达地点 -------*\n");
		printf("\t\t*--- 7-特等票价 ------*------- 8-特等余票 ---------*----- 9-一等票价 -------*\n");
		printf("\t\t*--- 10-一等余票 -----*------- 11-二等票价 --------*----- 12-二等余票 ------*\n");
		printf("\t\t 0-结束程序\n");
		printf("\t\t 13-返回查询\n");
		printf("\t\t 14-返回车次管理界面\n");
		printf("\t\t 15-返回主界面\n"); 
		int ok2=0; 
		int c;
		do{
			ok2=0;
			printf("\n请输入选择: ");
			scanf("%d",&c);
			if(c==0) return 0;
			else if(c==13) return 2;
			else if(c==14) return 20;
			else if(c==15) return 9;
			else if(0<c&&c<=12) ok2=0;
			else ok2=1,printf("\n按要求输入，重输或退出(0): ");
		}while(ok2);
		if(c==1){
			printf("请输入更改后的车次：");
			scanf("%s",inf[_id].number);
		}
		else if(c==2){
			printf("请输入更改后的检票口：");
			scanf("%s",inf[_id].chek); 
		}
		else if(c==3){
			printf("请输入更改后的出发时间(年 月 日 时 分)：");
			int i=_id;
			struct time t;
			scanf("%d%d%d%d%d",&t.year,&t.month,&t.day,&t.h,&t.m);
			int ok=0;
			do{
				ok=0;
				if(!chek_time(t)){
					ok=1;
					printf("\n你输入时间的不合法，请从新输入或返回(-1)");
					scanf("%d",&t.year);
					if(t.year==-1) return 20;
					scanf("%d%d%d%d",&t.month,&t.day,&t.h,&t.m);
					ok=1;
				}
				int ck=chek_t(t,I_et);
				if(!ok&&ck){
					int cho; 
					if(ck==1){
						printf("\n出发时间不能晚于到达时间，请重新输入或返回(-1)");
						scanf("%d",&t.year);
						if(t.year==-1) return 20;
						scanf("%d%d%d%d",&t.month,&t.day,&t.h,&t.m);
						ok=1;
					}
					else if(ck==2) {
						printf("\n与到达时间间隔过大,确认修改吗(1-是,2-重输,0-返回): ");
						scanf("%d",&cho);
						if(cho==1) ok=0;
						else if(cho==2){
							printf("\n请输入: "); 
							scanf("%d%d%d%d%d",&t.year,&t.month,&t.day,&t.h,&t.m);
							ok=1;
						}
						else return 20;
					}
					else if(ck==3) {
						printf("\n与到达时间间隔过小,确认修改吗(1-是,2-重输,0-返回): ");
						scanf("%d",&cho);
						if(cho==1) ok=0;
						else if(cho==2){
							printf("\n请输入: "); 
							scanf("%d%d%d%d%d",&t.year,&t.month,&t.day,&t.h,&t.m);
							ok=1;
						}
						else return 20;
					}
				}
			}while(ok); 
			I_bt=t;
		}
		else if(c==4){
			printf("请输入更改后的到达时间(年 月 日 时 分)：");
			int i=_id;
			struct time t;
			scanf("%d%d%d%d%d",&t.year,&t.month,&t.day,&t.h,&t.m); 
			int ok=0;
			do{
				ok=0;
				if(!chek_time(t)){
					ok=1;
					printf("\n你输入时间的不合法，请从新输入或返回(-1)");
					scanf("%d",&t.year);
					if(t.year==-1) return 20;
					scanf("%d%d%d%d",&t.month,&t.day,&t.h,&t.m);
				}
				int ck=chek_t(I_bt,t);
				if(!ok&&ck){
					int cho; 
					if(ck==1){
						printf("\n到达时间不早能于出发时间，请重新输入或返回(-1)");
						scanf("%d",&t.year);
						if(t.year==-1) return 20;
						scanf("%d%d%d%d",&t.month,&t.day,&t.h,&t.m);
						ok=1;
					}
					else if(ck==2) {
						printf("\n与出发时间间隔过大,确认修改吗(1-是,2-重输,0-返回): ");
						scanf("%d",&cho);
						if(cho==1) ok=0;
						else if(cho==2){
							printf("\n请输入: "); 
							scanf("%d%d%d%d%d",&t.year,&t.month,&t.day,&t.h,&t.m);
							ok=1;
						}
						else return 20;
					}
					else if(ck==3) {
						printf("\n与出发时间间隔过小,确认修改吗(1-是,2-重输,0-返回): ");
						scanf("%d",&cho);
						if(cho==1) ok=0;
						else if(cho==2){
							printf("\n请输入: "); 
							scanf("%d%d%d%d%d",&t.year,&t.month,&t.day,&t.h,&t.m);
							ok=1;
						}
						else return 20;
					}
				}
			}while(ok);
			I_et=t;
			
		}
		else if(c==5){
			printf("请输入更改后的出发地点：");
			char s[50];
			scanf("%s",s);
			int ok=0; 
			do{
				ok=0;
				if(!strcmp(inf[_id].end,s)){
					printf("\n不能与到达地点相同，请从新输入或返回(0): ");
					scanf("%s",s);
					if(!strcmp(s,"0")) return 20;
					ok=1;
				}
			}while(ok);
			strcpy(inf[_id].begin,s); 
		}
		else if(c==6){
			printf("请输入更改后的到达地点：");
			char s[50];
			scanf("%s",s); 
			int ok=0; 
			do{
				ok=0;
				if(!strcmp(inf[_id].begin,s)){
					printf("\n不能与出发地点相同，请从新输入或返回(0): ");
					scanf("%s",s);
					if(!strcmp(s,"0")) return 20;
					ok=1;
				}
			}while(ok);
			strcpy(inf[_id].end,s);
		}
		else if(c==7){
			printf("请输入更改后的票价：");
			int p;
			scanf("%d",&p);
			int ok=0;
			do{
				ok=0;
				if(p<=0){
					printf("\n你输入的票价不合法请重新输入或返回(0): ");
					scanf("%d",&p);
					if(p==0) return 20;
					ok=1;
				}
			}while(ok);
			inf[_id].price1=p;
		}
		else if(c==8){
			printf("请输入更改后的余票："); 
			int r;
			scanf("%d",&r);
			int ok=0;
			do{
				ok=0;
				if(r<0){
					printf("\n你输入不合法，请从新输入或返回(-1): ");
					scanf("%d",&r);
					if(r==-1) return 20;
					ok=1;
				}
			}while(ok);
			inf[_id].remainder1=r;
		}
		else if(c==9){
			printf("请输入更改后的票价："); 
			int p;
			scanf("%d",&p);
			int ok=0;
			do{
				ok=0;
				if(p<=0){
					printf("\n你输入的票价不合法请重新输入或返回(0): ");
					scanf("%d",&p);
					if(p==0) return 20;
					ok=1;
				}
			}while(ok);
			inf[_id].price2=p;
		}
		else if(c==10){
			printf("请输入更改后的余票："); 
			int r;
			scanf("%d",&r);
			int ok=0;
			do{
				ok=0;
				if(r<0){
					printf("\n你输入不合法，请从新输入或返回(-1): ");
					scanf("%d",&r);
					if(r==-1) return 20;
					ok=1;
				}
			}while(ok);
			inf[_id].remainder2=r;
		}
		else if(c==11){
			printf("请输入更改后的票价：");
			int p;
			scanf("%d",&p);
			int ok=0;
			do{
				ok=0;
				if(p<=0){
					printf("\n你输入的票价不合法请重新输入或返回(0): ");
					scanf("%d",&p);
					if(p==0) return 20;
					ok=1;
				}
			}while(ok);
			inf[_id].price3=p;
		}
		else if(c==12){
			printf("\n请输入更改后的余票：");
			int r;
			scanf("%d",&r);
			int ok=0;
			do{
				ok=0;
				if(r<0){
					printf("\n你输入不合法，请从新输入或返回(-1): ");
					scanf("%d",&r);
					if(r==-1) return 20;
					ok=1;
				}
			}while(ok);
			inf[_id].remainder1=r;
		}
		else {
			printf("\n输入不合法，请重新输入或退出(0): ");
			scanf("%d",&c);
			if(c==0) ok=0;
			else ok=1;
		}
		if(1<=c&&c<=12){
			for(int i=1;i<=my_num;i++){
				if(_id==str_to_int(train[i].id)) cp(i,_id);
			}
			system("cls");
			printf("\t\t\t\t\t\t 恭喜你，修改成功\n\n");
			print(inf[_id]);
			printf("\n\t\t\t\t\t 修改成功!!\n");
			printf("\n\t\t\t\t\t 1-继续修改");
			printf("\n\t\t\t\t\t 2-返回车次管理界面");
			printf("\n\t\t\t\t\t 9-返回主界面"); 
			printf("\n\t\t\t\t\t 0-退出软件");
			int choice; 
			do{
				printf("请输入："); 
				scanf("%d",&choice);
				if(choice==1) return 28;
				else if(choice==2) return 20;
				else if(choice==9) return 9;
				else if(choice==0) return 0;
				else printf("听话,按提示输哦！\n");
			}while(1);
		}
	}while(ok);
	return 20;
}
int del_train()
{
	int ok=0;
	char id[5];
	do{
		system("cls");
		header();
		if(my_num<1) my_num=10;
		for(int i=1;i<=my_num;i++){
			printf(Format_out,my_train[i].id,my_train[i].number,my_train[i].begin,my_train[i].end,m_Begin_time_out,m_End_time_out,my_train[i].price,my_train[i].remainder1,my_train[i].remainder2,my_train[i].remainder3);
		}
		ender();
		printf("亲爱的管理员你好："); 
		printf("\n请输入您需要删除的车次序列号：");
		scanf("%s",id);
		if(!chek(id)){
			printf("\n序列号错误请从新输入：");
			scanf("%s",id);
			if(!chek(id)) ok=1;
			else ok=0; 
		}
		else ok=0; 
	}while(ok);
	printf("\n你确定要删除%s号列车吗(1-Y,0-N)？",id);
	int cho;
	scanf("%d",&cho);
	if(cho==1){
		int _id=str_to_int(id);
		sort(train+1,train+1+num,cmp6);
		for(int i=_id;i<num;i++){
			int id_=str_to_int(train[i+1].id);
			id_--;
			int_to_str(train[i+1].id,id_);
			strcpy(inf[i+1].id,train[i+1].id);
			train[i]=train[i+1];
			inf[i]=inf[i+1];
		}
		num--;
		max_id--;
		int_to_str(ma_id,max_id);
		for(int i=1;i<=10;i++) my_train[i]=train[i];
		printf("\n\t\t\t\t\t 删除成功!!\n");
		printf("\n\t\t\t\t\t 1-继续删除");
		printf("\n\t\t\t\t\t 2-返回车次管理界面");
		printf("\n\t\t\t\t\t 3-前往车票查询界面"); 
		printf("\n\t\t\t\t\t 9-返回主界面"); 
		printf("\n\t\t\t\t\t 0-退出软件");
		int choice; 
		do{
			printf("\n请输入："); 
			scanf("%d",&choice);
			if(choice==1) return 27;
			else if(choice==3) return 2; 
			else if(choice==2) return 20;
			else if(choice==9) return 9;
			else if(choice==0) return 0;
			else printf("听话,按提示输哦！\n");
		}while(1);
	}
	return 9;
}
/*void admin_head(int n)
{
	printf("\n*************************--Dear admin , hello--*******************************\n");
	printf("\n****************************-- 1-add train --*********************************\n");
	printf("\n**************************-- 2-chang train --*********************************\n");
	printf("\n**************************-- 3-delete train --********************************\n");
	printf("\n****************************-- 0-go back --***********************************\n");
	if(!n) printf("\nPlease input the choice: ");
	else printf("\nThe inpur error,please try again: ");
}

int admin_train()
{
	admin_head(0);
	int choice,ok=0,ret=9;
	do{
		ok=0;
		scanf("%d",&choice);
		if(choice==0){
			ret=9;
		}
		else if(choice==1){
			ret=add();
		}
		else if(choice==2){
			ret=chang();
			sort(train+1,train+num+1,cmp6);
			for(int i;i<=num;i++) cpy(i);
		}
		else if(choice==3){
			ret=del();
		}
		else{
			ok=1;
			system("cls");
			admin_head(1);
		}
	}while(ok);
	return ret;
}
*/
#endif
