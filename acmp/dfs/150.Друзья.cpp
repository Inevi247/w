#include <iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<char> used;

void dfs(int v)
{
	used[v] = 1;
	for (int to : g[v])
		if (!used[to])
			dfs(to);
}

int main()
{
	int s;
    cin >> n >> s;
	s--;
    g.resize(n);
	used.resize(n, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			if (a)
				g[i].push_back(j);
		}
	dfs(s);
	int count = 0;
	for (int x : used)
		count += x;
	cout << count - 1;
}
