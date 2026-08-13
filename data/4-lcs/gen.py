import random
import sys;

SEED = int(sys.argv[1])
ALPHABET = sys.argv[2]
LEN = int(sys.argv[3])


def randomString(alfabet, k):
    return "".join(rd.choices(alfabet, k=k))

def randomStrings():
    sLength = LEN
    s = randomString(ALPHABET, sLength)
    print(s)

    tLength = LEN
    t = randomString(ALPHABET, tLength)
    print(t)

def partialStrings():
    n = LEN
    s = randomString(ALPHABET, n)
    l = rd.randint(1, n)
    r = rd.randint(1, n)
    if l > r:
        l, r = r, l

    x = rd.randint(0, n - (r - l + 1))
    t = randomString(ALPHABET, x) + s[l - 1:r] + randomString(ALPHABET, n - r)
    print(s)
    print(t)

def equalStrings():
    sLength = rd.randint(MIN_LEN, MAX_LEN)
    s = randomString(ALPHABET, sLength)
    print(s)
    print(s)

if __name__ == "__main__":
    rd = random.Random(SEED)
    testType = int(sys.argv[5]) if len(sys.argv) > 5 else 0
    if testType == 0:
        randomStrings()
    elif testType == 1:
        equalStrings()
    elif testType == 2:
        partialStrings()
