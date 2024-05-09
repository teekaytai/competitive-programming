while True:
    h, w = map(int, input().split())
    if not h: break
    g = [input() for _ in range(h)]
    g = sorted(map(''.join,zip(*g)), key=str.lower)
    for t in zip(*g): print(''.join(t))
    print()
