#include <iostream>
#include "../../estruturas/suffixArray.hpp"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  string s;
  getline(cin, s);
  auto start = chrono::high_resolution_clock::now();
  SuffixArray sa(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
  sa.buildLCP();
  auto& lcp = sa.lcp;
  long long n = s.size();

  auto start2 = chrono::high_resolution_clock::now();
  long long ans = n * (n + 1) / 2;
  for (auto x : lcp) ans -= x;
  auto end2 = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

  cout << ans << endl;
  return 0;
}

