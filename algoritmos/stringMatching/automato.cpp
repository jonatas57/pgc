#include <iostream>

#include "../../estruturas/suffixAutomaton.cpp"

using namespace std;

bool isSubstring(SuffixAutomaton& automaton, const string& pattern) {
  int currentNode = 0;
  for (char c : pattern) {
    if (!automaton[currentNode].has(c)) {
      return false;
    }
    currentNode = automaton[currentNode][c];
  }
  return true;
}

int main() {
  string s;
  int n;
  cin >> s >> n;
  SuffixAutomaton automaton(s);
  for (int i = 0; i < n; ++i) {
    string pattern;
    cin >> pattern;
    cout << (isSubstring(automaton, pattern) ? "YES" : "NO") << endl;
  }
  return 0;
}

