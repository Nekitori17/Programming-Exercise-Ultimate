#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n, s;
  cin >> n >> s;
  vector<int> cs(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> cs[i];

  vector<int> dp(s + 1, INF);
  dp[0] = 0;

  for (int i = 1; i <= s; i++) {
    for (int j = 1; j <= n; j++) {
      int c = cs[j];
      if (c <= i && dp[i - c] != INF)
        dp[i] = min(dp[i], dp[i - c] + 1);
    }
  }

  cout << (dp[s] == INF ? -1 : dp[s]);

  return 0;
};