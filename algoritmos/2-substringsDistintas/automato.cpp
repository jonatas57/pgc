#include <bits/stdc++.h>
#include "../../estruturas/suffixAutomaton.hpp"
 
using namespace std;
 
long long countDistinctSubstrings(SuffixAutomaton& sa) {
  vector<pair<int, int>> order;
  for (int i = 0;i < sa.size;i++) order.emplace_back(sa[i].length, i);
  sort(order.rbegin(), order.rend());
  vector<long long> cnt(sa.size, -1);
  for (auto& [len, at] : order) {
    cnt[at] = 1;
    for (auto& p : sa[at].next) {
      cnt[at] += cnt[p.second];
    }
  }
  return cnt[0] - 1;
}
 
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
  string s;
  cin >> s;
  SuffixAutomaton sa(s);
  cout << countDistinctSubstrings(sa) << endl;
  return 0;
}
