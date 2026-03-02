for _ in range(int(input())):
    input()
    a = sorted(int(input().split()[1])for _ in range(int(input())))
    print(sum(abs(i - x) for i, x in enumerate(a, start=1)))
