#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<bool>> visited;

void dfs(int i, int j) {
  if (i < 0 || i > n - 1) return;
  if (j < 0 || j > m - 1) return;

  if (visited[i][j]) return;

  visited[i][j] = true;

  dfs(i + 1, j);
  dfs(i - 1, j);
  dfs(i, j + 1);
  dfs(i, j - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  
  cin >> n >> m;
  visited.resize(n, vector<bool>(m, true));

  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      char c = s[j];
      visited[i][j] = (c == '.') ? false : true;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!visited[i][j]) {
        ans++;
        dfs(i, j);
      }
  
  cout << ans;

  return 0;
};