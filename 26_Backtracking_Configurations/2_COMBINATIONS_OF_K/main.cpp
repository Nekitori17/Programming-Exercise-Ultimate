#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
vector<int> a;

void backtracking(int idx, int i) {
  if (idx > k) {
    for (int i = 1; i <= k; i++) cout << a[i] << " ";
    cout << "\n";
    return;
  }

  for (ll s = i; s <= n - k + idx; s++) {
    a[idx] = s;

    backtracking(idx + 1, s + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  cin >> n >> k;
  a.resize(k + 1);

  backtracking(1, 1);

  return 0;
}