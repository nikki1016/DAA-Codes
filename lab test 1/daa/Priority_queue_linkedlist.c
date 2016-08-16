#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
int val;
char name[20];
struct node *lchild;
struct node *rchild;
struct node *parent;
};

struct node *root=NULL;
int nodes = 0;
int a[33];

void check(struct node *n) {
	int t;
	char *item;
	if(n==root) return;
	if(n->parent->val > n->val) {
	t= n->parent->val;
	n->parent->val = n->val;
	n->val = t;
	strcpy(item,n->parent->name);
	strcpy(n->parent->name,n->name);
	strcpy(n->name,item);
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

void createnode(char ch[],int value) {
struct node *n = (struct node *)malloc(sizeof(struct node));
n->val = value;
strcpy(n->name,ch);
n->lchild = NULL;
n->rchild = NULL;
n->parent = NULL;
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
printf("%s \t",n->name);
inorder(n->rchild);
}
void maxify(struct node *n)
{
	if(n->lchild==NULL && n->rchild== NULL) return;
	struct node *small = n;
	char item[20];
	int temp;
	if(n->lchild->val < n->val) small = n->lchild;
	if((n->rchild!=NULL) && (small->val > n->rchild->val)) small = n->rchild;
	if(small!=n) {
		temp = small->val;
		small->val = n->val;
		n->val = temp;
		strcpy(item,small->name);
		strcpy(small->name,n->name);
		strcpy(n->name,item);
		maxify(small);
	}
}

void delete_key()
{
	if(root==NULL){
		printf("Empty heap\n");
		return;
	}
	char item[20];
	strcpy(item,root->name);
	printf("Deleted value %s\n",item);
	int l = getbinary();
	struct node *t= root;
	struct node *parent = NULL;
	int i,temp;
	if(l==1){
		free(root);
		root = NULL;
		nodes = 0;
		return;
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
			strcpy(item,parent->lchild->name);
			strcpy(parent->lchild->name,root->name);
			strcpy(root->name,item);
			t = parent->lchild;
			parent->lchild = NULL;
			maxify(root);
	}
	else {
		temp = parent->rchild->val;
		parent->rchild->val = root->val;
		root->val = temp;
		strcpy(item,parent->rchild->name);
		strcpy(parent->rchild->name,root->name);
		strcpy(root->name,item);
		t = parent->rchild;
		parent->rchild = NULL;
		maxify(root);
	}
	free(t);
	nodes--;
}


int main()
{int i;
char ch[20];

while(1) {
	scanf("%s%d",&ch,&i);
	if(i==-1) break;
	createnode(ch,5);
}
inorder(root);
printf("\n");
int n = nodes;
for(i=0;i<n;i++){
	delete_key();
//	printf("%s\n",t);
}
return 0;
}
