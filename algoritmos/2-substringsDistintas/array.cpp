#include <iostream>
#include "../../estruturas/suffixArray.hpp"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  string s;
  cin >> s;
  SuffixArray sa(s);
  sa.buildLCP();
  auto& lcp = sa.lcp;
  long long n = s.size();

  long long ans = n * (n + 1) / 2;
  for (auto x : lcp) ans -= x;

  cout << ans << endl;
  return 0;
}

