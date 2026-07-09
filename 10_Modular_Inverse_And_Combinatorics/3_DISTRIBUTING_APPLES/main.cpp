#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

const ll MODULO = 1000000007;

ll binPow(ll a, ll n, ll m) {
  if (n == 0)
    return 1;

  a %= m;

  if (n & 1)
    return a * binPow(a, n - 1, m) % m;

  ll half = binPow(a, n / 2, m);
  return half * half % m;
}

const int MAXN = 2000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  vector<ll> frac(MAXN + 1);
  vector<ll> invFrac(MAXN + 1);
  frac[0] = 1;
  for (int i = 1; i <= MAXN; i++)
    frac[i] = frac[i - 1] * i % MODULO;

  invFrac[MAXN] = binPow(frac[MAXN], MODULO - 2, MODULO);
  for (int i = MAXN - 1; i >= 0; i--)
    invFrac[i] = invFrac[i + 1] * (i + 1) % MODULO;

  ll x, y;
  cin >> x >> y;

  ll n = x + y - 1, k = y - 1;
  cout << frac[n] * invFrac[k] % MODULO * invFrac[n - k] % MODULO << "\n";

  return 0;
};