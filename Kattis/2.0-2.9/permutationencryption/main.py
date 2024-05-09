while True:
    n, *a = map(int, input().split())
    if not n: break
    s = list(input())
    s.extend(' '*(-len(s)%n))
    c = [s[i+a[i%n]-1-i%n] for i in range(len(s))]
    print(f"'{''.join(c)}'")
