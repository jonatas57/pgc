#include <iostream>
#include "../../estruturas/suffixArray.hpp"
 
using namespace std;
 
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

  vector<string> trios = {"aaa", "aac", "aag", "aat", "aca", "acc", "acg", "act",
                          "aga", "agc", "agg", "agt", "ata", "atc", "atg", "att",
                          "caa", "cac", "cag", "cat", "cca", "ccc", "ccg", "cct",
                          "cga", "cgc", "cgg", "cgt", "cta", "ctc", "ctg", "ctt",
                          "gaa", "gac", "gag", "gat", "gca", "gcc", "gcg", "gct",
                          "gga", "ggc", "ggg", "ggt", "gta", "gtc", "gtg", "gtt",
                          "taa", "tac", "tag", "tat", "tca", "tcc", "tcg", "tct",
                          "tga", "tgc", "tgg", "tgt", "tta", "ttc", "ttg", "ttt"};

  vector<int> trioCounts(64, 0);
  for (int i = 0; i < trios.size(); i++) {
    trioCounts[i] = countOcurrences(arr, trios[i]);
  }
  auto end2 = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

  double fa = (double)a / s.size(), fc = (double)c / s.size(), fg = (double)g / s.size(), ft = (double)t / s.size();
  for (int i = 0; i < trios.size(); i++) {
    double expected = 1.0;
    for (char c : trios[i]) {
      if (c == 'a') expected *= fa;
      else if (c == 'c') expected *= fc;
      else if (c == 'g') expected *= fg;
      else if (c == 't') expected *= ft;
    }
    cout << trios[i] << " " << (double)trioCounts[i] / (s.size() - 2) << " " << expected << endl;
  }
  return 0;
}
