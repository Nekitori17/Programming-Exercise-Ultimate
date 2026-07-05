#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n;
  cin >> n;

  vector<ll> a(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  for (int i = 1; i <= n; i++)
  {
    if (a[i - 1] == (a[n] - a[i])) {
      cout << i;

      return 0;
    }
  }

  cout << -1;

  return 0;
};