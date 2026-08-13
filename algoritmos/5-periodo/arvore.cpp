#include <iostream>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

int main() {
  int t;
  cin >> t;
  getchar();
  for (int i = 0;i < t;i++) {
    string s;
    getline(cin, s);
    int n = s.size();
    
    auto start = chrono::high_resolution_clock::now();
    SuffixTree st(s);
    auto end = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    auto start2 = chrono::high_resolution_clock::now();
    SuffixTree::state at(0, 0);
    int k = 0;
    for (int i = 0;i < n - 1;i++) {
      at = st.go(at, i, i + 1);
      auto suf = st.go(at, n, n + 1);
      if (suf.v != -1) k = i + 1;
    }
    auto end2 = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

    cout << n - k << endl;
  }
  return 0;
}

