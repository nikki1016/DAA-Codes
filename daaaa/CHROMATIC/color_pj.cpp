#include <iostream>
#include <cstdio>

using namespace std;

int chk (int a[][100], int node, int col, int n, int c[])
{

	for (int i = 1; i <= n; i++) {
		if (a[node][i] == 1 && c[i] == col)
		{
			return 0;
		}
	}
	return 1;
}
void chrm_col (int a[][100], int c[], int x, int node, int *f, int n)
{

	int flag = 0;
	if (node == n + 1)
	{
		*f = 1;
		return;
	}

	for (int i = 1; i <= x; i++)
	{

		if (chk (a, node, i, n, c)) {
			c[node] = i;
			chrm_col (a, c, x, node + 1, f, n);
			if (*f == 1 || *f == 2)
			{
				return;
			}
			flag = 1;
		}
	}
	if (flag == 0)
	{
		*f = 2;
		return;
	}
}
int main ()
{

	cout << "Enter total nodes -> ";
	int n, n1, n2;
	cin >> n;
	int a[100][100], c[n + 1];
	for (int i = 0; i <= n; i++) 
	{
		for (int j = 0; j <= n; j++)
		{
			a[i][j] = -1;
		}
	}
	cout << "Enter connected nodes........... ENTER -1 TO STOP\n";
	while (1)
	{
		cin >> n1;
		if (n1 == -1)
		{
			break;
		}
		cin >> n2;
		a[n1][n2] = 1;
		a[n2][n1] = 1;
	}

	int f = 0, x;
	for (x = 1; ; x++)
	{
		f = 0;
		chrm_col (a, c, x, 0, &f, n);
		if (f == 1) {
			break;
		}
		for (int i = 0; i <= n; i++) {
			c[i] = 0;
		}
	}
	cout << "\n\nColouring of Graph possible by " << x << " colours\n";
	cout << "Coloured Graph is\n";
	for (int i = 1; i <= n; i++) {
		cout << "Node " << i << " ->  C" << c[i] << "\n";
	}
	cout << endl;
	
	return 0;
}