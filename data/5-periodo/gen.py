import random
import sys

base_chars = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'

if len(sys.argv) > 1:
    try:
        S = base_chars[:int(sys.argv[1])]
    except ValueError:
        S = sys.argv[1]
else:
    S = base_chars
length = int(sys.argv[2]) if len(sys.argv) > 2 else 10
rep = int(sys.argv[3]) if len(sys.argv) > 3 else 1

def randomString(n):
    return ''.join(random.choice(S) for _ in range(n))

s = randomString(length)
text = s * rep
print(text)
