#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct RunningMedian {
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;

  void insert(int val) {
    if (!max_heap.empty() && val <= max_heap.top())
      max_heap.push(val);
    else min_heap.push(val);

    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else if (max_heap.size() < min_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double getMedian() {
    if (max_heap.size() > min_heap.size())
      return max_heap.top();
    else return min(max_heap.top(), min_heap.top());
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n;
  if (cin >> n) {
    RunningMedian rm;
    for (int i = 0; i < n; ++i) {
      int val;
      cin >> val;
      rm.insert(val);
      cout << rm.getMedian() << "\n";
    }
  }

  return 0;
}