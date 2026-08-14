#include <map>
#include <vector>

using namespace std;

struct SuffixTree {
  struct node {
    int l, r, par, link;
    map<char, int> next;

    node(int l = 0, int r = 0, int par = -1) : l(l), r(r), par(par), link(-1) {}
    int len() { return r - l; }
    int& operator[](char c) {
      if (!next.count(c)) next[c] = -1;
      return next[c];
    }
  };

  struct state {
    int v, pos;
    state(int v = 0, int pos = 0) : v(v), pos(pos) {}
  };

  state ptr;
  vector<node> t;
  string str;
  int sz;

  SuffixTree(string s) : t(1), str(s), sz(1) {
    for (int i = 0;s[i];i++) {
      extend(i);
    }
    extend(s.size());
  }

  int get(int v, char c) {
    return t[v][c];
  }

  void extend(int pos) {
    while (true) {
      state nptr = go(ptr, pos, pos + 1);
      if (nptr.v != -1) {
        ptr = nptr;
        return;
      }

      int mid = split(ptr);
      int leaf = sz++;
      t.emplace_back(pos, str.size() + 1, mid);
      t[mid][str[pos]] = leaf;
      ptr.v = getLink(mid);
      ptr.pos = t[ptr.v].len();
      if (!mid) break;
    }
  }

  state go(state st, int l, int r) {
    while (l < r) {
      if (st.pos == t[st.v].len()) {
        st = state(t[st.v][str[l]], 0);
        if (st.v == -1) return st;
      }
      else {
        if (str[t[st.v].l + st.pos] != str[l]) return state(-1, -1);
        if (r - l < t[st.v].len() - st.pos) return state(st.v, st.pos + r - l);
        l += t[st.v].len() - st.pos;
        st.pos = t[st.v].len();
      }
    }
    return st;
  }

  state go(state st, char c) {
    while (true) {
      if (st.pos == t[st.v].len()) {
        st = state(t[st.v][c], 0);
        if (st.v == -1) return st;
      }
      else {
        if (str[t[st.v].l + st.pos] != c) return state(-1, -1);
        if (1 < t[st.v].len() - st.pos) return state(st.v, st.pos + 1);
        st.pos = t[st.v].len();
        break;
      }
    }
    return st;
  }

  int split(state st) {
    if (st.pos == t[st.v].len()) {
      return st.v;
    }
    if (st.pos == 0) {
      return t[st.v].par;
    }
    node v = t[st.v];
    int id = sz++;
    t.emplace_back(v.l, v.l + st.pos, v.par);
    t[v.par][str[v.l]] = id;
    t[id][str[v.l + st.pos]] = st.v;
    t[st.v].par = id;
    t[st.v].l += st.pos;
    return id;
  }

  int getLink(int v) {
    if (t[v].link != -1) return t[v].link;
    if (t[v].par == -1) return 0;
    int to = getLink(t[v].par);
    return t[v].link = split(go(state(to, t[to].len()), t[v].l + (t[v].par == 0), t[v].r));
  }

  node& operator[](int v) {
    return t[v];
  }
};
