tcs = int(input())
for tc in range(tcs):
    n = int(input())
    a = [len(x) for x in input().split('#') if x != '']
    print(2 if any(x > 2 for x in a) else 2 * a.count(2) + a.count(1))
