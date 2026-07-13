#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m;
  cin >> n >> m;

  priority_queue<ll> pq;

  while (n--) {
    ll x; cin >> x;
    pq.push(x);
  }

  ll ans = 0;
  while (m--) {
    ll i = pq.top(); pq.pop();

    ans += i;
    pq.push(i - 1);
  }

  cout << ans;
  
  return 0;
};