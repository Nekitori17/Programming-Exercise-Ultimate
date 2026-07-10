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

  stack<ll> st;
  vector<ll> ans(n, -1);
  for (ll i = 0; i < n; i++) {
    ll v = a[i];

    while (!st.empty() && a[st.top()] < v) {
      ans[st.top()] = v;
      st.pop();
    }

    st.push(i);
  }

  for (ll i : ans) cout << i << " ";

  return 0;
};