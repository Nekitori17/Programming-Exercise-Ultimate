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

  vector<ll> tail;

  for (ll x : a) {
    auto it = lower_bound(tail.begin(), tail.end(), x);

    if (it == tail.end())
      tail.push_back(x);
    else
     *it = x;
  }

  cout << tail.size();

  return 0;
};