#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int n, i, times;
		cin >> n;
		int ans = 0;
		for (i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			times = (i + 1) * (n - i);
			if (times % 2 == 1)
				ans ^= num;
		}
		cout << ans << endl;
	}
	return 0;
}
