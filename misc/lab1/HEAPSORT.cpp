#include <stdio.h>
#include <math.h>

int heap_size;
void display(int a[], int n);
void max_heapify(int a[], int i);
void build_heap(int a[], int n);
void heapsort(int a[], int n);
int left(int i);
int right(int i);
int parent(int i);

int main() {
	int i, length;
	printf("Enter the no of elements in the array: ");
	scanf("%d", &length);
	heap_size = length;
	
	int a[length+1];
	
	printf("Enter the elements: \n");

	for (i = 1; i <= length; i++) {
		scanf("%d", &a[i]);
	}

	
	build_heap(a, length+1);
	printf("The heap built from the input array: \n");
	display(a, length+1);
	
	heapsort(a, length+1);
	printf("The sorted array: \n");
	display(a, length+1);
	
	return 0;
}

void build_heap(int a[], int length)
{
	int i;
	heap_size = length-1;
	for (i = floor(length-1/2); i >= 1; i--) {
		max_heapify(a,i);
	}
}

void max_heapify(int a[], int i)
{
	int l, r, largest, temp;
	
	l = left(i);
	r = right(i);
	
	if (l <= heap_size && a[l] > a[i])
	largest = l;
	else 
	largest = i;
	
	if (r <= heap_size && a[r] > a[largest])
	largest = r;
	
	if (largest != i) {
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		max_heapify(a, largest);
	}
	
	//return ;
}

void heapsort(int a[], int length)
{
	int i, temp;
	build_heap(a, length);
	for (i = length-1; i >= 2; i--) {
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		heap_size--;
		max_heapify(a, 1);
	}
}

int parent(int i){
	return (floor(i/2));
}

int left(int i) {
	return (2*i);
}

int right(int i) {
	return (2*i + 1);
}

void display(int a[], int length) {
	int i;
	
	for(i = 1; i <= length-1; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return ;
}
