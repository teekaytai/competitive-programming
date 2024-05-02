from collections import Counter
i = 0
while n:=int(input()):
    i += 1
    c = Counter(input().lower().rsplit(maxsplit=1)[-1] for _ in range(n))
    print(f'List {i}:')
    for k, v in sorted(c.items()):
        print(k, '|', v)
