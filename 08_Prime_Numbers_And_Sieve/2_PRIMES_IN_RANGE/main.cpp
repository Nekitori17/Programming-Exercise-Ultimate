#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN =  1e7 + 5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  vector<bool> primes(MAXN, true);
  primes[0] = primes[1] = false;
  for (ll i = 2; i * i <= MAXN; i ++) {
    if (primes[i])
      for (ll j = i * i; j < MAXN; j += i)
        primes[j] = false;
  }

  vector<ll> pre(MAXN, 0);
  for (ll i = 1; i < MAXN; i++)
    pre[i] = pre[i - 1] + primes[i];

  ll q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] << "\n";
  }

  return 0;
};