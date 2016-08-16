#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void tsp (int a[50][50],int st,int n,int nv,int &curp, int &maxp, int visited[50],int s, vector<int> &vb, vector<int> &v)
{
	if ( nv == n && a[st][s] != 0 )
	{
		curp = curp + a[st][s];
		v.push_back(s);
		cout<<endl;
		cout<<"current "<<curp<<endl;
		if ( maxp > curp )
		{
			int t;
			vb.clear();
			t = v.size();
			vb.resize(t);
			copy(v.begin(),v.end(),vb.begin());
			maxp = curp;
		}

		return;
	}

	for ( int i = 0; i < n; i++ )
	{
		if (a[st][i] != 0 && visited[i] != 1  )
		{
			visited[i] = 1;
			nv++;
			cout<<"Adding "<<i<<" ";
			v.push_back(i);
			curp = curp + a[st][i];
			cout<<"current profit"<<curp<<" ";
			tsp(a,i,n,nv,curp,maxp,visited,s,vb,v);

			visited[i] = 0;
			if ( nv == n )
			{
				curp = curp - a[i][s];
				//v.pop_back();
			}
			cout<<"removing "<<i;
			v.pop_back();
			nv--;
			curp = curp - a[st][i];
			cout<<" new profit "<<curp<<endl;
		}


	}

	return;
}


int main()
{
	int n,s;
	int nv = 0;
	int st;
	int curp = 0;
	int maxp = 9999999;

	cin>>n;
	
	int visited[50];
	int a[50][50];

	vector<int> v;
	vector<int> vb;

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0 ; j < n; j++ )
		{
			cin>>a[i][j];
		}

		visited[i] = 0;
	}

	cout<<"enter the starting node"<<endl;
	cin>>st;
	s = st;

	visited[st] = 1;
	v.push_back(s);
	nv++;

	tsp(a,st,n,nv,curp,maxp,visited,s,vb,v);
	cout<<endl<<endl;

	cout<<maxp<<endl;

	for ( int i = 0; i < vb.size(); i++ )
	{
		cout<<vb[i]<<" ";
	}



	return 0;
}



