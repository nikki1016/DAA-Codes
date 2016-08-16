#include <iostream>
#include <string.h>

using namespace std;

char x[1000];
char y[1000];
char z[1000];
//char lc[1000];
char a[100][1000];
int c[100][100][100];
char b[100][100][100];
int k;

void print_lcs(char x[], int i, int j,int k);
int lcs(char x[], char y[],char z[]);

int main()
{	int n,i;
//	scanf("%d",&n);

	scanf("%s", x);
	scanf("%s", y);
	scanf("%s", z);
	int l = lcs(x,y,z);
//	printf("%s\n",lc);
//	l=lcs(lc, a[2]);
//	printf("%s\n",lc);
/*	for(i=2;i<n;i++){
		l = lcs(lc,a[i]);
	}*/
}

int lcs(char x[], char y[],char z[])
{
	int m, n, i, j,k,l;
	m = strlen(x);
	n = strlen(y);
	l = strlen(z);
	
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			for(k=0;k<=l;k++){
				if (i == 0 || j == 0|| k ==0)
				c[i][j][k] = 0;
			else if (x[i-1] == y[j-1]&& x[i-1] == z[k-1]) {
				c[i][j][k] = c[i-1][j-1][k-1]+1;
				b[i][j][k] = 'd';
			}
			else if (c[i-1][j][k] >= c[i][j-1][k] && c[i-1][j][k] >= c[i][j][k-1]) {
				c[i][j][k] = c[i-1][j][k];
				b[i][j][k] = 'u';					
			}
			else if (c[i][j-1][k] >= c[i-1][j][k] && c[i][j-1][k] >= c[i][j][k-1]) {
				c[i][j][k] = c[i][j-1][k];
				b[i][j][k] = 's';
			}
			else if (c[i][j][k-1] >= c[i-1][j][k] && c[i][j][k-1] >= c[i][j-1][k]) {
				c[i][j][k] = c[i][j][k-1];
				b[i][j][k] = 't';
			}	
			}
		}
	}
	printf("%d\n", c[m][n][l]);
	k = 0;
	print_lcs(x, m, n, l);
//	printf("\n");
	//lc[c[m][n][l]] = '\0';
//	return c[m][n];
}

void print_lcs(char x[], int i, int j,int k)
{
	if (i == 0|| j == 0|| k == 0)
		return;
	
	if ( b[i][j][k] == 'd' ) {
		print_lcs(x, i-1, j-1,k-1);
		printf("%c", x[i-1]);
	//	lc[k++] = x[i-1];
	}
	else if(b[i][j][k] == 'u') {
		print_lcs(x, i-1, j,k);
	}
	else if(b[i][j][k] == 's'){
		print_lcs(x, i, j-1,k);
	}
	else if(b[i][j][k] == 't'){
		print_lcs(x, i, j,k-1);
	}
}

