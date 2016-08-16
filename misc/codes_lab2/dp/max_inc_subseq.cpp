#include<iostream>
#include<climits>
using namespace std;
int main() {
	int n;
	cin>>n;
	int arr[n];
	int i,j;
	for(i=0;i<n;i++)cin>>arr[i];
	int m[n];
	for(i=0;i<n;i++)m[i]=arr[i];
	for(i=1;i<n;i++) {
		for(j=0;j<i;j++) {
			if(arr[i]>arr[j] && m[i]<m[j]+arr[i]) {
				m[i]=m[j]+arr[i];
			}
		}
	}
	int max=INT_MIN;
	for(i=0;i<n;i++) {
		if(m[i]>max)max=m[i];
	}
	cout<<max<<endl;
	return 0;
}
