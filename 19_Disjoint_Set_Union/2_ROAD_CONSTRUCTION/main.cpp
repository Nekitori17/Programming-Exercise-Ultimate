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

  int unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (rx != ry) {
      if (sz[rx] < sz[ry]) swap(rx, ry);
      parents[ry] = rx;
      return sz[rx] += sz[ry];
    } else return 0;
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

  int ctn = n;
  int mx = 1;
  while (q--) {
    int x, y;
    cin >> x >> y;
    
    int r = dsu.unite(x, y);
    
    if (r) {
      ctn--;
      mx = max(mx, r); 
    }

    cout << ctn << " " << mx << "\n";
  }

  return 0;
};