#include <stdio.h>
#include <string.h>

int main(){
	int n,i,j,k,t;
	char a[100001],b[200004];
	scanf("%d",&t);
	while(t--){
		scanf("\n%s",a);
		n=strlen(a);
		int c[2*n+1];
		for(i=0;i<2*n+1;i++) b[i]='\0';
		for(i=n-1;i>=0;i--) b[n-1-i]=a[i];
		strcat(b,"#");
		strcat(b,a);
	//	printf("%s\n",b);
		j=0; c[0]=0; i=1;
		
		while(i<=2*n){
			if(b[i]==b[j]){
				j++;
				c[i]=j;
					i++;
			}
			else {
				if(j!=0){
				j=c[j-1];
				}
				else if(j==0){
					c[i]=0;
					i++;
				}
			}
		}
//		for(i=0;i<2*n;i++) printf("%d ",c[i]);
//		printf("\n");
//		printf("%d\n",c[2*n]);
		k=n-c[2*n];
		
		printf("%s",a);
		for(i=k-1;i>=0;i--) printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}

