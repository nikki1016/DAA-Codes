#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<stdlib.h>
int main() {
	int n;
	scanf("%d",&n);
	int i,arr[n];
	for(i=0;i<n;i++) {
		arr[i]=rand()%100+1;
		printf("%d\t",arr[i]);
	}
	int lis[n];
	for(i=0;i<n;i++) {
		lis[i]=1;
	}
	int j;
	for(i=1;i<n;i++) {
		for(j=0;j<n;j++) {
			if(arr[i]>arr[j] && lis[i]<lis[j]+1) {
				lis[i]=lis[j]+1;
			}
		}
	}
	int max=INT_MIN;
	for(i=0;i<n;i++){
		if(max<lis[i]){
			max=lis[i];
		}	
	}
	printf("\n%d\n",max);
	return 0;
}
