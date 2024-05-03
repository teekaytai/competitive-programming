a, b, h = map(int, input().split())
print(max((h-b-1)//(a-b)+1, 1))
