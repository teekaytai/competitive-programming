a, b = map(int, input().split())
print(sum(map(int, ''.join(map(str, range(a, a + (b-a)%9 + 1))))) % 9)
