import random
import sys

SEED = int(sys.argv[1])
ALPHABET = sys.argv[2]
MIN_LENGTH = int(sys.argv[3])
MAX_LENGTH = int(sys.argv[4])

def randomString(alphabet, n):
    return ''.join(random.choice(alphabet) for _ in range(n))

def main():
    sLength = random.randint(MIN_LENGTH, MAX_LENGTH)
    s = randomString(ALPHABET, sLength)
    print(s)

if __name__ == "__main__":
    if SEED != 0:
        random.seed(SEED)
    main()
