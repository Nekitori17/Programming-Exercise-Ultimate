#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  priority_queue<ll, vector<ll>, greater<ll>> pq;

  ll n;
  cin >> n;
  while (n--) {
    ll x;
    cin >> x;
    pq.push(x);
  }

  ll ans = 0;
  while (pq.size() > 1) {
    ll a = pq.top(); pq.pop();
    ll b = pq.top(); pq.pop();
    
    ll p = a + b;
    ans += p;
    pq.push(p);
  }

  cout << (ans == 0 ? pq.top() : ans);

  return 0;
};