# include <iostream>
# include <algorithm>
using namespace std;

int b[1000][1000];
int ctr = 0;
bool place(int a[],int i, int j)
{
	
	int k = 0;
	for (k = 0; k < i; k++){
		if(a[k] == j){
			return false;
		} else if (a[k] -k == j - i){
			return false;
		} else if(a[k] +k == i+j){
			return false;
		} 
	}
	return true;
}

bool check(int a[] ,int n)
{

	for (int j = 0; j < ctr; j++){
	
		
		for (int i = 0; i < n; i++) {

			if(b[j][i] + a[i] == n-1){
				return false;
			}
		}
	}
	return true;
}
int cnt = 0;
	
bool queens(int a[],int i,int n)
{
//	cout << "Called on" << i << "and n is " << n << endl;
	
	if(i == n){
		
	//	if(check(a,n)){
			cout << "Answer" << endl;
			cnt++;
			for (int j = 0; j < n; j++){
				cout << a[j] << " ";
				b[ctr][j] = a[j];

		
			}
			ctr++;
			cout << endl;
	//		return true;
	//	}
		return true;
	} else {
		
		
		int flag = 0;
		for (int j = a[i]+1; j < n; j++){

			if( place(a,i,j)){
				a[i] = j;
	//			cout << i << " " << a[i] << endl;
				flag = 1;
				break;
			}
		}
		
		if(flag == 0){
			return false;
		}
	}
	bool p;
//	cout << "calling" << i+1 << endl;
	p = queens(a,i+1,n);
	
//	cout << "Returning to " << i << "with" << p << endl;
	if(p == false){	
		if(i+1 < n){
			a[i+1] = -1;	
		}
//		cout << "Calling " << i << endl;
		p = queens(a,i,n);
		
	}

	bool l;

	if(p == false){
		return false;
	} else {
		for (int j = i+1; j < n; j++){
			a[j] = -1;
		}
		for (int j = a[i]+1; j < n; j++){
			if(place(a,i,j)){
				a[i] = j;
	//			cout << i <<" " << a[i] << endl;
		
	//			cout << "calling" << i+1 << "inside" <<endl;
				l = queens(a,i+1,n);
				if(l == false){
					a[i+1] = -1;
				} else {

					a[i+1] = -1;
				
				}
					
			}
		}
		return true;
	}			
				
}
	

int main()
{

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++){
		a[i] = -1;
	}

	queens(a,0,n);
	cout << "Total solutions" << cnt << endl;

	return 0;
}
	
