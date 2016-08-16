#include <stdio.h>

int heapsize = 0;
int length;

int parent(int i){
	return i/2;
}
int left(int i){
	return (2*i);
}
int right(int i){
	return (2*i) + 1;
}
void maxheapify(int a[],int i)
{
	int l,r,largest,t;
	l=left(i);
	r = right(i);
	if(l<=heapsize&&a[l]>a[i])
	largest = l;
	else largest = i;
	if(r<=heapsize&&a[r]>a[largest])
	largest = r;
	if(largest!=i){
		t = a[i];
		a[i]=a[largest];
		a[largest] = t;
		maxheapify(a,largest);
	}
}
void build_heap(int a[]){
	heapsize = length;
	int i;
	for(i=length/2;i>0;i--){
		maxheapify(a,i);
	}
}
void display(int a[]){
	int i;
	for(i=1;i<=length;i++){
		printf("%d\t",a[i]);
	}
printf("\n");
}

void heapsort(int a[],int low,int high){
	int t,i;
	int b[100];
	for(i=low;i<=high;i++){
		b[i]=a[i];	
	}
	length = high-low +1;
	build_heap(b);
	
	for(i=length;i>=1;i--){
		t=b[1];
		b[1]=b[i];
		b[i]=t;
		heapsize--;
		maxheapify(b,1);
	}
	for(i=1;i<=length;i++){
		a[low+i-1]=b[i];	
	}
}
int main(){
	int n;
	scanf("%d",&n);
	length = n;
	int a[100000],i,b[100000];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		b[i]=a[i];
	}
	heapsort(a,1,length);
	display(a);
}
