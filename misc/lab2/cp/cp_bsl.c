#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef struct node {
	int i;
	int j;
	double dist;
}point;

point closepair(int x[], int y[], int l, int u);
double distance(int x[], int y[], int l, int u);
point merge(int x[], int y[], int l, int u, int m, point ldist, point rdist);
int partition_cormen(int a[], int b[], int low, int up);

void quick(int a[], int b[], int low, int up) {

	int pivloc;
	if (low >= up)
		return;
	pivloc = partition_cormen(a, b, low, up);
	quick(a, b, low, pivloc-1);
	quick(a, b, pivloc+1, up);
}

int partition_cormen(int a[], int b[], int low, int up)
{	
	int i, j, pivot, temp, t, p;
	pivot = a[up];
	p = b[up];
	i = low-1;
	
	for (j = low; j <= (up-1); j++) {
		if (a[j] <= pivot) {
			i = i+1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			t = b[i];
			b[i] = b[j];
			b[j] = t;
		}
	}
	a[up] = a[i+1];
	a[i+1] = pivot;
	b[up] = b[i+1];
	b[i+1] = p;
	
	return (i+1);
}

int main()
{
	int n, i;
	double dist;
	scanf("%d", &n);
	int x[n];
	int y[n];

	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}

	quick(x, y, 0, n-1);
	point pt;
	pt = closepair(x, y, 0, n-1);
	printf("Points are: (%d,%d) & (%d,%d)\nDistance is: %lf\n",x[pt.i],y[pt.i],x[pt.j],y[pt.j],pt.dist);

	return 0;
}

point closepair(int x[], int y[], int l, int u)
{
	double dist, mid;
	int m, i;
	point pt,ldist,rdist;
	pt.i = l;
	pt.j = u;
	
	if (l == u)  {
		pt.dist = INT_MAX;
		return pt;
	}
	else if (l == u-1) {
		pt.dist = distance(x, y, l, u);
		return pt;
	}
	else {
		mid = (x[l]+x[u])/2.0;
		for (i = l; i <= u; i++) {
			if (x[i] == mid) {
				m = i;
				break;
			}
			if (x[i] > mid) {
				m = i-1;
				break;
			}
			
		}
		ldist = closepair(x, y, l, m);
		rdist = closepair(x, y, m+1, u);
		pt = merge(x, y, l, u, m, ldist, rdist);
	}
	return pt;
}

double distance(int x[], int y[], int l, int u)
{
	double d;
	d = sqrt(((x[u]-x[l])*(x[u]-x[l])) + ((y[u]-y[l])*(y[u]-y[l])));
	return d;
}

point merge(int x[], int y[], int l, int u, int m, point ldist, point rdist)
{
	int i, j;
	point pt;
	double mid, d;
	mid = (x[l]+x[u])/2.0;

	if (ldist.dist <= rdist.dist) {
		pt.dist = ldist.dist;
		pt.i = ldist.i;
		pt.j = ldist.j;
	}
	else {
		pt.dist = rdist.dist;
		pt.i = rdist.i;
		pt.j = rdist.j;
	}
	
	for (i = m; i >= l; i--) {
		if ((mid-x[i]) > pt.dist) break;
		for (j = m+1; j <= u; j++) {
			if ((x[j]-mid) > pt.dist) break;
			d = distance(x, y, i, j);
			if (d <= pt.dist) {
				pt.dist = d;
				pt.i = i;
				pt.j = j;
			}
		}
	}
	return pt;
}

