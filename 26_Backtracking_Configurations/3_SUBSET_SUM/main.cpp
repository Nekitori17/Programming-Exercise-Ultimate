#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int k;
vector<int> a;
bool founded = false;

vector<int> x;

void backtracking(int idx, int sum) {
  if (sum == k) {
    for (int i : x) cout << i << " ";
    cout << "\n";
    founded = true;
    return;
  }
  
  if (sum > k || idx > n) return;

  x.push_back(a[idx]);
  backtracking(idx + 1, sum + a[idx]);

  x.pop_back();
  backtracking(idx + 1, sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  cin >> n >> k;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  sort(a.begin() + 1, a.end());

  backtracking(1, 0);

  if (!founded) cout << -1;

  return 0;
};