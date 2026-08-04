#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, c;
  cin >> n >> c;

  vector<pair<ll, ll>> a(n + 1);
  for (ll i = 1; i <= n; i++) {
    ll w, v;
    cin >> w >> v;
    a[i] = {w, v};
  }

  vector<long long> dp(c + 1, 0);

  for (int i = 1; i <= n; i++)
    for (int j = c; j >= 1; j--)
      if (j >= a[i].first)
        dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);

  cout << dp[c];

  return 0;
};