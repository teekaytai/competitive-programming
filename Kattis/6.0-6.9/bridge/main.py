n = int(input())
*a, = sorted(int(input()) for _ in range(n))
t = 0
steps = []
while len(a) > 3 and 2 * a[1] <= a[0] + a[-2]:
    t += a[0] + 2 * a[1] + a[-1]
    steps.extend([(a[0], a[1]), (a[0],), (a.pop(), a.pop()), (a[1],)])
while len(a) > 2:
    t += a[0] + a[-1]
    steps.extend([(a[0], a.pop()), (a[0],)])
t += a[-1]
steps.append((*a,))
print(t)
for step in steps:
    print(*step)
