#include<stdio.h>

int n;
  
void display(int sol[]);
 
int check(int v, int graph[][n], int sol[], int c)
{
	int i;
    for (i = 0; i < n; i++)
        if (graph[v][i] && c == sol[i])
            return 0;
    return 1;
}

int ch(int graph[][n], int m, int sol[], int level)
{
   int c;
    if (level == n)
        return 1;
 
    for (c = 1; c <= m; c++)
    {
        if (check(level,graph, sol, c) == 1)
        {
           sol[level] = c;
 
           if (ch( graph, m, sol, level+1) == 1)
             return 1;
 
           sol[level] = 0;
        }
    }
 
    return 0;
}

int graphColoring(int graph[][n], int k)
{
   int i;
    int sol[n];
    for (i = 0; i < n; i++)
       sol[i] = 0;
 
    if (ch(graph, k, sol, 0) == 0)
    {
      return 0;
    }

    display(sol);
    return 1;
}
 
void display(int sol[])
{
	int i;
    printf("Following are the assigned Colors \n");
    for (i = 0; i < n; i++)
      printf(" C%d ", sol[i]);
    printf("\n");
}

int main()
{
	int m, i, j, k, valid;
	scanf("%d", &n);   
	int graph[n][n];
   
   	for (i = 0; i < n; i++) {
   		for (j = 0; j < n; j++) {
   			scanf("%d", &graph[i][j]);
   		}
   	}
    
    for (k = 1; k <= n; k++) {
    	valid = graphColoring (graph, k);
    	if (valid == 1) {
    		printf("Chromatic Number of graph: %d\n", k);
    		break;
    	}
    }
    return 0;
}
