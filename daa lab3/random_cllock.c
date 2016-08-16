#include <stdio.h>
#include <time.h>

int heap_size;
void display(int a[], int n);
void max_heapify(int a[], int i);
void build_heap(int a[], int n);
void heapsort(int a[], int n);
int left(int i);
int right(int i);
int parent(int i);
void quick_sort(int a[], int low, int up, int x);
int partition(int a[], int low, int up);

int a[2000000];
int b[2000000];
int c[2000000];
int d[2000000];
int e[2000000];

int main()
{
	int n, i, num, k;
	int nc[] = {2, 16, 64, 128, 8192};
	clock_t beg;
	clock_t end;
	float tm;
	time_t second;
	FILE *fp;
	fp = fopen("lab.dat", "w");
	scanf("%d", &n);

	if (n == 100000) {
		srand((unsigned)(&second));
		for (i = 0; i < n; i++) {
			a[i] = rand()%1000 + 1;
			b[i] = a[i];
			c[i] = a[i];
			d[i] = a[i];
			e[i] = a[i];

		}
	}
	else {
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
			c[i] = a[i];
			d[i] = a[i];
			e[i] = a[i];

		}
	}

	beg = clock();
	quick_sort(a, 0, n-1, nc[0]);
	end = clock();

	tm = (float)(end - beg)/CLOCKS_PER_SEC;

	printf("Time: %9.5f sec\n", tm);
	printf("nc = %d\n", nc[0]);
	fprintf(fp, "%d %9.5f", nc[0], tm);

	for (k = 0; k < n; k++) {
		printf("%d\n", a[k]);
	}

	beg = clock();
	quick_sort(b, 0,  n-1, nc[1]);
	end = clock();

	tm = (float)(end - beg)/CLOCKS_PER_SEC;

	printf("Time: %9.5f sec\n", tm);
	printf("nc = %d\n", nc[1]);
	  fprintf(fp, "%d %9.5f", nc[1], tm);


	for (k = 0; k < n; k++) {
		printf("%d\n", b[k]);
	}

	beg = clock();
	quick_sort(c,0,  n-1, nc[2]);
	end = clock();

	tm = (float)(end - beg)/CLOCKS_PER_SEC;

	printf("Time: %9.5f sec\n", tm);
	printf("nc = %d\n", nc[2]);
	fprintf(fp, "%d %9.5f", nc[2], tm);


	for (k = 0; k < n; k++) {
		printf("%d\n", c[k]);
	}

	beg = clock();
	quick_sort(d, 0, n-1, nc[3]);
	end = clock();

	tm = (float)(end - beg)/CLOCKS_PER_SEC;

	printf("Time: %9.5f sec\n", tm);
	printf("nc = %d\n", nc[3]);
	fprintf(fp, "%d %9.5f", nc[3], tm);


	for (k = 0; k < n; k++) {
		printf("%d\n", d[k]);
	}

	beg = clock();
	quick_sort(e,0, n-1, nc[4]);
	end = clock();

	tm = (float)(end - beg)/CLOCKS_PER_SEC;

	printf("Time: %9.5f sec\n", tm);
	printf("nc = %d\n", nc[4]);
	fprintf(fp, "%d %9.5f", nc[4], tm);


	for (k = 0; k < n; k++) {
		printf("%d\n", e[k]);
	}
	fclose(fp);


	return 0;
}

void quick_sort(int a[], int low, int up, int nc) {

	int pivloc;
	if (low >= up)
		return;

	pivloc = partition(a, low, up);

	if ((pivloc - low - 1) > nc)
		quick_sort(a, low, pivloc-1, nc);
	else
		heapsort(a, (pivloc-low));
	if ((up - pivloc - 1) > nc)
		quick_sort(a, pivloc+1, up, nc);
	else
		heapsort(a, (up-pivloc));
}

int partition(int a[], int low, int up) {

	int i, j, pivot, t;
	i = low+1;
	j = up;
	pivot = a[low];
	while (i <= j) {
		while ((a[i] < pivot) && (i < up))
			i++;
		while (a[j] > pivot) 
			j--;
		if (i < j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
		else 
			i++;
	}
	a[low] = a[j];
	a[j] = pivot;
	return j;
}

void build_heap(int a[], int length)
{
	int i;
	heap_size = length;
	for (i = (length/2); i >= 1; i--) {
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
	for (i = length; i >= 2; i--) {
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		heap_size--;
		max_heapify(a, 1);
	}
}

int parent(int i){
	return ((i/2));
}

int left(int i) {
	return (2*i);
}

int right(int i) {
	return (2*i + 1);
}



