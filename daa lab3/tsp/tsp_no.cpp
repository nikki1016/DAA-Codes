#include <stdio.h>
#define MAX 100
#define INF 99999
int min[MAX][2];
double wmin;
int c;
int sol[MAX];
void quick(int arr[], int low, int up);
int partition(int arr[], int low, int up);

int validity(int i,int s[], int n, int level)
{
	int j;
	for(j = 0; j <= level; j++)
	{
		if (i == s[j])
			return 0;
	}                                                      
	return 1;
}

int tsp(int w[][100],int n,int s[],int level,double e,double cw){
	c++;
	int f = 0;
	if(level == n-1 && w[s[level]][1]==INF) return 0;
	if(level==n-1 && w[s[level]][1]+cw < wmin){
		printf("Here\n");
		wmin=cw+w[s[level]][1];
		int i;
		for(i=0;i<n;i++) {
			sol[i]=s[i];
		}
		return 1;
	}
	else
	{
		int i,j,v,k;
		double e1,cw1;
		for(i = 2; i <= n; i++)
		{
			v = validity(i, s, n, level);
			if (v==1 && w[sol[level]][i] != INF)
			{
				cw1=cw+w[s[level]][i];
				e1=e-0.5*(min[s[level]][1]+min[i][1]);
				if(cw1+e1<wmin)
				{
					s[level+1]=i;
					k = tsp(w,n,s,level+1,e1,cw1);
					if(k==1) f = 1;
				}
			}
		}
	}	
	return f; 
}
int main() {
	int wt[MAX][MAX]={999999};
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&wt[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(wt[i][j]==0) wt[i][j] = INF;
		}
	}
	
	int a[n+1];
	int s[n+1];
	s[0] = 1;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			a[j] = wt[i][j];
		}
		quick(a,1,n);
		min[i][0] = a[1];
		min[i][1] = a[2];
	/*	if(a[1] == INF || a[2] == INF){
			printf("No solution\n");
			return 0;
		}*/
	}
/*	for(i=1;i<=n;i++){
		printf("%d %d\n",min[i][0],min[i][1]);
	}
*/	double e = 0;
	for(i=1;i<=n;i++){
		e = e+ (min[i][0]+min[i][1]);
	}
	e = e/2;
//	printf("e = %lf\n",e);
	for(i=1;i<n;i++){
//			printf("wmin = %lf\n",wmin);
			wmin += wt[i][i+1];
	}	
	wmin+=wt[n][1];
	printf("wmin = %lf\n",wmin);
	int m,up = 0;
	for(i=1;i<=n;i++){
		m = -1;
		for(j=1;j<=n;j++){
			if( wt[i][j] != INF && m > wt[i][j]){
				m = wt[i][j];
				up += m;
			}
		}
	}
	int f = tsp(wt,n,s,0,e,0);
	if(f==0) printf("No Solution\n");
	else {
		printf("%lf\n",wmin);
		for(i=0;i < n;i++) {
			printf("%d->",sol[i]);
		}
		printf("1\n");
		printf("counter c = %d\n",c);
	}
	return 0;

}

void quick(int a[], int low, int up)
{
	int pivloc;

	if(low >= up)
		return ;

	pivloc = partition(a, low, up);

	quick(a, low, pivloc-1);
	quick(a, pivloc+1, up);
}

int partition(int a[], int low, int up)
{
	int temp, i, j, pivot;

	i = low+1;
	j = up;

	pivot = a[low];

	while (i <= j) {
		while ((a[i] < pivot) && (i < up))
			i++;
		while (a[j] > pivot)
			j--;

		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;j--;
		}
		else
			i++;
	}

	a[low] = a[j];
	a[j] = pivot;

	return j;

}
