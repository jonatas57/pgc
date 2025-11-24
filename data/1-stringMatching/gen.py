import random
import sys

ALPHABET = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'

if len(sys.argv) > 1:
    try:
        ALPHABET = ALPHABET[:int(sys.argv[1])]
    except ValueError:
        ALPHABET = sys.argv[1]

LENGTH = int(sys.argv[2]) if len(sys.argv) > 2 else 10

def randomString(alphabet, length):
    import random
    return ''.join(random.choice(alphabet) for _ in range(length))

s = randomString(ALPHABET, LENGTH)
print(s)

n = int(sys.argv[3]) if len(sys.argv) > 3 else 5
print(n)
for _ in range(n):
    p = random.random()
    if p < 0.33:
        start = random.randint(0, LENGTH - 1)
        length = random.randint(1, LENGTH - start)
        print(s[start:start+length])
    elif p < 0.66:
        length = random.randint(1, LENGTH)
        sub = randomString(ALPHABET, length)
        print(sub)
    else:
        length = random.randint(1, LENGTH)
        sub = randomString(ALPHABET, length)
        start = random.randint(0, LENGTH - 1)
        end = start + random.randint(0, LENGTH - start)
        modified = s[:start] + sub + s[end:]
        print(modified)
