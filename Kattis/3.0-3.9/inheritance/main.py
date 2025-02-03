from collections import deque

def main():
    n = int(input())
    q = deque([2, 4])
    ans = []
    while q:
        x = q.popleft()
        if n % x == 0: ans.append(x)
        x = x * 10 + 2
        if x <= n:
            q.append(x)
            x += 2
            if x <= n: q.append(x)
    print(*ans, sep='\n')

main()
