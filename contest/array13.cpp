#include <iostream>
#include<algorithm>
#include<climits>

using namespace std;
long long int a[10005];
long long int b[10005];
long long int n;

void copy1(){
	long long int i;
	for(i=0;i<=n;i++)
	b[i]=a[i];
}
long long int partition(long long int arr[], long long int l, long long int r, long long int k);

long long int findMedian(long long int arr[], long long int n)
{
    sort(arr, arr+n);
    return arr[n/2];   
}
 
long long int kthSmallest(long long int arr[], long long int l, long long int r, long long int k)
{
    
    if (k > 0 && k <= r - l + 1)
    {
        long long int n = r-l+1;
        long long int i, median[(n+4)/5]; 
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5); 
            i++;
        }  
        long long int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);
        long long int pos = partition(arr, l, r, medOfMed);
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1) 
            return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}
 
void swap(long long int *a, long long int *b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}
 
long long int partition(long long int arr[], long long int l, long long int r, long long int x)
{
    long long int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
    i = l;
    for (long long int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int main()
{
	long long int t;
	char ch[2];
	long long int p,q;
	scanf("%lld",&n);
	long long int i;
	a[0]=0;
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	scanf("%lld",&t);
	while(t--){
		scanf("%s",ch);
		if(ch[0]=='U'){
			scanf("%lld%lld",&p,&q);
			a[p]=q;
		}
		else if(ch[0]=='P'){
			scanf("%lld",&p);
			p = kthSmallest(a, 0, n, p+1);
			printf("%lld\n",p);		
		}
	}
return 0;
}
