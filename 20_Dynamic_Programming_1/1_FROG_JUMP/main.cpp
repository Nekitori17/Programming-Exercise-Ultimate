#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n;
  cin >> n;

  vector<ll> dp(n + 1, INF);
  vector<ll> h(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> h[i];

  dp[1] = 0;
  dp[2] = abs(h[2] - h[1]);
  
  for (int i = 3; i <= n; i++) {
    dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[n];

  return 0;
};