#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;

  ll sum = n * (n + 1) / 2;

  if (sum % 2) {
    cout << 0;
    return 0;
  }

  sum /= 2;

  vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 0));
  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= i)
        dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
    }
  }

  cout << dp[n - 1][sum];
}