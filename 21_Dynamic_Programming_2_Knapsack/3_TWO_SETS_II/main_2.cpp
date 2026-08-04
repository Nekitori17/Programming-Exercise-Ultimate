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

  vector<ll> dp(sum + 1, 0);
  dp[0] = 1;

  for (int i = 1; i < n; i++)
    for (int j = sum; j >= 1; j--)
      if (j >= i)
        dp[j] = (dp[j] + dp[j - i]) % MOD;

  cout << dp[sum];
}