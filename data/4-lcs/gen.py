import random
import sys;

SEED = int(sys.argv[1])
ALPHABET = sys.argv[2]
LEN = int(sys.argv[3])
TLEN = int(sys.argv[4])

def randomString(alfabet, k):
    return "".join(rd.choices(alfabet, k=k))

if __name__ == "__main__":
    rd = random.Random(SEED)
    testType = int(sys.argv[4]) if len(sys.argv) > 4 else 0
    print(randomString(ALPHABET, LEN))
    print(randomString(ALPHABET, TLEN))
