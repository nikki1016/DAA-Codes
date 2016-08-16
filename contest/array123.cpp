#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long int a[n];
	long long int b[n];
	int i;
	for (i = 0; i < n; i++) {
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++) b[i]=a[i];
	int t;
	scanf("%d", &t);
	while (t--) {
	char c;
	int p, q, r;
	cin >> c;
	if (c == 'U') {
		scanf("%d%d",&p,&q);
		b[p-1] = q;
	}
	if (c == 'P') {
		for (i=0;i<n;i++) {
			a[i]=b[i];
		}
		scanf("%d", &r);
		sort(a, a+n);
		printf("%lld\n", a[r-1]);
	}
	}
	return 0;
}
