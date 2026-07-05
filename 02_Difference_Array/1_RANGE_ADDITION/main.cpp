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

  vector<ll> dif(n + 2, 0);
  ll l, r, v;
  while (q--)
  {
    cin >> l >> r >> v;
    dif[l] += v;
    dif[r + 1] -= v;
  }

  ll pr = 0;
  for (ll i = 1; i <= n; i++)
  {
    pr += dif[i];
    cout << pr << " ";
  }

  return 0;
};