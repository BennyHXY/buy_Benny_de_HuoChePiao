#ifndef My_function_H
#define My_function_H

#include <stdio.h>
#include <string.h>
#include "my_struct.h" 

void header()
{
	printf("*-------*-------*-----------*-----------*--------------------*--------------------*--------*--------------------------*\n");
	printf("|序列号 |车次   |  出发地   | 目的地    |    出发时间        |     到达时间       |最低票价|          剩余票          |\n");
	printf("*-------*-------*-----------*-----------*--------------------*--------------------*--------*--------------------------*\n");
}
void ender()
{
	printf("*-------*-------*-----------*-----------*--------------------*--------------------*--------*--------------------------*\n");
}
int str_to_int(char str[])
{
	int re=0;
	int n=strlen(str);
	for(int i=0;i<n;i++){
		re=re*10+(str[i]-'0');
	}
	return re;
}
void int_to_str(char str[],int n)
{
	int i=3;
	while(i){
		str[--i] = ((n%10)+'0');
		n/=10;
	}
	str[3]='\0';
}

int chek_time(struct time t)
{
	int da[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(t.year<=999||t.year>10000) return 0;
	if(t.month<=0||t.month>12) return 0;
	if(t.day<=0||t.day>da[t.month]) return 0;
	if(t.h<=0||t.h>24) return 0;
	if(t.m<=0||t.m>60) return 0;
	return 1;
} 



#endif
