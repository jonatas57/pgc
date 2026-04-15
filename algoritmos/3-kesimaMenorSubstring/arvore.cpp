#include <iostream>
#include <vector>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

int main() {
  string s;
  int q, k;
  cin >> s >> q;
  SuffixTree st(s);
  vector<long long> dp(st.sz);
  function<long long(int)> dfs = [&] (int u) {
    dp[u] = 0;
    char c;
    int v;
    for (auto& p : st.t[u].next) {
      tie(c, v) = p;
      dp[u] += dfs(v) + st.t[v].len();
    }
    return dp[u];
  };
  dfs(0);

  for (int tc = 0;tc < q;tc++) {
    cin >> k;
    int at = 0;
    string ans;
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
    cout << ans << endl;
  }
  return 0;
}

