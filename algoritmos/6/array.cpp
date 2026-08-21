#include <iostream>
#include "../../estruturas/suffixArray.hpp"
 
using namespace std;

const double EPS = 1e-7;
 
int countOcurrences(SuffixArray& arr, const string& pattern) {
  int n = arr.size();
  int left = 1, right = n + 1;
  while (left < right) {
    int mid = (left + right) / 2;
    bool greater = false;
    for (int i = 0; ; i++) {
      if (!pattern[i]) {
        greater = true;
        break;
      }
      if (arr.str[arr[mid] + i] > pattern[i]) {
        greater = true;
        break;
      }
      else if (arr.str[arr[mid] + i] < pattern[i]) {
        break;
      }
    }
    if (greater) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  int first = left;
  left = 1, right = n + 1;
  while (left < right) {
    int mid = (left + right) / 2;
    bool greater = false;
    for (int i = 0; i < pattern.size(); i++) {
      if (!pattern[i]) {
        break;
      }
      if (arr.str[arr[mid] + i] > pattern[i]) {
        greater = true;
        break;
      }
      else if (arr.str[arr[mid] + i] < pattern[i]) {
        break;
      }
    }
    if (greater) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  int last = left;
  return last - first;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);

  string s;
  getline(cin, s);

  auto start = chrono::high_resolution_clock::now();
  SuffixArray arr(s);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  auto start2 = chrono::high_resolution_clock::now();
  int a = countOcurrences(arr, "a");
  int c = countOcurrences(arr, "c");
  int g = countOcurrences(arr, "g");
  int t = countOcurrences(arr, "t");

  vector<string> octos;
  string bases = "acgt";
  for (int i = 0; i < (1 << 16);i++) {
    string octo;
    for (int j = 3, k = 0; k < 8;k++, j <<= 2) {
      int x = (i & j) >> (k * 2);
      octo += bases[x];
    }
    octos.push_back(octo);
  }

  vector<int> octoCounts(octos.size(), 0);
  for (int i = 0; i < octos.size(); i++) {
    octoCounts[i] = countOcurrences(arr, octos[i]);
  }
  auto end2 = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

  vector<pair<string, double>> results;
  double fa = (double)a / s.size(), fc = (double)c / s.size(), fg = (double)g / s.size(), ft = (double)t / s.size();
  for (int i = 0; i < octos.size(); i++) {
    double expected = 1.0;
    for (char c : octos[i]) {
      if (c == 'a') expected *= fa;
      else if (c == 'c') expected *= fc;
      else if (c == 'g') expected *= fg;
      else if (c == 't') expected *= ft;
    }
    // cout << octos[i] << " " << (double)octoCounts[i] / (s.size() - 2) << " " << expected << endl;
    results.emplace_back(octos[i], (double)octoCounts[i] / (s.size() - 2));
  }
  sort(results.begin(), results.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
    if (abs(a.second - b.second) < EPS) {
      return a.first < b.first;
    }
    return a.second > b.second;
  });
  for (int i = 0;i < 10;i++) {
    cout << results[i].first << " " << results[i].second << endl;
  }
  return 0;
}
