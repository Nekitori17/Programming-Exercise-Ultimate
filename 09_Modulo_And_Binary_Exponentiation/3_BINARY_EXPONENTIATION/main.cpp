#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binPow(ll a, ll n, ll m) {
  if (n == 0) return 1 % m;

  a %= m;

  if (n % 2 == 0) {
    ll haf = binPow(a, n / 2, m);
    return (haf * haf) % m;
  } else {
    return (a * binPow(a, n - 1, m)) % m;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll a, n, m;
  cin >> a >> n >> m;

  cout << binPow(a, n, m);

  return 0;
};