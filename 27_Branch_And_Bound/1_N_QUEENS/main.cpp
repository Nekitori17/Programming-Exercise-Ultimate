#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int cnt = 0;
int q = 0;
vector<bool> cs, d1s, d2s;

void backtracking(int r) {
  if (r > n) {
    cnt++;
    return;
  }

  for (int c = 1; c <= n; c++) {
    int d1 = r + c;
    int d2 = n + c - r;

    if (cs[c] || d1s[d1] || d2s[d2]) continue;

    cs[c] = d1s[d1] = d2s[d2] = true;
    backtracking(r + 1);
    
    cs[c] = d1s[d1] = d2s[d2] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  cin >> n;
  cs.resize(n + 1);
  d1s.resize(2 * n + 1);
  d2s.resize(2 * n + 1);

  backtracking(1);

  cout << cnt;

  return 0;
};