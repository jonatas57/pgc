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
  string s;
  int n;
  cin >> s >> n;
  SuffixArray arr(s);
  for (int i = 0; i < n; ++i) {
    string pattern;
    cin >> pattern;
    cout << (isSubstring(arr, pattern) ? "YES" : "NO") << endl;
  }
  return 0;
}
