#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;

  ll ans = 0;
  ll x;
  while (n--) {
    cin >> x;
    ans ^= x;
  }

  cout << ans;

  return 0;
};