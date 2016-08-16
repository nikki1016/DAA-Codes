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

void tsp(int w[][100],int n,int s[],int level,double e,double cw){
	c++;
	if(level==n-1 && w[s[level]][1]+cw < wmin){
		wmin=cw+w[s[level]][1];
		int i;
		for(i=0;i<n;i++) {
			sol[i]=s[i];
		}
	}
	else
	{
		int i,j,v;
		double e1,cw1;
		for(i = 1; i < n; i++)
		{
			v = validity(i, s, n, level);
			if (v==1)
			{
				cw1=cw+w[s[level]][i];
				e1=e-0.5*(min[s[level]][1]+min[i][1]);
				if(cw1+e1<wmin)
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
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&wt[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(wt[i][j]==0) wt[i][j] = INF;
		}
	}
	int a[n+1];
	int s[n+1];
	s[0] = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[j] = wt[i][j];
		}
		quick(a,0,n-1);
		min[i][0] = a[0];
		min[i][1] = a[1];
//		if(a[1]== INF )
	}
/*	for(i=1;i<=n;i++){
		printf("%d %d\n",min[i][0],min[i][1]);
	}
*/	double e = 0;
	for(i=0;i<n;i++){
		e = e+ (min[i][0]+min[i][1]);
	}
	e = e/2;
//	sol[0] = 1;
//	printf("e = %lf\n",e);
	for(i=0;i < n-1;i++){
//			printf("wmin = %lf\n",wmin);
			wmin += wt[i][i+1];
			sol[i] = i;
	}
	wmin+=wt[n-1][0];
	sol[n-1] = n-1;
	printf("wmin = %lf\n",wmin);
	int m,up = 0;
	for(i=0;i<n;i++){
		m = -1;
		for(j=0;j<n;j++){
			if( m < wt[i][j] && wt[i][j] != INF  ){
				m = wt[i][j];
			}
		}
		up += m;
	}
	printf("up : %d \n",up );
	/*	cur = 1;
	for(i=1; i < n;i++){
		visited[cur] = 1;
		sol[i-1] = cur;
		m = INF;
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
	sol[i-1] = cur; */
//	printf("wmin = %lf\n",wmin);
	tsp(wt,n,s,0,e,0);
	if(wmin > up){
		printf("NO SOLUTION\n");
	}
	else {
		printf("%lf\n",wmin);
		for(i=0;i<n;i++) {
			printf("%d->",sol[i]);
		}
		printf("0\n");
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
