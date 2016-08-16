#include<iostream>
using namespace std;
int x[100];
bool place(int k,int i)
{
	int l,m;
	for(int j=0;j<k;j++)
	{
		l=x[j]-i;
		m=j-k;
		if(l<0 || m<0)
		{
			if(l<0)
			{
				l=-l;
				}
				if(m<0)
				{
					m=-m;
					
				}
					}
					
		if((x[j]==i)||l==m)
		{
			return 0;
			}
			}
			return 1;
		}
		int Nqueen(int k,int n)
		{
			int q;
			for(int i=0;i<n;i++)
			{
				if(place(k,i))
				{
					x[k]=i;
					if(k==n-1)
					{
						return 0;
						}
						else
						{
							q=Nqueen(k+1,n);
							if(q==0)
							{
								return 0;
								}
							}
					}
					}
					return 1;
					}
int main()
{
	int n;
	cin>>n;
	Nqueen(0,n);
	for(int i=0;i<n;i++)
	{
	cout<<i<<"    "<<x[i]<<endl;
}
	return 0;
	
}
