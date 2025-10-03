#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for (auto& x : s)
#define loop(x)     for (int i = 0;i < x;i++)
#define vloop(v, x) for (int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

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
  }

  void extend(int pos) {
    while (true) {
      state nptr = go(ptr, pos, pos + 1);
      if (nptr.v != -1) {
        ptr = nptr;
        return;
      }

      int mid = split(ptr); // quebra a aresta atual
      int leaf = sz++;
      t.emplace_back(pos, str.size(), mid); // adiciona o novo no, representando
      t[mid][str[pos]] = leaf;     // o caminho onde o prefixo divergiu
      ptr.v = getLink(mid);
      ptr.pos = t[ptr.v].len();
      if (!mid) break;
    }
  }

  state go(state st, int l, int r) {
    while (l < r) {
      if (st.pos == t[st.v].len()) {
        st = state(t[st.v][str[l]], 0);
        if (st.v == -1) return st;  // Aresta usando str[l] não existe no nó st.v
      }
      else {
        if (str[t[st.v].l + st.pos] != str[l]) return state(-1, -1); // sufixo não forma prefixo
        if (r - l < t[st.v].len() - st.pos) return state(st.v, st.pos + r - l); // se o que eu quero estender é menor do que falta pra completar a aresta, avança na aresta
        l += t[st.v].len() - st.pos;
        st.pos = t[st.v].len();
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
    if (t[v].link != -1) return t[v].link; // link já calculado
    if (t[v].par == -1) return 0; // se não existe link, o link é a raíz
    int to = getLink(t[v].par);
    return t[v].link = split(go(state(to, t[to].len()), t[v].l + (t[v].par == 0), t[v].r));
  }

  node& operator[](int i) {
    return t[i];
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
    int n = s.size();
    s += '$';
    SuffixTree st(s);
    int at = 0, pos = 0;
    stack<int> ls;
    while (pos < n) {
      at = st[at][s[pos]];
      pos += st[at].len();
      ls.push(pos);
    }
    ls.pop();
    int p = n;
    if (!ls.empty()) {
      int k = n - ls.top();
      if (n % k == 0) p = k;
    }
    cout << p << endl;
  }
  return 0;
}

