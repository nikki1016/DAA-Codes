#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void path(int root[][100], vector<int> &tree, int s, int d,int wt[][100])
{
     //cout << s << " " << d << endl; ( what we are sendind)

     if(s > d) return; // like 5,2
     
     tree.push_back(root[s][d]);
     
     if(s == d)
     { 
	     return; // leaf node
     }
     
     else 
     {
            path(root,tree,s,wt[s][d]-1,wt); // node = wt
            path(root,tree,wt[s][d]+1,d,wt);
     }
}
     
int main()
{
    int n;
    int k;
    double f;
    cin>>n;
    
    vector <pair<int,double> > v;
    vector<int> tree;

    for (int i = 0; i < n; i++)
    {
	    cin >>k>>f;
            v.push_back(make_pair(k,f));
    }
    
    sort(v.begin(),v.end());
    
    double m[n][n];
    int root[n][100];
    int wt[n][100];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
	{
            m[i][j] = 99999;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        m[i][i] = v[i].second;
        root[i][i] = v[i].first;
        wt[i][i]= i;
    }
    
    
    for (int i = 0; i < n-1; i++)
    {
        if(v[i].second < v [i+1].second)
	{
                       m[i][i+1] = v[i+1].second + 2 * v[i].second;
                       root[i][i+1] = v[i+1].first;
                       wt[i][i+1] = i+1;
        } 
	
	else 
	{
               m[i][i+1] = v[i].second + 2 * v[i+1].second;
               root[i][i+1] = v[i].first;
               wt[i][i+1] = i;
        }
    }
    
    for (int k = 2; k < n; k++)
    {
	for (int i = 0,j = k; i < n-k && j < n; i++,j++)
	{
			
		for (int s = i; s <= j; s++)
		{
			double r = 0;
			//r = (  m[i][s-1]) + ( m[s+1][j]);
			
			if(s > 0)
			{
                             r = r + m[i][s-1];
                 	}
                 
			if( s < n-1)
			{
                              r = r +  m[s+1][j];
                 	}

                 	
			for (int p = i; p <= j; p++)
			{
                     		r = r + v[p].second;
                 	}
			
			if(r < m[i][j]) 
			{
				m[i][j] = r;
				root[i][j]  = v[s].first;  // s is the root of that subtree
				wt[i][j] = s;
				
			}
				
				
		}
			
		
	}
    }
	cout<<"cost matrix"<<endl;
	
    for (int i = 0; i < n; i++)
    {
       	for (int j = 0; j < n; j++) 
	{
            cout << m[i][j] <<" ";
        }
        
	cout << endl;
    }
    
    cout<<"total cost"<<endl;
	
    cout << m[0][n-1] << endl;
	
    path(root,tree,0,n-1,wt);
    
    
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i] <<" ";
    }

    int e;
    cin>>e;

    return 0;
}
