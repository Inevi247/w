//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<deque>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> used;

void dfs(int v, int comp)
{
	used[v] = comp;
	for (int to : g[v])
		if (!used[to])
			dfs(to, comp);
}

int main()
{
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			cnt++;
			dfs(i, cnt);
		}
	}
	cout << cnt << endl;
	vector<vector<int>> comps(cnt);
	for (int i = 0; i < n; i++)
		comps[used[i] - 1].push_back(i);
	for (auto& comp : comps)
	{
		cout << comp.size() << endl;
		for (int v : comp)
			cout << v + 1 << " ";
		cout << endl;
	}
}
