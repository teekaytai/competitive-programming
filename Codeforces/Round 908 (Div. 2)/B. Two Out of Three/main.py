t = int(input())
for I in range(t):
    n = int(input())
    a = [3] * n
    seen = [0] * 101
    count = 0
    for i, d in enumerate(map(int, input().split())):
        if seen[d] == 0:
            seen[d] = 1
        elif seen[d] == 1:
            seen[d] = 2
            count += 1
            a[i] = count
            if count == 2:
                break
    print(*a) if count == 2 else print(-1)

