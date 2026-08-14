#include <iostream>
#include "../../estruturas/suffixArray.hpp"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  getchar();
  for (int i = 0;i < t;i++) {
    string s;
    getline(cin, s);
    int n = s.length();

    auto start = chrono::high_resolution_clock::now();
    SuffixArray sa(s);
    sa.buildLCP();
    auto end = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    auto& lcp = sa.lcp;

    auto start2 = chrono::high_resolution_clock::now();
    int pos = 0;
    for (;sa[pos] != 0;pos++);
    int len = n;
    int k = 0;
    for (int j = pos - 2;j >= 0 and len >= 0;j--) {
      len = min(len, lcp[j]);
      if (n - sa[j + 1] == len) {
        k = max(k, len);
      }
    }
    auto end2 = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

    cout << n - k << endl;
  }
  return 0;
}

