#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int N;
ll W;

struct Item {
  ll w, v;
};

vector<Item> items;
ll best_val = 0;

double upperBound(int idx, ll curVal, ll remain) {
  double bound = (double)curVal;
  for (int i = idx; i < N && remain > 0; i++) {
    if (items[i].w <= remain) {
      remain -= items[i].w;
      bound += (double)items[i].v;
    } else {
      bound += (double)items[i].v * ((double)remain / (double)items[i].w);
      remain = 0;
    }
  }
  return bound;
}

void solve(int idx, ll curVal, ll curWeight) {
  if (curVal > best_val)
    best_val = curVal;

  if (idx == N)
    return;

  ll remain = W - curWeight;

  double bound = upperBound(idx, curVal, remain);
  if (bound <= (double)best_val)
    return;

  if (items[idx].w <= remain) {
    solve(idx + 1, curVal + items[idx].v, curWeight + items[idx].w);
  }

  solve(idx + 1, curVal, curWeight);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  cin >> N >> W;
  items.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> items[i].w >> items[i].v;
  }

  sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
    return (ld)a.v * b.w > (ld)b.v * a.w;
  });

  solve(0, 0, 0);

  cout << best_val << "\n";

  return 0;
};