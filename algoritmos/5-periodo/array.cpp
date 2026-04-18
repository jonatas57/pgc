#include <iostream>
#include "../../estruturas/suffixArray.hpp"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  for (int i = 0;i < t;i++) {
    string s;
    cin >> s;
    int n = s.length();
    SuffixArray sa(s);
    sa.buildLCP();
    auto& lcp = sa.lcp;
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
    cout << n - k << endl;
  }
  return 0;
}

