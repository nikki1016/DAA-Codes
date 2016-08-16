#include <stdio.h>

int count=0,l[100][100],marked[100],ss[100];

double wmin;//=99999;

void bubble(int n,int k)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(l[k][j]>l[k][j+1])
			{
				t=l[k][j];
				l[k][j]=l[k][j+1];
				l[k][j+1]=t;
			}
		}
	}
}

int validity(int i,int s[], int n, int ll)
{
	int j;
	for(j = 0; j <= ll; j++)
	{
		if (i == s[j])
			return 0;
	}                                                      
	return 1;
}

void tsp(int w[][100],int n,int s[],int ll,double e,double cw)
{
	count++;
	if(ll==n-1&&cw+w[s[ll]][1]<wmin)
	{
		wmin=cw+w[s[ll]][1];
		int i;
		for(i=0;i<n;i++)
		{
			ss[i]=s[i];
		}
	}
	else
	{	//printf("Hello\n");
		int i,j,v;
		double e1,cw1;
		for(i = 2; i <= n; i++)
		{
			v = validity(i, s, n, ll);
			if (v==1)
			{
				cw1=cw+w[s[ll]][i];
				e1=e-0.5*(l[s[ll]][2]+l[i][2]);
				if(cw1+e1<wmin)
				{
					s[ll+1]=i;
					tsp(w,n,s,ll+1,e1,cw1);
				}
			}
		}
	}
}

int main()
{
	int i,j,w[100][100],n,s[100];
	double e=0,cw=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&w[i][j]);
			l[i][j]=w[i][j];
		}
		bubble(n,i);
	}
	for(i=1;i<=n;i++){
		printf("%d %d\n",l[i][1],l[i][2]);
	}	
	for(i=1;i<=n;i++)
	{
		e=e+l[i][1]+l[i][2];
	}
	e=e/2;
	printf("e = %lf\n",e);
	s[0]=1;
	for(i=1;i<n;i++){
		printf("wmin = %lf\n",wmin);
			wmin+=w[i][i+1];
	}
//		wmin+=w[i][i+1];
	wmin+=w[n][1];
	printf("wmin = %lf\n",wmin);
	tsp(w,n,s,0,e,0); 
	for(i=0;i<n;i++)
	{
			printf("%d->",ss[i]);
	}
	printf("1\n");
	printf("%lf\n",wmin);
	printf("%d\n",count);
	return 0;
}
