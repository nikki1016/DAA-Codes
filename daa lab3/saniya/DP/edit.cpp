#include <iostream>
#include <string.h>
#define del_cost 1
#define ins_cost 1
#define rep_cost 1
using namespace std;

int edit_distance(char x[], char y[]);

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
	int res;
	char x[100];
	char y[100];
	
	scanf("%s %s", x, y);
	
	res = edit_distance(x, y);
	
	printf("%d\n", res);
	
	return 0;
}

int edit_distance(char x[], char y[])
{
	int m, n, i, j, left, up, corner;
	m = strlen(x)+1;
	n = strlen(y)+1;
	
	int t[m][n];
	
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			t[i][j] = -1;
		}
	}
	
	for (i = 0; i < m; i++) {
		t[i][0] = i;
	}
	
	for (j = 0; j < n; j++) {
		t[0][j] = j;
	}
	//E(i, j) = min( [E(i-1, j) + D], [E(i, j-1) + I],  [E(i-1, j-1) + R if i,j characters are not same] )
	
	for (i = 1; i < m; i++) {
		for (j = 1; j < n; j++) {
			left = t[i][j-1];
			left = left+ ins_cost;
			
			up = t[i-1][j];
			up = up+del_cost;
			
			corner = t[i-1][j-1];
			corner = corner + (x[i-1]== y[j-1] ? 0:rep_cost);
			
			t[i][j] = minimum(left, up, corner);
		}
	}
	
	/*for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}*/
	
	return t[m-1][n-1];
	
}
