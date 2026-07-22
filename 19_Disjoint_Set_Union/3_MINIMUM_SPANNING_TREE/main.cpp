#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
  int u, v;
  ll w;
};

bool sortW(Edge a, Edge b) {
  return a.w < b.w;
}

struct DSU {
  vector<int> parents;
  vector<int> sz;

  DSU(int n) {
    parents.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1;i <= n; i++) parents[i] = i;
  }

  int find(int x) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
  }

  bool unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (rx != ry) {
      if (sz[rx] < sz[ry]) swap(rx, ry);
      parents[ry] = rx;
      sz[rx] += sz[ry];
      return true;
    } else return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, q;
  cin >> n >> q;

  vector<Edge> Edges(q);
  for (ll i = 0;i < q; i++) cin >> Edges[i].u >> Edges[i].v >> Edges[i].w;
  sort(Edges.begin(), Edges.end(), sortW);

  DSU dsu(n);
  int ans = 0;
  ll ctn = 0;

  for (auto [u, v, w] : Edges) {
    if (dsu.unite(u, v)) ans += w, ctn++;
    if (ctn == n-1) break;
  }

  if (ctn < n-1) cout << "IMPOSSIBLE";
  else cout << ans;

  return 0;
};