#include <bits/stdc++.h>
#include "../../estruturas/suffixAutomaton.hpp"

using namespace std;

bool findPattern(SuffixAutomaton& sa, string pat) {
  int at = 0;
  for (char c : pat) {
    if (sa[at].has(c)) {
      at = sa[at][c];
    }
    else return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  cin >> s;
  SuffixAutomaton sa(s);
  int k;
  cin >> k;
  for (int i = 0;i < k;i++) {
    string s;
    cin >> s;
    cout << (findPattern(sa, s) ? "YES" : "NO") << endl;
  }
  return 0;
}

