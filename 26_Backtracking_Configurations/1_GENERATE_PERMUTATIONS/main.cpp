#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> a;
vector<bool> used;

void backtracking(int idx) {
  if (idx > n) {
    for (int l : a) cout << l << " ";
    cout << "\n";
    return;
  }

  for (int i = 1; i <= n; i++)
    if (!used[i]) {
      used[i] = true;
      a.push_back(i);

      backtracking(idx + 1);

      a.pop_back();
      used[i] = false;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  cin >> n;
  used.resize(n + 1, false);

  backtracking(1);

  return 0;
};