# include <iostream>
# include <vector>
# include <utility>
# include <cmath>
# include <algorithm>
# include <fstream>
# include <ctime>
using namespace std;

# define INF 1000000



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
long long merge(vector<pair<int,int> > v, int low, int high,long long d,pair<int,int> &res1, pair<int,int> &res2)
{

//	cout << "here" << endl;
	int mid = (low+high)/2;
		
	double dist = sqrt(d);
	vector<pair<int,int> > p;
	int j = mid;

	while( j >= 0 && (double)v[j].first >= (double)(v[mid].first - dist)){
		
		p.push_back(make_pair(v[j].second,v[j].first));
		j--;
	}

	j = mid+1;

	while(j <= high && (double)v[j].first <= (double)(v[mid].first+dist)){
		
		p.push_back(make_pair(v[j].second,v[j].first));
		j++;
	}


	sort(p.begin(),p.end());

//	for (int i = 0; i < p.size(); i++){
//		cout << p[i].second <<" " << p[i].first << endl;
//	}

	for (int i = 0; i < p.size(); i++){
		for (int x = i+1; x <= i+ min((int)p.size()-i-1,6); x++){
			
			long long distance;
			distance = (euclid_distance(p[i].second,p[i].first,p[x].second,p[x].first)); 
			if(distance < d) {
				
				d = distance;
				res1 = make_pair(p[i].second,p[i].first);
				res2 = make_pair(p[x].second,p[x].first);
			}
		}
	}

	return d;
}
				
				
				
			

	
	

long long closest_pair(vector<pair<int,int> > v, int low, int high, pair<int,int> &res1, pair<int,int> &res2)
{
	//cout << "Called on " << low << " " << high << endl;

	if(high-low+1 == 1){
		return INF;
	} else if (high-low+1 == 2){
		res1 = v[low];
		res2 = v[high];
		return euclid_distance(v[low].first,v[low].second,v[high].first,v[high].second);
	} else if (high-low+1 == 3){
		long long d,d1,d2;

		int m;
		m = (low+high)/2;
		d = euclid_distance(v[low].first,v[low].second,v[high].first,v[high].second);
		d1 = euclid_distance(v[low].first , v[low].second, v[m].first,v[m].second);
		d2 = euclid_distance(v[m].first,v[m].second,v[high].first,v[high].second);
		
		long long mini = d;
		res1 = v[low];
		res2 = v[high];

		if(d1 < mini){
			mini = d1;
			res1 = v[low];
			res2 = v[m];
		}
		if(d2 < mini){
			mini = d2;
			res1 = v[m];
			res2 = v[high];
		}
	//	cout << mini << endl;

		return mini;
	} else {

		int mid;
		mid = (low+high)/2;

		pair<int,int> left1,right1,left2,right2,split1,split2;
		
		long long distl,distr,distm;
		distl = closest_pair(v,low,mid,res1,res2);
		
		left1 = res1;
		left2 = res2;

		distr = closest_pair(v,mid+1,high,res1,res2);
		
		right1 = res1;
		right2 = res2;

		distm = merge(v,low,high,min(distl,distr),res1,res2);

		split1 = res1;
		split2 = res2;

		long long mini = distl;

		res1 = left1;
		res2 = left2;

		if(distr < mini){
			mini = distr;
			res1 = right1;
			res2 = right2;
		}

		if(distm < mini){
			mini = distm;
			res1 = split1;
			res2 = split2;
		}

	//	cout << mini << endl;

		return mini;
	}
}
	
		
		

int main()
{

	int n;
	cin >> n;

	int x,y;
	vector<pair<int,int> > v;
	
	ofstream fout("input.txt");

	for (int i = 0; i < n; i++){
		x = rand() % 100;
		y = rand() % 100;
		fout << x <<" " << y << endl;
	}
	fout.close();

	ifstream fin("input.txt");

	for (int i = 0; i < n; i++){
		fin >> x >> y;
		
		v.push_back(make_pair(x,y));
	}

	int start_s = clock();
	sort(v.begin(),v.end());

//	cout << "Sorted" << endl;

	pair<int,int> res1,res2;
	double dist;

	dist = closest_pair(v,0,n-1,res1,res2);
	dist = sqrt(dist);

	int stop_s = clock();

	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	fin.close();
	ofstream fout1("output.txt");

	fout1 << "The closest pairs are" << res1.first << " " << res1.second << " and " << res2.first << " " << res2.second << "and distance is " << dist << endl;

	fout1.close();
	return 0;
}
