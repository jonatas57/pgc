#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct SuffixAutomaton {
  struct Node {
    int id = 0;
    int length = 0;
    int link = -1;
    int endpos = -1;
    bool isclone = false;
    map<char, int> next;
    vector<int> invlink;

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
      extend(c, last);
    }
    for (int u = 1;u < size; u++) {
      nodes[nodes[u].link].invlink.push_back(u);
    }
  }

  void extend(char c, int& last) {
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
    clone.isclone = true;
    return clone;
  }

  Node& operator[](int index) {
    return nodes[index];
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  for (int i = 0;i < t;i++) {
    if (i) cout << endl;
    string s;
    cin >> s;
    SuffixAutomaton sa(s);
    int n = s.length();
    int at = 0;
    for (char c : s) at = sa[at][c];
    int k = sa[at].length - sa[sa[at].link].length;
    bool ok = n % k == 0;
    for (int x = at;sa[x].length > k and ok;x = sa[x].link) {
      int y = sa[x].link;
      if (sa[x].length - sa[y].length != k) {
        ok = false;
      }
    }
    cout << (ok ? k : n) << endl;
  }
  return 0;
}

