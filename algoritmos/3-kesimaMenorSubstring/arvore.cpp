#include <iostream>
#include <vector>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

vector<long long> countSubstrings(SuffixTree& st) {
  vector<long long> dp(st.sz);
  queue<int> q;
  q.push(0);
  vector<int> ord;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ord.push_back(u);
    for (auto& [ch, v] : st.t[u].next) {
      q.push(v);
    }
  }
  for (int i = ord.size() - 1;i >= 0;i--) {
    int u = ord[i];
    for (auto& [ch, v] : st.t[u].next) {
      dp[u] += dp[v] + st.t[v].len();
    }
  }
  return dp;
}

string kth_substring(SuffixTree& st, int k) {
  vector<long long> dp = countSubstrings(st);
  int at = 0;
  string ans;
  string& s = st.str;
  char c;
  int v;
  while (k) {
    for (auto& p : st.t[at].next) {
      tie(c, v) = p;
      long long cnt = dp[v] + st.t[v].len();
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
  int q, k;
  cin >> s >> q;

  auto start = chrono::high_resolution_clock::now();
  SuffixTree st(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  for (int tc = 0;tc < q;tc++) {
    cin >> k;
    auto itstart = chrono::high_resolution_clock::now();
    string ans = kth_substring(st, k);
    auto itend = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(itend - itstart).count() << endl;
    cout << ans << endl;
  }
  return 0;
}

