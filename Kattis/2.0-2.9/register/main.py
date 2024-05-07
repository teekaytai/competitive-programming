t = 0
for p, x in [*zip([2,3,5,7,11,13,17,19], map(int, input().split()))][::-1]:
    t = p * t + p - x - 1
print(t)
