#include <iostream>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

int main() {
  string s;
  cin >> s;
  SuffixTree st(s);
  long long ans = 0;
  for (auto& u : st.t) {
    ans += u.len();
  }
  cout << ans << endl;
  return 0;
}

