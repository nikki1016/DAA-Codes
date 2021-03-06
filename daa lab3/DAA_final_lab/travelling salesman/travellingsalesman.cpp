# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;


bool estimate(int g[][100], int n, vector<bool> visited, int min_wt,int curr_wt,int in)
{
	
	int k = 0;
	
	visited[in] = true;
	
	for (int i = 1; i < visited.size(); i++) {
	
		vector<int> op;	
		if(visited[i] == false) {

			for (int j = 0; j  < n; j++){
				op.push_back(g[i-1][j]);
			}

			sort(op.begin(),op.end());

			k += ((op[0] + op[1])/ 2);
		}

	}
	
    visited[in] = false;		

	if(curr_wt+k >= min_wt){
		return false;
	} else {
		return true;
	}
}

	
	
void travelling(int g[][100],int n,vector<int> &curr_ass,int &curr_wt,int &min_wt,vector<int> &best_ass,vector<bool> &visited,bool &flag)
{

	
	cout << curr_wt << endl;
	for (int i = 0; i < curr_ass.size(); i++){
		cout << curr_ass[i] <<" ";
	}

	cout << endl << endl; 

	if( curr_ass.size() == n) {

		bool f = false;
		if(g[curr_ass[curr_ass.size()-1]-1][0] != -1){
			
			
			
			curr_wt += g[curr_ass[curr_ass.size()-1]-1][0];
			curr_ass.push_back(1);
			f = true;
			if(curr_wt < min_wt){
			min_wt = curr_wt;
			best_ass.clear();
			best_ass.resize(curr_ass.size());
			copy(curr_ass.begin(),curr_ass.end(),best_ass.begin());
			flag = true;
		//	f = true;
	//		cout << "here";
			}	
		}

		if(f) {

		//	cout << curr_ass[curr_ass.size()-1] << endl;
			curr_ass.pop_back();
			curr_wt -= g[curr_ass[curr_ass.size()-1]-1][0];
			cout << curr_wt << endl;
        		for (int i = 0; i < curr_ass.size(); i++){
                		cout << curr_ass[i] <<" ";
        		}

       		 	cout << endl << endl;


		}
		
		return;

	}

 	for (int i = 2; i <= n; i++){
		if((visited[i] == false) && g[curr_ass[curr_ass.size()-1]-1][i-1] != -1 && estimate(g,n,visited,min_wt,g[curr_ass[curr_ass.size()-1]-1][i-1]+curr_wt,i))  {

			
			curr_wt += g[curr_ass[curr_ass.size()-1]-1][i-1];
			curr_ass.push_back(i);
			visited[i] = true;
			travelling(g,n,curr_ass,curr_wt,min_wt,best_ass,visited,flag);
			visited[i] = false;
			curr_ass.pop_back();
			curr_wt -= g[curr_ass[curr_ass.size()-1]-1][i-1];

			cout << curr_wt << endl;
 	       		for (int i = 0; i < curr_ass.size(); i++){
         	       		cout << curr_ass[i] <<" ";
        		}

        		cout << endl << endl;


			
			
			
		}
	}


}



	
int main()
{

	int n;
	cin >> n;

	int g[100][100];

	for (int i = 0; i < n; i++){
		
		for (int j = 0; j < n; j++){
			
			cin >> g[i][j];
		}
	}

	vector<int> best_ass;
	vector<int> cur_ass;
	vector<bool> visited;
	bool flag = false;

	for (int i = 0; i < n+1; i++){
		visited.push_back(false);
	}
	int cur_wt = 0;
	int min_wt = 99999;
	cur_ass.push_back(1);

	travelling(g,n,cur_ass,cur_wt,min_wt,best_ass,visited,flag);

	if(flag){
	cout << min_wt << endl;
	for (int i = 1; i < best_ass.size();i++) {

		cout << best_ass[i] <<" ";
	
	}
	} else {
		cout << "No Solution" << endl;
	}
	
	int op;
	cin >> op;

	return 0;
}
	

	
