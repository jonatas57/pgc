#include <iostream>
#include "../../estruturas/suffixAutomaton.hpp"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  for (int i = 0;i < t;i++) {
    if (i) cout << endl;
    string s;
    cin >> s;
    SuffixAutomaton sa(s);
    int n = s.length();
    int at = 0;
    for (char c : s) at = sa[at][c];
    int k = sa[at].length - sa[sa[at].link].length;
    bool ok = n % k == 0;
    for (int x = at;sa[x].length > k and ok;x = sa[x].link) {
      int y = sa[x].link;
      if (sa[x].length - sa[y].length != k) {
        ok = false;
      }
    }
    cout << (ok ? k : n) << endl;
  }
  return 0;
}

