import sys

input = lambda: sys.stdin.readline().strip()

def count_invs(a):
    return sum(a[j] > a[i] for i in range(len(a)) for j in range(i))

n, k = map(int, input().split())
*a, = map(int, input().split())
if k == n:
    x1 = count_invs(a)
    x2 = count_invs(a[::-1])
    if x1 < x2:
        print(x1)
        print(0)
    else:
        print(x2)
        print(1)
        print('1' * n)
    exit()

steps = []
*A, = sorted((x, i) for i, x in enumerate(a))
for i in range(n):
    a[A[i][1]] = i
*A, = sorted(a)

for i in range(n-1, k, -1):
    s = {*A[:k-1], A[i]}
    I = [0] * n
    a2 = []
    a3 = []
    for j in range(n-1, -1, -1):
        if a[j] in s:
            s.remove(a[j])
            I[j] = 1
            a2.append(a[j])
        else:
            a3.append(a[j])
    a = a2 + a3[::-1]
    # print(a)
    steps.append(I)
# print()
flippety = [1] * k + [0] * (n-k)
for i in range(k+1):
    s = {*A[:k+1]}
    s.remove(A[i])
    I = [0] * n
    a2 = []
    a3 = []
    for j in range(n):
        if a[j] in s:
            s.remove(a[j])
            I[j] = 1
            a2.append(a[j])
        else:
            a3.append(a[j])
    a = a2 + a3
    steps.append(I)
    # print(a)
    steps.append(flippety)

print(0)
print(len(steps))
for step in steps:
    print(*step, sep='')
