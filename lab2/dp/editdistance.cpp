# include <iostream>
# include <string>

using namespace std;

void path(int c[][100],string s1,string s2,int ins, int del,int sub)
{
     int i = s1.size();
     int j = s2.size();
     
     while(i != 0 || j != 0){
         
          if(i == 0 && j > 0){
               cout << "inserted " << s2[j-1] << endl;
               j--;
          } 
		  else if (j == 0 && i > 0) {
                 cout << "deleted " << s1[i-1] << endl;
                 i--;
          }
          else {
          	if(s1[i-1] == s2[j-1]){
                   if(i > 0 && j> 0 && c[i][j] == c[i-1][j-1]) {            
                        i = i-1;
                        j = j - 1;
                   } else if ( i > 0 && c[i][j] == c[i-1][j]+del){
                        cout << "deleted " << s1[i-1] << endl;
                        i = i-1;
                   } else if( j > 0 && c[i][j] == c[i][j-1] + ins){
                        cout << "inserted " << s2[j-1] << endl;
                        j = j - 1;
                   }
          	  }
		  	  else if ( s1[i-1] != s2[j-1]){
		  		  	if( i  > 0 && j > 0 && c[i][j] == c[i-1][j-1]+sub){
            	        cout << "Replaced " << s1[i-1] << " with " << s2[j-1] << endl;
                	    i = i-1;
                	    j = j-1;
                	 }
					else if ( i > 0 && c[i][j] == c[i-1][j]+del){
                	    cout << "deleted " << s1[i-1] << endl;
                	    i = i-1;
                	}
					else if( j > 0 && c[i][j] == c[i][j-1] + ins){
                		cout << "inserted " << s2[j-1] << endl;
                	    j = j - 1;
                	} 
          		}
          }
     }
}                       
                         
                    
int mini(int x, int y, int z)
{
    int k = min(x,y);
    return min(k,z);
}
int main()
{
    
    int t;
    cin >> t;
    
    for (int ko = 0; ko  < t; ko++){
	    string s1,s2;
	    cin >> s1 >>s2;
    
	    int c[100][100];
    
	    for (int i = 0; i <= s1.size(); i++){
	        for (int j = 0; j <= s2.size(); j++){
	            c[i][j] = 0;
            }
    	}
    	int ins = 1;
    	int del = 1;
    	int sub = 2;
    
    	c[0][0] =  0;
    	for (int i = 1; i <= s2.size(); i++){
    	    c[0][i] = c[0][i-1] + ins ;
    	}
    	for (int i = 1; i <= s1.size(); i++){
    	    c[i][0] = c[i-1][0]  + del;
    	}
    
    	for (int i = 1; i <= s1.size(); i++){
    	    for (int j = 1; j <= s2.size(); j++){
    	        if(s1[i-1] != s2[j-1]){
    	                 c[i][j] = mini(c[i-1][j] + del,c[i][j-1] + ins, c[i-1][j-1] + sub);
    	        }
				else {
                   c[i][j] = mini(c[i-1][j] + del, c[i-1][j-1],c[i][j-1] + ins);
            	}
        	}
    	}
    
   		/*for (int i = 0; i <= s1.size(); i++){
    		for (int j = 0; j <= s2.size(); j++){
    			cout << c[i][j] <<" ";
    	    }
    	    cout << endl;
    	} */
    	cout << c[s1.size()][s2.size()] << endl;
    
    	path(c,s1,s2,ins,del,sub);
    }
    return 0;
}
