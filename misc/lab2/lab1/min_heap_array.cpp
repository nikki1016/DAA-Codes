#include <stdio.h>
#include <math.h>

int heap_size;
void display(int a[], int n);
void min_heapify(int a[], int i);
void build_heap(int a[], int n);
int heapsort(int a[], int n);
int left(int i);
int right(int i);
int parent(int i);

int main() {
	int i, length, num;
	printf("Enter the no of elements in the array: ");
	scanf("%d", &length);
	//heap_size = length;
	
	int a[length+1];
	
	printf("Enter the elements: \n");

	for (i = 1; i <= length; i++) {
		scanf("%d", &a[i]);
	}
	
	build_heap(a, length);
	printf("The heap built from the input array: \n");
	display(a, length);
	
	
	heap_size = length;
	for (i = 1; i <= length; i++) {
		num = heapsort(a, heap_size);
		printf("%d ", num);
	}
	//display(a, length);
	
	return 0;
}

void build_heap(int a[], int length)
{
	int i;
	heap_size = length;
	for (i = floor(length/2); i >= 1; i--) {
		min_heapify(a,i);
	}
}

void min_heapify(int a[], int i)
{
	int l, r, largest, temp;
	
	l = left(i);
	r = right(i);
	
	if (l <= heap_size && a[l] < a[i])
	largest = l;
	else 
	largest = i;
	
	if (r <= heap_size && a[r] < a[largest])
	largest = r;
	
	if (largest != i) {
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		min_heapify(a, largest);
	}
	
	//return ;
}

int heapsort(int a[], int heapsize)
{
	int max;
	
	if (heap_size < 1) {
		printf("Heap Underflow\n");
		return -1;
	}
	
	max = a[1];
	a[1] = a[heap_size];
	heap_size--;
	min_heapify(a, 1);
	
	return max;	
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
	
	for(i = 1; i <= length; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return ;
}
