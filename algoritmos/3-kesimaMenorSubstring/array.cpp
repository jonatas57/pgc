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
  auto start = chrono::high_resolution_clock::now();
  SuffixArray sa(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  sa.buildLCP();
  auto& lcp = sa.lcp;

  int st, length;
  for (int i = 0;i < q;i++) {
    cin >> k;

    auto itstart = chrono::high_resolution_clock::now();
    tie(st, length) = kth_substring(sa, lcp, k);
    auto itend = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(itend - itstart).count() << endl;

    string ans = s.substr(st, length);
    cout << ans << endl;
  }
  return 0;
}
