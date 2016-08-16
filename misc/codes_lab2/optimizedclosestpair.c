#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
double merg(int x[],int y[],int l,int u,int m,double dl,double dr);
int bin_search(int x[],int xm,int l,int u)
{
	int mid,pos,flag=0;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(x[mid]==xm)
		{
			flag=1;
			pos=mid;
			break;
		}
		else if(xm<x[mid])
		{
			u=mid-1;
		}
		else
			l=mid+1;
	}
	if(flag==1)
	return pos;
	if(xm<x[mid])
	return mid-1;
	else
	return mid+1;
}
void merge(int arr[],int b[],int temp[],int temp2[],int low1,int up1,int low2,int up2);
void copy(int arr[],int b[],int temp[],int temp2[],int low,int up)
{
	int i;
	for(i=low;i<=up;i++)
	{
		arr[i]=temp[i];
		b[i]=temp2[i];
	}
}
void merge_sort(int arr[],int b[],int low,int up)
{
	int temp[100],temp2[100],mid;
	if(low<up)
	{
	mid=(low+up)/2;
	merge_sort(arr,b,low,mid);
	merge_sort(arr,b,mid+1,up);
	merge(arr,b,temp,temp2,low,mid,mid+1,up);
	copy(arr,b,temp,temp2,low,up);
	}
}
void merge(int arr[],int b[],int temp[],int temp2[],int low1,int up1,int low2,int up2)
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
			temp2[k]=b[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=arr[j];
			temp2[k]=b[j];
			k++;
			j++;
		}
	}
	while(i<=up1)
	{
		temp[k]=arr[i];
		temp2[k]=b[i];
		k++;
		i++;
	}
	while(j<=up2)
	{
		temp[k]=arr[j];
		temp2[k]=b[j];
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
	int i;
	if(l==u)
		return 9999;
	if(l==u-1)
		return dist(x,y,l,u);
	double xm,dl,dd,dr;
	int m;
	xm=(x[l]+x[u])/2;
	m=bin_search(x,xm,l,u);
//	printf("xm=%lf m=%d\n",xm,m);
//		for(i=l;i<=u;i++)
//	{
//		printf("%d %d\n",x[i],y[i]);
//	}
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
//	printf("dd=%lf dl=%lf dr=%lf\n",dd,dl,dr);
	int i,j;
	merge_sort(y,x,l,m);
	merge_sort(y,x,m+1,u);
//	for(i=l;i<=m;i++)
//	{
//		printf("l=%d %d\n",x[i],y[i]);
//	}
//	printf("\n");
//	for(i=m+1;i<=u;i++)
//	{
//		printf("m+1=%d %d\n",x[i],y[i]);
//	}
	int start=m+1,end=start+5;
	for(i=1;i<=m;i++)
	{
		for(j=start;j<=end&&j<=u;j++)
		{
			dis=dist(x,y,i,j);
			if(dis<dd)
				dd=dis;
		}
		while(abs(y[start]-y[i+1])>dd)
		start++;
		end=start+5;
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


