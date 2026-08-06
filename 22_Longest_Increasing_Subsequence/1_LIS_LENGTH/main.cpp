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

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<int> dp(n + 1, 1);
  for (int i = 1; i <= n; i++)
    for (int j = i - 1; j >= 1; j--)
      if (a[i] > a[j])
        dp[i] = max(dp[i], dp[j] + 1);

  cout << *max_element(dp.begin() + 1, dp.end());

  return 0;
};