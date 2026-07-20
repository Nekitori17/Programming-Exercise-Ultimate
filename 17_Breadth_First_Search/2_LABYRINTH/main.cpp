#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n, m;
  cin >> n >> m;

  pair<int, int> st, ed;
  vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, true));
  vector<vector<char>> trace(n + 1, vector<char>(m + 1));
  char c;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> c;
      if (c == 'A') {
        st = {i, j};
        visited[i][j] = false;
      } else if (c == 'B') {
        ed = {i, j};
        visited[i][j] = false;
      } else if (c == '.')
        visited[i][j] = false;
    }

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  char dc[] = {'U', 'D', 'L', 'R'};

  queue<pair<int, int>> qu;
  visited[st.first][st.second] = true;
  qu.push(st);

  while (!qu.empty()) {
    pair<int, int> u = qu.front();
    qu.pop();

    if (u == ed) break;

    for (int i = 0; i < 4; i++) {
      pair<int, int> v = make_pair(u.first + dx[i], u.second + dy[i]);

      if (v.first < 1 || v.first > n || v.second < 1 || v.second > m)
        continue;

      if (visited[v.first][v.second])
        continue;

      visited[v.first][v.second] = true;
      trace[v.first][v.second] = dc[i];
      qu.push(v);
    }
  }

  if (!visited[ed.first][ed.second])
    cout << "NO";
  else {
      string ans;

      pair<int, int> cur = ed;

      while (cur != st) {
        char c = trace[cur.first][cur.second];
        ans += c;

        if (c == 'U')
          cur.first++;
        else if (c == 'D')
          cur.first--;
        else if (c == 'L')
          cur.second++;
        else if (c == 'R')
          cur.second--;
      }

      reverse(ans.begin(), ans.end());

      cout << "YES" << "\n";
      cout << ans.size() << "\n";
      cout << ans;
  }

  return 0;
};