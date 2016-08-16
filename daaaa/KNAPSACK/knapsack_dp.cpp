//# include <stdio.h>
#include<iostream>
using namespace std;
  int table[51][1001];
      
int max(int x,int y)
{
        if(x > y){
                return x;
        } else {
                return y;
        }
}
int knapsack(int cap,int wt[],int val[],int n)
{
        
        int i,j;
        
        for(i=0;i<=cap;i++){
                            table[0][i]=0; }
        
        for (i = 1; i <= n; i++){
                table[i][0]=0;
                for (j = 0; j <= cap;j++){
                        //if(i == 0 || j == 0){
                          //      table[i][j] = 0;
                       // } 
                       
                        if(wt[i]<=j)
                        {
                                    if(val[i]+table[i-1][j-wt[i]] > table[i-1][j])
                                    {      table[i][j]=val[i]+table[i-1][j-wt[i]];  
                          //          cout<<table[i][j]<<endl;
                                    }
                                    
                                    
                                    else
                                    table[i][j]=table[i-1][j];
                        }
                        
                  //      else if(wt[i-1] <= cap){
                    //            table[i][j] = max(table[i-1][j],val[i-1]+table[i-1][j-wt[i-1]]);
                      //  } 
                        else {
                                table[i][j] = table[i-1][j];
                        }
                }
        }
        return table[n][cap];
}
int main()
{
        int t;
        scanf("%d",&t);
        int i;
        for (i = 0 ; i < t; i++){
                int cap,n;
                scanf("%d %d",&cap,&n);
                int j;
                int wt[n];
                int val[n];
                for (j = 1; j <= n; j++){
                        scanf("%d %d",&wt[j],&val[j]);
                }
                int ans;
                ans = knapsack(cap,wt,val,n);
 
                printf("Hey stupid robber, you can get %d.\n",ans);
        }
//        system("pause");
        return 0;
}
