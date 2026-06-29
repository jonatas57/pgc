#include <iostream>
#include "../../estruturas/suffixAutomaton.hpp"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  getchar();
  for (int i = 0;i < t;i++) {
    string s;
    getline(cin, s);

    auto start = chrono::high_resolution_clock::now();
    SuffixAutomaton sa(s);
    auto end = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    auto start2 = chrono::high_resolution_clock::now();
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
    auto end2 = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

    cout << (ok ? k : n) << endl;
  }
  return 0;
}

