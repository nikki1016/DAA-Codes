#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

char a[100],b[100];
char lc[100];

void lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
 
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         	L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         	L[i][j] = L[i-1][j-1] + 1;
       else if (L[i-1][j] >= L[i][j-1])
			L[i][j] = L[i-1][j];					
		else
			L[i][j] = L[i][j-1];
     }
   }
 
   int index = L[m][n];
 
   lc[index] = '\0'; 
   
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      if (X[i-1] == Y[j-1])
      {
          lc[index-1] = X[i-1]; 
          i--; 
		  j--; 
		  index--;     
  	  }
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
   // Print the lcs
   //cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

int main() {
	int t;
	cin>>t;
	int m, n;
	cin>>lc;
	t = t-1;
	while(t--) {
		cin>>b;
		strcpy(a,lc);
		lcs(a,b,strlen(a),strlen(b));	
	}
	cout<<lc<<endl;
	cout << "Length of LCS: " << strlen(lc);
	return 0;
}
