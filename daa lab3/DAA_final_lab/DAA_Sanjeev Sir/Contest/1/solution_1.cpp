#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    int T;
    int i,j,k,a,b,l,temp;
    cin>>T;
    while(T--)
    {
        string str;
    	cin>>str;
        if(str.length() <= 1)
    {
        a = (str[0] - '0');
        if(a% 8 == 0)
        cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
            continue;
    }
    if(str.length() <= 2)
    {
        a = 10*(str[0] - '0') + (str[1] - '0');
        b = 10*(str[1] - '0') + (str[0] - '0');
        if(a% 8 == 0 || b% 8 == 0)
        cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        continue;
    }
    else
    {
        l = str.length();
        temp=0;
        for(i=0 ; i< l ; i++)
        {
            for(j=0 ; j< l ; j++)
        {
            for(k=0 ; k< l ; k++)
            {
                if(i!=j && j!=k && k!=i)
            	{
                 	a = 100*(str[i] - '0') + 10*(str[j] - '0') + (str[k] - '0');
                	if(a%8 == 0)
               		{
               	 		  temp=1;
                		  break;
                	}
            	}
            }
        }
        }
        if(temp==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    }
    return 0;
}
