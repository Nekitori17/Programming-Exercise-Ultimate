#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> trace(n + 1);
  vector<int> visted(n + 1);

  queue<int> qe;
  qe.push(1);
  visted[1] = true;

  while (!qe.empty()) {
    int u = qe.front(); qe.pop();

    
    for (int v : adj[u]) {
      if (!visted[v]) {
        visted[v] = true;
        qe.push(v);
        trace[v] = u;
      }
    }  
  }

  if (!visted[n]) {
    cout << "IMPOSSIBLE";
  } else {
    vector<int> path;
    int curr = n;
    while (curr != 1) {
      path.push_back(curr);
      curr = trace[curr];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++) {
      cout << path[i] << " ";
    }
  }

  return 0;
};