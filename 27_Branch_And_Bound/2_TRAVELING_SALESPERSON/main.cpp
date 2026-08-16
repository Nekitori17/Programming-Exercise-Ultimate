#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int m_cost = 1e9;
int m_result = 1e9;
vector<vector<int>> WS;
vector<bool> visted;

void backtracking(int c, int u, int c_cost) {
  if (c == n) {
    m_result = min(m_result, c_cost + WS[u][1]);
    return;
  }

  if (m_result <= c_cost + (n - c + 1) * m_cost) return;

  for (int i = 2; i <= n; i++)
    if (!visted[i]) {
      visted[i] = true;
      backtracking(c + 1, i, c_cost + WS[u][i]);

      visted[i] = false;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  cin >> n;
  WS.resize(n + 1, vector<int>(n + 1));
  visted.resize(n + 1, false);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> WS[i][j];
      if (i != j)
        m_cost = min(m_cost, WS[i][j]);
    }
  
  visted[1] = true;

  backtracking(1, 1, 0);

  cout << m_result;

  return 0;
};