#include <iostream>
#include "../../estruturas/suffixAutomaton.hpp"

using namespace std;

int getPeriod(SuffixAutomaton& sa, string& s) {
  int n = s.length();
  int border = 0;
  int at = 0;
  for (auto& c : s) {
    at = sa[at][c];
    if (sa[at].terminal and sa[at].length < n) {
      border = max(border, sa[at].length);
    }
  }
  return n - border;
}

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
    int ans = getPeriod(sa, s);
    auto end2 = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

    cout << ans << endl;
  }
  return 0;
}

