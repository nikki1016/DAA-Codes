#include <iostream>

using namespace std;

int ks(int W, int wt[], int v[], int n);

int picks[100][100];

void print(int n, int W, int wt[]);

int max(int a, int b){
	if (a > b)
		return a;
	else 
		return b;	
}

int main()
{
	int n, i, w;
	scanf("%d%d",&w, &n);
	int wt[n];
	int v[n];
	
	for (i = 0; i < n; i++) {
		scanf("%d%d", &wt[i],&v[i]);
	}
		
	printf("%d\n", ks(w, wt, v, n));
//	print(n, w, wt);
}

int ks(int W, int wt[], int v[], int n)
{
	int i, w;
	int k[n+1][W+1];
		
		for(i = 0; i <=n; i++) {
			for (w = 0; w <= W; w++) {
				if (i == 0 || w == 0)
					k[i][w] = 0;
				else if (wt[i-1] <= w) {
					k[i][w] = max(v[i-1]+k[i-1][w - wt[i-1]], k[i-1][w]);
					
					if (v[i-1]+k[i-1][w-wt[i-1]] > k[i-1][w]) 
						picks[i][w] = 1;
					else 
						picks[i][w] = -1;	
				}
				else  {
					k[i][w] = k[i-1][w];
					picks[i][w] = -1;
				}
//				cout<<"i = "<<i<< "w = "<<w<<" k[i][w] = "<<k[i][w]<<"\n";
			}
		}
		
		return k[n][W];
}

void print(int n, int W, int wt[])
{
	while (n >0) {
		if (picks[n][W] == 1) {
			printf("%d ", wt[n-1]);
			n--;
			W = W-wt[n];
		}
		else {
			n--;
		}	
	}
	printf("\n");
	
	return ;
}
