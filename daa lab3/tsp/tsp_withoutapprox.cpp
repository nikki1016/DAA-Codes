#include <stdio.h>
#define MAX 100
int min[MAX][2];
double wmin;
int sol[MAX];
int c;
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
void tsp(int w[][100],int n,int s[],int level,double e,double cw) {
	c++;
	if(level==n-1 && w[s[level]][1]+cw < wmin){
		wmin=cw+w[s[level]][1];
		int i;
		for(i=0;i<n;i++) {
			sol[i]=s[i];
		}
	}
	else
	{	printf("Hello\n");
		int i,j,v;
		double e1,cw1;
		for(i = 2; i <= n; i++)
		{
			v = validity(i, s, n, level);
			if (v==1)
			{
				cw1=cw+w[s[level]][i];
			//	e1=e-0.5*(min[s[level]][1]+min[i][1]);
				if(cw1<wmin)
				{
					s[level+1]=i;
					tsp(w,n,s,level+1,e1,cw1);
				}
			}
		}
	}
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
			if(wt[i][j]==0) wt[i][j] = 9999999;
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
	}
/*	for(i=1;i<=n;i++){
		printf("%d %d\n",min[i][0],min[i][1]);
	}*/
	int visited[n];
	double e = 0;
	for(i=1;i<=n;i++){
		visited[i] = 0;
		e = e+ (min[i][0]+min[i][1]);
	}
	e = e/2;
//	printf("e = %lf\n",e);
	int cur,mini,m;
	cur = 1;
	for(i=1; i < n;i++){
		visited[cur] = 1;
		m = 999999;
		for(j=1;j<=n;j++){
			if(cur !=j && m>wt[cur][j] && visited[j] == 0){
				m = wt[cur][j];
				mini = j;
			}
		}
		wmin += m;
		cur = mini;
	}
	wmin +=wt[cur][1];
	tsp(wt,n,s,0,e,0); 
	printf("%lf\n",wmin);
	for(i=0;i<n;i++) {
			printf("%d->",sol[i]);
	}
	printf("1\n");
	printf("counter c = %d\n",c);
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
