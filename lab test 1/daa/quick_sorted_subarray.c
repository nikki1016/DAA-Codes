#include <stdio.h>

int quicksort(int a[], int n);

int a[1000];

int main() {

	int n, i;
	scanf("%d", &n);
	
	int a[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	quicksort(a,n);
		
	return 0;
}

int quicksort(int a[], int n)
{
	int pivot, l, r, i, j, k;
	int left[1000];
	int right[1000];
	
	if (n <= 1)
		return n;
		
	pivot = a[0];
	j = 0;
	k = 0;
	for (i = 1; i < n; i++) {
		if (a[i] <= pivot) {
			left[j++] = a[i];
		}
		else 
			right[k++] = a[i];
	}
	
	l = quicksort(left, j);
    r = quicksort(right, k);
    
	left[j++] = pivot;
    for (i = 0; i < k; i++) 
        left[j++] = right[i];

    for (i = 0; i < j; i++) {
    	a[i] = left[i];
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return l;

}


