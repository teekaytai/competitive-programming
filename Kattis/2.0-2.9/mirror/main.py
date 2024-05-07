for i in range(1, int(input())+1):
    h, w = map(int, input().split())
    g = [input() for _ in range(h)]
    print('Test', i)
    for r in g[::-1]:
        print(r[::-1])
