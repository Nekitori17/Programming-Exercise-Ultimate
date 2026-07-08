#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MODULO = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;
  
  ll ans = 1;
  for (ll i = 2; i <= n; i++)
    ans = ((ans % MODULO) * (i % MODULO)) % MODULO;

  cout << ans;

  return 0;
};