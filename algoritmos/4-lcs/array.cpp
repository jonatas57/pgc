#include <iostream>
#include <vector>

#include "../../estruturas/suffixArray.hpp"

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  string s = a + '#' + b;
  int n = s.size();

  auto start = chrono::high_resolution_clock::now();
  SuffixArray sa(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  sa.buildLCP();

  auto start2 = chrono::high_resolution_clock::now();
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if ((sa[i] < a.size()) != (sa[i + 1] < a.size())) {
      ans = max(ans, sa.lcp[i - 1]);
    }
  }
  auto end2 = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

  cout << ans << endl;
  return 0;
}

