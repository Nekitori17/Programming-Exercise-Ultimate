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

  multiset<ll> ms;
  ll x;
  while (n--) {
    cin >> x;
    ms.insert(x);
  }

  ll y;
  while (m--) {
    cin >> y;
    auto it = ms.upper_bound(y);

    if (it == ms.begin()) {
      cout << -1 << '\n';
    } else {
      --it;
      cout << *it << '\n';
      ms.erase(it);
    }
  }

  return 0;
};