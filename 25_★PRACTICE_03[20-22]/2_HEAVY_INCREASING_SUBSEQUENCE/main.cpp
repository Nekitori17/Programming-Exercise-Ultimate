#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;

  vector<ll> a(n + 1);
  vector<ll> w(n + 1);
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  for (ll i = 1; i <= n; i++)
    cin >> w[i];

  vector<ll> dp(n + 1);
  for (ll i = 1; i <= n; i++)
    dp[i] = w[i];

  for (ll i = 1; i <= n; i++)
    for (ll j = i - 1; j >= 1; j--)
      if (a[i] > a[j])
        dp[i] = max(dp[i], dp[j] + w[i]);

  cout << *max_element(dp.begin() + 1, dp.end());

  return 0;
};