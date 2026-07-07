#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<ll> &a, ll h, ll t) {
  ll s = 0;
  
  for (ll i : a)
    if (i > h) {
      s += i - h;

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

  ll l = 0, r = 0;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    r = max(r, a[i]);
  }

  ll as;
  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (check(a, mid, k)) {
      l = mid + 1;
      as = mid;
    } else r = mid - 1;
  }

  cout << as;

  return 0;
};