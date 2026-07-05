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

  vector<ll> a(1, 0);
  ll l, r;
  while (n--) {
    cin >> l >> r;
    if (r + 2 > a.size())
      a.resize(r + 2, 0);

    a[l]++;
    a[r + 1]--;
  }

  ll pr = 0;
  ll bi, be = 0;
  for (ll i = 1; i < a.size(); i++) {
    pr += a[i];

    if (pr > be) {
      bi = i;
      be = pr;
    }
  }

  cout << bi << " " << be;

  return 0;
};