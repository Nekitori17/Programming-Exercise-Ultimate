#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string hasValue(vector<ll> &a, ll t) {
  
  ll l = 0, r = a.size() - 1;

  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (a[mid] == t) return "YES";

    if (a[mid] < t) l = mid + 1;
    else r = mid - 1;
  }
  
  return "NO";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q;
  cin >> n >> q;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];

  ll t;
  while (q--) {
    cin >> t;
    cout << hasValue(a, t) << "\n";
  }

  return 0;
};