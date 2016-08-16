#include <stdio.h>

int a[1000];
int temp[1000];
	
void merge_sort(int a[], int up);
void merge_pass(int a[], int temp[], int size, int n);
void merge(int a[], int temp[], int low1, int up1, int low2, int up2);
void copy(int a[], int temp[], int up);

int main()
{
	int i, MAX;
	scanf("%d", &MAX);
	

	for (i = 0; i < MAX; i++) {
		scanf("%d", &a[i]);
	}

	merge_sort(a, MAX);

	printf("Sorted list: \n");
	for (i = 0; i < MAX; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

void merge_sort(int a[], int n) 
{
	int size = 1;

	while (size < n) {
		merge_pass(a, temp, size, n);
		size = size*2;
	}
}

void merge_pass(int a[], int temp[], int size, int n)
{
	int i, low1, low2, up1, up2;
	low1 = 0;
	
	while (low1+size < n) {
		up1 = low1 + size-1;
		low2 = low1+size;
		up2 = low2+size-1;
		
		if (up2 >= n)
			up2 = n-1;
		merge(a, temp, low1, up1, low2, up2);
		low1 = up2+1;
	}
	for (i = low1; i <= n-1; i++) {
		temp[i] = a[i];
	}
	copy(a, temp, n);
}
void merge(int a[], int temp[], int low1, int up1, int low2, int up2 )
{
	int i, j, k;
	i = low1;
	j = low2;
	k = low1;

	while ((i <=up1) && (j <=up2)) {
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <=up1)
		temp[k++] = a[i++];
	while (j <=up2) 
		temp[k++] = a[j++];
}

void copy (int a[], int temp[], int up)
{
	int i;
	for (i = 0; i <= up; i++) {
		a[i] = temp[i];
	}
}


