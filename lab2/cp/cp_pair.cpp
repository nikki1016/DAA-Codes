#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

double closepair(int x[], int y[], int n, int l, int u);
double distance(int x[], int y[], int l, int u);
double merge(int x[], int y[], int n, int l, int u, int m, double ldist, double rdist);

int px, py, qx, qy;

int main()
{
	int n, i;
	double dist;
	scanf("%d", &n);
	int x[n];
	int y[n];
	pair<int,int> p[n];

	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		p[i] = make_pair(x[i], y[i]);
	}

	sort(p, p+n);
	
	for (i = 0; i < n; i++) {
		x[i] = p[i].first;
		y[i] = p[i].second;
	}

	dist = closepair(x, y, n, 0, n-1);
	printf("x: %d y: %d\tx: %d y: %d\n", px, py, qx, qy);
	printf("%lf\n", dist);
	

	return 0;
}

double closepair(int x[], int y[], int n, int l, int u)
{
	double ldist, rdist, dist, mid;
	int m, i;

	if (l == u)
		return INT_MAX;
	else if (l == u-1) {
		return distance(x, y, l, u);
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
		ldist = closepair(x, y, n, l, m);
		rdist = closepair(x, y, n, m+1, u);
		dist = merge(x, y, n, l, u, m, ldist, rdist);
	}
	return dist;
}

double distance(int x[], int y[], int l, int u)
{
	double d;
	//cout<<l<<u<<endl;
	d = sqrt(((x[u]-x[l])*(x[u]-x[l])) + ((y[u]-y[l])*(y[u]-y[l])));

	return d;
}

double merge(int x[], int y[], int n, int l, int u, int m, double ldist, double rdist)
{
	int i, j;
	double dist, mid, d;
	mid = (x[l]+x[u])/2.0;

	if (ldist <= rdist) {
		dist = ldist;
	/*	px = x[l];
		py = y[l];
		qx = x[u];
		qy = y[u];*/
		//printf("x: %d y: %d\tx: %d y: %d\n", px, py, qx, qy);
	}
		
	else {
		dist = rdist;
		px = x[l];
		py = y[l];
		qx = x[u];
		qy = y[u];
		//printf("x: %d y: %d\tx: %d y: %d\n", px, py, qx, qy);	
	}
		

	for (i = m; i >= l; i--) {
		if ((mid-x[i]) > dist) break;
		for (j = m+1; j <= u; j++) {
			if ((x[j]-mid) > dist) break;
			d = distance(x, y, i, j);
			if (d <= dist) {
				dist = d;
				px = x[i];
				py = y[i];
				qx = x[j];
				qy = y[j];
				//printf("x: %d y: %d\tx: %d y: %d\n", px, py, qx, qy);
			}
		}
	}
	return dist;
}

