import random
import sys

SEED = int(sys.argv[1])
ALPHABET = sys.argv[2]
QUERY_COUNT = int(sys.argv[3])
LEN = int(sys.argv[4])
MIN_CYCLE_LEN = int(sys.argv[5])
MAX_CYCLE_LEN = int(sys.argv[6])

def randomString(alphabet, length):
    return ''.join(random.choice(alphabet) for _ in range(length))

def main():
    print(QUERY_COUNT)
    for _ in range(QUERY_COUNT):
        cycle_len = random.randint(MIN_CYCLE_LEN, MAX_CYCLE_LEN)
        cycle = randomString(ALPHABET, cycle_len)
        sLength = LEN
        s = ''.join(cycle[i % cycle_len] for i in range(sLength))
        print(s)

if __name__ == "__main__":
    random.seed(SEED)
    main()
