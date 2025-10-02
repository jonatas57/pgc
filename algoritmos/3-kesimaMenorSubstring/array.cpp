#include <bits/stdc++.h>

using namespace std;

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

pair<int, int> kth_substring(SuffixArray& sa, vector<int>& lcp, int k) {
  int start, length;
  int n = sa.size();
  for (int i = 0;i < n;i++) {
    int cnt = n - sa.array[i + 1];
    if (i) cnt -= lcp[i - 1];
    if (cnt < k) {
      k -= cnt;
    }
    else {
      length = k;
      if (i) length += lcp[i - 1];
      start = sa.array[i + 1];
      break;
    }
  }
  return make_pair(start, length);
}

int main() {
  string s;
  int q, k;
  cin >> s >> q;
  SuffixArray sa(s);
  auto lcp = lcp_construction(s, sa.array);
  int start, length;
  for (int i = 0;i < q;i++) {
    cin >> k;
    tie(start, length) = kth_substring(sa, lcp, k);
    cout << s.substr(start, length) << endl;
  }
  return 0;
}
