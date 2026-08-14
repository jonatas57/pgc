#include <iostream>
#include <vector>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

vector<long long> countSubstrings(SuffixTree& st) {
  vector<long long> dp(st.sz, -1);
  stack<pair<int, int>> q;
  int n = st.str.size();
  q.emplace(0, -1);
  while (!q.empty()) {
    auto& [u, p] = q.top();
    if (dp[u] == -1) {
      dp[u] = 0;
      for (auto& [ch, v] : st[u].next) {
        q.emplace(v, u);
      }
    }
    else {
      q.pop();
      if (p != -1) {
        dp[p] += dp[u] + st[u].len() - (st[u].r == n + 1);
      }
    }
  }
  return dp;
}

string kth_substring(SuffixTree& st, vector<long long>& dp, long long k) {
  if (k > dp[0]) {
    return "";
  }
  int at = 0;
  string ans;
  string& s = st.str;
  int n = s.length();
  char c;
  int v;
  while (k) {
    for (auto& [c, v] : st[at].next) {
      long long cnt = dp[v] + st.t[v].len() - (st[v].r == n + 1);
      if (k > cnt) {
        k -= cnt;
      } else {
        for (int i = st.t[v].l;i < st.t[v].r and k;i++) {
          ans += s[i];
          k--;
        }
        at = v;
        break;
      }
    }
  }
  return ans;
}

int main() {
  string s;
  int q;
  getline(cin, s);
  cin >> q;

  auto start = chrono::high_resolution_clock::now();
  SuffixTree st(s);
  auto dp = countSubstrings(st);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  long long k;
  for (int tc = 0;tc < q;tc++) {
    cin >> k;
    auto itstart = chrono::high_resolution_clock::now();
    string ans = kth_substring(st, dp, k);
    auto itend = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(itend - itstart).count() << endl;
    cout << ans << endl;
  }
  return 0;
}

