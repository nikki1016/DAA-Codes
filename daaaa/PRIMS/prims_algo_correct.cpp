#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
typedef struct b_tree {
	struct b_tree *left,*right;
	int val,x,y;
}nod;
nod *arr[10000];
int a[100][100],size, node[100], front = 0, end = 1, u = 0;
nod *root = NULL;
void minheap ( nod *root );
void print ( nod * root );
void adj_matrix ()
{
	int j,k;
	printf ( "enter the number of nodes?\n");
	scanf ( "%d", &size );
	printf ( "enter the value of nodes\n");
	for ( int i = 0; i < size; i++) {
		scanf ( "%d", &node[i] );
	}
	printf ( "enter adjacency matrix\n");
	for ( int i = 0; i < size; i++) {
		for ( int j = 0; j < size; j++) {
			scanf ( "%d", &a[i][j] );
		}
	}
}
void build_tree ( int num, int x, int y )
{
	nod *t;
	if ( arr[u] == NULL ) {
		t = new nod;
		t -> val = num;
		t -> x = x;
		t -> y = y;
		t -> right = t -> left = NULL;
		arr[u] = t;
		if ( u == 0 ) {
			root = arr[0];
		}
	}else if ( arr[u] -> left == NULL ) {
		t = new nod;
		t -> val = num;
		t -> x = x;
		t -> y = y;
		t -> right = t -> left = NULL;
		arr[u] -> left = t;
		arr[end++] = t;
	}else if ( arr[u] -> right == NULL ) {
		t = new nod;
		t -> val = num;
		t -> x = x;
		t -> y = y;
		t -> right = t ->left = NULL;
		arr[u] -> right = t;
		arr[end++] = t;
		u++;
	}
}
void print ( nod *root )
{
	if ( root != NULL ) {
		print ( root ->left );
		print ( root -> right );
		printf ( "%d->%d->%d\n", root -> val,root -> x, root -> y);
	}
}
void swap ( nod *p, nod *u)
{
	int temp,i,j;
	temp = p -> val;
	i = p -> x;
	j = p -> y;
	p -> val = u -> val;
	p -> x = u -> x;
	p -> y = u -> y;
	u -> val = temp;
	u -> x = i;
	u -> y = j;
}

void min_heap ( nod *root )
{
	if ( root -> left == NULL ) {
		return;
	}else {
		min_heap(root -> left );
		if ( root -> val > root -> left -> val ) {
			swap ( root, root -> left );
		}
	}
	if ( root -> right == NULL ) {
		return;
	}else {
		min_heap ( root -> right );
		if ( root -> val > root -> right  -> val ) {
			swap ( root, root -> right );
		}
	}
}

void delete1 ( nod *root )
{
	if ( arr[u] -> right == NULL && arr[u] -> left == NULL ) {
		if ( u == 0 ) {
			arr[u] = NULL;
			end--;
		}else {
			u--;
			swap( arr[u] -> right, root );
			arr[u] -> right = NULL;
			end--;
		}
	}else if ( arr[u] -> right == NULL && arr[u] -> left != NULL ) {
		swap ( root , arr[u] -> left );
		arr[u] -> left = NULL;
		end--;
	}
}

void level_wise ( nod *root )
{
	queue<nod*> q;
	q.push ( root );
	nod *t;
	while ( !q.empty() ) {
		t = q.front();
		if ( t -> left ) {
			q.push(t -> left );
		}
		if ( t -> right ) {
			q.push(t -> right );
		}
		printf ( "%d->", t -> val );
		q.pop();
	}
}


int main()
{
	int n,k,sum = 0,n1,flag = 0,flag1 = 0,visited[100] = {0};
	adj_matrix();
	printf ( "enter the strating node?\n");
	scanf ( "%d", &n1 );
	n1--;
	while ( flag == 0 ) {
		flag = 1;
		if ( flag1 == 0 ) {
			for ( int i = 0; i < size; i++) {
				if ( a[n1][i] != 99999 ) {
					build_tree ( a[n1][i], n1, i );
					a[i][n1] = 99999;
				}
			}
		}
		min_heap ( root );
		//print(root);
//		printf ( "\n");
		//	level_wise ( root );
		//	printf ( "\n" );
		if ( visited [ root -> x ] == 0 || visited [ root -> y ] == 0 ) {
			n1 = root -> y;
			sum += root -> val;
			visited [ root -> x ] = 1;
			visited [ root -> y ] = 1;
			printf ( "%d\t%d\n", node[root -> x], node[root -> y] );
			delete1 ( root );
			min_heap ( root );
		}else {
			delete1 ( root );
			min_heap ( root );
		}
		for ( int i = 0; i < size; i++) {
			if ( visited[i] == 0 ) {
				flag = 0;
				break;
			}
		}
	}
	printf ( "weight of minimum spanning tree = %d\n", sum );
	return 0;
}


