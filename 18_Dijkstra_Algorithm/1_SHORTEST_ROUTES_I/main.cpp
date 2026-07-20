#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
  }

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  vector<ll> dist(n + 1, INF);

  pq.push({0, 1});
  dist[1] = 0;

  while (!pq.empty()) {
    ll u = pq.top().second;
    ll uw = pq.top().first;
    pq.pop();

    if (uw > dist[u]) continue;

    for (pair<int, int> edge : adj[u]) {
      int v = edge.first;
      int w = edge.second;

      ll vw = uw + w;

      if (dist[v] > vw) {
        dist[v] = vw;
        pq.push({dist[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[i] << ' ';
  }

  return 0;
};