#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;

  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; i++)
    cin >> a[i];

  stack<ll> ns;
  stack<ll> ps;

  vector<ll> nsr(n + 1, n + 1);
  vector<ll> psr(n + 1, 0);

  for (ll i = 1; i <= n; i++) {
    ll v = a[i];

    while (!ns.empty() && a[ns.top()] > v) {
      nsr[ns.top()] = i;
      ns.pop();
    }

    ns.push(i);
  }

  for (ll i = n; i >= 1; i--) {
    ll v = a[i];

    while (!ps.empty() && a[ps.top()] > v) {
      psr[ps.top()] = i;
      ps.pop();
    }

    ps.push(i);
  }

  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    ll v = a[i];

    ans = max(ans, v * (nsr[i] - psr[i] - 1));
  }

  cout << ans;

  return 0;
};