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

  map<string, ll> fqs;
  string s;
  while (n--)
  {
    cin >> s;
    fqs[s]++;
  }


  for (pair<string, ll> fq : fqs)
    cout << fq.first << " " << fq.second << "\n";

  return 0;
};