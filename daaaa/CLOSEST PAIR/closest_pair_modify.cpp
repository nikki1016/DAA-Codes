# include <iostream>
# include <vector>
# include <utility>
# include <cmath>
# include <algorithm>
# include <fstream>
# include <ctime>
# include <set>
using namespace std;

# define INF 1000000


struct node{

	pair<int,int> p1;
	pair<int,int> p2;
};


struct classcomp{

	bool operator() (node a, node b)
	{
		if(a.p1.first == b.p1.first && a.p1.second == b.p1.second && a.p2.first == b.p2.first && a.p2.second == b.p2.second){
			return false;
		} else {
			return true;
		}
	}
};
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
long long merge(vector<pair<int,int> > v, int low, int high,long long d,pair<int,int> &res1, pair<int,int> &res2,set<node,classcomp> &s)
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
				node no;
				
				no.p1 = res1;
				no.p2 = res2;
				s.clear();
				s.insert(no);
			} else if (distance == d) {
				node no;
				no.p1 = make_pair(p[i].second,p[i].first);
				no.p2 = make_pair(p[x].second,p[x].first);
				s.insert(no);
			} 
		}
	}

	return d;
}
				
				
				
			

	
	

long long closest_pair(vector<pair<int,int> > v, int low, int high, pair<int,int> &res1, pair<int,int> &res2,set<node,classcomp> &s)
{
	cout << "Called on " << low << " " << high << endl;

    cout << "set is" << endl;
    
    	set<node,classcomp> :: iterator it;
	for (it = s.begin(); it != s.end(); it++){
		cout << (*it).p1.first <<" " << (*it).p1.second <<"       "  << (*it).p2.first  << " " << (*it).p2.second << endl;
	}
	if(high-low+1 == 1){
		return INF;
	} else if (high-low+1 == 2){
		res1 = v[low];
		res2 = v[high];
		
	   set<node,classcomp> :: iterator it;
	   
	   it = s.begin();
	   
	  
		node no;
	    long long di;
		no.p1 = res1;
		no.p2 = res2;
		
		di =  euclid_distance(v[low].first,v[low].second,v[high].first,v[high].second);
		
		if(s.size() > 0 && di < euclid_distance((*it).p1.first,(*it).p1.second,(*it).p2.first,(*it).p2.second)){
                    s.clear();
                    s.insert(no);
        } else if ( s.size() > 0 && di ==  euclid_distance((*it).p1.first,(*it).p1.second,(*it).p2.first,(*it).p2.second)){
                  s.insert(no);
        } else if (s.size() == 0){
                  s.insert(no);
        }
	}/* else if (high-low+1 == 3){
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

		node no;

		no.p1 = res1;
		no.p2 = res2;

		s.insert(no);
		return mini;
	} */else {

		int mid;
		mid = (low+high)/2;

		pair<int,int> left1,right1,left2,right2,split1,split2;
		
		long long distl,distr,distm;
		distl = closest_pair(v,low,mid,res1,res2,s);
		
		left1 = res1;
		left2 = res2;

		distr = closest_pair(v,mid+1,high,res1,res2,s);
		
		right1 = res1;
		right2 = res2;

		distm = merge(v,low,high,min(distl,distr),res1,res2,s);

		split1 = res1;
		split2 = res2;

		long long mini = distl;

		res1 = left1;
		res2 = left2;
		node nop;
		nop.p1 = res1;
		nop.p2 = res2;
		s.insert(nop);

		if(distr < mini){
			mini = distr;
			res1 = right1;
			res2 = right2;
			
			node no;
			s.clear();
			no.p1 = res1;
			no.p2 = res2;
			s.insert(no);
		} else if (distr == mini){
			node no;
			no.p1 = res1;
			no.p2 = res2;
			s.insert(no);
		}

		if(distm < mini){
			mini = distm;
			res1 = split1;
			res2 = split2;
			s.clear();

			node no;
			no.p1 = res1;
			no.p2 = res2;
			s.insert(no);
			
		} else if (distm == mini){
			node no;
			no.p1 = res1;
			no.p2 = res2;
			s.insert(no);
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


	for (int i = 0; i < n; i++){
		cin >> x >> y;
		
		v.push_back(make_pair(x,y));
	}

	int start_s = clock();
	sort(v.begin(),v.end());

//	cout << "Sorted" << endl;

	pair<int,int> res1,res2;
	double dist;
	set<node,classcomp> s;
	dist = closest_pair(v,0,n-1,res1,res2,s);
	dist = sqrt(dist);

	int stop_s = clock();

	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
//	fin.close();
//	ofstream fout1("output.txt");

//	fout1 << "The closest pairs are" << res1.first << " " << res1.second << " and " << res2.first << " " << res2.second << "and distance is " << dist << endl;

//	fout1.close();
//
//
	cout << dist << endl;
	cout << endl;
	set<node,classcomp> :: iterator it;
	for (it = s.begin(); it != s.end(); it++){
		cout << (*it).p1.first <<" " << (*it).p1.second <<"       "  << (*it).p2.first  << " " << (*it).p2.second << endl;
	}
	return 0;
}
