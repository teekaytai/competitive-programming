tcs = int(input())
for tc in range(tcs):
    n, k = map(int, input().split())
    a = map(int, input().split())
    x=2023
    for b in a:
        if x%b != 0:
            print('NO')
            break
        x//=b
    else:
        print('YES')
        print(*([x]+[1]*(k-1)))
