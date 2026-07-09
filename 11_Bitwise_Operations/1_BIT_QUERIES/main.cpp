#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll x, q;
  cin >> x >> q;

  ll t, i;
  while (q--) {
    cin >> t >> i;

    switch (t) {
      case 1:
        x = x | (1LL << i);
        break;
      case 2:
        x = x ^ (1LL << i);
        break;
      case 3:
        cout << ((x >> i) & 1) << "\n";
        break;
      default:
        break;
    }
  }

  cout << x;

  return 0;
};