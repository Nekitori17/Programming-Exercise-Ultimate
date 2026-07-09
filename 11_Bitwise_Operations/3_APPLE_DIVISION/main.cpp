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

  ll sum = 0;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  ll ans = 1e18;
  for (ll mask = 0; mask < (1LL << n); mask++) {
    ll csum = 0;
    for (ll i = 0; i < n; i++)
      if (mask >> i & 1) csum += a[i];

    ans = min(ans, abs(csum - (sum - csum)));
  }

  cout << ans;
    
  return 0;
};