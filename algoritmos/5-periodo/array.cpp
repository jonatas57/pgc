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

const char FIRST = '$';
const char LAST = 'z';
const int ALPHABET_SIZE = LAST - FIRST + 1;

struct SuffixArray {
  string text;
  vector<int> array;

  int size() {
    return array.size() - 1;
  }

  int ord(char c) {
    return c - FIRST;
  }

  SuffixArray(string s) : text(s) {
    s += '$';
    int n = s.length();

    array.resize(n, 0);
    vector<int> c(n, 0);
    vector<int> cnt(max(ALPHABET_SIZE, n), 0);

    for (int i = 0; i < n; i++) {
      cnt[ord(s[i])]++;
    }
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    for (int i = 0; i < n; i++) {
      array[--cnt[ord(s[i])]] = i;
    }

    int nc = 1;
    for (int i = 1; i < n; i++) {
      if (s[array[i]] != s[array[i - 1]]) nc++;
      c[array[i]] = nc - 1;
    }

    vector<int> p2(n, 0);
    vector<int> c2(n, 0);
    for (int h = 1; h < n; h <<= 1) {
      for (int i = 0; i < n; i++) {
        p2[i] = array[i] - h;
        if (p2[i] < 0) p2[i] += n;
      }

      fill(cnt.begin(), cnt.end(), 0);
      for (int i = 0; i < n; i++) {
        cnt[c[p2[i]]]++;
      }
      partial_sum(cnt.begin(), cnt.end(), cnt.begin());
      for (int i = n - 1; i >= 0; i--) {
        array[--cnt[c[p2[i]]]] = p2[i];
      }

      pair<int, int> prev(0, c[h]), cur;
      nc = 1;
      for (int i = 1; i < n; i++) {
        cur = make_pair(c[array[i]], c[(array[i] + h) % n]);
        if (cur != prev) nc++;
        c2[array[i]] = nc - 1;
        prev = cur;
      }

      c.swap(c2);
    }
  }
};

vector<int> lcp_construction(string s, vector<int> const& p) {
  int n = s.size();
  vector<int> rank(n, 0);
  for (int i = 0; i < n; i++)
    rank[p[i + 1]] = i;

  int k = 0;
  vector<int> lcp(n-1, 0);
  for (int i = 0; i < n; i++) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = p[rank[i] + 2];
    while (i + k < n && j + k < n && s[i+k] == s[j+k])
      k++;
    lcp[rank[i]] = k;
    if (k)
      k--;
  }
  return lcp;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  for (int i = 0;i < t;i++) {
    if (i) cout << endl;
    string s;
    cin >> s;
    SuffixArray sa(s);
    vi lcp = lcp_construction(s, sa.array);
    int pos = 0;
    for (;sa.array[pos] != 0;pos++);
    pos--;
    int k = sa.size() - sa.array[pos + 1] - (pos > 0 ? lcp[pos - 1] : 0);
    int n = s.length();
    cout << (n % k == 0 ? k : n) << endl;
  }
  return 0;
}

