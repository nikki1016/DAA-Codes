#include <iostream>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <algorithm>
using namespace std;

struct node{
	double dis;
	int x;
	int y;
};
double distance(int x[],int y[],int i,int j){
	double dist = sqrt(((y[j]-y[i])*(y[j]-y[i]))+((x[j]-x[i])*(x[j]-x[i])));
	printf("(x,y) (x2,y2) = %lf\n",dist);
	return dist;
}
struct node* merge(int x[],int y[],int l,int u,int m,struct node* ldist,struct node* rdist)
{
	int i, j,min_x,min_y;
	struct node* min = NULL;
	double mid, dis;
	mid = (x[l]+x[u])/2.0;
	if (ldist->dis <= rdist->dis)
		min = ldist;
	else
		min = rdist;
	for(i = m;i>=l;i--){
		if ((mid-(double)x[i]) > min->dis) break;
		for(j=m+1;j<=u;j++){
			if(x[j]-mid>min->dis) break;
			else {
				dis = distance(x,y,i,j);
				if(dis<min->dis){
					min->dis = dis;
					min->x = i;
					min->y = j;
				}		
			}
		}
	}
	return min;
}

struct node* closestpair(int x[],int y[],int n,int l,int u)
{
	double dis,xm,med;
	struct node *min = NULL, *ldis= NULL, *rdis = NULL;
	int i,m;
	if (l == u){
			min->dis = 999999999;
			min->x = l;
			min->y = u;
			return min;
		}
	else if (l == u-1) {
			min->dis = distance(x, y,l,u);
			min->x = l;
			min->y = u;
			return min;
		}
	else {
		int flag = 0;
		int k = x[l];
		cout<<"Testing x\n";
		for(i = l +1 ;i<=u;i++){
			if(x[i]!=k){
				flag = 1;
				cout<<"Flag set to 1\n";
				break;
			}
		}
		if(flag == 0){
		//	cout<<"Flag set to 0\n"<<l<<"\n"<<y[l+1]<<y[l];
			dis = sqrt((double)(y[l+1]-y[l])*(double)(y[l+1]-y[l]));
			min->dis = dis;
			min->x = l;
			min->y = l+1;
			return min;
		}
		else {			
			med = (x[l]+x[u])/2.0;
			if(med == x[u]) med = med -1;
			for(i=0;i<n;i++){
				if(x[i]>med){
					m = i-1;
					break;
				}
			}
			ldis = closestpair(x,y,n,l,m);
			rdis = closestpair(x,y,n,m+1,u);
	//		printf(" In Merge ldis = %lf rdis = %lf\n",ldis,rdis);
			min = merge(x, y, l, u, m, ldis, rdis);	
			return min;
		}
	}
}
int main()
{
	int n, i;
	struct node *d;
	printf("Enter the number of points: ");
	scanf("%d", &n);

	int x[n];
	int y[n];
	pair <int, int> p[n];	
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i],&y[i]);
		p[i] = make_pair(x[i],y[i]);
	}
//	quick(x,y, 0, n-1);
	sort(p,p+n);
	for (i = 0; i < n; i++) {
	//	scanf("%d%d", &x[i],&y[i]);
	x[i]=p[i].first; //= x[i];
	y[i]=p[i].second;// = y[i];
	}
	d = closestpair(x,y,n,0,n-1);
	printf("%d %d %lf\n",d->x,d->y,d->dis);
	return 0;
}

