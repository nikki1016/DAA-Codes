#include <bits/stdc++.h>

using namespace std;

pair <int, int> a[40009];

int main()
{
	int b[40009], t, n, i, x, y, j, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d", &a[i].first, &a[i].second);
		}
		sort(a, a + n + 1);
		for(i = n - 1; i >= 0; i--)
		{
			x = a[i].second;
			y = a[i].first;
			m = 1;
			j = i + 1;
			while (m <= x && j<=n)
			{
				a[j - 1].first = a[j].first;
				a[j - 1].second = a[j].second;
				j++;
				m += 1;
			}
			if (m >= 2)
			{
				a[j - 1].second = x;
				a[j - 1].first = y;
			}
		}
		for (i = 1; i <= n; i++)
		{
			printf("%d ", a[i].first);
		}
		printf("\n");
	}
	return 0;
}

