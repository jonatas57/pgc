#include <bits/stdc++.h>
 
using namespace std;
 
const char FIRST = '$';
const char LAST = 'z';
const int ALPHABET_SIZE = LAST - FIRST + 1;
 
struct SuffixArray {
  string text;
  vector<int> array;
 
  int size() {
    return array.size() - 1;
  }
 
  int ord(char c) {
    return c - FIRST;
  }
 
  SuffixArray(string s) : text(s) {
    s += '$';
    int n = s.length();
 
    array.resize(n, 0);
    vector<int> c(n, 0);
    vector<int> cnt(max(ALPHABET_SIZE, n), 0);
 
    for (int i = 0; i < n; i++) {
      cnt[ord(s[i])]++;
    }
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    for (int i = 0; i < n; i++) {
      array[--cnt[ord(s[i])]] = i;
    }
 
    int nc = 1;
    for (int i = 1; i < n; i++) {
      if (s[array[i]] != s[array[i - 1]]) nc++;
      c[array[i]] = nc - 1;
    }
 
    vector<int> p2(n, 0);
    vector<int> c2(n, 0);
    for (int h = 1; h < n; h <<= 1) {
      for (int i = 0; i < n; i++) {
        p2[i] = array[i] - h;
        if (p2[i] < 0) p2[i] += n;
      }
 
      fill(cnt.begin(), cnt.end(), 0);
      for (int i = 0; i < n; i++) {
        cnt[c[p2[i]]]++;
      }
      partial_sum(cnt.begin(), cnt.end(), cnt.begin());
      for (int i = n - 1; i >= 0; i--) {
        array[--cnt[c[p2[i]]]] = p2[i];
      }
 
      pair<int, int> prev(0, c[h]), cur;
      nc = 1;
      for (int i = 1; i < n; i++) {
        cur = make_pair(c[array[i]], c[(array[i] + h) % n]);
        if (cur != prev) nc++;
        c2[array[i]] = nc - 1;
        prev = cur;
      }
 
      c.swap(c2);
    }
  }
};
 
bool isSubstring(SuffixArray& arr, const string& pattern) {
  int n = arr.size();
  int left = 1, right = n + 1;
  while (left < right) {
    int mid = (left + right) / 2;
    bool greater = false;
    for (int i = 0; ; i++) {
      if (!pattern[i]) return true;
      if (arr.text[arr.array[mid] + i] > pattern[i]) {
        greater = true;
        break;
      }
      else if (arr.text[arr.array[mid] + i] < pattern[i]) {
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
