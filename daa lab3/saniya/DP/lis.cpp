#include <iostream>

using namespace std;

int lis(int a[], int n);

int b[100];
int prev[100];
int k;

void print(int prev[], int a[], int n, int bestend);

int main()
{
	int n, i, max;
	scanf("%d", &n);
	int a[n];
	
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	//int a[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	//n = 9;
	max  = lis(a, n);
	printf("\nLength of LIS: %d\n", max);
	
	return 0;
}

int lis(int a[], int n)
{
	int l[n];
	int i, j, max, end = 0;
	k = 0;
	
	for (i = 0; i < n; i++) {
		l[i] = 1;
		prev[i] = -1;
	}
	
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (a[i] > a[j] && l[i]<l[j]+1) {
				l[i] = l[j]+1;
				prev[i] = j; 
			}
		}
	}
	
	max = l[0];
	for (i = 1; i <n; i++) {
		if (l[i] > max) {
			max = l[i];
			end = i;
		}
	}
	print(prev, a, n, end);
	return max;
}

void print(int prev[], int a[], int n, int end)
{
	int i, k;
	k = 1;
	i = end;
	b[0] = a[i];
	while (prev[i] != -1) {
		i = prev[i];
		b[k++] = a[i];
	}
	for (i = k-1; i >= 0; i--) {
		printf("%d ", b[i]);
	}
}
