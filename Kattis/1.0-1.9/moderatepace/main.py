input()
print(*[sorted(t)[1]for t in zip(*(map(int, input().split())for _ in range(3)))])
