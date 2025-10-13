#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct SuffixAutomaton {
  struct Node {
    int id = 0;
    int length = 0;
    int link = -1;
    int endpos = -1;
    map<char, int> next;

    int& operator[](char c) {
      return next[c];
    }

    bool has(char c) {
      return next.count(c);
    }
  };

  vector<Node> nodes;
  int size;

  SuffixAutomaton(string s) : nodes(2 * s.length()), size(1) {
    int last = 0;
    for (char c : s) {
      Node& current = newState(nodes[last].length + 1);
      int p = last;
      for (; p != -1 and !nodes[p].has(c); p = nodes[p].link) {
        nodes[p][c] = current.id;
      }
      if (p == -1) {
        current.link = 0;
      }
      else {
        int q = nodes[p][c];
        if (nodes[p].length + 1 == nodes[q].length) {
          current.link = q;
        }
        else {
          Node& clone = cloneNode(nodes[q]);
          clone.length = nodes[p].length + 1;
          while (p != -1 and nodes[p][c] == q) {
            nodes[p][c] = clone.id;
            p = nodes[p].link;
          }
          current.link = clone.id;
          nodes[q].link = clone.id;
        }
      }
      last = current.id;
    }
  }

  Node& newState(int length, int link = -1) {
  nodes[size].id = size;
    nodes[size].length = length;
    nodes[size].link = link;
    nodes[size].endpos = length - 1;
    return nodes[size++];
  }

  Node& cloneNode(Node& node) {
    Node& clone = newState(node.length, node.link);
    clone.next = node.next;
    clone.endpos = node.endpos;
    return clone;
  }

  Node& operator[](int index) {
    return nodes[index];
  }

  void toGraph() {
    for (int i = 0; i < size; i++) {
      for (auto& [c, j] : nodes[i].next) {
        cout << i << " " << j << " " << c << endl;
      }
      cout << i << " --> " << nodes[i].link << endl;
    }
  }
};

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

