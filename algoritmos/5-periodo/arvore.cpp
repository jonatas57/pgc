#include <iostream>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0;i < t;i++) {
    string s;
    cin >> s;
    int n = s.size();
    s += '$';
    SuffixTree st(s);
    SuffixTree::state at(0, 0);
    int k = 0;
    for (int i = 0;i < n - 1;i++) {
      at = st.go(at, i, i + 1);
      auto suf = st.go(at, n, n + 1);
      if (suf.v != -1) k = i + 1;
    }
    cout << n - k << endl;
  }
  return 0;
}

