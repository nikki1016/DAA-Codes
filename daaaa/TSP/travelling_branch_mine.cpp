#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool estimate(int a[][50],int n,int visited[],int maxp,int curp,int id)
{
	
	int k = 0;
	
	visited[id] = true;
	
	for (int i = 0; i < n; i++) {
	
		vector<int> op;	
		if(visited[i] == false) {

			for (int j = 0; j  < n; j++){
				op.push_back(a[i-1][j]);
			}

			sort(op.begin(),op.end());

			k = k + ((op[0] + op[1])/ 2);
		}

	}

	visited[id] = false;
			

	if (curp + k >= maxp)
	{
		return false;
	} 
	
	else 
	{
		return true;
	}
}

void tsp (int a[50][50],int st,int n,int nv,int &curp, int &maxp, int visited[50],int s, vector<int> &vb, vector<int> &v, int &c)
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
			c = 1;
		}
		
		else if ( maxp == curp )
		{
             c++;
        }

		return;
	}

	for ( int i = 0; i < n; i++ )
	{
		if (a[st][i] != 0 && visited[i] != 1 && estimate(a,n,visited,maxp,a[st][i]+curp,i)  )
		{
			visited[i] = 1;
			nv++;
			cout<<"Adding "<<i<<" ";
			v.push_back(i);
			curp = curp + a[st][i];
			cout<<"current profit"<<curp<<" ";
			tsp(a,i,n,nv,curp,maxp,visited,s,vb,v,c);

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
	int c = 0;
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

	tsp(a,st,n,nv,curp,maxp,visited,s,vb,v,c);
	cout<<endl<<endl;

	cout<<maxp<<endl;

	for ( int i = 0; i < vb.size(); i++ )
	{
		cout<<vb[i]<<" ";
	}
	
	cout<<endl;
	cout<<c;


int u;
cin>>u;
	return 0;
}



