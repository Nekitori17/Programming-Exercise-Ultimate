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
    adj[v].push_back({u, w});
  }

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  vector<ll> dist(n + 1, INF);
  vector<int> trace(n + 1);

  pq.push({0, 1});
  dist[1] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    ll uw = pq.top().first;
    pq.pop();

    if (uw > dist[u]) continue;

    for (pair<int, int> edge : adj[u]) {
      int v = edge.first;
      ll w = edge.second;

      ll vw = uw + w;

      if (vw < dist[v]) {
        dist[v] = vw;
        trace[v] = u;
        pq.push({vw, v});
      }
    }
  }

  if (!trace[n] || dist[n] == INF) {
    cout << -1;
    return 0;
  }

  vector<int> path;
  for (int i = n; i != 1; i = trace[i])
    path.push_back(i);

  path.push_back(1);
  reverse(path.begin(), path.end());

  for (int i : path) cout << i << " ";

  return 0;
};