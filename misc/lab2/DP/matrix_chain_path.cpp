#include<iostream>
#include<cstdio>

using namespace std;

struct ar
{
	int row;
	int col;
};

void root( int arr[100][100], int x, int y )
{
	if ( y == x )
	{
		printf ("%d ",arr[x][y]);
		return;
	}
	cout << "(";
	root ( arr, x, arr[x][y]-1);
	root ( arr, arr[x][y], y);
	cout << ")";
}

int main()
{
	int indx;
	int i,j,l,n,k;
	int path[100][100];
	int c[100][100]={999999};
	struct ar st[1000];
	printf ( "enter the number of matrix\n");
	scanf("%d",&n);
	printf ( "enter the dimension of matrix\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&st[i].row,&st[i].col);
	}
	for(i=0;i<n;i++)
	{
		c[i][i]=0;
		path[i][i] = i+1;
	}
	for(i=1;i<n;i++) {
		for(j=0;j < n-i;j++) {
			l = i+j;
			c[j][l] = 999999;
			for(k=j;k<l;k++) {
				if(c[j][l] > c[j][k] + c[k+1][l] + st[j].row*st[k].col*st[l].col) {
					c[j][l] = c[j][k] + c[k+1][l] + st[j].row*st[k].col*st[l].col;
					indx = k+1;
				}
			}
			path[j][l] = indx;
		}
	}
	printf ( "cost marix is\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	printf ( "cost is \n");
	printf("%d\n",c[0][n-1]);
	printf ( "path matrix\n");
	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			printf ("%d ",path[i][j]);
		}
		printf("\n");
	}
	root(path,0,n-1);
	
	int op;
	cin>>op;
}

