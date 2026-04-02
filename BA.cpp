#include<stdio.h>
void show_welcome()
{
	FILE* file = fopen("banner.txt","r");
	char line[2000];
	
	printf("\n");
	
	while (fgets(line, 255, file) != NULL) {

		printf(" %s", line);
	}
    fclose(file);
}
int main()
{
	show_welcome();
	return 0;
}
