#include <stdio.h>
int heapsize = 0;
int length;
int parent(int i){
	if(i%2)
	return i/2;
	else return (i-1)/2;
}
int left(int i){
	return (2*i)+1;
}
int right(int i){
	return (2*i) + 2;
}
void maxheapify(int a[],int i)
{
	int l,r,largest,t;
	l=left(i);
	r = right(i);
	if(l<heapsize&&a[l]>a[i])
	largest = l;
	else largest = i;
	if(r<heapsize&&a[r]>a[largest])
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
	for(i=((length/2)-1);i>=0;i--){
		maxheapify(a,i);
	}
}
void display(int a[]){
	int i;
	for(i=0;i<heapsize;i++){
		printf("%d\t",a[i]);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	length = n;
	int a[100],i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	build_heap(a);
	display(a);	
}
