#include <iostream>

using namespace std;

bool subset_sum(int a[], int n, int sum);

int main()
{
	int n, i, sum;
	scanf("%d", &n);
	int a[n];
	
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &sum);
	
	if(subset_sum(a, n, sum)) 
		printf("YES\n");
	else 
		printf("NO\n");	
}

bool subset_sum(int a[], int n, int sum)
{
	int i, j;
	int s[sum+1][n+1];
	
	for (i = 0; i <= n; i++) {
		s[0][i] = true;
	}
	for (i = 1; i <= sum; i++) {
		s[i][0] = false;
	}
	
	for (i = 1; i <= sum; i++) {
		for (j = 1; j <= n; j++) {
			s[i][j] = s[i][j-1];
			
			if (i >= a[j-1]) {
				s[i][j] = (s[i][j-1]) || (s[i-a[j-1]][j-1]);
			}
		}
	}
	
	return s[sum][n];
}
