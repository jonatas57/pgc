#include <iostream>
#include <vector>

#include "../../estruturas/suffixArray.hpp"

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  string s = a + '#' + b;
  int n = s.size();
  SuffixArray sa(s);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) rank[sa[i]] = i;
  int k = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = sa[rank[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    if ((i < a.size()) != (j < a.size())) ans = max(ans, k);
    if (k) k--;
  }
  cout << ans << endl;
  return 0;
}

