#include <iostream>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

int main() {
  string s;
  getline(cin, s);
  auto start = chrono::high_resolution_clock::now();
  SuffixTree st(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  auto start2 = chrono::high_resolution_clock::now();
  long long ans = 0;
  for (auto& u : st.t) {
    ans += u.len();
  }
  auto end2 = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

  cout << ans << endl;
  return 0;
}

