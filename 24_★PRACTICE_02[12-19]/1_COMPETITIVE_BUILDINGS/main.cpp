#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];

  stack<pair<ll, ll>> st;

  vector<ll> ans(n);
  for (ll i = n - 1; i >= 0;i--) {
    if (st.empty() || a[i] <= st.top().first)
      st.push({a[i], 0});
    else {
      ll ct = 0;
      while (!st.empty() && a[i] > st.top().first) {
        ct += st.top().second + 1;
        st.pop();
      }

      st.push({a[i], ct});
    }

    ans[i] = st.top().second;
  }

  for (ll i = 0; i < n; i++)
    cout << ans[i] << " ";

  return 0;
};