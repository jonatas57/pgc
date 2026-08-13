#include <iostream>
#include <queue>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

const char WORDSEP = '#';

int lcs(string a, string b) {
  auto start = chrono::high_resolution_clock::now();
  SuffixTree st(a + WORDSEP + b);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  auto start2 = chrono::high_resolution_clock::now();
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  vector<int> len(st.t.size()), cnt(st.t.size()), ord;
  while (!q.empty()) {
    auto [u, l] = q.front();
    q.pop();
    ord.push_back(u);
    len[u] = l;
    for (auto& [ch, v] : st[u].next) {
      q.emplace(v, l + st[v].len());
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
  auto end2 = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;
  return ans;
}

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  cout << lcs(a, b) << endl;
  return 0;
}
