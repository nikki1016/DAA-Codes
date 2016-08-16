#include <stdio.h>

#define MAX 10

void merge_sort(int arr[], int low, int up);
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2);
void copy (int arr[], int temp[], int low, int up);

int main()
{
	int i, n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);

	int arr[n+1];

	for (i = 0; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 1, n);

	printf("Sorted list:\n");

	for (i = 0; i <= n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

void merge_sort(int arr[], int low, int up)
{
	int mid;

	int temp[MAX];

	if (low < up ) {
		mid = (low+up)/2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, up);

		merge(arr, temp, low, mid, mid+1, up);

		copy(arr, temp, low, up);

	}

}

void merge(int arr[], int temp[], int low1, int up1, int low2, int up2)
{
	int i, j, k;
	i = low1;
	j = low2;
	k = low1;

	while ((i <= up1) && (j <= up2)) {
		if (arr[i] <= arr[j]) 
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= up1)
		temp[k++] = arr[i++];
	while (j <= up2) 
		temp[k++] = arr[j++];
}

void copy(int arr[], int temp[], int low, int up)
{
	int i;

	for (i = low; i <=up; i++) {
		 arr[i] = temp[i];
	 }
}



