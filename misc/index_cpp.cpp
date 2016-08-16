#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

struct ans {
	float dist;
	int ind1, ind2;
};

int partition (int a[],int b[], int p, int r)

{

	int j,temp;

	int x = a[r]; //choosing last element as pivot

	int i= p-1;

	for(j=p;j<r;j++)

	{

		if(a[j]<=x) {

			i++;

			temp = a[j];

			a[j] = a[i];

			a[i] = temp;
			temp = b[j];
			b[j] = b[i];
			b[i] = temp;

		}

	}

	temp = a[i+1];

	a[i+1] = a[r];

	a[r] = temp;
	temp = b[i+1];
	b[i+1] = b[r];
	b[r] = temp;

	return i+1;

}


void sort(int x[],int y[], int p, int r)

{

	if (p < r) {

		int q = partition(x,y,p,r);

		sort(x,y,p,q-1);

		sort(x,y,q+1,r);

	}

}

float distance (int x1, int x2, int y1, int y2)
{
	float temp = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return sqrt(temp);
}

int binary_search (float q,int a[], int l, int u)
{
	
	if(l<=u) {
		int mid = (l+u)/2;
		if (a[mid] == q) return mid;
		if(a[mid]<q){
			if(mid==u) return u;
			else if(a[mid+1]>q) return mid;
			binary_search(q,a,mid+1,u);
		}
		if(a[mid]>q){
			if(mid==l) return l;
			else if(a[mid-1]<q) return mid-1;
			binary_search(q,a,l,mid-1);
		}
	}
}

struct ans* merge(int x[], int y[], int n, int l, int u, int m,struct ans* val_l, struct ans* val_r)
{
	struct ans* temp = (struct ans*)malloc(sizeof (struct ans));
	float q = (x[l]+x[u])/2.0;
	float val_min;
	if(val_l->dist < val_r->dist){
		val_min = val_l->dist;
		temp->dist = val_l->dist;
		temp->ind1 = val_l->ind1;
		temp->ind2 = val_l->ind2;
	}
	else {
		val_min = val_r->dist;
		temp->dist = val_r->dist;
		temp->ind1 = val_r->ind1;
		temp->ind2 = val_r->ind2;
	}

	int i,j;
	for(i=m;i>=l;i--)
	{
		if((q-x[i])>val_min) break;
		for(j=m+1;j<=u;j++)
		{
			if((x[j]-q)>val_min) break;
			float dist = distance(x[i],x[j],y[i],y[j]);
			if(dist<val_min) {
				val_min = temp->dist = dist;
				temp->ind1 = i;
				temp->ind2 = j;
			}
		}
	}
	return temp;
}


struct ans* cp(int x[], int y[], int n, int l, int u)
{
	struct ans* temp = (struct ans*)(malloc)(sizeof(struct ans));
	if(l==u) {
		temp->dist = FLT_MAX;
		temp->ind1 = l;
		temp->ind2 = l;
		return temp;
	}
	if(l==u-1) {
		temp->dist = distance(x[l],x[u],y[l],y[u]);
		temp->ind1 = l;
		temp->ind2 = u;
		return temp;
	}
	float q = (x[l]+x[u])/2.0;
	int m = binary_search(q,x,l,u);
	struct ans* val_l = cp(x,y,n,l,m);
	struct ans* val_r = cp(x,y,n,m+1,u);
	struct ans* val_min = merge(x,y,n,l,u,m,val_l,val_r);
	return val_min;
}


int main()
{
	int n,i,j,k;
	int x1,y1,x2,y2;
	struct ans* cd;
	scanf("%d",&n);
	int x[n+1],y[n+1],a[n+1],b[n+1];
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	
	for(i=1;i<=n;i++) {
		a[i] = x[i];
		b[i] = y[i];
	//	printf("%d %d\n",x[i],y[i]);
	}
	sort(x,y,1,n);
	cd = cp(x,y,n,1,n);
	x1 = x[cd->ind1];
	x2 = x[cd->ind2];
	y1 = y[cd->ind1];
	y2 = y[cd->ind2];
	for(i=1;i<=n;i++){
		if(a[i]==x1&&b[i]==y1) break;
	}
	for(j=1;j<=n;j++){
		if(a[j]==x2&&b[j]==y2) break;
	}
	printf("%d %d %f\n",i-1,j-1,cd->dist);
	return 0;
}

