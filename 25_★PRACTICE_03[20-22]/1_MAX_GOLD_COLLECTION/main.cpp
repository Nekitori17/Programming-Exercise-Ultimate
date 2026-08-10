#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll N, W;
  cin >> N >> W;

  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));

  for (ll i = 1; i <= N; i++) {
    ll w, v;
    cin >> w >> v;

    for (ll j = 1; j <= W; j++) {
      dp[i][j] = dp[i - 1][j];

      if (w <= j) {
        ll prev_val = (i >= 2) ? dp[i - 2][j - w] : 0;
        dp[i][j] = max(dp[i][j], prev_val + v);
      }
    }
  }

  cout << dp[N][W];

  return 0;
};