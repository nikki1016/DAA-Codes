#include <iostream>

using namespace std;

//void display(int a[], int n);
 
int main()
{
	int n, i, key, j, ctr = 0;
	scanf("%d", &n);
	int a[n];
	
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	//display(a, n);
	for (j = 1; j < n; j++) {
		key = a[j];
		
		i = j-1;
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			ctr++;
			i = i-1;
		}
		a[i+1] = key;
	}
	printf("%d\n", ctr);
//	display(a, n);
}

/*void display(int a[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}*/
