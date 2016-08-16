#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct node 
{
	struct node* left;
	struct node* right;
	struct node* parent;
	int value;
};

void heapify(struct node *ctr)
{
	if ( ctr->left == NULL )
	{
		return;
	}

	else
	{
		heapify(ctr->left);
		if ( (ctr->left)->value < ctr->value )
		{
			swap((ctr->left)->value,ctr->value);
		}
	}

	if ( ctr->right == NULL )
	{
		return;
	}

	else 
	{
		heapify(ctr->right);
		if ( (ctr->right)->value < ctr->value )
		{
			swap((ctr->right)->value,ctr->value);
		}
	}
}

int number_of_levels (int n)
{
	float y;
	y = log2(n);
	y = ceil(y);
	return y;
}

void print_level(node *root)
{
	queue<node *> q;

	q.push(root);


	node *temp;
	while(!q.empty()){
		
		temp = q.front();
		q.pop();

		cout << temp -> value << " ";

		if(temp -> left != NULL){
			q.push(temp -> left);
		}
		if(temp -> right != NULL){
			q.push(temp -> right);
		}
		
	}
	cout << endl << endl;
}


int main()
{
	int n,m;
	int d;
	int count = 0;
	int x = 0;
	struct node* queue[100];
	struct node* ptr = NULL, *root = NULL;
	cin>>n;

	int a;
	for ( int i = 0; i < n ;i++ )
	{
		cin>>a;

		if ( count == 0 )
		{
			queue[0] = (struct node*) malloc ( sizeof(struct node));
			ptr = queue[0];
			root = queue[0];
			queue[0]->left = NULL;
			queue[0]->right = NULL;
			queue[0]->parent = NULL;
			queue[0]->value = a;
			count = 1;
		}

		else
		{
			if ( ptr->left == NULL )
			{
				queue[count] = (struct node*) malloc ( sizeof(struct node));
				queue[count]->left = NULL;
				queue[count]->right = NULL;
				queue[count]->parent = ptr;
				queue[count]->value = a;
				ptr->left = queue[count];
			}

			else if ( ptr->right == NULL )
			{
				queue[count] = (struct node*) malloc ( sizeof (struct node) );
				queue[count]->left = NULL;
				queue[count]->right = NULL;
				queue[count]->parent = ptr;
				queue[count]->value = a;
				ptr->right = queue[count];
				x++;
				ptr = queue[x];
			}
			count++;
		}
	}

	m = number_of_levels(n);
	cout<<"number of levels "<<m<<endl;

	for ( int i = 0; i < n-1; i++ )
	{
		heapify(root);

		d = root->value;
		cout<<d<<" ";

		if ( ptr->left == NULL )
		{
			x--;
			ptr = queue[x];
			swap((ptr->right)->value,root->value);
			ptr->right = NULL;
		}

		else if ( ptr->right == NULL )
		{
			swap((ptr->left)->value,root->value);
			ptr->left = NULL;
		}
	}

	cout<<root->value<<endl;


	return 0;
}

					
				





