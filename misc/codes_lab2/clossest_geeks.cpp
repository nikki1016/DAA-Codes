#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>
int part(int arr[],int array[],int low,int up) {
	int pivot=arr[up];
	int i=low-1;
	int j;
	for(j=low;j<up;j++) {
		if(arr[j]<=pivot) {
			i++;
			int tmp,t2;
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			t2=array[i];
			array[i]=array[j];
			array[j]=t2;
		}
	}
	int tmp,t2;
	tmp=arr[i+1];
	arr[i+1]=arr[up];
	arr[up]=tmp;
	t2=array[i+1];
	array[i+1]=array[up];
	array[up]=t2;
	return i+1;
}
void qs(int arr[],int array[],int low,int up) {
	if(low<up) {
		int mid=part(arr,array,low,up);
		qs(arr,array,low,mid-1);
		qs(arr,array,mid+1,up);
	}
}
float min(float a,float b){
	return a>b?a:b;
}
float brute(int arx[],int ary[],int n) {
	int i,j;
	float d=INT_MAX;
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if(d>sqrt((arx[i]-arx[j])*(arx[i]-arx[j])+(ary[i]-ary[j])*(ary[i]-ary[j]))) {
				d=sqrt((arx[i]-arx[j])*(arx[i]-arx[j])+(ary[i]-ary[j])*(ary[i]-ary[j]));
			}
		}
	}
	return d;
}
float stripclosest(int a1[],int a2[],int n,float dist) {
	qs(a2,a1,0,n-1);//sorting along y axis
	float min=INT_MAX;
	int i,j;
	for(i=0;i<n;i++) {
		for(j=i+1;j<n && (abs(a2[i]-a2[j])<dist);j++) {//minimising the pts to be checked
			if(min>sqrt((a1[i]-a1[j])*(a1[i]-a1[j])+(a2[i]-a2[j])*(a2[i]-a2[j]))) {
				min=sqrt((a1[i]-a1[j])*(a1[i]-a1[j])+(a2[i]-a2[j])*(a2[i]-a2[j]));
			}
		}
	}
	return min;
}
float closest(int arrx[],int arry[],int low,int up,int n) {
	if(n<=3) {
		return brute(arrx,arry,n);
	}
	int mid=arrx[n/2];
	float dl,dr,d;
	dl=closest(arrx,arry,low,mid,mid-low+1);
	dr=closest(arrx,arry,mid,up,up-mid+1);
	d=1;
	d=min(dl,dr);
	int a1[n],a2[n];
	int i,j;
	j=0;
	for(i=0;i<n;i++) {
		if(abs(arrx[i]-mid)<d) {
			a1[j]=arrx[i];
			a2[j]=arry[i];
			j++;
		}
	}
	return min(d,stripclosest(a1,a2,j,d));
}
int main(){
	int n;
	scanf("%d",&n);
	int i;
	int arrx[n],arry[n];
	for(i=0;i<n;i++) {
		scanf("%d%d",&arrx[i],&arry[i]);
	}
	qs(arrx,arry,0,n-1);
	float d=closest(arrx,arry,0,n-1,n);
	printf("%lf\n",d);
	for(i=0;i<n;i++) {
		printf("%d\t%d\n",arrx[i],arry[i]);
	}
	return 0;
}
