#include <iostream>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  SuffixTree st(s);
  for (int i = 0;i < k;i++) {
    string t;
    cin >> t;
    int v = 0, pos = 0;
    bool ok = true;
    for (auto& c : t) {
      if (!ok) break;
      if (pos == st[v].len()) {
        v = st[v][c];
        pos = 1;
      }
      else if (c == st.str[st[v].l + pos]) {
        pos++;
      }
      else v = -1;
      ok = v != -1;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}

