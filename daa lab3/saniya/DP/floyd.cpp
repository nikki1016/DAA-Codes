#include <stdio.h>
# define INF 9999

void floyd_warshall(int adj[][100], int v, int d[][100], int pred[][100]);
void find_path(int d[][100], int pred[][100], int s, int dest, int v);
void display(int a[][100], int v);

int main()
{
	int adj[100][100];
	int d[100][100];
	int pred[100][100];
	int i, j, s, v, dest;
	scanf("%d", &v);
	
	for (i = 0; i < v; i++) {
		for (j = 0; j < v; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	
	floyd_warshall(adj, v, d, pred);
	
	printf("Enter Source  and Destination Vertex: ");
	scanf("%d%d", &s, &dest);
	
	printf("Length of Shortest Path: %d\n", d[s][dest]);
	display(pred, v);
	
	find_path(d, pred, s, dest, v);
}

void floyd_warshall(int adj[][100], int v, int d[][100], int pred[][100])
{
	//display(adj, v);
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
	display(d, v);
	
	printf("Predecessor Matrix: \n");
	display(pred, v);
	
	return;
	
}

void find_path(int d[][100], int pred[][100], int s, int dest, int v)
{
	
	if (d[s][dest] == INF) {
 		printf("No Path found\n");
		return;
	}
	int i, ctr = -1, u;
	int path[100];
	
	do {
		path[++ctr] = dest;
		//printf("pred[%d][%d]: %d\n", s, dest, pred[s][dest]);
		u = pred[s][dest];
		dest = u;
	}while(dest != s);
	path[++ctr] = s;
	
	for (i = ctr; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("\n");
}

void display(int a[][100], int v)
{
	int i, j;
	
	for (i = 0; i < v; i++) {
		for (j = 0; j < v; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
}
