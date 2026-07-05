#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q;
  cin >> n >> q;

  string x;
  vector<vector<ll>> a(n + 1, vector<ll>(n + 1, 0));
  for (ll i = 1; i <= n; i++)
  {
    cin >> x;
    for (ll j = 1; j <= n; j++)
    {
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (x[j - 1] == '*' ? 1 : 0);
    }
  }

  ll x1, y1, x2, y2;
  while (q--)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1] << "\n";
  }

  return 0;
};