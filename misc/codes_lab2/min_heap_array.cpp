#include<stdio.h>
void min_heapify(int arr[],int i,int size) {
	int l=2*i+1;
	int r=2*i+2;
	int smallest=i;
	//printf("i=%dl=%dr=%d\n",i,l,r);
	if(l<size && arr[l]<arr[smallest]) {
		smallest=l;
	//	printf("l=%d\n",l);
	}
	else
	smallest=i;
	//printf("smallest l=%d\n",smallest);
	if(r<size && arr[r]<arr[smallest]) {
		smallest=r;
	//	printf("r=%d\n",r);
	}
	//printf("smallest r=%d\n",smallest);
	if(smallest!=i) {
		int t=arr[smallest];
		arr[smallest]=arr[i];
		arr[i]=t;
		min_heapify(arr,smallest,size);
	}
}
void build_heap(int arr[],int low,int up,int size) {
	int i;
	for(i=(size)/2;i>=low;i--) {
		min_heapify(arr,i,size);
	}
}
int extract_min(int arr[],int low,int up,int size) {
	build_heap(arr,low,up,size);
	int t=arr[0];
	arr[0]=arr[size-1];
	size--;
	min_heapify(arr,0,size);
	return t;
}
int main() {
	int i,n;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	for(i=n;i>=1;i--) {
		printf("%d\n",extract_min(arr,0,i-1,i));
	}
}
