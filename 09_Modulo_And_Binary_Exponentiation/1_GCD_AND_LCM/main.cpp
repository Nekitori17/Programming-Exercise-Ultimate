#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll q;
  cin >> q;

  while (q--) {
    ll a, b;
    cin >> a >> b;

    ll GCD = gcd(a, b);
    ll LCM = (a/ GCD) * b;

    cout << GCD << " " << LCM << "\n";
  }

  return 0;
};