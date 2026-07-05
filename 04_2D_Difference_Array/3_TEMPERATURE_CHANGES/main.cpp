#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m, q;
  cin >> n >> m >> q;

  vector<vector<ll>> g(n + 1, vector<ll>(m + 1, 0));
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      cin >> g[i][j];

  vector<vector<ll>> a(n + 2, vector<ll>(m + 2, 0));
  ll x1, y1, x2, y2, v;
  while (q--) {
    cin >> x1 >> y1 >> x2 >> y2 >> v;
    a[x1][y1] += v;
    a[x2 + 1][y1] -= v;
    a[x1][y2 + 1] -= v;
    a[x2 + 1][y2 + 1] += v;
  }

  vector<vector<ll>> r(n + 1, vector<ll>(m + 1, 0));
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++)
      r[i][j] = r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1] + a[i][j];

  ll bs = -1e18, ct = 0;
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++) {
      g[i][j] += r[i][j];

      if (g[i][j] > bs) {
        bs = g[i][j];
        ct = 1;
      } else if (g[i][j] == bs) {
        ct++;
      }
    }

  cout << bs << " " << ct;

  return 0;
};