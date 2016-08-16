#include <stdio.h>

int mcp(int r, int c, int a[][c], int m, int n);

int minimum(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else
		return c;		
}

int main()
{
	int r, c, i, j, m, n;
	scanf("%d %d", &r, &c);
	int a[r][c];
	
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	scanf("%d %d", &m, &n);
	
	printf("MCP: %d\n", mcp(r, c, a, m, n));
	
}

int mcp(int r, int c, int a[][c], int m, int n)
{
	int t[r][c];
	int i, j;
	
	t[0][0] = a[0][0];
	for (i = 1; i <= m; i++) {
		t[i][0] = t[i-1][0] + a[i][0];
	}
	
	for (j = 1; j <= n; j++) {
		t[0][j] = t[0][j-1] + a[0][j];
	}
	
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			t[i][j] = minimum(t[i-1][j-1], t[i][j-1], t[i-1][j]) + a[i][j];
		}
	}
	
	return t[m][n];
}
