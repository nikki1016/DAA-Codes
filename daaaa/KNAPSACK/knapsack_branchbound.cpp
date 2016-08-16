# include<iostream>
# include <vector>
# include <algorithm>
using namespace std;


bool estimate(int i, vector<int> wt,vector<int> pro,int max_p,int cap,int curr_pro)
{

//	cout << i <<" "<< cap <<" "<<max_p <<" " ;
	vector<pair<double,int> > v;

	double x;
	for (int in = i; in < wt.size(); in++) {

		x = ((double) pro[in]/ (double) wt[in]);
		
		v.push_back(make_pair(x,in));
	}

	sort(v.begin(),v.end());

	int cur_w = 0;
	int cur_p = curr_pro;

	for (int in = v.size()-1; in >= 0; in--) {

		if(cur_w + wt[v[in].second] <= cap) {

			cur_w += wt[v[in].second];
			cur_p += pro[v[in].second];

		} else {

			
			cur_p += (v[in].first * wt[v[in].second]);
			break;
		}	
	}
//	cout << cur_p << endl;

	if(cur_p >= max_p){
		return true;
	} else {
		return false;
	}
}
		
		
		

void knapsack(vector<int> wt,vector<int> pro,int cap,int &cur_p,int &cur_wt,vector<int> &cur_ass,int &max_p,vector<int> &best_ass)
{


	
	if(cur_p > max_p){
		
		max_p = cur_p;
		best_ass.clear();
		best_ass.resize(cur_ass.size());
	//	cout <<"E" << endl;
		copy(cur_ass.begin(),cur_ass.end(),best_ass.begin());
		
	//	cout << "D" << endl;

	}
//	cout << cur_ass.size() << endl;
	
	for (int i = cur_ass[cur_ass.size()-1]+1; i <= pro.size(); i++) {
	//	cout << i << endl;
	//	cout << wt[i-1] << endl;

		if(cur_wt+ wt[i-1] <= cap && estimate(i,wt,pro,max_p,cap-cur_wt-wt[i-1],cur_p+pro[i-1])){
			
		//	cout << pro[i-1] << endl;
			cur_p += pro[i-1];
		//	cout <<"A"<<endl;
			cur_ass.push_back(i);
		//	cout << "B"<<endl;
			cur_wt += wt[i-1];
		//	cout << "C" << endl;
			

			knapsack(wt,pro,cap,cur_p,cur_wt,cur_ass,max_p,best_ass);

			cur_ass.pop_back();
			cur_p -= pro[i-1];
			cur_wt -= wt[i-1];

				
		}
	}
}



		

		

	
int main()
{

	int n,cap;
	cin >> n >> cap;

	vector<int> wt,pro,cur_ass,best_ass;

	int x,y;
	for (int i = 0; i < n; i++){
		
		cin >> x >> y;

		wt.push_back(x);
		pro.push_back(y);
	}

	int cur_p = 0;
	int cur_wt = 0;

	int max_p = 0;
	
	cur_ass.push_back(0);
//	cout << "here" <<endl;
	knapsack(wt,pro,cap,cur_p,cur_wt,cur_ass,max_p,best_ass);

	cout << max_p << endl;
	for (int i = 1; i < best_ass.size();i++){
		
		cout << best_ass[i] << " " ;
	
	}
	

	
	return 0;
}
