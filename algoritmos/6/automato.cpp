#include <iostream>
#include "../../estruturas/suffixAutomaton.hpp"

using namespace std;

vector<long long> countOcurrences(SuffixAutomaton &sa, const string &s) {
  vector<long long> counts(sa.size, 0);
  int at = 0;
  for (char c : s) {
    at = sa[at][c];
    counts[at]++;
  }
  vector<pair<int, int>> order;
  for (int i = 0;i < sa.size;i++) {
    order.emplace_back(sa[i].length, i);
  }
  sort(order.rbegin(), order.rend());
  for (auto& [len, i] : order) {
    if (sa[i].link != -1) {
      counts[sa[i].link] += counts[i];
    }
  }
  return counts;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);

  string dna;
  getline(cin, dna);

  auto start = chrono::high_resolution_clock::now();
  SuffixAutomaton sa(dna);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  auto start2 = chrono::high_resolution_clock::now();
  vector<long long> counts = countOcurrences(sa, dna);
  int a = counts[sa[0]['a']];
  int c = counts[sa[0]['c']];
  int g = counts[sa[0]['g']];
  int t = counts[sa[0]['t']];

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

  vector<long long> octoCounts(octos.size(), 0);
  for (int i = 0; i < octos.size(); i++) {
    int at = 0;
    for (char c : octos[i]) {
      at = sa[at][c];
      if (at == 0) break;
    }
    octoCounts[i] = at == 0 ? 0 : counts[at];
  }
  auto end2 = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

  double fa = (double)a / dna.size(), fc = (double)c / dna.size(), fg = (double)g / dna.size(), ft = (double)t / dna.size();
  for (int i = 0; i < octos.size(); i++) {
    double expected = 1.0;
    for (char c : octos[i]) {
      if (c == 'a') expected *= fa;
      else if (c == 'c') expected *= fc;
      else if (c == 'g') expected *= fg;
      else if (c == 't') expected *= ft;
    }
    cout << octos[i] << " " << (double)octoCounts[i] / (dna.size() - 2) << " " << expected << endl;
  }
}
