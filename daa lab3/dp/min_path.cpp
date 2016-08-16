#include<stdio.h>
int min(int x,int y,int z) {
	if(x<y){
		return x<z?x:z;
	}else {
		return y<z?y:z;
	}
}
int main(){
	int m,n,r,c;
	scanf("%d%d",&r,&c);
	int cost[r][c];
	int i,j;
	for(i=0;i<r;i++) {
		for(j=0;j<c;j++) {
			scanf("%d",&cost[i][j]);
		}
	}
	scanf("%d%d",&m,&n);
	int mat[r][c];
	mat[0][0]=cost[0][0];
	for(i=1;i<=m;i++) {
		mat[i][0]=mat[i-1][0]+cost[i][0];
	}
	for(i=1;i<=n;i++){
		mat[0][i]=mat[0][i-1]+cost[0][i];	
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++) {
			mat[i][j]=min(mat[i-1][j],mat[i][j-1],mat[i-1][j-1])+cost[i][j];
		}
	}
	printf("%d\n",mat[m][n]);
	return 0;
}
