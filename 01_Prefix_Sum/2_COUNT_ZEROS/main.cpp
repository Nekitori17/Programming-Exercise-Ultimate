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

  vector<int> a(n + 1, 0);
  int x;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    a[i] = a[i - 1] + (x == 0 ? 1: 0);
  }

  int l, r;
  while (q--)
  {
    cin >> l >> r;
    cout << a[r] - a[l - 1] << '\n';
  }

  return 0;
};