#include<stdio.h>
#include<string.h>

void lcsub(char x[],char y[],int m,int n)
{

        int i,j;
        int table[m+1][n+1];

        int max=0,ind=0;
        for(i=0;i<=m;i++)
          for(j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                  table[i][j]=0;

                else
                 {
                     if(x[i-1]==y[j-1])
                        table[i][j]=table[i-1][j-1]+1;
                     else
                        table[i][j]=0;
                 }

                if(max<table[i][j])
                  {
                      max=table[i][j];
                      ind=i;
                  }
            }

         printf("maximum length LCSUBSTRING IS :%d\n",max);
         printf("maximum LCSUBSTRING IS :");
         for(i=ind-max;i<=max;i++)
           printf("%c",x[i]);
         printf("\n");

}


int main()
{
	char str1[1000];
	char str2[1000];
	scanf("%s",str1);
	scanf("%s",str2);
    //char str1[]="GeeksforGeeks";
    //char str2[]="Geeksboy";

    int m=strlen(str1);
    int n=strlen(str2);

    lcsub(str1,str2,m,n);

    return 0;
}
