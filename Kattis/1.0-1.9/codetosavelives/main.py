def f():
    return int(''.join(input().split()))
for _ in range(int(input())):
    print(*str(f()+f()))
