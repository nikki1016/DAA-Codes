# include <iostream>
using namespace std;

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
int cnt = 0;
bool queens(int a[],int i, int n)
{
     if(i == n){
          for (int j = 0; j < n; j++){
              cout << a[j] <<" " ;
              //cout << endl;
             // cnt++;
          }
          cnt++;
          cout << endl;
         // return true;
     } else {
                       bool p;
     
                       for (int k = a[i]+1; k < n; k++){
                           if(place(a,i,k)){
                                            a[i] = k;
                                       p =  queens(a,i+1,n);
                                       if(p ==  true){
                                          //  return true;
                                       }
                           }
                       }
                       a[i] = -1;
            //   return false;
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
    cout << endl << endl;
    cout << cnt << endl;
    int op;
    cin >> op;
    return 0;
}
