k=int(input())-1
t = 210
for _ in range(int(input())):
    dt, l = input().split()
    t -= int(dt)
    if t <= 0: print(k+1); break
    k = (k + (l == 'T')) % 8
