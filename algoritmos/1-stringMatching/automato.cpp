#include <bits/stdc++.h>
 
using namespace std;
 
struct SuffixAutomaton {
  struct Node {
    int id = 0;
    int length = 0;
    int link = -1;
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
    return nodes[size++];
  }
 
  Node& cloneNode(Node& node) {
    Node& clone = newState(node.length, node.link);
    clone.next = node.next;
    return clone;
  }
  
  Node& operator[](int x) {
    return nodes[x];
  }
};
 
bool findPattern(SuffixAutomaton& sa, string pat) {
  int at = 0;
  for (char c : pat) {
    if (sa[at].has(c)) {
      at = sa[at][c];
    }
    else return false;
  }
  return true;
}
 
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
  string s;
  cin >> s;
  SuffixAutomaton sa(s);
  int k;
  cin >> k;
  for (int i = 0;i < k;i++) {
    string s;
    cin >> s;
    cout << (findPattern(sa, s) ? "YES" : "NO") << endl;
  }
  return 0;
}

