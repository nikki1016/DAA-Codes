#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
	int src,dest,wt;
	struct node *next;	//node1->node2->...so on
};
struct adjList{
	struct node *head;	//ptr to node
};
struct graph{
	int v;
	struct adjList *array;	//array that will store head i.e ptr to nodes
};
struct minNode{	
	int key,v;	//v->vertex no && key->wt
};
struct minHeap {
	int size,capacity;	//capacity = g->v
	int *pos;	//show position of vertice
	struct minNode **array;	//array to keep min_nodes
};
struct graph *create(int v) {	//creating graph structure
	struct graph *g=(struct graph *)malloc(sizeof(struct graph));
	g->v=v;
	g->array=(struct adjList *)malloc(v*(sizeof(struct adjList)));
	int i;
	for(i=0;i<v;i++) {
		g->array[i].head=NULL;
	}	
	return g;
}
struct node *newNode(int src,int dest,int wt) {	//nodes in graph
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->src=src;
	n->dest=dest;
	n->wt=wt;
	n->next=NULL;
	return n;
}
void addEdge(struct graph *g,int src,int dest,int wt) {
	struct node *n=newNode(src,dest,wt);
	n->next=g->array[src].head;	//new node that comes is joined at start and its next point to prevoisly added node for that src
	g->array[src].head=n;	//head of src will point 2 that node
	n=newNode(dest,src,wt);	//undirected graph
	n->next=g->array[dest].head;
	g->array[dest].head=n;
}
struct minNode *newMinNode(int v,int key) {	//min heap node is created
	struct minNode *newnode=(struct minNode *)malloc(sizeof(struct minNode));
	newnode->v=v;	//vertex no
	newnode->key=key;	//initially consist INT_MAX 
	return newnode;
}
struct minHeap *create_heap(int v) {
	struct minHeap *minheap=(struct minHeap *)malloc(sizeof(struct minHeap));
	minheap->size=0;
	minheap->capacity=v;
	minheap->pos=(int *)malloc(v*(sizeof(int)));
	minheap->array=(struct minNode **)malloc(v*(sizeof(struct minNode *)));
	return minheap;
}
int isEmpty(struct minHeap *minheap) {
	return minheap->size==0;	//returns true when empty :P
}
void swapMinHeapNode(struct minNode** a, struct minNode** b)
{
    struct minNode* t = *a;
    *a = *b;
    *b = t;
}
void minheapify(struct minHeap *min,int index) {
	int l=2*index+1;
	int r=l+1;
	int small=index;
	if(l < min->size && min->array[l]->key < min->array[small]->key) {
		small=l;
	}
	if(r < min->size && min->array[r]->key < min->array[small]->key) {
		small=r;
	}
	if(small!=index) {
		struct minNode *smaller=min->array[small];
		struct minNode *swap=min->array[index];
		min->pos[smaller->v]=index;
		min->pos[swap->v]=small;
		swapMinHeapNode(&min->array[small],&min->array[index]);
		minheapify(min,small);
	}
}
void decrease_key(struct minHeap *heap,int v,int key) {
	int i=heap->pos[v];	//storing org position 
	heap->array[i]->key=key;	//changing key val
	while(i && heap->array[i]->key<heap->array[(i-1)/2]->key) {	//checking key of this node with its parent node and swapping
		heap->pos[heap->array[i]->v]=(i-1)/2;	
		heap->pos[heap->array[(i-1)/2]->v]=i;
		swapMinHeapNode(&heap->array[(i-1)/2],&heap->array[i]);
		i=(i-1)/2;
	}
}
struct minNode *extract_min(struct minHeap *minheap) {
	if(isEmpty(minheap))return NULL;
	struct minNode *root=minheap->array[0];	
	struct minNode *last=minheap->array[minheap->size-1];
	minheap->array[0]=last;
	minheap->pos[root->v]=minheap->size-1;
	minheap->pos[last->v]=0;
	--minheap->size;
	minheapify(minheap,0);	//restructring min heap acc 2 key values
	return root;
	
}
void printArr(int arr[], int n)
{	int i;
    for (i = 1; i < n; ++i)
        printf("%d - %d\n", arr[i], i);
}
int isInHeap(struct minHeap *heap,int v) {
	if(heap->pos[v]<heap->size)return 1;
	return 0;
}
void prim(struct graph *g) {
	int V=g->v;
	int parent[V];	//array that will store parent of all vertices
	int key[V];		//store wt
	struct minHeap *minheap=create_heap(V);
	int i;
	for(i=1;i<V;i++) {
		parent[i]=-1;	//initialising ever vertex parent as -1 except starting vertex i.e 0 in this case
		key[i]=INT_MAX;
		minheap->array[i]=newMinNode(i,key[i]);
		minheap->pos[i]=i;	//giving position to each vertex in min heap structure
	}
	minheap->size=V;	//allocating size
	key[0]=0;	//src=0 => key[0]=0
	minheap->array[0]=newMinNode(0,key[0]);
	minheap->pos[0]=0;	//first node=>acc to it the min wt node from it will be picked
	while(!isEmpty(minheap)) {
		struct minNode *first=extract_min(minheap);	//extracting min key node
		int u=first->v;	//extracting its vertex no
		struct node *p=g->array[u].head;	//traversing graph array in acc 2 to that extracted vertex no
		while(p!=NULL) {
			int v=p->dest;		
			if(isInHeap(minheap,v) && p->wt < key[v]) {
				key[v]=p->wt;	//putting least wt
				parent[v]=u;
				decrease_key(minheap,v,key[v]);	//changing key val of min heap node
			}
			p=p->next;	//node1->node2->...
		}
	}
	printArr(parent,V);
}
int main() {
	int n;
	scanf("%d",&n);
	int a,b,wt,v;
	scanf("%d",&v);
	struct graph *g=create(v);
	while(n--) {
		scanf("%d%d%d",&a,&b,&wt);
		addEdge(g,a,b,wt);
	}
	prim(g);
	return 0;
}
