#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q, k;
  cin >> n >> q >> k;

  vector<vector<ll>> a(n + 2, vector<ll>(n + 2, 0));
  ll x1, y1, x2, y2;
  while (q--) {
    cin >> x1 >> y1 >> x2 >> y2;
    a[x1][y1]++;
    a[x2 + 1][y1]--;
    a[x1][y2 + 1]--;
    a[x2 + 1][y2 + 1]++;
  }

  vector<vector<ll>> r(n + 1, vector<ll>(n + 1, 0));
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      r[i][j] = r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1] + a[i][j];

      ans += r[i][j] >= k ? 1 : 0;
    }
  }

  cout << ans;

  return 0;
};