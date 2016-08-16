#include <stdio.h>

void quick(int a[], int low, int up);
//int partition(int a[], int low, int up);
int partition_cormen(int a[], int low, int up);

int main()
{
	int i, n, num;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	FILE *fp;
	fp = fopen("numbers.txt", "w");

	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		fprintf(fp,"%d ",num);//putw(num, fp);
	}
	fclose(fp);
	
	fp = fopen("numbers.txt", "r");
	i = 0;
	int a[n];
	do {
		fscanf(fp, "%d ", &a[i++]);
		
	}while (!feof(fp));
	
	fclose(fp);
	
	/*for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}*/
	
	quick(a, 0, n-1);
	
	fp = fopen("numbers.txt", "w");
	for (i = 0; i < n; i++) {
		fprintf(fp,"%d ",a[i]);//putw(num, fp);
	}
	
	fclose(fp);
	
	return 0;
}

void quick(int a[], int low, int up) {

	int pivloc;
	if (low >= up)
		return;
	pivloc = partition_cormen(a, low, up);
	quick(a, low, pivloc-1);
	quick(a, pivloc+1, up);
	//display(a, low, up);
}

void display(int a[], int low, int up) {
	int i;
	
	for (i = low; i <= up; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

/*int partition(int a[], int low, int up) {

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
}*/

int partition_cormen(int a[], int low, int up)
{	
	int i, j, pivot, temp;
	pivot = a[up];
	i = low-1;
	
	for (j = low; j <= (up-1); j++) {
		if (a[j] <= pivot) {
			i = i+1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[up] = a[i+1];
	a[i+1] = pivot;
	
	return (i+1);
}
