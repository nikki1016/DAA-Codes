#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

double merg(int x[],int y[],int l,int u,int m,double dl,double dr);
int bin_search(int x[],int xm,int l,int u)
{
	int i;
	for(i=l;i<=u;)
	{	
		if(x[i]<xm)
			i++;
		else if(x[i]==xm)
			return i;
		else
			return i-1;
	}
	
}
void merge(int arr[],int b[],int temp[],int low1,int up1,int low2,int up2);
void copy(int arr[],int temp[],int low,int up)
{
	int i;
	for(i=low;i<=up;i++)
	arr[i]=temp[i];
}
void merge_sort(int arr[],int b[],int low,int up)
{
	int temp[100],mid;
	if(low<up)
	{
	mid=(low+up)/2;
	merge_sort(arr,b,low,mid);
	merge_sort(arr,b,mid+1,up);
	merge(arr,b,temp,low,mid,mid+1,up);
	copy(arr,temp,low,up);
	}
}
void merge(int arr[],int b[],int temp[],int low1,int up1,int low2,int up2)
{
	int i,j,k;
	i=low1;
	j=low2;
	k=low1;
	while(i<=up1&&j<=up2)
	{
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			b[k]=b[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=arr[j];
			b[k]=b[j];
			k++;
			j++;
		}
	}
	while(i<=up1)
	{
		temp[k]=arr[i];
		b[k]=b[i];
		k++;
		i++;
	}
	while(j<=up2)
	{
		temp[k]=arr[j];
		b[k]=b[j];
		k++;
		j++;
	}
}
double dist(int x[],int y[],int l,int u)
{
	return sqrt((x[l]-x[u])*(x[l]-x[u])+(y[l]-y[u])*(y[l]-y[u]));
}
double cp(int x[],int y[],int l,int u)
{
	if(l==u)
		return 9999;
	if(l==u-1)
		return dist(x,y,l,u);
	double xm,dl,dd,dr;
	int m;
	xm=(x[l]+x[u])/2;
	m=bin_search(x,xm,l,u);
	dl=cp(x,y,l,m);
	dr=cp(x,y,m+1,u);
	dd=merg(x,y,l,u,m,dl,dr);
	return dd;
}
double min(double a,double b)
{
	if(a<b)
		return a;
	else
		return b;
}
double merg(int x[],int y[],int l,int u,int m,double dl,double dr)
{
	double dd,dis,xm=(x[l]+x[u])/2;
	dd=min(dl,dr);
	int i,j;
	for(i=m;i>=l;i--)
	{
		if(abs(xm-x[i])>dd)
			break;
		for(j=m+1;j<=u;j++)
		{
			if(abs(x[j]-xm)>dd)
				break;
			dis=dist(x,y,i,j);
			if(dis<dd)
				dd=dis;
		}
	}
	return dd;
}
int main()
{
	int n,i;
	double d;
	time_t t;
	srand((unsigned)time(&t));
	scanf("%d",&n);
	int x[n+1],y[n+1];
	for(i=1;i<=n;i++)
	{
//		x[i]=rand()%10;
//		y[i]=rand()%10;
		scanf("%d %d",&x[i],&y[i]);
	}
	merge_sort(x,y,1,n);
	for(i=1;i<=n;i++)
	{
		printf("%d %d\n",x[i],y[i]);
	}
	d=cp(x,y,1,n);
	printf("%lf\n",d);
	return 0;
}


