from itertools import accumulate
n, *A = [*map(int, input().split())]
MA = [*accumulate(A, max)]
MI = [*accumulate(reversed(A), min)][::-1]
P = [A[i] for i in range(n) if MA[i] <= A[i] <= MI[i]]
print(len(P), *P[:100])
