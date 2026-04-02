#include "user_management.h"
#include <iostream>
#include <cstdio>

using namespace std;



void print_main_menu()
{
	FILE* file = fopen("banner.txt","r");
	char line[2000];
	while (fgets(line, 255, file) != NULL) {

		printf(" %s", line);
	}
    fclose(file);
	
	
	
	printf("\n\n\t ******************* 欢迎来到中国铁路  **********************\n");
	printf("\t|*			            			   *|\n");
	printf("\t|*			            			   *|\n");
	printf("\t|*			1.登录  			   *|\n");
	printf("\t|*			            			   *|\n");
	printf("\t|*			2.注册      		           *|\n");
	printf("\t|*			            			   *|\n");
	printf("\t|*			3.车票查询 		           *|\n");
	printf("\t|*			            			   *|\n");
	printf("\t|*			4.个人信息  		           *|\n");
	printf("\t|*			            			   *|\n");
	printf("\t|*			0.退出软件       	           *|\n");
	printf("\t|*			            			   *|\n");
	printf("\t|*			            			   *|\n");
	printf("\t ***********************************************************\n");
	
}

int home_page()
{
	print_main_menu();
	printf("\n当前登录状态: %s\n", UserStatus[dU.st]);
	
	printf("\nplease choose(0~9)：");
	int opt;
	cin >> opt;
	while(1)
	{
		switch(opt)
		{
			case 1: return 1;	break;
			case 2: return 19;  break;
			case 3: return 2;	break;
			case 4: return 5;	break;
			case 0: return 0;	break;
			default: printf("??\n");
				printf("\nplease choose(0~9)：");
				cin >> opt;
				break;
		}
		
	}
	
//	printf("1");
	return opt;
}
