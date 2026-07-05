#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, x;
  cin >> n >> x;
  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; i++)
    cin >> a[i];

  ll l = 1, r = n;
  while (l < r) {
    ll s = a[l] + a[r];

    if (s == x) {
      cout << l << " " << r;
      return 0;
    }

    if (s > x)
      r--;
    else
      l++;
  }

  cout << -1 << " " << -1;

  return 0;
};