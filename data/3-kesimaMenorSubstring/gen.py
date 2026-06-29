import sys
import random

SEED = int(sys.argv[1])
ALPHABET = sys.argv[2]
MIN_LEN = int(sys.argv[3])
MAX_LEN = int(sys.argv[4])
QUERY_CNT = int(sys.argv[5])

def randomString(alphabet, length):
    return ''.join(random.choice(alphabet) for _ in range(length))

def main():
    sLength = random.randint(MIN_LEN, MAX_LEN)
    s = randomString(ALPHABET, sLength)
    print(s)
    mink = 1
    maxk = sLength * (sLength + 1) // 2
    query_cnt = min(QUERY_CNT, maxk)
    print(query_cnt)
    if query_cnt == maxk:
        for k in range(1, maxk + 1):
            print(k)
    else:
        for _ in range(query_cnt):
            k = random.randint(mink, maxk)
            print(k)

if __name__ == "__main__":
    random.seed(SEED)
    main()
