# include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define aman 99999
using namespace std;

typedef struct node {
	double x, y;
}point;

bool comp (point a, point b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return (a.x < b.x);
}

double angle(point c, point d) {
	double t = (c.y - d.y) / (sqrt(((c.x - d.x) * (c.x - d.x)) + ((c.y - d.y) * (c.y - d.y))));
	return acos(t);
}

double ccw(point a, point b, point c) {
	double d = (((b.x - a.x) * (c.y - a.y)) - ((b.y - a.y) * (c.x - a.x)));
	return d;
}

point *brute(point b[], int low, int high, int n) {
	int k = 0;
	point *ch = new point[5];
	if (n == 2) {
		for (int i = high; i >= low; i--) {
			ch[k].x = b[i].x;
			ch[k++].y = b[i].y;
		}
		ch[k].x = aman;
		ch[k++].y = aman;
	}
	else {
		ch[0].x = b[high].x;
		ch[0].y = b[high].y;
		double d1 = angle(ch[0], b[low]);
		double d2 = angle(ch[0], b[low+1]);
		if (d1 < d2) {
			ch[1].x = b[low].x;
			ch[1].y = b[low].y;
			ch[2].x = b[low+1].x;
			ch[2].y = b[low+1].y;
		}
		else {
			ch[1].x = b[low+1].x;
			ch[1].y = b[low+1].y;
			ch[2].x = b[low].x;
			ch[2].y = b[low].y;
		}
		
		ch[3].x = aman;
		ch[3].y = aman;
	}
	return ch;
}

point *conquer(point a[],point b[]);	

point *divide(point a[], int low, int high, int n) {
	if (n <= 3) {
		return brute(a, low, high, n);
	}
	int mid = (low + high) / 2;
	int m = (n+1)/2;
	point *chleft = divide(a, low, mid, m);
	point *chright = divide(a, mid + 1, high, n - m);
	point *chull = conquer(chleft, chright);
	return chull;
}

int f(int a, int b) {
	if (a == b) {
		return 0;
	}
	else if (a < 0){
		return b - 1;
	}
	else {
		return a;
	}
}

point *conquer(point c1[] , point c2[]) {
	int i = 0;
	int j = 0, p, s, e, g, h, o;
	double max = -aman;
	s = 0;
	for (j = 0; c1[j].x != aman; j++) {
		if (max < c1[j].x) {
			max = c1[j].x;
			s = j;
		}
	}
	int n = j;
	i = s;
	double min = aman;
	for (j = 0; c2[j].x != aman; j++) {
		if (min > c2[j].x) {
			min = c2[j].x;
			p = j;
		}
	}
	int m = j;
	j = p;
	point *chull = new point[n+m+1];
	while ((ccw(c1[f(i-1, n)], c1[i], c2[j]) > 0) || (ccw(c1[i], c2[j], c2[f(j+1, m)]) > 0)) {
		while (ccw(c1[f(i-1, n)], c1[i], c2[j]) > 0) {
			i = f(i-1, n);
		}
		while (ccw(c1[i], c2[j], c2[f(j+1, m)]) > 0) {
			j = f(j+1, m);
		}
	}

	e = i;
	o = j;
	i = s;
	j = p;
	while ((ccw(c1[f(i+1, n)], c1[i], c2[j]) < 0) || (ccw(c1[i], c2[j], c2[f(j-1, m)]) < 0)) {
		
		while (ccw(c1[f(i+1, n)], c1[i], c2[j]) < 0) {
			i = f(i+1, n);
		}
		while (ccw(c1[i], c2[j], c2[f(j-1, m)]) < 0) {
			j = f(j-1, m);
		}
	}
	if ((ccw(c1[f(i+1, n)], c1[i], c2[j]) == 0) && (ccw(c1[i], c2[j], c2[f(j-1, m)]) == 0)) {
		i = f(i+1, n);
		j = f(j-1, m);
	}
	g = i;
	h = j;
	int k = 0;
	chull[k].x = c1[e].x;
	chull[k++].y = c1[e].y;
	while(o != h) {
		chull[k].x = c2[o].x;
		chull[k++].y = c2[o].y;
		o = f(o+1, m);
	}
	chull[k].x = c2[h].x;
	chull[k++].y = c2[h].y;
	while (g != e) {
		chull[k].x = c1[g].x;
		chull[k++].y = c1[g].y;
		g = f(g+1, n);
	}
	chull[k].x = aman;
	chull[k++].y = aman;
/*	for (int i = 0; chull[i].x != aman; i++) {
		cout << chull[i].x << " dr " << chull[i].y << endl;
	}*/
	return chull;
}

int main()
{
	ifstream fin;
	
	int n, i;
//	cout << "Enter the o. of points\n";
	cin >> n;
	point a[n], c[n];
//	cout << "Enter the points\n";
	for (i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
//	cout << endl;
	sort(a, a + n, comp);
	/*c[0].x = a[0].x;
	c[0].y = a[0].y;
	int k = 1;
	for (int i = 1; i < n; i++) {
		if (a[i].x != a[i-1].x || a[i].y != a[i-1].y) {
			c[k].x = a[i].x;
			c[k++].y = a[i].y;
		}
	}*/
	int flag[1000];
	for (i = 0; i < n; i++) {
		flag[i] = 1;
	}
	for (i = 0; i < n - 2; i++) {
		if (ccw(a[i], a[i+1], a[i+2]) == 0) {
			flag[i+1] = 0;
		}
	}
	int k = 0;
	for (i = 0; i < n; i++) {
		if (flag[i] == 1) {
			c[k].x = a[i].x;
			c[k++].y = a[i].y;
		}
	}

//	ofstream fout("output.txt");
	point *b;
	b = divide(c, 0, k-1, k);
	cout << "The points in convex hull are\n";
	for (i = 0; b[i].x != aman; i++) {
		flag[i] = 1;
	}
	for (i = 0; b[i+2].x != aman; i++) {
		if (ccw(b[i], b[i+1], b[i+2]) == 0) {
			flag[i+1] = 0;
		}
	}
	k = 0;
	for (i = 0; b[i].x != aman; i++) {
		if (flag[i] == 1) {
			c[k].x = b[i].x;
			c[k++].y = b[i].y;
		}
	}
//	cout << k << endl;

	for (i = 0; i < k; i++) {
		cout << c[i].x<< " " << c[i].y << endl;
	}
	return 0;
}


