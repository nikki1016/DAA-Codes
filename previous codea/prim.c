#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adj[20][20]={9999};
int n;
int nodes = 0;
int a[33];

struct node{
	int val;
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
	int n1;
	int n2;
};

struct node *root=NULL;

void check(struct node *n) {
	int t;
	if(n==root) return;
	if(n->parent->val > n->val) {
		t= n->parent->val;
		n->parent->val = n->val;
		n->val = t;
		t= n->parent->n1;
		n->parent->n1 = n->n1;
		n->n1 = t;
		t= n->parent->n2;
		n->parent->n2 = n->n2;
		n->n2 = t;
		check(n->parent);
	}
}

int getbinary() {
	memset(a,0,sizeof(a));
	if(nodes == 0) return 0;
	int n = nodes,i = 0;
	while(n!=0){
		a[i]=n%2;
		n=n/2;
		i++;
	}
	return i;
}

void createnode(int value,int node1,int node2) {
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->val = value;
	n->lchild = NULL;
	n->rchild = NULL;
	n->parent = NULL;
	n->n1 = node1;
	n->n2 = node2;
	nodes++;
	if(nodes == 1) {
		root = n;
		//printf("Root node created\n");
	}
	else {
		struct node *t = root;
		struct node *parent = NULL; 
		int l = getbinary();
		int i;
		for(i=l-2;i>=0;i--){
			parent = t;
			if(a[i]==0) 
				t =t->lchild;
			else
				t= t->rchild;
			if(t==NULL){
				if(a[i]==0) parent->lchild = n;
				else parent->rchild = n;
				n->parent = parent;
				check(n);
				//printf("Node created %d with parent %d\n",n->val,n->parent->val);
			}  
		}
	}
}


void inorder(struct node *n){
	if(n == NULL)
		return;
	inorder(n->lchild);
	printf("%d \t",n->val);
	inorder(n->rchild);
}
void maxify(struct node *n)
{
	if(n->lchild==NULL && n->rchild== NULL) return;
	struct node *small = n;
	int temp;
	if(n->lchild->val < n->val) small = n->lchild;
	if((n->rchild!=NULL) && (small->val > n->rchild->val)) small = n->rchild;
	if(small!=n) {
		temp = small->val;
		small->val = n->val;
		n->val = temp;
		temp = small->n1;
		small->n1 = n->n1;
		n->n1 = temp;
		temp = small->n2;
		small->n2 = n->n2;
		n->n2 = temp;
		maxify(small);
	}
}

struct node *del() {
	if(root==NULL){
		printf("Empty heap\n");
		return root;
	}
	//int item = root->val;
	//printf("Deleted value %d\n",root->val);
	int l = getbinary();
	struct node *t= root;
	struct node *parent = NULL;
	int i,temp;
	if(l==1){
		//	free(root);
		root = NULL;
		nodes = 0;
		return t;
	}
	for(i=l-2;i>=0;i--){
		parent = t;
		if(a[i]==0) t =t->lchild;
		else t= t->rchild;
	}

	//	if(t==NULL) printf("hi\n");	
	if(a[0]==0) {
		temp = parent->lchild->val;
		parent->lchild->val = root->val;
		root->val = temp;
		temp = parent->lchild->n1;
		parent->lchild->n1 = root->n1;
		root->n1 = temp;
		temp = parent->lchild->n2;
		parent->lchild->n2 = root->n2;
		root->n2 = temp;

		t = parent->lchild;
		parent->lchild = NULL;
		maxify(root);
	}
	else {
		temp = parent->rchild->val;
		parent->rchild->val = root->val;
		root->val = temp;
		temp = parent->rchild->n1;
		parent->rchild->n1 = root->n1;
		root->n1 = temp;
		temp = parent->rchild->n2;
		parent->rchild->n2 = root->n2;
		root->n2 = temp;
		t = parent->rchild;
		parent->rchild = NULL;
		maxify(root);
	}
	//free(t);
	nodes--;
	return t;
}
void display(int adj[20][20])
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
}

void prim()
{	int i,j,k,n1,n2,newnode,edge,f1,f2;
	int sp[20][20]={-1};
	printf("root Vertex = %d\n",0);
	for(i=0;i<n;i++) for(j = 0;j<n;j++) sp[i][j] = -1;
	struct node *t;
	sp[0][0] = 0;
	for(i = 0;i<n;i++) createnode(adj[0][i],0,i);
	t = del();
	edge = t->val;
	n1 = t->n1;
	n2 = t->n2;
	free(t);
	printf("edge = %d n1 = %d n2 = %d\n",edge,n1,n2);
	if(n1==0) newnode = n2;
	else n2 = newnode;
	sp[0][newnode] =adj[0][newnode];
	//display(sp);
	for(i = 2;i<n;i++){
		for(j = 0;j<n;j++) createnode(adj[newnode][i],newnode,i);
		f1 = f2=0;
		while(f1==0 && f2==0){
			t = del();
			if(t==NULL) return;
			edge = t->val;
			n1 = t->n1;
			n2 = t->n2;
			free(t);
			printf("edge = %d n1 = %d n2 = %d\n",edge,n1,n2);
			for(k = 0;k<n;k++){
				f1 = 1;
				if(sp[n1][k]!=-1){
					f1 = 0;
					break;
				}
			}
			for(k = 0;k<n;k++){
				f2 = 1;
				if(sp[n2][k]!=-1){
					f2 = 0;
					break;
				} 
			}
		}
		if(f1 == 1) {newnode = n1;
			sp[newnode][n2] = edge;
		}
		else if(f2 == 1){newnode = n2;
			sp[newnode][n1] = edge;
	//		display(sp);
		}
		//printf("new node =%d\n",newnode);
	}
	display(sp);
}
void create_graph()
{	n = 4;
	adj[0][0] = adj[1][1]=adj[2][2] = adj[3][3] = 9999;
	 adj[2][3] =adj[3][2]= 9999;	
	adj[0][1] = 7;	adj[1][0] = 7;
	adj[0][2] = 3;	adj[2][0] = 3;
	adj[0][3] = 4;	adj[3][0] = 4;
	adj[1][2] = 5;	adj[2][1] = 5;
	adj[1][3] = 2;	adj[3][1] = 2;

}

int main()
{
	create_graph();
//	display(adj);
	prim();
}
