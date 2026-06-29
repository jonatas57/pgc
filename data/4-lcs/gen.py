import random
import sys;

SEED = int(sys.argv[1])
ALPHABET = sys.argv[2]
MIN_LEN = int(sys.argv[3])
MAX_LEN = int(sys.argv[4])


def randomString(alfabet, k):
    return "".join(rd.choices(alfabet, k=k))

def randomStrings():
    sLength = rd.randint(MIN_LEN, MAX_LEN)
    s = randomString(ALPHABET, sLength)
    print(s)

    tLength = rd.randint(MIN_LEN, MAX_LEN)
    t = randomString(ALPHABET, tLength)
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
