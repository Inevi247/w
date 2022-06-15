#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;

const int inf = 2009000999;
int n, m, s;
vector<vector<pair<int, int>>>  g;
vector<int> dist;
vector<char> used;

void levit(int s) {
    deque<int> q;
    q.push_back(s);
    dist[s] = 0;
    while (q.size())
    {
        int v = q.front();
        q.pop_front();
        used[v] = 2;
        for (auto [to, l] : g[v]) {
            if (dist[to] > dist[v] + l) {
                dist[to] = dist[v] + l;
                if (used[v] == 0)
                    q.push_back(to);
                else if (used[v] == 2)
                    q.push_front(to);
                used[v] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    g.resize(n);
    dist.resize(n, inf);
    used.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        g[a].push_back({ b , l });
        g[b].push_back({ a , l });
    }
    levit(s);
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
}
