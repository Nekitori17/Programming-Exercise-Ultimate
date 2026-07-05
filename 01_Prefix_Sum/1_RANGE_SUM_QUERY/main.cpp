#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  vector<ll> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  int l, r;
  while (q--) {
    cin >> l >> r;
    cout << a[r] - a[l - 1] << '\n';
  }

  return 0;
};