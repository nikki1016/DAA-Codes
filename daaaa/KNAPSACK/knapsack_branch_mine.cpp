#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node 
{
	double r;
	double wt;
	double p;
};

bool pred( struct node m , struct node o )
{
	if ( m.r >= o.r)
	{
		return true;
	}

	else
	{
		return false;
	}
}


double fractional ( int c,int n, int rw, struct node a[] )
{
	struct node b[n];
	int g = 0;
	int p = 0;
	int j = 0;

	for ( int i = c; i < n; i++ )
	{

		b[j].r = a[i].r;
		b[j].wt = a[i].wt;
		b[j].p = a[i].p;
		j++;
	}

	j = 0;

	c = n - c;


	sort(b,b+c,pred);

	while ( g + b[j].wt <= rw && j < c )
	{
		g = g + b[j].wt;
		p = p + b[j].p;
		j++;

	}

	g = rw - g;

	p = p + g*(b[j].r);

	return p;
}

void knapsack(int i,int n,double w,double &maxp, double &curp,double &curw, struct node a[], vector<int> &vb , vector<int> &v)
{

	if ( curp > maxp )
	{
		int t;
		maxp = curp;
		vb.clear();
		t = v.size();
		vb.resize(t);
		copy(v.begin(),v.end(),vb.begin());
	}

	for ( int j = i; j < n; j++ )
	{

		if (a[j].wt + curw <= w && ( fractional(j+1,n,w-curw-a[j].wt,a ) + curp + a[j].p  > maxp ) )
		{
			curp = curp + a[j].p;
			curw = curw + a[j].wt;
			v.push_back(j+1);
			knapsack(j+1,n,w,maxp,curp,curw,a,vb,v);
			curp = curp - a[j].p;
			curw = curw - a[j].wt;
			v.pop_back();
		}

	}
	
}

int main()
{
	double w;
	double h;
	int n;
	double maxp = 0;
	double curp = 0;
	double curw = 0;

	vector<int> v;
	vector<int> vb;


	cout<<"enter number of elements"<<endl;
	cin>>n;
	cout<<"enter max capacity of knapsack"<<endl;
	cin>>w;

	struct node a[n];

	for ( int i = 0; i < n; i++ )
	{
		cin>>a[i].wt>>a[i].p;
		a[i].r = (a[i].p) / (a[i].wt);

	}

	knapsack(0,n,w,maxp,curp,curw,a,vb,v);

	cout<<endl;

	cout<<maxp<<endl;

	for ( int i = 0; i < vb.size(); i++ )
	{
		cout<<vb[i]<<" ";
	}

	return 0;
}






