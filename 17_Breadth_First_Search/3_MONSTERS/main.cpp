#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<string> grid(n);

  pair<int, int> st;
  queue<pair<int, int>> q;

  vector<vector<int>> monster(n, vector<int>(m, INF));
  vector<vector<int>> dist(n, vector<int>(m, INF));
  vector<vector<char>> trace(n, vector<char>(m));

  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'M') {
        q.push({i, j});
        monster[i][j] = 0;
      } else if (grid[i][j] == 'A') {
        st = {i, j};
      }
    }
  }

  if (st.first == 0 || st.first == n - 1 || st.second == 0 ||
      st.second == m - 1) {
    cout << "YES\n0\n";
    return 0;
  }

  const int dx[] = {-1, 1, 0, 0};
  const int dy[] = {0, 0, -1, 1};

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (grid[nx][ny] == '#')
        continue;
      if (monster[nx][ny] != INF)
        continue;

      monster[nx][ny] = monster[x][y] + 1;
      q.push({nx, ny});
    }
  }

  while (!q.empty())
    q.pop();

  dist[st.first][st.second] = 0;
  q.push(st);

  pair<int, int> ed = {-1, -1};

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
      ed = {x, y};
      break;
    }

    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (grid[nx][ny] == '#')
        continue;
      if (dist[nx][ny] != INF)
        continue;

      int nd = dist[x][y] + 1;

      if (nd >= monster[nx][ny])
        continue;

      dist[nx][ny] = nd;

      if (k == 0)
        trace[nx][ny] = 'U';
      else if (k == 1)
        trace[nx][ny] = 'D';
      else if (k == 2)
        trace[nx][ny] = 'L';
      else
        trace[nx][ny] = 'R';

      q.push({nx, ny});
    }
  }

  if (ed.first == -1) {
    cout << "NO\n";
    return 0;
  }

  string ans;

  int x = ed.first;
  int y = ed.second;

  while (make_pair(x, y) != st) {
    char c = trace[x][y];
    ans += c;

    if (c == 'U')
      x++;
    else if (c == 'D')
      x--;
    else if (c == 'L')
      y++;
    else
      y--;
  }

  reverse(ans.begin(), ans.end());

  cout << "YES\n";
  cout << ans.size() << '\n';
  cout << ans << '\n';

  return 0;
}