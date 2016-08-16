# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>
# include <ctime>
# include <cmath>
using namespace std;

long long euclid_distance(int x1, int y1, int x2, int y2)
{

	long long distx,disty,dist;

	distx = (x2-x1);
	distx = distx * distx;
	disty = ((y2-y1));
	disty = disty * disty;
	
	dist = distx+disty;

	return dist;
}

int main()
{

	int n;
	cin >> n;
	ifstream fin("input.txt");

	int x,y;
	vector<pair<int,int> > v;
	for (int i = 0; i < n; i++){
		
		fin >> x >> y;
		v.push_back(make_pair(x,y));
	}

	

	

	int start_s = clock();

//	sort(v.begin(),v.end());

	int p1,p2,p3,p4;
	long long min = 1e18;
	long long dis;
	for (int i = 0; i < v.size(); i++){
		for (int j = 0; j < v.size(); j++){
			
			if(i != j){
			dis = euclid_distance(v[i].first,v[i].second,v[j].first,v[j].second);
			if(dis < min) {
				min = dis;
				p1 = v[i].first;
				p2 = v[i].second;
				p3 = v[j].first;
				p4 = v[j].second;

				
			}
			}

		}
	}

	double xop = sqrt(min);
	int stop_s = clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	cout << p1 <<" " << p2 <<"   "<<p3 <<" " <<p4 <<"    ";
	cout << xop << endl;
	return 0;
}				
