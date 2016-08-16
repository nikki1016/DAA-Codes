#include <stdio.h>
#include <conio.h>

int main()
{
	FILE *f;
	int a,b,c,d;
	f = fopen("abc.txt","r");
	do
	{
		a= getw(f);
		printf("%d\n",a);
	}while(!feof(f));
	fclose(f);	
//	printf("%d %d %d %d\n",a,b,c,d);
}
