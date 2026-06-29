#include <iostream>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

bool isSubstring(SuffixTree& st, const string& pattern) {
  int v = 0, pos = 0;
  for (auto& c : pattern) {
    if (pos == st[v].len()) {
      v = st[v][c];
      pos = 1;
    }
    else if (c == st.str[st[v].l + pos]) {
      pos++;
    }
    else return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  int k;
  getline(cin, s);
  cin >> k;
  getchar();
  auto start = chrono::high_resolution_clock::now();
  SuffixTree st(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
  for (int i = 0;i < k;i++) {
    string t;
    getline(cin, t);
    auto itstart = chrono::high_resolution_clock::now();
    bool ok = isSubstring(st, t);
    auto itend = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(itend - itstart).count() << endl;
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}

