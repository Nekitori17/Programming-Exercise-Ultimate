#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<ll> &xs, ll cn, ll c) {
  ll l = c - 1;
  ll lx = xs[0];
  for (ll i = 1; i < xs.size(); i++) {
    if (xs[i] - lx >= cn) {
      l--;
      lx = xs[i];
    }

    if (l == 0) return true;
  }

  return l == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  ll l = 0, r = a[a.size() - 1] - a[0];

  ll ans;
  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (check(a, mid, k)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }

  cout << ans;
  return 0;
};