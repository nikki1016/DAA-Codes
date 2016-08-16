#include <stdio.h>
int a[10005];
int b[10005];
int n;

void copy1(){
	int i;
	for(i=0;i<=n;i++)
	b[i]=a[i];
}
void merge_sort(int arr[], int low, int up);
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2);
void copy (int arr[], int temp[], int low, int up);

void merge_sort(int arr[], int low, int up)
{
	int mid;

	int temp[10005];

	if (low < up ) {
		mid = (low+up)/2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, up);

		merge(arr, temp, low, mid, mid+1, up);

		copy(arr, temp, low, up);

	}

}

void merge(int arr[], int temp[], int low1, int up1, int low2, int up2)
{
	int i, j, k;
	i = low1;
	j = low2;
	k = low1;

	while ((i <= up1) && (j <= up2)) {
		if (arr[i] <= arr[j]) 
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= up1)
		temp[k++] = arr[i++];
	while (j <= up2) 
		temp[k++] = arr[j++];
}

void copy(int arr[], int temp[], int low, int up)
{
	int i;

	for (i = low; i <=up; i++) {
		 arr[i] = temp[i];
	 }
}

int main()
{	int t;
	char ch[2];
	int p,q;
	scanf("%d",&n);
	int i;
	a[0]=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&t);
	while(t--){
		scanf("%s",ch);
		if(ch[0]=='U'){
			scanf("%d%d",&p,&q);
			a[p]=q;
		}
		else if(ch[0]=='P'){
			scanf("%d",&p);
			copy1();
			merge_sort(b,1,n);
			printf("%d\n",b[p]);		
		}
	}
return 0;
}
