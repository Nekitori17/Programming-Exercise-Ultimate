#include <algorithm>
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

  vector<pair<int, int>> rects(n);
  for (int i = 0; i < n; i++)
    cin >> rects[i].first >> rects[i].second;

  sort(rects.begin(), rects.end(), [](pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first)
      return x.second > y.second;
    
    return x.first < y.first;
  });

  vector<ll> tail;
  for (pair<int, int> rect : rects) {
    auto it = lower_bound(tail.begin(), tail.end(), rect.second);

    if (it == tail.end())
      tail.push_back(rect.second);
    else
      *it = rect.second;
  }

  cout << tail.size();

  return 0;
};