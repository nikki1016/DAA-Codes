#include <iostream>
#include <string.h>

using namespace std;

char x[1000];
char y[1000];
char lc[1000];
char a[100][1000];
int c[1000][1000];
char b[1000][1000];
int k;

void print_lcs(char x[], int i, int j);
int lcs(char x[], char y[]);

int main()
{	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s", a[i]);
	}
//	scanf("%s", x);
//	scanf("%s", y);
	int l=lcs(a[0], a[1]);
	printf("%s\n",lc);
//	l=lcs(lc, a[2]);
//	printf("%s\n",lc);
/*	for(i=2;i<n;i++){
		l = lcs(lc,a[i]);
	}*/
	
}

int lcs(char x[], char y[])
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
	k = 0;
	print_lcs(x, m, n);
//	printf("\n");
	lc[c[m][n]] = '\0';
	return c[m][n];
}

void print_lcs(char x[], int i, int j)
{
	if (i == 0|| j == 0)
		return;
	
	if (b[i][j] == 'd') {
		print_lcs(x, i-1, j-1);
	//	printf("%c", x[i-1]);
		lc[k++] = x[i-1];
	}
	else if(b[i][j] == 'u') {
		print_lcs(x, i-1, j);
	}
	else if(b[i][j] == 's'){
		print_lcs(x, i, j-1);
	}	
}

