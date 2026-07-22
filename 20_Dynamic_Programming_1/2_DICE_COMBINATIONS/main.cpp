#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n;
  cin >> n;

  vector<ll> dp(n + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i - j >= 0) {
        dp[i] = (dp[i] + dp[i - j]) % MOD;
      }
    }
  }

  cout << dp[n];

  return 0;
};