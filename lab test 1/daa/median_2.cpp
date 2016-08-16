#include <iostream>

using namespace std;

int A[100001];

int partitions(int low,int high)
{
    int j, p = low, r = high, x = A[r], i = p-1, temp;
    
    for(j=p;j<=r-1;j++)
    {
        if (A[j]<=x)
        {

            i=i+1;
            swap(A[i],A[j]);
        }
    }
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    
    return i+1;
}


int selection_algorithm(int left,int right,int kth)
{
    for(;;)
    {
        int pivotIndex=partitions(left,right);          //Select the Pivot Between Left and Right
        int len=pivotIndex-left+1;

        if(kth==len)
            return A[pivotIndex];

        else if(kth<len)
            right=pivotIndex-1;

        else
        {
            kth=kth-len;
            left=pivotIndex+1;
        }
    }
}

int main() {

	int n, i, ans;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	
	if (n%2 == 0) {
		ans = selection_algorithm(1, n, n/2);
		printf("%d\n", ans);
	}
	else {
		ans = selection_algorithm(1, n, (n+1)/2);
		printf("%d\n", ans);
	}
	
	return 0;
}
