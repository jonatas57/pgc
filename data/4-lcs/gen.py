import random as rd;
import sys;

def randomString(alfabet, k):
    return "".join(rd.choices(alfabet, k=k))

if __name__ == "__main__":
    MAXN = sys.argv[1]
    ans = rd.randint(1, MAXN)
    rs = randomString("abcdefghijklmnopqrstuvwxyz", ans)
    n = rd.randint(0, MAXN - ans)
    m = rd.randint(0, MAXN - ans)
    l = rd.randint(0, n)
    s = randomString("abcdefghijklmnopqrstuvwxyz", l) + rs + randomString("abcdefghijklmnopqrstuvwxyz", n - l)
    l = rd.randint(0, m)
    t = randomString("abcdefghijklmnopqrstuvwxyz", l) + rs + randomString("abcdefghijklmnopqrstuvwxyz", m - l)
    print(s)
    print(t)
