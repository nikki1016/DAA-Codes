#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int valid(int sol[],int level,int i){
	int j;
	for(j=1;j<=level-1;j++){
		if(i==sol[j])
			return 0;
		else if(level-i == j -sol[j]){
				return 0;
			}
		else if(level+i==j+sol[j])
			return 0;
	}
	return 1;

}
int c = 0;
void nq(int sol[],int n,int level){

	int i,v,f;//,h = 1;
	if(level == n+1){
		c++;
		for(i=1;i<=n;i++){
			printf("%d\t",sol[i]);
		}
		printf("\n");
//		exit(0);
		return ;
	}
	f = 0;
	for(i=1;i<=n;i++){
		v = valid(sol,level,i);
		if(v==1){
			sol[level] = i;
			 nq(sol,n,level+1);
		}
	}


}

int main(){
	int n,i;
	int sol[100];
	scanf("%d",&n);
//	clock_t start,end;
//	double diff;
//	for(i=4;i<=15;i++){
//	start = clock();
	nq(sol,n,1);
//	end = clock();
//	diff = (double)end-start/CLOCKS_PER_SEC;
	printf("Total solution : %d",c);
//	}
}


