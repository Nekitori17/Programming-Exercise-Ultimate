#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n + 2, 0);

  while (k--) {
    ll l, r, v;
    cin >> l >> r >> v;

    a[l] += v;
    a[r + 1] -= v;
  }

  ll m, cnt = -1e18;
  for (ll i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    
    if (a[i] > m) {
      m = a[i];
      cnt = 1;
    } else if (a[i] == m)
      cnt++;
  }

  cout << m << " " << cnt;

  return 0;
};