for i in range(1, int(input())+1):
    n, k = map(int, input().split())
    print(f'Case #{i}:', ['OFF', 'ON'][~k&((1<<n)-1)==0])
