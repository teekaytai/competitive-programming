a, b = map(int, input().split())
if a%b: print(0)
else:
    c = a//b
    print(sum(c%i==0 for i in range(1, 10)))
