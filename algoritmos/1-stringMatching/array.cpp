#include <iostream>
#include "../../estruturas/suffixArray.hpp"
 
using namespace std;
 
bool isSubstring(SuffixArray& arr, const string& pattern) {
  int n = arr.size();
  int left = 1, right = n + 1;
  while (left < right) {
    int mid = (left + right) / 2;
    bool greater = false;
    for (int i = 0; ; i++) {
      if (!pattern[i]) return true;
      if (arr.str[arr[mid] + i] > pattern[i]) {
        greater = true;
        break;
      }
      else if (arr.str[arr[mid] + i] < pattern[i]) {
        greater = false;
        break;
      }
    }
    if (greater) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return false;
}
 
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  int n;
  getline(cin, s);
  cin >> n;
  getchar();
  auto start = chrono::high_resolution_clock::now();
  SuffixArray arr(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
  for (int i = 0; i < n; ++i) {
    string pattern;
    getline(cin, pattern);
    auto itstart = chrono::high_resolution_clock::now();
    bool ok = isSubstring(arr, pattern);
    auto itend = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::nanoseconds>(itend - itstart).count() << endl;
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
