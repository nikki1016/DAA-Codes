# include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 99999

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
		ch[k].x = INF;
		ch[k++].y = INF;
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
		
		ch[3].x = INF;
		ch[3].y = INF;
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
	
	/*cout << "LEFT HULL" << endl;
	for (int i = 0; chleft[i].x != INF; i++) {
		cout << chleft[i].x  << chleft[i].y << endl;
	}
	cout << "RIGHT HULL" << endl;
	for (int i = 0; chright[i].x != INF; i++) {
		cout << chright[i].x  <<" " <<  chright[i].y << endl;
	}*/
	
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

point *conquer(point lhull[] , point rhull[]) {
	int i = 0;
	int j = 0, min_x, max_x, max_l, min_l, min_r, max_r;
	cout<<"Left Hull Is\n";
	for(j=0;lhull[j].x!=INF;j++){
		cout<<lhull[j].x<<"\t"<<lhull[j].y<<"\n";
	}
	cout<<"Right Hull Is\n";
	for(j=0;rhull[j].x!=INF;j++){
		cout<<rhull[j].x<<"\t"<<rhull[j].y<<"\n";
	}
	
	double max = -INF;
	max_x = 0;
	for (j = 0; lhull[j].x != INF; j++) {
		if (max < lhull[j].x) {
			max = lhull[j].x;
			max_x = j;
		}
	}
	int n = j;//number of points in lhull
	i = max_x;
	double min = INF;
	for (j = 0; rhull[j].x != INF; j++) {
		if (min > rhull[j].x) {
			min = rhull[j].x;
			min_x = j;
		}
	}
	int m = j;//number of points in rhull
	j = min_x;
	point *chull = new point[n+m+1];
	//FINDING UPPER TANGENT
	while ((ccw(lhull[f(i-1, n)], lhull[i], rhull[j]) > 0) || (ccw(lhull[i], rhull[j], rhull[f(j+1, m)]) > 0)) {
		while (ccw(lhull[f(i-1, n)], lhull[i], rhull[j]) > 0) {
			i = f(i-1, n);
		}
		while (ccw(lhull[i], rhull[j], rhull[f(j+1, m)]) > 0) {
			j = f(j+1, m);
		}
	}

	max_l = i;
	max_r = j;
	i = max_x;
	j = min_x;
	//FINDING LOWER TANGENT
	while ((ccw(lhull[f(i+1, n)], lhull[i], rhull[j]) < 0) || (ccw(lhull[i], rhull[j], rhull[f(j-1, m)]) < 0)) {
		
		while (ccw(lhull[f(i+1, n)], lhull[i], rhull[j]) < 0) {
			i = f(i+1, n);
		}
		while (ccw(lhull[i], rhull[j], rhull[f(j-1, m)]) < 0) {
			j = f(j-1, m);
		}
	}
	cout<<"Here i = "<<i<<"\n";
	//CHECKING FOR COLINEAR POINTS
	if ((ccw(lhull[f(i+1, n)], lhull[i], rhull[j]) == 0) && (ccw(lhull[i], rhull[j], rhull[f(j-1, m)]) == 0)) {
		i = f(i+1, n);
		j = f(j-1, m);
	}
	min_l = i;
	min_r = j;
	int k = 0;
	//Printing
	cout<<min_l<<"min_l \t min_r " <<min_r;
	while(min_l!=max_l){
	chull[k].x = lhull[min_l].x;
	chull[k++].y = lhull[min_l].y;	
	min_l = f(min_l+1,n);
	}
	chull[k].x = lhull[max_l].x;
	chull[k++].y = lhull[max_l].y;
	
	while(max_r!=min_r){
	chull[k].x = rhull[max_r].x;
	chull[k++].y = rhull[max_r].y;
	max_r = f(max_r+1,m);	
	}
	chull[k].x = rhull[min_r].x;
	chull[k++].y = rhull[min_r].y;
	chull[k].x = INF;
	chull[k++].y = INF;
	cout<<"After Merging\n";
	for (int i = 0; chull[i].x != INF; i++) {
		cout << chull[i].x << "\t" << chull[i].y << endl;
	}
	cout<<"\n";
	return chull;
}

int main()
{
	ifstream fin;
	
	int n, i;

	cin >> n;
	point a[n], c[n];
	
	/*srand((unsigned int)time(NULL));
    double a = 5.0;
	for (i = 0; i < n; i++) {
        x[i] = (((double)rand()/(double)(RAND_MAX)) * a);
        y[i] = (((double)rand()/(double)(RAND_MAX)) * a);
        p[i] = make_pair(x[i],y[i]);
    }*/
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
	for (i = 0; b[i].x != INF; i++) {
		flag[i] = 1;
	}
	for (i = 0; b[i+2].x != INF; i++) {
		if (ccw(b[i], b[i+1], b[i+2]) == 0) {
			flag[i+1] = 0;
		}
	}
	k = 0;
	for (i = 0; b[i].x != INF; i++) {
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


