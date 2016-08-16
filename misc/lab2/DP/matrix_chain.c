#include <stdio.h>
#include <limits.h>

int matrix_chain(int p[], int n);
void print_opt_paren(int r, int c, int s[][c], int i, int j);

int main()
{
	int n, i, res;
	
	scanf("%d", &n);
	
	int p[n];
	
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	
	res = matrix_chain(p, n);
	printf("\n%d\n", res);
}

int matrix_chain(int p[], int n)
{
	int i, j, k, l, q;
	
	int m[n][n];
	int s[n][n+1];
		
	for (i = 1; i < n; i++) {
		m[i][i] = 0;
	}
	for (i = 1; i < n; i++) {
		for(j=1;j<=n;j++)
		s[i][j] = 0;
	}
	
	for (l = 2; l < n; l++) {
		for (i = 1; i <= n-l+1; i++) {
			j = i+l-1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j-1; k++) {
				q = m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if (q < m[i][j]) {
 					m[i][j] = q;
 					s[i][j] = k;
				}
			}
		}
	}
	
	/*for (i = 1; i <= n-1; i++) {
		for (j = 2; j <= n; j++) {
			if(s[i][j]==0) printf("  ");
			else printf("%d ", s[i][j]);
		}
		printf("\n");
	}*/
	print_opt_paren(n, n+1, s, 1, n-1);
	
	return m[1][n-1];
}

void print_opt_paren(int r, int c, int s[][c], int i, int j)
{
//	if (i == r || j == c)
//		return;
	if (i == j)
		printf("A%d", i);
	else {
		printf("(");
		print_opt_paren(r, c, s, i, s[i][j]);
		print_opt_paren(r, c, s, s[i][j]+1, j);
		printf(")"); 
	}
}
