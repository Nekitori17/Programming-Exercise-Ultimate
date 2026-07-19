#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;

vector<bool> visited;

void dfs(int u) {
  visited[u] = true;
  
  for (int v: adj[u])
    if (!visited[v])
      dfs(v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  visited.resize(n + 1);

  int u, v;
  while (m--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!visited[i]) {
      dfs(i);
      ans++;
    }

  cout << ans;

  return 0;
};