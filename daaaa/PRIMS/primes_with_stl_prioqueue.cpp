#include <iostream>
#include <queue>
using namespace std;
int w[100][100];
void display(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << w[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    priority_queue<pair<int , int>, vector<pair<int, int> > , greater<pair<int , int> > > q;
    pair<int , int> r;
    int i, j, m, n, k;
    cout << "Enter the no. of nodes\n";
    cin >> n;
    int l[n+1];
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            w[i][j] = 0;
        }
    }
    while (1) {
        cout << "Enter two nodes and its weight\n";
        cin >> i >> j >> k;
        if (i == 0 && j == 0 && k == 0) {
            break;
        }
        w[i][j] = k;
        w[j][i] = k;
    }
    for (i = 1; i <= n; i++) {
        l[i] = 0;
    }
    int curr = 1;
    int sum = 0;
    while (1) {
        if (l[curr] != 1) {
            l[curr] = 1;
            for (i = 1; i <= n; i++) {
                if (l[i] != 1 && w[curr][i] != 0) { // if node is not visited and the weight of the path is non zero
                    q.push(make_pair(w[curr][i], i)); //inserting into p_q making pairs
                }
            }
        }
        if (!q.empty()) {
            r = q.top();
            curr = r.second;
            if (l[curr] != 1) {
                sum = sum + r.first;
                cout <<"visiting "<<curr << endl;
            }
            else {
                cout << "for "<<curr<<" l[curr]= "<<l[curr]<<endl;
            }
            q.pop();
        }
        else {
            break;
        }
    }
    cout << sum << endl;
    return 0;
}
