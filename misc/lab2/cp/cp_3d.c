#include <stdio.h>
#include <math.h>
#include <limits.h>

double closepair(int x[], int y[], int z[], int n, int l, int u);
double distance(int x[], int y[], int z[], int l, int u);
double merge(int x[], int y[], int z[], int n, int l, int u, int m, double ldist, double rdist);

void quick(int a[], int b[], int c[], int low, int up) {

	int pivloc;
	if (low >= up)
		return;
	pivloc = partition_cormen(a, b, c, low, up);
	quick(a, b, c, low, pivloc-1);
	quick(a, b, c, pivloc+1, up);
}

int partition_cormen(int a[], int b[], int c[], int low, int up)
{	
	int i, j, pivot, temp, t, p;
	pivot = a[up];
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
	p = b[up];
	b[up] = b[i+1];
	b[i+1] = p;
	temp = c[up];
	c[up] = c[i+1];
	c[i+1] = temp;
	
	return (i+1);
}

int main()
{
	int n, i;
	double dist;
	scanf("%d", &n);
	int x[n];
	int y[n];
	int z[n];

	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
	}

	quick(x, y, z, 0, n-1);

	dist = closepair(x, y,z, n, 0, n-1);
	printf("%lf\n", dist);

	return 0;
}

double closepair(int x[], int y[], int z[], int n, int l, int u)
{
	double ldist, rdist, dist, mid;
	int m, i;

	if (l == u)
		return INT_MAX;
	else if (l == u-1) {
		return distance(x, y, z, l, u);
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
		ldist = closepair(x, y, z,n, l, m);
		rdist = closepair(x, y, z,n, m+1, u);
		dist = merge(x, y, z, n, l, u, m, ldist, rdist);
	}
	return dist;
}

double distance(int x[], int y[], int z[], int l, int u)
{
	double d;
	d = sqrt(((x[u]-x[l])*(x[u]-x[l])) + ((y[u]-y[l])*(y[u]-y[l])) + ((z[u]-z[l])*(z[u]-z[l])));

	return d;
}

double merge(int x[], int y[], int z[], int n, int l, int u, int m, double ldist, double rdist)
{
	int i, j, k;
	double dist, mid, d;
	mid = (x[l]+x[u])/2.0;

	if (ldist <= rdist)
		dist = ldist;
	else
		dist = rdist;

	for (i = m; i >= l; i--) {
		if (abs(mid-x[i]) > dist) break;
		for (j = m+1; j <= u; j++) {
			if (abs(x[j]-mid) > dist) break;
			for (k = l; k <= u; k++) {
				if (abs(z[k]-mid) > dist)
					break;
				d = distance(x, y, z, i, j);
				if (d < dist)
					dist = d;
			}
		}
	}
	return dist;
}

