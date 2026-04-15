#include <iostream>
#include <string>
#include "../../estruturas/suffixAutomaton.hpp"

using namespace std;

int longestCommonSubstring(SuffixAutomaton& automaton, string& t) {
  int length = 0;
  int maxLength = 0;
  int position = 0;

  int currentState = 0;
  for (int i = 0; i < t.length(); i++) {
    char c = t[i];
    if (automaton[currentState].has(c)) {
      currentState = automaton[currentState][c];
      length++;
    } else {
      while (currentState != -1 && !automaton[currentState].has(c)) {
        currentState = automaton[currentState].link;
      }
      if (currentState == -1) {
        currentState = 0;
        length = 0;
      } else {
        length = automaton[currentState].length + 1;
        currentState = automaton[currentState][c];
      }
    }
    if (length > maxLength) {
      maxLength = length;
      position = i;
    }
  }
  return maxLength;
}

int main() {
  string s, t;
  cin >> s >> t;
  SuffixAutomaton automaton(s);
  cout << longestCommonSubstring(automaton, t) << endl;
  return 0;
}

