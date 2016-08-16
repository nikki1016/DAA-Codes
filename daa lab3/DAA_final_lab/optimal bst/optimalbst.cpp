# include <iostream>
# include <vector>
using namespace std;

void path(int d[][100], vector<int> &path_ass, int x, int y,int node[][100])
{
    // cout << x << " " << y << endl;
     if(x > y) return;
     path_ass.push_back(d[x][y]);
     
     if(x == y) return;
   /*  else if ( x == y-1) {
          if(x == n[x][y]){
               path_ass.push_back(d[x][y]);
          } else {
                 path_ass.push_back(x);
          }
     } */ else {
            path(d,path_ass,x,node[x][y]-1,node);
            path(d,path_ass,node[x][y]+1,y,node);
     }
}
     
int main()
{
    int n;
    cin >> n;
    
    vector<pair<int,double> > v;
    for (int i = 0; i < n; i++){
        int x;
        double p;
        
        cin >> x >> p;
        
        v.push_back(make_pair(x,p));
    }
    
    sort(v.begin(),v.end());
    
    double c[n][n];
    int d[n][100];
    int node[n][100];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = 99999;
        }
    }
    
    for (int i = 0; i < n; i++){
        c[i][i] = v[i].second;
        d[i][i] = v[i].first;
        node[i][i]= i;
    }
    
    
    for (int i = 0; i < n-1; i++){
        if(v[i].second < v [i+1].second){
                       c[i][i+1] = v[i+1].second + 2 * v[i].second;
                       d[i][i+1] = v[i+1].first;
                       node[i][i+1] = i+1;
        } else {
               c[i][i+1] = v[i].second + 2 * v[i+1].second;
               d[i][i+1] = v[i].first;
               node[i][i+1] = i;
        }
    }
    
    	for (int k = 2; k < n; k++){
		for (int i = 0,j = k; i < n-k && j < n; i++,j++){
			
		
			
			for (int s = i; s <= j; s++){
				
				double r = 0;
				
				//r = (  c[i][s-1]) + ( c[s+1][j]);
				if(s > 0){
                             r += c[i][s-1];
                 }
                 if( s < n-1){
                              r += c[s+1][j];
                 }
                 for (int p = i; p <= j; p++){
                     r += v[p].second;
                 }
				if(r < c[i][j]) {

					
					c[i][j] = r;
					d[i][j]  = v[s].first;
					node[i][j] = s;
				
				}
				
				
			}
			
		
			
		
		}
	}
	
	for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cout << c[i][j] <<" ";
        }
        cout << endl;
   }
	cout << c[0][n-1] << endl;
	
	vector<int> path_ass;
	path(d,path_ass,0,n-1,node);
    
    
    for (int i = 0; i < path_ass.size(); i++){
        cout << path_ass[i] <<" ";
    }
    int op;
    cin >> op;
    return 0;
}
