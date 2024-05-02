H,W,h,w = map(int, input().split())
A = [[*map(int, input().split())] for _ in range(H)]
B = [[*map(int, input().split())] for _ in range(h)]
for R in range(H-h+1):
    print(*[sum(A[R+r][C+c]*B[-r-1][-c-1] for r in range(h) for c in range(w)) for C in range(W-w+1)])
