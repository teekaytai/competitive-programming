a=set(input())
print(*['*'*len(w) if set(w)&a else w for w in input().split()])
