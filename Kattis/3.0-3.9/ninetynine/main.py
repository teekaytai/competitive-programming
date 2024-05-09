s = 0
while s < 99:
    m = -s % 3 or s%2+1
    s += m
    print(s, flush=True)
    if s == 99: break
    s = int(input())
