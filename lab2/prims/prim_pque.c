#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct edge
{
	int u;
	int v;
	int weight;
	struct edge *link;
}*front = NULL;

int sp[MAX][MAX];
int adj[MAX][MAX];
int n = 4;

//void make_tree(struct edge tree[]);
void insert_pque(int i,int j,int wt);
struct edge *del_pque();
int isEmpty_pque( );
void create_graph();

void insert_pque(int i,int j,int wt)
{
	struct edge *tmp,*q;

	tmp = (struct edge *)malloc(sizeof(struct edge));
	tmp->u = i;
	tmp->v = j;
	tmp->weight  =  wt;

	/*Queue is empty or edge to be added has weight less than first edge*/
	if( front == NULL || tmp->weight < front->weight )
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		q = front;
		while( q->link != NULL && q->link->weight <= tmp->weight )
			q = q->link;
		tmp->link  =  q->link;
		q->link = tmp;
		if(q->link == NULL)	/*Edge to be added at the end*/
			tmp->link = NULL;
	}
}

struct edge *del_pque()
{
	struct edge *tmp;
	tmp = front;
	front = front->link;
	return tmp;
}
int isEmpty_pque()
{
	if(front == NULL)
		return 1;
	else
		return 0;
}

void create_graph() {
	int i,j, max_edges, origin, dest, wt;
	printf("Enter no. of verticies: ");
	scanf("%d", &n);
	max_edges = n*(n-1)/2;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			adj[i][j] = 999999;
			sp[i][j] = -1;
		}
	}

	for (i = 0; i < max_edges; i++) {
		printf("Enter edges: origin: destination (-1 -1 to QUIT)\n");
		scanf("%d %d", &origin, &dest);
		if (origin == -1 && dest == -1)
			break;
		printf("Enter the weight: ");
		scanf("%d", &wt);
		if (origin >= n || origin < 0 || dest >= n || dest < 0) {
			printf("Invalid edge\n");
			i--;
		}
		else {
			adj[origin][dest] = wt;
			//adj[origin][dest] = -1;
			adj[dest][origin] = wt;
			//adj[dest][origin] = -1;
		}
	}
	/*adj[0][0] = adj[1][1]=adj[2][2] = adj[3][3] = 9999;
	adj[2][3] =adj[3][2]= 9999;	
	adj[0][1] = 7;	adj[1][0] = 7;
	adj[0][2] = 3;	adj[2][0] = 3;
	adj[0][3] = 4;	adj[3][0] = 4;
	adj[1][2] = 5;	adj[2][1] = 5;
	adj[1][3] = 2;	adj[3][1] = 2;*/

}

void prim()
{	int i,j,k,n1,n2,newnode,edge,f1,f2;
	//int sp[20][20]={-1};
	//printf("root Vertex = %d\n",0);
	for(i = 0; i < n; i++) 
		for(j = 0;j<n;j++) 
			sp[i][j] = -1;
	
	struct edge *t;
	sp[0][0] = 0;
	
	for(i = 0;i<n;i++)
		insert_pque(0,i, adj[0][i]);
	
	t = del_pque();
	edge = t->weight;
	n1 = t->u;
	n2 = t->v;
	free(t);


	if(n1==0) newnode = n2;
	else newnode = n1;
	
	sp[0][newnode] =adj[0][newnode]; 
	sp[newnode][0]= adj[0][newnode];
	//display(sp);
	for(i = 2;i<n;i++){
		for(j = 0;j<n;j++)
		 	insert_pque(newnode,j, adj[newnode][j]);
		f1 = f2=0;
		while(f1==0 && f2==0){
			t = del_pque();
			if(t==NULL) return;
			edge = t->weight;
			n1 = t->u;
			n2 = t->v;
			free(t);
			printf("EDGE\tWEIGHT\n");
			printf("%d - %d\t%d\n", n1, n2, edge);
	
			//printf("edge = %d n1 = %d n2 = %d\n",edge,n1,n2);
			for(k = 0; k < n; k++){
				f1 = 1;
				if(sp[n1][k]!=-1){
					f1 = 0;
					break;
				}
			}
			for(k = 0; k < n; k++){
				f2 = 1;
				if(sp[n2][k]!=-1){
					f2 = 0;
					break;
				} 
			}
		}
		if(f1 == 1) {
			newnode = n1;
			sp[newnode][n2] = edge;
			sp[n2][newnode] = edge;
		}
		else if(f2 == 1){
			newnode = n2;
			sp[newnode][n1] = edge;
			sp[n1][newnode] = edge;
		}
	}
	//display(sp);
}

int main()
{
	int i, j, n1, n2, fg1, fg2, k, newnode, edge;

	create_graph();

	printf("Graph Ceated: \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", adj[i][j]);
		}
		printf("\n");
	}
	
	prim();
	printf("The Resultant Adjacency Matrix: \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", sp[i][j]);
		}
		printf("\n");
	}

	return 0;

}
