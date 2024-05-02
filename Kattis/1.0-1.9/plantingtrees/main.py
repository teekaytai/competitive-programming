input()
a = sorted(map(int, input().split()), reverse=True)
print(max(i+x for i, x in enumerate(a))+2)
