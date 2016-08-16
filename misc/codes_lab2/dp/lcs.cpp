#include<stdio.h>
int max(int a,int b) {
	return a>b?a:b;
}
int main(){
	int n,m;
	scanf("%d%d",&m,&n);
	int i,j;
	char X[m];
	char Y[n];
	scanf("%s%s",X,Y);
	printf("%s\t%s\n",X,Y);
	int L[m+1][n+1];
   //int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
	printf("%d",L[m][n]);
	return 0;
}
