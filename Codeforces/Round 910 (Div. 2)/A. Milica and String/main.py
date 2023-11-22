t = int(input())
for I in range(t):
    n, k = map(int, input().split())
    s = input()
    c = s.count('B')
    if (c == k):
        print(0)
    else:
        d = abs(c - k)
        C = 'A' if c > k else 'B'
        for i in range(n):
            d -= s[i] != C
            if (d == 0):
                break
        print(1)
        print(i + 1, C)

