import random
import sys

SEED = int(sys.argv[1])
ALPHABET = sys.argv[2]
LENGTH = int(sys.argv[3])
PAT_COUNT = int(sys.argv[4])
PAT_LENGTH = int(sys.argv[5])

def randomString(alphabet, length):
    return ''.join(random.choice(alphabet) for _ in range(length))

def main():
    s = randomString(ALPHABET, LENGTH)
    print(s)

    n = PAT_COUNT
    print(n)
    for _ in range(n):
        p = random.random()
        if p < 0.5:
            start = random.randint(0, LENGTH)
            length = random.randint(1, min(PAT_LENGTH, sLength - start))
            print(s[start:start+length])
        else:
            length = random.randint(PAT_MIN_LENGTH, PAT_MAX_LENGTH)
            sub = randomString(ALPHABET, length)
            print(sub)

if __name__ == "__main__":
    random.seed(SEED)
    main()
