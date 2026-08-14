#include <iostream>
#include "../../estruturas/suffixAutomaton.hpp"

using namespace std;

string kthSubstring(SuffixAutomaton& sa, long long k) {
  int currentState = 0;
  if (k > sa.countPaths(currentState)) {
    return "";
  }
  string result;
  long long acc = 0;
  for (int at = 0; acc < k and !sa.nodes[at].next.empty();) {
    for (auto& [ch, v] : sa.nodes[at].next) {
      if (acc + sa.countPaths(v) < k) {
        acc += sa.countPaths(v);
      }
      else {
        result += ch;
        at = v;
        acc++;
        break;
      }
    }
  }
  return result;
}

int main() {
  string s;
  long long q, k;
  getline(cin, s);
  cin >> q;
  
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
