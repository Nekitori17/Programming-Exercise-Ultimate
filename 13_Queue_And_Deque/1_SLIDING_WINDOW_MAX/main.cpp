#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  deque<int> dq;

  for (int i = 0; i < n; i++) {
    while (!dq.empty() && a[dq.back()] <= a[i]) {
      dq.pop_back();
    }

    dq.push_back(i);

    if (dq.front() <= i - k) {
      dq.pop_front();
    }

    if (i >= k - 1) {
      cout << a[dq.front()] << " ";
    }
  }
  cout << endl;

  return 0;
};