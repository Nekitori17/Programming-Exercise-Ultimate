#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, x;
  cin >> n >> x;

  vector<pair<ll, ll>> a;
  ll z;
  for (ll i = 1; i <= n; i++) {
    cin >> z;
    a.push_back({z, i});
  }

  sort(a.begin(), a.end());

  for (ll i = 0; i < n; i++) {
    ll t = x - a[i].first;

    ll l = i + 1, r = n - 1;
    while (l < r) {
      ll s = a[l].first + a[r].first;

      if (s == t) {
        cout << a[i].second << " " << a[l].second << " " << a[r].second;
        return 0;
      }

      if (s > t) r--;
      else l++;
    }
  }

  cout << "IMPOSSIBLE";

  return 0;
};