#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n;
  cin >> n;

  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<ll> dp(n + 1);
  dp[0] = 0;
  dp[1] = a[1];

  for (int i = 2; i <= n; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
  }

  cout << dp[n];

  return 0;
};