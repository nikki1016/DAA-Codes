#include <iostream>
#include <string.h>
#include <limits.h>
#include <ctype.h>

using namespace std;

char x[1000];
char y[1000];

int c[1000][1000];
char b[1000][1000];

void print_lcs(char x[], int i, int j);
void lcs(char x[], char y[]);

int main()
{
	int i;
	scanf("%s", x);
	scanf("%s", y);
	
	
	for (i = 0; i < strlen(x); i++) {
		if (isupper(x[i]))
			x[i] = tolower(x[i]);
	}
	for (i = 0; i < strlen(y); i++) {
		if (isupper(y[i]))
			y[i] = tolower(y[i]);
	}
	
	lcs(x, y);
}

void lcs(char x[], char y[])
{
	int m, n, i, j;
	m = strlen(x);
	n = strlen(y);
	
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				c[i][j] = 0;
			else if (x[i-1] == y[j-1]) {
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 'd';
			}
			else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 'u';					
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = 's';
			}
		}
	}
	printf("%d\n", c[m][n]);
	print_lcs(x, m, n);
	printf("\n");
}

void print_lcs(char x[], int i, int j)
{
	if (i == 0|| j == 0)
		return;
	
	if (b[i][j] == 'd') {
		print_lcs(x, i-1, j-1);
		printf("%c", x[i-1]);
	}
	else if(b[i][j] == 'u') {
		print_lcs(x, i-1, j);
	}
	else if(b[i][j] == 's'){
		print_lcs(x, i, j-1);
	}	
}

