for _ in range(int(input())):
    input()
    n = int(input())
    s = sum(int(input()) for _ in range(n))
    print(['NO', 'YES'][s%n==0])
