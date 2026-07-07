#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<ll> &ms, ll x, ll t) {
  ll s = 0;
  for (ll m: ms) {
    s += x / m;

    if (s >= t) return true;
  }

  return s >= t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  ll l = 1e18, r = 0;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    l = min(l, a[i]);
    r = max(r, a[i]);
  }

  r *= k;
  ll ans;
  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (check(a, mid, k)) {
      ans = mid;
      r = mid - 1;
    } else l = mid + 1;
  }

  cout << ans;

  return 0;
};