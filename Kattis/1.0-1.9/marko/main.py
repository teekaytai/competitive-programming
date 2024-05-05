d = dict(zip('abcdefghijklmnopqrstuvwxyz','22233344455566677778889999'))
a = [input() for _ in range(int(input()))]
s = input()
print(sum(''.join(map(d.get, x)) == s for x in a))
