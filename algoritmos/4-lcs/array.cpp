#include <bits/stdc++.h>

using namespace std;

inline bool leq(int a1, int a2, int b1, int b2) { return(a1 < b1 || a1 == b1 && a2 <= b2); }
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) { return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3)); }

static void radixPass(int* a, int* b, int* r, int n, int K) {
  int* c = new int[K + 1];
  for (int i = 0; i <= K; i++) c[i] = 0;
  for (int i = 0; i < n; i++) c[r[a[i]]]++;
  for (int i = 0, sum = 0; i <= K; i++)
  { int t = c[i]; c[i] = sum; sum += t; }
  for (int i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i];
  delete [] c;
}


void suffixArray(int* T, int* SA, int n, int K) {
  int n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2;
  int* R = new int[n02 + 3]; R[n02]= R[n02+1]= R[n02+2]=0;
  int* SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
  int* R0 = new int[n0];
  int* SA0 = new int[n0];

  for (int i=0, j=0; i < n+(n0-n1); i++) if (i%3 != 0) R[j++] = i;

  radixPass(R , SA12, T+2, n02, K);
  radixPass(SA12, R , T+1, n02, K);
  radixPass(R , SA12, T , n02, K);

  int name = 0, c0 = -1, c1 = -1, c2 = -1;
  for (int i = 0; i < n02; i++) {
    if (T[SA12[i]] != c0 || T[SA12[i]+1] != c1 || T[SA12[i]+2] != c2) {
      name++;
      c0 = T[SA12[i]];
      c1 = T[SA12[i]+1];
      c2 = T[SA12[i]+2];
    }
    if (SA12[i] % 3 == 1) {
      R[SA12[i]/3] = name;
    }
    else {
      R[SA12[i]/3 + n0] = name;
    }
  }

  if (name < n02) {
    suffixArray(R, SA12, n02, name);
    for (int i = 0; i < n02; i++) R[SA12[i]] = i + 1;
  }
  else {
    for (int i = 0; i < n02; i++) SA12[R[i] - 1] = i;
  }


  for (int i=0, j=0; i < n02; i++) if (SA12[i] < n0) R0[j++] = 3*SA12[i];
  radixPass(R0, SA0, T, n0, K);

  for (int p=0, t=n0-n1, k=0; k < n; k++) {
#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
    int i = GetI();
    int j = SA0[p];
    if (SA12[t] < n0 ?
        leq(T[i], R[SA12[t] + n0], T[j], R[j/3]) :
        leq(T[i],T[i+1],R[SA12[t]-n0+1], T[j],T[j+1],R[j/3+n0]))
    {
      SA[k] = i; t++;
      if (t == n02)
        for (k++; p < n0; p++, k++) SA[k] = SA0[p];
    }
    else {
      SA[k] = j; p++;
      if (p == n0) {
        for (k++; t < n02; t++, k++) SA[k] = GetI();
      }
    }
  }
  delete [] R; delete [] SA12; delete [] SA0; delete [] R0;
}

int main() {
  string a, b;
  cin >> a >> b;
  string s = a + '#' + b + '$';
  int n = s.size();
  int* arr = new int[n];
  for (int i = 0; i < n; i++) arr[i] = s[i];
  int* sa = new int[n];
  suffixArray(arr, sa, n, 256);
  int* rank = new int[n];
  for (int i = 0; i < n; i++) rank[sa[i]] = i;
  int k = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = sa[rank[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    if ((i < a.size()) != (j < a.size())) ans = max(ans, k);
    if (k) k--;
  }
  cout << ans << endl;
  return 0;
}

