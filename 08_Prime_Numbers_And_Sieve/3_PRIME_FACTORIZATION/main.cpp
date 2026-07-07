#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 1e7 + 5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;
  for (ll i = 2; i * i <= n; i++)
    while (n % i == 0) {
      cout << i << " ";
      n /= i;
    }

  if (n != 1) cout << n;

  return 0;
};