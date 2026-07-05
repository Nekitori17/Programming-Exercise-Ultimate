#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m, q;
  cin >> n >> m >> q;

  vector<vector<ll>> a(n + 2, vector<ll>(m + 2, 0));
  ll x1, y1, x2, y2, v;
  while (q--)
  {
    cin >> x1 >> y1 >> x2 >> y2 >> v;
    a[x1][y1] += v;
    a[x2 + 1][y1] -= v;
    a[x1][y2 + 1] -= v;
    a[x2 + 1][y2 + 1] += v;
  }

  vector<vector<ll>> r(n + 2, vector<ll>(m + 2, 0));
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++)
    {
      r[i][j] = r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1] + a[i][j];
      cout << r[i][j] << " ";
    }

    cout << "\n";
  }

  return 0;
};