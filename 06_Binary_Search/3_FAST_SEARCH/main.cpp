#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  cin >> q;

  ll l, r;
  while (q--) {
    cin >> l >> r;

    ll ct = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
    cout << ct << " ";
  }

  return 0;
};