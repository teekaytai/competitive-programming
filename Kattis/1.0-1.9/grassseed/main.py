c = float(input())
n = int(input())
print(c*sum(float.__mul__(*map(float, input().split())) for _ in range(n)))
