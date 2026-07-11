#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, s;
  cin >> n >> s;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
   cin >> a[i];

  ll ans = 0;
  deque<ll> dqmn;
  deque<ll> dqmx;
  
  ll l = 0;
  for (ll r = 0; r < n; r++) {
    ll v = a[r];

    while (!dqmn.empty() && a[dqmn.back()] > v)
      dqmn.pop_back();
    dqmn.push_back(r);

    while (!dqmx.empty() && a[dqmx.back()] < v)
      dqmx.pop_back();
    dqmx.push_back(r);

    while (a[dqmx.front()] - a[dqmn.front()] > s) {
      l++;
      while (!dqmn.empty() && dqmn.front() < l) dqmn.pop_front();
      while (!dqmx.empty() && dqmx.front() < l) dqmx.pop_front();
    }

    ans = max(ans, r - l + 1);
  }

  cout << ans;

  return 0;
};