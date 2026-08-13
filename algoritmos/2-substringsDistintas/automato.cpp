#include <iostream>
#include "../../estruturas/suffixAutomaton.hpp"
 
using namespace std;
 
long long countDistinctSubstrings(SuffixAutomaton& sa) {
  vector<long long> dp(sa.size, -1);
  stack<pair<int, int>> st;
  st.emplace(0, -1);
  while (!st.empty()) {
    auto [at, parent] = st.top();
    if (dp[at] == -1) {
      dp[at] = 0;
      for (auto& [ch, v] : sa[at].next) {
        st.emplace(v, at);
      }
    }
    else {
      st.pop();
      if (parent != -1) {
        dp[parent] += dp[at] + 1;
      }
    }
  }
  return dp[0];
}
 
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
  string s;
  getline(cin, s);
  auto start = chrono::high_resolution_clock::now();
  SuffixAutomaton sa(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  auto start2 = chrono::high_resolution_clock::now();
  long long ans = countDistinctSubstrings(sa);
  auto end2 = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

  cout << ans << endl;
  return 0;
}
