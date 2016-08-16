#include <iostream>
#include <string.h>

using namespace std;

int lc[101];
int a[101];
int b1[101];
int c[105][105];
char b[105][105];
int k;

void print_lcs(int x[], int, int);
int lcs(int x[], int y[],int,int);

int main()
{	int n,i,m,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d", &b1[i]);
	}
	
	int l=lcs(a,b1,n,m);
	for(i=0;i<l-1;i++){
		printf("%d ",lc[i]);
	}
	printf("%d\n",lc[l-1]);
}

int lcs(int x[], int y[],int m,int n)
{
	int i, j;
	
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
//	printf("%d\n", c[m][n]);
	k = 0;
	print_lcs(x, m, n);
//	printf("\n");
//	lc[c[m][n]] = '\0';
	return c[m][n];
}

void print_lcs(int x[], int i, int j)
{
	if (i == 0|| j == 0)
		return;
	
	if (b[i][j] == 'd') {
		print_lcs(x, i-1, j-1);
		lc[k++] = x[i-1];
	}
	else if(b[i][j] == 'u') {
		print_lcs(x, i-1, j);
	}
	else if(b[i][j] == 's'){
		print_lcs(x, i, j-1);
	}	
}

