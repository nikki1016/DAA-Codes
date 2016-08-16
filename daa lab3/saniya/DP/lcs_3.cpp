#include <iostream>
#include <string.h>
#include <limits.h>
#include <ctype.h>

using namespace std;

char x[100];
char y[100];
char z[100];

int c[100][100][100];
char b[100][100][100];

void print_lcs(char x[], int i, int j, int k);
void lcs(char x[], char y[], char z[]);

int main()
{
	int i;
	scanf("%s", x);
	scanf("%s", y);
	scanf("%s", z);
	
	
	for (i = 0; i < strlen(x); i++) {
		if (isupper(x[i]))
			x[i] = tolower(x[i]);
	}
	for (i = 0; i < strlen(y); i++) {
		if (isupper(y[i]))
			y[i] = tolower(y[i]);
	}
	for (i = 0; i < strlen(z); i++) {
		if (isupper(z[i]))
			z[i] = tolower(z[i]);
	}
	
	lcs(x, y, z);
}

void lcs(char x[], char y[], char z[])
{
	int m, n, i, j, o, k;
	m = strlen(x);
	n = strlen(y);
	o = strlen(z);
	
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			for (k = 0; k <= o; k++) {
				if (i == 0 || j == 0 || k == 0)
					c[i][j][k] = 0;
				else if (x[i-1] == y[j-1] && y[j-1] == z[k-1]) {
					c[i][j][k] = c[i-1][j-1][k-1]+1;
					b[i][j][k] = 'd';
				}
				else if (c[i-1][j][k] >= c[i][j-1][k] && c[i-1][j][k] >= c[i][j][k-1]  ) {
					c[i][j][k] = c[i-1][j][k];
					b[i][j][k] = 'u';					
				}
				else if (c[i][j-1][k] >= c[i-1][j][k] && c[i][j-1][k] >= c[i][j][k-1]  ) {
					c[i][j][k] = c[i][j-1][k];
					b[i][j][k] = 's';					
				}
				else if (c[i][j][k-1] >= c[i-1][j][k] && c[i][j][k-1] >= c[i][j-1][k]  ) {
					c[i][j][k] = c[i][j][k-1];
					b[i][j][k] = 't';					
				}
			}
		}
	}
	printf("%d\n", c[m][n][o]);
	print_lcs(x, m, n, o);
	printf("\n");
}

void print_lcs(char x[], int i, int j, int k)
{
	if (i == 0|| j == 0 || k == 0)
		return;
	
	if (b[i][j][k] == 'd') {
		print_lcs(x, i-1, j-1, k-1);
		printf("%c", x[i-1]);
	}
	else if(b[i][j][k] == 'u') {
		print_lcs(x, i-1, j, k);
	}
	else if(b[i][j][k] == 's'){
		print_lcs(x, i, j-1, k);
	}
	else if(b[i][j][k] == 't'){
		print_lcs(x, i, j, k-1);
	}		
}

