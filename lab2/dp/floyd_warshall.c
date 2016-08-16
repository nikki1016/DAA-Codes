#include <stdio.h>

# define MAX 10
# define INF 9999

int adj[MAX][MAX];
int d[MAX][MAX];
int pred[MAX][MAX];
int path[MAX];

void floyd_warshall(int v, int adj[][v]);
void find_path(int s, int dest);
void display(int v, int a[][v]);

int main()
{
	int v, i, j, s, dest;
	scanf("%d", &v);
	int adj[v][v];
	
	for (i = 0; i < v; i++) {
		for (j = 0; j < v; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	
	floyd_warshall(v, adj);
}

void floyd_warshall(int v, int adj[][v])
{
	int d[v][v];
	int pred[v][v];
	int i, j, k, s, dest;
	
	for (i = 0; i < v; i++) {
		for (j = 0; j < v; j++) {
			if (adj[i][j] == 0) {
				d[i][j] = INF;
				pred[i][j] = -1;
			}
			else {
				d[i][j] = adj[i][j];
				pred[i][j] = i;	
			}
		}
	}
	
	for (k = 0; k < v; k++) {
		for (i = 0; i < v; i++) {
			for (j = 0; j < v; j++) {
				if ((d[i][k]+d[k][j]) < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
					pred[i][j] = pred[k][j];
				}
			}
		}
	}
	
	printf("Shortest Distance Matrix: \n");
	display(v, d);
	
	printf("Predecessor Matrix: \n");
	display( v, pred);
	
	printf("Enter Source  and Destination Vertex: ");
	scanf("%d%d", &s, &dest);
	
	printf("Length of Shortest Path: %d", d[s][dest]);
	find_path(s, dest);
	
	return;
	
}

void find_path(int s, int dest)
{
	
	if (d[s][dest] == INF) {
 		printf("No Path found\n");
		return;
	}
	printf("\n1\n");
	int i, ctr = -1;

	do {
		printf("2\n");
		path[++ctr] = dest;
		dest = pred[s][dest];
	}while(dest != s);
	
	path[++ctr] = s;
	
/*	for (i = 0; i < ctr; i++) {
		printf("3\n");
		printf("%d ", path[i]);
	}*/
	for (i = ctr; i >= 0; i--) {
		printf("3\n");
		printf("%d ", path[i]);
	}
	printf("\n");
}

void display(int v, int a[][v])
{
	int i, j;
	
	for (i = 0; i < v; i++) {
		for (j = 0; j < v; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
}
