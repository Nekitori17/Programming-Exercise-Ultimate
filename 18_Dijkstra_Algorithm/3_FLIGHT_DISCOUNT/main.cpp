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

  priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<tuple<ll, int, bool>>>
      pq;
  vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));

  pq.push({0, 1, false});
  dist[1][0] = 0;

  while (!pq.empty()) {
    int u = get<1>(pq.top());
    ll uw = get<0>(pq.top());
    bool used = get<2>(pq.top());
    pq.pop();

    if (uw > dist[u][used])
      continue;

    for (pair<int, int> edge : adj[u]) {
      int v = edge.first;
      int w = edge.second;

      ll vw = uw + w;
      ll vwc = uw + w/2;

      if (!used) {
        if (dist[v][0] > vw) {
          dist[v][0] = vw;
          pq.push({vw, v, false});
        }

        if (dist[v][1] > vwc) {
          dist[v][1] = vwc;
          pq.push({vwc, v, true});
        }
      } else {
        if (dist[v][1] > vw) {
          dist[v][1] = vw;
          pq.push({vw, v, true});
        }
      }
    }
  }

  cout << dist[n][1];

  return 0;
};