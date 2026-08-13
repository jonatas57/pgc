#include <iostream>
#include "../../estruturas/suffixTree.hpp"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);

  string dna;
  getline(cin, dna);

  auto start = chrono::high_resolution_clock::now();
  SuffixTree st(dna);
  auto end = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

  auto start2 = chrono::high_resolution_clock::now();
  vector<int> counts(st.sz, -1);
  stack<pair<int, int>> s;
  s.emplace(0, -1);
  while (!s.empty()) {
    auto [at, parent] = s.top();
    if (counts[at] == -1) {
      counts[at] = 0;
      for (auto &[c, child] : st[at].next) {
        s.emplace(child, at);
      }
    }
    else {
      s.pop();
      if (st[at].next.empty()) counts[at] = 1;
      if (parent != -1) counts[parent] += counts[at];
    }
  }

  int a = counts[st.go({0, 0}, 'a').v];
  int c = counts[st.go({0, 0}, 'c').v];
  int g = counts[st.go({0, 0}, 'g').v];
  int t = counts[st.go({0, 0}, 't').v];

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
    SuffixTree::state at(0, 0);
    for (char c : trios[i]) {
      at = st.go(at, c);
    }
    trioCounts[i] = counts[at.v];
  }
  auto end2 = chrono::high_resolution_clock::now();
  cerr << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << endl;

  double fa = (double)a / dna.size(), fc = (double)c / dna.size(), fg = (double)g / dna.size(), ft = (double)t / dna.size();
  for (int i = 0; i < trios.size(); i++) {
    double expected = 1.0;
    for (char c : trios[i]) {
      if (c == 'a') expected *= fa;
      else if (c == 'c') expected *= fc;
      else if (c == 'g') expected *= fg;
      else if (c == 't') expected *= ft;
    }
    cout << trios[i] << " " << (double)trioCounts[i] / (dna.size() - 2) << " " << expected << endl;
  }
}
