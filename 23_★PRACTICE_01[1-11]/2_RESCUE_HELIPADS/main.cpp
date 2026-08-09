#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll r, ll k, vector<ll> &a) {
  ll t = 1;

  ll c2r = 0;
  for (ll i = 1; i < a.size(); i++) {
    if (c2r + a[i] - a[i - 1] > 2 * r) {
      t++;
      c2r = 0;
      if (t > k) return false;
    } else 
      c2r += a[i] - a[i - 1];
  }

  return t <= k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (ll i = 0; i < n;i++)
    cin >> a[i];

  ll l = 0, h = a[n - 1] - a[0];

  ll ans = 0;
  while (l <= h) {
    ll mid = l + (h - l) / 2;

    if (check(mid, k, a)) {
      ans = mid;
      h = mid - 1;
    } else
      l = mid + 1;
  }

  cout << ans;

  return 0;
};