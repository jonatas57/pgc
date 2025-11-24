import sys
import random

def generate_test_case(alphabet='abcdefghijklmnopqrstuvwxyz', length=-1, n=-1, maxN=5):
    length = length if length != -1 else random.randint(1, 10)
    s = ''.join(random.choices(alphabet, k=length))
    
    num_distinct = length * (length + 1) // 2
    
    n = n if n != -1 else random.randint(1, maxN)
    
    queries = [random.randint(1, num_distinct) for _ in range(n)]
    
    print(s)
    print(n)
    for query in queries:
        print(query)

if __name__ == "__main__":
    generate_test_case()
