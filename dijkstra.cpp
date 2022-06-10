#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<int> par;
vector<char> used;

void dijkstra(int s) {
	dist[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		int mn = INF, mni;
		for (int j = 0; j < n; j++)
			if (!used[j] && dist[j] < mn) {
				mn = dist[j];
				mni = j;
			}
		if (mn == INF)
			break;
		used[mni] = 1;
		for (auto [to, len] : g[mni]) {
			if (dist[to] > dist[mni] + len) {
				dist[to] = dist[mni] + len;
				par[to] = mni;
			}
		}
	}
}

void return_path(int f, vector<int>& path) {
	while (f != -1) {
		path.push_back(f);
		f = par[f];
	}
	reverse(path.begin(), path.end());
}

int main() {
	cin >> n >> m;
	g.resize(n);
	dist.resize(n, INF);
	par.resize(n, -1);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		a--; b--;
		g[a].push_back({ b, len });
		g[b].push_back({ a, len });
	}
	dijkstra(0);
	if (dist[n - 1] == INF)
		cout << -1;
	else {
		cout << dist[n - 1] << endl;
		vector<int> path;
		return_path(n - 1, path);
		for (int p : path)
			cout << p + 1 << " ";
	}
}
/*
8 12
1 2
6
1 3 2
1 4 4
2 5 1
3 6 10
4 7 3
2 3 2
3 4 2
5 6 3
5 8 6
6 8 2
7 8 3
*/
