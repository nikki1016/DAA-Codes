#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
int val;
struct node *lchild;
struct node *rchild;
struct node *parent;
};

struct node *root=NULL;
int nodes = 0;
int a[33];

void check(struct node *n) {
int t;
if(n==root) return;
if(n->parent->val < n->val) {
t= n->parent->val;
n->parent->val = n->val;
n->val = t;
check(n->parent);
}
}

int getbinary()
{
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

void createnode(int value) {
struct node *n = (struct node *)malloc(sizeof(struct node));
n->val = value;
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
	if(a[i]==0) t =t->lchild;
	else t= t->rchild;
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

void delete()
{
int l = getbinary();
struct node *t,*parent;
t = root;
for(i=l-2;i>=0;i--){
	parent = t;
	if(a[i]==0) t =t->lchild;
	else t= t->rchild;
	}

}


int main()
{
createnode(5);
createnode(7);
createnode(9);
createnode(10);
createnode(17);
createnode(19);
createnode(2);
inorder(root);
printf("\n");

return 0;
}
