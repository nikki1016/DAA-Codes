#include <stdio.h>
#include <limits.h>
#define MAX 100
//edge not present -1
int w[MAX][MAX];
int ans[MAX], aa[MAX];
int min[2][MAX];
float wmin = 0.0;

int findwmin(int node, int level, int n, int check[]) {
	if (level == n)  {
		wmin += w[node][0];
		return wmin;
	}
	int i, min, j, node2;
	min = INT_MAX;
	for(i = 0; i < n; i++) {
		if (w[node][i]!=-1 && check[i]!=1) {
			if (w[node][i] < min) {
				min = w[node][i];
				node2 = i;
			}
		}
	}
	wmin += min;
	node = node2;
	check[node2] = 1;
//	printf("node2 %d\n",node2);
	findwmin(node, level+1, n, check);
}


float tsp (int n, int a[], int l, float curwt, float est) {
	if (l == n-1) {
		int i;
		if (wmin > curwt + w[a[n-1]][a[0]]) {
			wmin = curwt + w[a[n-1]][a[0]];
				for (i = 1; i < n; i++) {
				ans[i] = aa[i];
			}
		}
		return wmin;
	}
	else {
		int i, j, temp;
		float nl;
		float est2;
		for (i = l+1; i < n; i++) {
			temp = a[l+1];
			a[l+1] = a[i];
			a[i] = temp;
			est -= 0.5*(min[1][a[l]]+min[1][a[l+1]]);
			if (w[a[l]][a[l+1]]!=-1) {
				nl = curwt + w[a[l]][a[l+1]];
				float wmin1;
				if (nl + est  < wmin) {
					aa[l+1] = a[l+1];
			//		printf("%d %d\n", l+1, ans[l+1]);
					wmin1 = tsp(n, a, l+1, nl, est);
					if (wmin > wmin1) {
							for (j = 1; j <= l+1; j++) {
								ans[j] = aa[j];
							}
						wmin = wmin1;
					}
				}
			}
				temp = a[i];
				a[i] = a[l+1];
				a[l+1] = temp;
		}
		return wmin;
	}
}

int main() {
	int i, j, k, n, min1, min2, t1, t2, w1[MAX][MAX];
	float curwt = 0, est;
	
	scanf("%d",&n);
	est = 0;
	
	for (i = 0; i < n;i++) {
		for(j = 0; j < n;j++) {
				scanf("%d",&w[i][j]);
				w1[i][j] = w[i][j];
		}
	}
	
	int check[n];
	for(i = 0; i < n;i++) check[i] = 0;
	check[0] = 1;
	wmin = findwmin(0, 1, n, check);
	
	printf("%f\n",wmin); 
	
	for (i = 0; i < n;i++) {
		min1 = INT_MAX;
		for (j = 0; j < n; j++) {
			if (w[i][j] < min1 && i != j) {
				min1 = w[i][j];
				t1 = i;
				t2 = j;
			}
		}
		w1[t1][t2] = INT_MAX;
		min[0][i] = min1;
		est += min1;
	}
	for (i = 0; i < n;i++) {
		min2 = INT_MAX;
		for (j = 0; j < n; j++) {
			if (w1[i][j] < min2 && i!= j) {
				min2 = w1[i][j];
			}
		}
		min[1][i] = min2;
		est += min2;
	}
	est /= 2.0;
//	printf("%f\n", est);
	int a[n];
	for (i = 0; i < n; i++) {
		a[i] = i;
		ans[i] = i;
	}
	curwt = 0.0;
	tsp(n, a, 0, curwt, est);
	for (i = 0; i < n; i++) printf("%d ",ans[i]);
	printf("0");
	printf("\nwmin %f\n", wmin); 
	return 0;
}
