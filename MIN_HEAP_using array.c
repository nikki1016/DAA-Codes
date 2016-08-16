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
void minheapify(int a[],int i)
{
	int l,r,largest,t;
	l=left(i);
	r = right(i);
	if(l<=heapsize&&a[l]<a[i])
	largest = l;
	else largest = i;
	if(r<=heapsize&&a[r]<a[largest])
	largest = r;
	if(largest!=i){
		t = a[i];
		a[i]=a[largest];
		a[largest] = t;
		minheapify(a,largest);
	}
}
void build_heap(int a[]){
	heapsize = length;
	int i;
	for(i=length/2;i>0;i--){
		minheapify(a,i);
	}
}
void display(int a[]){
	int i;
	if(heapsize == 0) {
	printf("Empty heap\n");
	return;	
	}
	for(i=1;i<=length;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void heapsort(int a[]){
	int t,i;
	for(i=length;i>1;i--){
		t=a[1];
		a[1]=a[i];
		a[i]=t;
		heapsize--;
		minheapify(a,1);
	}
}
void heapsort_asc(int a[]){
	printf("%d\t",a[1]);
	//int t;
	a[1]=a[heapsize];
	heapsize--;
	minheapify(a,1);
	 
}

int main(){
	int n;
	scanf("%d",&n);
	length = n;
	int a[n+1],i;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build_heap(a);
	display(a);
	for(i=0;i<length;i++){
		heapsort_asc(a);
	}
}
