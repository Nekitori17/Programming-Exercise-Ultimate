#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

bool isOpen(char s) { return s == '(' || s == '{' || s == '['; }
bool isClose(char s) { return s == ')' || s == '}' || s == ']'; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);

  stack<char> st;
  string s;
  cin >> s;
  for (char x : s) {
    if (isOpen(x)) st.push(x);
    else if (isClose(x)) {
      if (st.empty()) {
        cout << "NO";
        return 0;
      }

      char t = st.top();
      if ((t == '(' && x == ')') || (t == '{' && x == '}') ||
          (t == '[' && x == ']'))
        st.pop();
      else {
        cout << "NO";
        return 0;
      };
    } else {
      cout << "NO";
      return 0;
    }
  }

  cout << (st.empty() ? "YES" : "NO");

  return 0;
};