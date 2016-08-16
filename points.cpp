#include <stdio.h>
#include <math.h>

void quick(int arr[],int b[], int low, int up);
int partition(int arr[],int b[],int low, int up);

void quick(int a[],int b[], int low, int up)
{
	int pivloc;
	if(low >= up)
		return ;
	pivloc = partition(a,b, low, up);
	quick(a,b, low, pivloc-1);
	quick(a,b, pivloc+1, up);
}

int partition(int a[],int b[], int low, int up)
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
			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
			i++;j--;
		}
		else
			i++;
	}
	a[low] = a[j];
	a[j] = pivot;
	temp = b[low];
	b[low] = b[j];
	b[j] = temp;
	return j;
}
double distance(int x[],int y[],int i,int j){
	double dist = sqrt(((y[j]-y[i])*(y[j]-y[i]))+((x[j]-x[i])*(x[j]-x[i])));
	printf("(x,y) (x2,y2) = %lf\n",dist);
	return dist;
}
double merge(int x[],int y[],int l,int u,int m,int ldist,int rdist)
{
	int i, j,min_x,min_y;
	double min, mid, dis;
	mid = (x[l]+x[u])/2.0;
	if (ldist<=rdist)
		min = ldist;
	else
		min = rdist;
	for(i = m;i>=l;i--){
		if ((mid-x[i]) > min) break;
		for(j=m+1;j<=u;j++){
			if(x[j]-mid>min) break;
			else {
				dis = distance(x,y,i,j);
				if(dis<min){
					min = dis;
				}		
			}
		}
	}
	return min;
}

double closestpair(int x[],int y[],int n,int l,int u)
{
	double dis,xm,ldis,rdis,med;
	int i,m;
	if (l == u)
		return 999999999;
	else if (l == u-1) {
		return distance(x, y,l,u);
	}
	else {
		med = (x[l]+x[u])/2.0;
		for(i=0;i<n;i++){
			if(x[i]>med){
				m = i-1;
				break;
			}
		}
		ldis = closestpair(x,y,n,l,m);
		rdis = closestpair(x,y,n,m+1,u);
		dis = merge(x, y, l, u, m, ldis, rdis);
	}
	//printf("%lf\n",dis);
	return dis;
}
int main()
{
	int n, i;
	double dist;
	printf("Enter the number of points: ");
	scanf("%d", &n);

	int x[n];
	int y[n];
	
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i],&y[i]);
	}
	quick(x,y, 0, n-1);
	dist = closestpair(x,y,n,0,n-1);
	printf("%lf\n",dist);
	return 0;
}

