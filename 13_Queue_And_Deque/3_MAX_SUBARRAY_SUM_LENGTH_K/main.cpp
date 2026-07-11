#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  vector<ll> pr(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    pr[i] = pr[i - 1] + x;
  }

  ll ans = -1e18;

  deque<ll> dq;
  dq.push_back(0);

  for (ll i = 1; i <= n; i++) {
    while (!dq.empty() && dq.front() < i - k) dq.pop_front();

    ll sum = pr[i] - pr[dq.front()];
    ans = max(ans, sum);

    while (!dq.empty() && pr[i] <= pr[dq.back()]) dq.pop_back();

    dq.push_back(i);
  }

  cout << ans << "\n";

  return 0;
};