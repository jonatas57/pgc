#include <bits/stdc++.h>
#include "../../estruturas/suffixAutomaton2.hpp"

using namespace std;

bool isSubstring(SuffixAutomaton& sa, string pat) {
  int at = 0;
  for (char c : pat) {
    if (sa[at].has(c - sa.firstch)) {
      at = sa[at][c - sa.firstch];
    }
    else return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  getline(cin, s);
  auto start = chrono::high_resolution_clock::now();
  SuffixAutomaton sa(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
  int k;
  cin >> k;
  getchar();
  for (int i = 0;i < k;i++) {
    string s;
    getline(cin, s);
    auto itstart = chrono::high_resolution_clock::now();
    bool ok = isSubstring(sa, s);
    auto itend = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(itend - itstart).count() << endl;
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}

