#include <iostream>
#include <string.h>
#include <limits.h>
#include <ctype.h>

using namespace std;

char x[1000];
char y[1000];

int c[1000][1000];
char b[1000][1000];
int a[1000];
char str[1000];

void print_lcs(char x[], int i, int j, int k);
void lcs(char x[], char y[]);

int main()
{
	int n, i;
	scanf("%d", &n);
	
	char s[n][1000];
	
	for (i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	
	lcs(s[0], s[1]);
	for (i = 2; i < n; i++) {
		lcs(str, s[i]);
	}
	
	printf("LCS: %s\n", str);
	printf("LENGTH OF LCS: %d\n", strlen(str));
	
	return 0;
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
	print_lcs(x, m, n, 0);
	str[c[m][n]] = '\0';
	printf("\n");
}

void print_lcs(char x[], int i, int j, int k)
{
	if (i == 0|| j == 0)
		return;
	
	if (b[i][j] == 'd') {
		print_lcs(x, i-1, j-1, k);
		str[k++] = x[i-1];
	}
	else if(b[i][j] == 'u') {
		print_lcs(x, i-1, j, k);
	}
	else if(b[i][j] == 's'){
		print_lcs(x, i, j-1, k);
	}	
}

