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
	for(i=1;i<=heapsize;i++){
		printf("%d\t",a[i]);
	}
}
int heap_max(int a[]){
	if(heapsize<1){
		printf("Empty Heap\n");
		return -1;
	} 
	return a[1];
}
int extract_max(int a[]){
	if(heapsize<1){
		printf("Empty Heap\n");
		return -1;
	} 
	int item = a[1];	
	a[1]=a[heapsize];
	heapsize--;
	maxheapify(a,1);
	return item;
}
void heap_increase_key(int a[],int i,int key){
	if(key<a[i]){
		printf("Key is smaller\n");
		return;
	}
	a[i] = key;
	int t;
	while(i>1&& a[parent(i)]<a[i]){
		t = a[i];
		a[i]=a[parent(i)];
		a[parent(i)] = t;
		i = parent(i);
	}
}
void insertkey(int a[],int key){
	heapsize++;
	a[heapsize]= -9999;
	heap_increase_key(a,heapsize,key);
}
int main(){
	int n;
/*	scanf("%d",&n);
	length = n;
	int a[100],i;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build_heap(a);
	display(a);*/
	int b[20],i;
	heapsize = 0;
	length = 0;
	while(1){
		scanf("%d",&i);
		if(i==-1) break;
		else {
			insertkey(b,i);
			length++;
		}
	}
	display(b);
	printf("max element =%d\n",heap_max(b));
	
	for(i=0;i<length;i++){
		printf("%d\t",extract_max(b));
	}
	printf("\n");
	
}
