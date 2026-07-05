#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;

  ll x;
  vector<vector<ll>> a(n + 1, vector<ll>(n + 1, 0));
  for (ll i = 1; i <= n; i++)
  {
    for (ll j = 1; j <= n; j++)
    {
      cin >> x;
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + x;
    }
  }

  ll best = -1e18;
  for (ll x2 = 1; x2 <= n; x2++)
    for (ll y2 = 1; y2 <= n; y2++)
      for (ll x1 = 1; x1 <= x2; x1++)
        for (ll y1 = 1; y1 <= y2; y1++)
          best = max(
            best,
            a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 -1]
          );

  cout << best;

  return 0;
};