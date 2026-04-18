#include <iostream>
#include "../../estruturas/suffixArray.hpp"

using namespace std;

pair<int, int> kth_substring(SuffixArray& sa, vector<int>& lcp, int k) {
  int start, length;
  int n = sa.size();
  for (int i = 0;i < n;i++) {
    int cnt = n - sa[i + 1];
    if (i) cnt -= lcp[i - 1];
    if (cnt < k) {
      k -= cnt;
    }
    else {
      length = k;
      if (i) length += lcp[i - 1];
      start = sa[i + 1];
      break;
    }
  }
  return make_pair(start, length);
}

int main() {
  string s;
  int q, k;
  cin >> s >> q;
  SuffixArray sa(s);
  sa.buildLCP();
  auto& lcp = sa.lcp;

  int start, length;
  for (int i = 0;i < q;i++) {
    cin >> k;
    tie(start, length) = kth_substring(sa, lcp, k);
    cout << s.substr(start, length) << endl;
  }
  return 0;
}
