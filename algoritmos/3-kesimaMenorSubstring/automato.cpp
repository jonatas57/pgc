#include <bits/stdc++.h>
#include "../../estruturas/suffixAutomaton.hpp"

using namespace std;

string kthSubstring(SuffixAutomaton& sa, int k) {
  int currentState = 0;
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
  int q, k;
  cin >> s >> q;
  SuffixAutomaton sa(s);
  for (int i = 0;i < q;i++) {
    cin >> k;
    cout << kthSubstring(sa, k) << endl;
  }
  return 0;
}
