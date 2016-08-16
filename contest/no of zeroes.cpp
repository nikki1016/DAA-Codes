#include <stdio.h>
#include <math.h>

int findTrailingZeros(int  n)
{
    int count = 0;
    for (int i=5; n/i>=1; i *= 5)
          count += n/i;
 
    return count;
}
int main()
{
	int t,a,i;
	scanf("%d",&t);
	i = 1;
	while(t--){
	double k;
	scanf("%lf",&k);
	double m = 4*k;
	long long int n = m;
	a = n%5;
	n =  n + (5-a);
	if(findTrailingZeros(n)==k) printf("Case %d: %d\n",i,n);
	else printf("Case %d: impossible\n",i);
	i++;
	}
	return 0;
}
