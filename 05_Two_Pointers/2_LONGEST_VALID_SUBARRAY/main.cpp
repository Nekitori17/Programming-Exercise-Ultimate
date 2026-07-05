#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, s;
  cin >> n >> s;
  vector<ll> a(n + 1, 0);
  for (ll i = 1; i <= n; i++)
    cin >> a[i];

  ll cu = 0,ans = 0;
  ll l = 1;
  for (ll r = 1; r <= n; r++) {
    cu += a[r];

    while (l <= r && cu > s) {
      cu -= a[l];
      l++;
    }

    if (cu <= s) {
      ans = max(ans, r - l + 1);
    }
  }

  cout << ans;

  return 0;
};