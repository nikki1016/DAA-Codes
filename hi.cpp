#include <iostream>
#define MAX 100000

using namespace std;

class heft {
	public:
		int ntasks,nproc;
		int g[MAX][MAX];
		int exec_time[MAX][MAX];
		void input(){
			int i,j,a,b,c;
			for(i=0;i<ntasks;i++){
				cout<<"st"<<i<<"\t";
				for(j=0;j<nproc;j++){
					cin>>exec_time[i][j];
					cout<<"HERE";
				}
				cout<<"HERE";
			}
			cout<<"HERE"<<ntasks;
		}
		/*	int maxlinks = ntasks*(ntasks-1);
			for (i = 1; i <= maxlinks; i++) {
				cout << "links" << i << "\t";
				cin >> a;
				if (a == -1){
				//	cout<<"\b\b\b\b\b\b";
					break;
				}
				else {
					cin >> b >> c;
					g[a][b] = c;
				}			
			}
		}
		
		/*void bcd(){
			cout<<a<<"\n";
		}*/
};
/*void heft::abc(int b) {
	a = b;
}*/
int main()
{
	heft h;
	cout<<"No_processors"<<"\t";
	cin>>h.nproc;
	cout<<"no_of_tasks"<<"\t";
	cin>>h.ntasks;
	h.input();
	
}

