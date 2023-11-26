t = int(input())
for I in range(t):
    n = int(input())
    s = input()
    if 'A' not in s or 'B' not in s:
        print(0)
        continue
    print(max(s.rfind('B') - s.find('A'), 0))
