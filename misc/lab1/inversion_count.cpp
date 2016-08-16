#include <stdio.h>

int a[1000];
int temp[1000];
	
int merge_sort(int a[], int low, int up);
int merge(int a[], int temp[], int low1, int up1, int low2, int up2);
void copy(int a[], int temp[], int low, int up);
void display(int a[], int low, int up);

int main()
{
	int i, MAX;
	scanf("%d", &MAX);
	

	for (i = 0; i < MAX; i++) {
		scanf("%d", &a[i]);
	}
	
	printf("Inversion Count: %d\n", merge_sort(a, 0, MAX-1));

	return 0;
}

int merge_sort(int a[], int low, int up) 
{
	int mid, inv_count = 0;

	if(low < up) {
		mid = (low+up)/2;
		inv_count = merge_sort(a, low, mid);
		inv_count += merge_sort(a, mid+1, up);
		inv_count += merge(a, temp, low, mid, mid+1, up);
		copy(a, temp, low, up);
	}
	return inv_count;
}

/*void display(int a[], int low, int up) {
	int i;
	
	for (i = low; i <= up; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}*/

int merge(int a[], int temp[], int low1, int up1, int low2, int up2 )
{
	int i, j, k, inv_count = 0;
	i = low1;
	j = low2;
	k = low1;

	while ((i <=up1) && (j <=up2)) {
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else {
			temp[k++] = a[j++];
			inv_count = inv_count + (low2 - i);
		}
	}
	while (i <=up1)
		temp[k++] = a[i++];
	while (j <=up2) 
		temp[k++] = a[j++];
		
	return inv_count;
}

void copy (int a[], int temp[], int low, int up)
{
	int i;
	for (i = low; i <= up; i++) {
		a[i] = temp[i];
	}
}


