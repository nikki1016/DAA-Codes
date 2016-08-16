#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int heap_size = 0;
void build_heap(int a[], int length);
void max_heapify(int a[], int i);
int heap_maximum(int a[]);
int heap_extract_max(int a[]);
void heap_increase_key(int a[], int i, int key); 
void insert(int a[], int key);
int parent(int i);
int left(int i);
int right(int i);
void display(int a[]);

int main() {
	int n, i, ch, key;
	printf("Enter the no of keys in the array: ");
	scanf("%d", &n);
	int a[n];
	
	printf("Enter the key associated with each element: \n");
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	do {
		printf(" 1. Build Heap\n 2. Heap Maximum\n 3. Heap Extract Max\n 4. Heap Increase key\n 5. Insert in the heap\n 6. Display\n 7. Exit\n");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1:
				build_heap(a, n);
				printf("The heap built: \n");
				display(a);
				break;
			case 2:
				printf("The maximun element of the heap is: %d\n", heap_maximum(a));
				break;
			case 3:
				printf("The maximun element of the heap is: %d\n", heap_extract_max(a));
				break;
			case 4:
				printf("Enter the index whose key is to be increased: ");
				scanf("%d", &i);
				printf("Enter the new key: ");
				scanf("%d", &key);
				heap_increase_key(a, i, key);
				break;
			case 5:
				printf("Enter the key to be inserted: ");
				scanf("%d", &key);
				insert(a, key);
				break;
			case 6:
				display(a);
				break;
			case 7:
				exit(1);
				break;
			default:
				printf("Wrong Choice: ");
				break;			 
		}
		
	}while (ch != 7);
	
	return 0;
}

void build_heap(int a[], int length)
{
	int i;
	heap_size = length;
	for (i = floor(length/2); i >= 1; i--) {
		max_heapify(a, i);
	}
}

void max_heapify(int a[], int i) {
	int temp, l, r, largest;
	
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
}

int heap_maximum(int a[]) {
	return (a[1]);
}

int heap_extract_max(int a[]) {
	int max;
	
	if (heap_size < 1) {
		printf("Heap Underflow\n");
	}
	
	else {
		max = a[1];
		a[1] = a[heap_size];
		heap_size--; 
		max_heapify(a, 1);
	
		return max;
	}
}

void heap_increase_key(int a[], int i, int key) {
	
	int temp;
	
	if (key < a[i]) {
		printf("New key is smaller than the current key\n");
	}
	
	else 
	{
		a[i] = key;
	
		while (i > 1 && a[parent(i)] < a[i]) {
			temp = a[i];
			a[i] = a[parent(i)];
			a[parent(i)] = temp;
			i = parent(i);
		}
	}
	
	return;
}

void insert(int a[], int key) {
	
	heap_size++;
	a[heap_size] = -9999;
	heap_increase_key(a, heap_size, key);
}

int parent(int i) {
	return (floor(i/2));
}

int left(int i) {
	return 2*i;
}

int right(int i) {
	return (2*i + 1);
}

void display(int a[]) {
	
	int i;
	
	for (i = 1; i <= heap_size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

