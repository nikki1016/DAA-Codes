#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node 
{
	int wt;
	int p;
};

void knapsack(int i,int n,int w,int &maxp, int &curp,int &curw, struct node a[],vector<int> &vb,vector<int> &v)
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
		if (a[j].wt + curw <= w )
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
	int w;
	int n;
	int maxp = 0;
	int curp = 0;
	int curw = 0;


	cout<<"enter number of elements"<<endl;
	cin>>n;
	cout<<"enter max capacity of knapsack"<<endl;
	cin>>w;

	struct node a[n];
	vector<int> v;
	vector<int> vb;
	vector<int> :: iterator it;

	for ( int i = 0; i < n; i++ )
	{
		cin>>a[i].wt>>a[i].p;
	}

	knapsack(0,n,w,maxp,curp,curw,a,vb,v);

	cout<<endl;

	cout<<maxp<<endl;

	for ( int k = 0; k < vb.size(); k++ )
	{
		cout<<vb[k]<<" ";
	}
	

	return 0;
}






