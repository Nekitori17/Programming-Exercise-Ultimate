#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(ll x){
  if (x < 2) return false;
  if (x == 2) return true;

  for (ll i = 2; i * i <= x; i++)
    if (x % i == 0) return false;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll q;
  cin >> q;

  ll x;
  while (q--) {
    cin >> x;
    cout << (isPrime(x) ? "YES" : "NO") << "\n";
  }

  return 0;
};