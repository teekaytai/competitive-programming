from collections import Counter

t = int(input())
for i in range(1, t + 1):
    n = int(input())
    c = Counter(int(x) for x in input().split())
    print('Yes' if len(c) == 1 or len(c) == 2 and c.most_common(1)[0][1] == (n + 1) // 2 else 'No')
