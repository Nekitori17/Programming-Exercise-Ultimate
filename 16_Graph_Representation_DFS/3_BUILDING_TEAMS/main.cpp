#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;

vector<int> colored;

bool dfs(int u, int c) {
  colored[u] = c;

  for (int v : adj[u]) {
    if (!colored[v]) {
      if (!dfs(v, 3 - c))
        return false;
    } else if (colored[v] == c) {
      return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  colored.resize(n + 1);

  int u, v;
  while (m--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
    if (!colored[i])
      if (!dfs(i, 1)) {
        cout << "IMPOSSIBLE";
        return 0;
      }

  for (int i = 1; i <= n; i++) cout << colored[i] << " ";

  return 0;
};