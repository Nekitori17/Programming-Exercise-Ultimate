#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q, k;
  cin >> n >> q >> k;

  vector<ll> a(n + 2, 0);
  ll l, r;
  while (q--)
  {
    cin >> l >> r;
    a[l]++;
    a[r + 1]--;
  }

  ll pre = 0;
  ll ans = 0;
  for (ll i = 1; i <= n; i++)
  {
    pre += a[i];
    ans += pre >= k ? 1 : 0;
  }

  cout << ans;

  return 0;
};