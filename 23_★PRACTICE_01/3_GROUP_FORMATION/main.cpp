#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 1e5;
const ll MOD = 1e9 + 7;
vector<ll> frac(MAXN + 1, 0);

ll binPow(ll a, ll n, ll m) {
  if (n == 0) return 1;
  if (n == 1) return a % m;

  a %= m;

  if (n % 2 == 0) {
    ll half = binPow(a, n / 2, m);
    return (half * half) % m;
  } else
    return a * binPow(a, n - 1, m) % m;
}

ll C(ll n, ll k) {
  if (k < 0 || k > n)
    return 0;
  
  ll nu = frac[n];
  ll de = frac[k] * frac[n - k] % MOD;

  return (nu * binPow(de, MOD - 2, MOD)) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m, k;
  cin >> n >> m >> k;

  frac[1] = frac[0] = 1;
  for (ll i = 2; i <= MAXN; i++)
    frac[i] = frac[i - 1] * i % MOD;

  ll ans = 0;
  ll f = max(2LL, k - m), t = min(k - 1, n);
  for (ll i = f; i <= t; i++) {
    ans = (ans + (C(n, i) * C(m, k - i)) % MOD) % MOD;
  }

  cout << ans;

  return 0;
};