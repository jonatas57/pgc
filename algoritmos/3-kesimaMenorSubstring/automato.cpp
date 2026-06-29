#include <bits/stdc++.h>
#include "../../estruturas/suffixAutomaton.hpp"

using namespace std;

string kthSubstring(SuffixAutomaton& sa, long long k) {
  int currentState = 0;
  if (k > sa.countPaths(currentState)) {
    return "";
  }
  string result;
  while (k) {
    k--;
    for (auto& [ch, v] : sa.nodes[currentState].next) {
      if (sa.countPaths(v) <= k) {
        k -= sa.countPaths(v);
      }
      else {
        currentState = v;
        result += ch;
        break;
      }
    }
  }
  return result;
}

int main() {
  string s;
  long long q, k;
  cin >> s >> q;
  
  auto start = chrono::high_resolution_clock::now();
  SuffixAutomaton sa(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  for (int i = 0;i < q;i++) {
    cin >> k;
    auto itstart = chrono::high_resolution_clock::now();
    string ans = kthSubstring(sa, k);
    auto itend = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(itend - itstart).count() << endl;
    cout << ans << endl;
  }
  return 0;
}
