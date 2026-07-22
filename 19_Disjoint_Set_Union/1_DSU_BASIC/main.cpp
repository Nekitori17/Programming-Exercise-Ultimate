#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
  vector<int> parents;
  vector<int> sz;

  DSU(int n) {
    parents.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) parents[i] = i;
  }

  int find(int x) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
  }

  void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (rx != ry) {
      if (sz[rx] < sz[ry]) swap(rx, ry);
      parents[ry] = rx;
      sz[rx] += sz[ry];
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  DSU dsu(n);

  for (int i = 0; i < q; i++) {
    int type, u, v;
    cin >> type >> u >> v;

    if (type == 1) {
      dsu.unite(u, v);
    } else {
      if (dsu.find(u) == dsu.find(v)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

  return 0;
};