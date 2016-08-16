#include<stdio.h>
#define MAX 50
void heap(int arr[], int size);
void build(int arr[], int size);
int del(int arr[], int *size);
void restore(int arr[], int i, int size);
void display(int arr[], int n);
int main()
{
	int i;
	int n; 
	int arr[MAX];
	printf("enter number of element\n");
	scanf("%d", &n);
	printf("elements are\n");
	for(i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	printf("entered list is\n");
	display(arr, n);
	heap(arr, n);
	printf("sorted list \n");
	display(arr, n);
	return 0;
}
void heap(int arr[], int size)
{
	int max;
	build(arr,size);
	printf("heap sort:\n");
	display(arr,size);
	while(size > 1){
		max = del(arr, &size);
		arr[size + 1] = max;
	}

}
int del(int arr[], int *size)
{
	int max = arr[1];
	arr[1] = arr[*size];
	(*size)--;
	restore(arr,1,*size);
	return max;
}
void build(int arr[], int size)
{
	int i;
	for(i = size/2; i >= 1; i--)
		restore(arr, i, size);
}
void restore(int arr[], int i, int size)
{
	int left = 2*i;
	int right = left + 1;
	int num = arr[i];
	while(right <= size){
		if(num >= arr[left] && num >= arr[right]){
			arr[i] = num;
			return;
		}
		else if(arr[left] > arr[right]){
			arr[i] = arr[left];
			i = left;
		}
		else 
		{
			arr[i] = arr[right];
			i = right;
		}
		left = 2*i;
		right = left + 1;
	}
	if(size == left && num < arr[left]){
		arr[i]= arr[left];
		i = left;
	}
	arr[i] = num;
}
void display(int arr[], int n)
{
	int i; 
	for(i = 1; i <= n; i++){
		printf("%d\n", arr[i]);
	}
}


