#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node 
{
	struct node *left,*right,*parent;
	int w,i,f;
};

void heapify(struct node *ctr)
{
	if(ctr -> left == NULL)
	return ;

	else 
	{
		heapify(ctr->left);
		if((ctr -> left)-> w < ctr -> w)
		{
			swap((ctr -> left)-> w,ctr->w);
			swap((ctr -> left)-> i,ctr->i);
			swap((ctr -> left)-> f,ctr->f);
		}
	}

	if(ctr -> right == NULL)
	return ;

	else 
	{
		 heapify(ctr->right);
		 if((ctr -> right)-> w < ctr -> w)
		 {
			swap((ctr -> right)-> w,ctr->w);
			swap((ctr -> right)-> i,ctr->i);
			swap((ctr -> right)-> f,ctr->f);
		 } 	
	}
}

int main()
{
	int n,i,j,e,x,y,w,k;

	printf("enter number of nodes = ");
	scanf("%d",&n);

	int a[n][n],b[n][n];
	int done[100] = {0};

	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++) 
		{
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}

	printf("enter number of edges = ");
	scanf("%d",&e);

	for(i = 0; i < e; i++) 
	{
		printf("enter source = ");
		scanf("%d",&x);
		printf("enter destination = ");
		scanf("%d",&y);
		printf("enter weight = ");
		scanf("%d",&w);
		a[x][y] = w;
		a[y][x] = w;
	}

	printf("enter node from where we want to start = ");
	scanf("%d",&k);

	done[k] = 1;
	int count = 0,nodes = 1;
	node *queue[100],*ptr= NULL,*root = NULL;
	x = 0;

	while(nodes != n) 
	{
		for(i = 0; i < n; i++) 
		{
			if(a[k][i] != 0 && done[i] != 1)
			{
					if(count == 0)
					{
						queue[0] = (node *)malloc(sizeof(node));
						ptr = queue[0];
						root = ptr;
						queue[0] -> left = NULL;
						queue[0] -> right = NULL;
						queue[0] -> parent = NULL;
						queue[0] -> i = k;
						queue[0] -> f = i;
						queue[0] -> w = a[k][i];
						count = 1;
					}
					
					else 
					{
						if(ptr -> left == NULL)
						{
							queue[count] = (node *)malloc(sizeof(node));
							queue[count] -> left = NULL;
							queue[count] -> right = NULL;
							queue[count] -> parent = ptr;
							queue[count] -> i = k;
							queue[count] -> f = i;
							queue[count] -> w = a[k][i];
							ptr -> left = queue[count];
						}
						else if(ptr -> right == NULL) 
						{
							queue[count] = (node *)malloc(sizeof(node));
							queue[count] -> left = NULL;
							queue[count] -> right = NULL;
							queue[count] -> parent = ptr;
							queue[count] -> i = k;
							queue[count] -> f = i;
							queue[count] -> w = a[k][i];
							ptr -> right = queue[count];
							x++;
							ptr = queue[x];
					 	}
						count++;
					}
			}
		}
			
		heapify(root);
		
		if(done[root -> f] != 1)
		{
			b[root->i][root->f] = root->w;
			done[root->f] = 1;
			nodes++;
 		}
 
		k = root->f;
		if(ptr -> left == NULL) 
		{
 			x--;
 			ptr = queue[x];
			swap(ptr->right->i,root->i);
			swap(ptr->right->f,root->f);
			swap(ptr->right->w,root->w);
			ptr -> right = NULL;
		 }
		
	       	else 
		{	 
		      	swap(ptr->left->i,root->i);
			swap(ptr->left->f,root->f);
			swap(ptr->left->w,root->w);
			ptr -> left = NULL;
 		}
		
		count--;
 	}
	
	for(i = 0; i < n; i++) 
	{
		for(j = 0; j < n; j++ ) 
		{
			printf("%d ",b[i][j]);
		}
		
		printf("\n");
	}	

return 0;
}
