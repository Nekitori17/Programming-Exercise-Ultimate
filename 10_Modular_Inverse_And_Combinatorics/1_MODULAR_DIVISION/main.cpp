#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binPow(ll a, ll n, ll m) {
  if (n == 0) return 1 % m;

  a %= m;

  if (n % 2 == 0) {
    ll half = binPow(a, n / 2, m);
    return (half * half) % m;
  } else return (a * binPow(a, n - 1, m)) % m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll a, b, m;
  cin >> a >> b >> m;

  cout << ((a % m) * binPow(b, m - 2, m)) % m;

  return 0;
};