#include <iostream>
#include <queue>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

const char WORDSEP = '#';

int lcs(string a, string b) {
  SuffixTree st(a + WORDSEP + b);
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  vector<int> len(st.t.size()), cnt(st.t.size()), ord;
  int u, l;
  while (!q.empty()) {
    tie(u, l) = q.front();
    q.pop();
    ord.push_back(u);
    len[u] = l;
    for (auto& p : st[u].next) {
      q.emplace(p.second, l + st[p.second].len());
    }
  }
  int ans = 0;
  for (int i = (int)ord.size() - 1;i >= 0;i--) {
    int u = ord[i];
    if (st[u].next.empty()) {
      if (st[u].l <= (int)a.size()) {
        cnt[u] = 1;
      }
      else {
        cnt[u] = 2;
      }
    }
    if (st[u].par != -1) cnt[st[u].par] |= cnt[u];
    if (cnt[u] == 3) {
      ans = max(ans, len[u]);
    }
  }
  return ans;
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << lcs(a, b) << endl;
  return 0;
}
