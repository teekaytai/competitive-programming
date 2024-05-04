from collections import Counter
input()
print(*(k for k,v in Counter(input().split()).most_common() for _ in range(v)))
