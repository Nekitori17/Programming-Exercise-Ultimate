#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<ll> tops;

  for (ll x : a) {
    auto it = upper_bound(tops.begin(), tops.end(), x);

    if (it == tops.end())
      tops.push_back(x);
    else
      *it = x;
  }

  cout << tops.size();

  return 0;
};