import sys
import random

SEED = int(sys.argv[1])
ALPHABET = sys.argv[2]
LENGTH = int(sys.argv[3])
QUERY_CNT = int(sys.argv[4])

def randomString(alphabet, length):
    return ''.join(random.choice(alphabet) for _ in range(length))

def main():
    sLength = LENGTH
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
