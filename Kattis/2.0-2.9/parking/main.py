a, b, c = map(int, input().split())
x = [0] * 101
for _ in range(3):
    s, t = map(int, input().split())
    for i in range(s, t): x[i] += 1
print(sum([0,a,2*b,3*c][v] for v in x))
