/*
1 1 1 1
1 1 1 0
1 1 1 1
1 0 1 1
*/
#include <iostream>
using namespace std;
bool issafe(int color[], int v, bool graph[][4], int c, int node) {
    for (int i = 0 ; i < node; i++) {
        if (graph[v][i] == 1 && (c == color[i])) {
            return false;
	}
    }
        return true;
    
}
void print(int  color[]) 
{
	for (int i = 0; i < 4; i++) {
		cout << color[i] << " ";
	}
	cout << endl;
}

bool coloring(bool graph[][4], int c, int v, int color[], int node) {
    if (v == node) {
	print(color);
        return true;
	
    }
//    cout << "no  of color = " << c << "vertex = " << v << endl;
    for (int i = 1; i <= c; i++) {

    	    if (issafe(color, v, graph, i, node)) {
//            cout << "c = " << c << " " << v << endl;
            color[v] = i;

		cout << "vertex = "  << v <<  "  color = " << color[v] << endl;

	    if (coloring(graph, c, v+1, color, node) == true) {
        	    return true;
             }
             color[v] = 0;
        }
    }
    return false;
}
int main()
{
    bool a[4][4];
    int color[5];
    cout << "enter mattrix" << endl;
    for (int i = 0 ; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        color[i] = 0;
    }
    for (int i = 1; i <= 5; i++) {
        if (coloring(a, i, 0, color, 4)== true) {
        	cout << " no of color used = " << i << endl;
		break;	
	} else {
            cout << "not possible" << endl;
        	for (int i = 0; i < 4; i++) {
			color[i] = 0;
		}	
	}
    }

}
