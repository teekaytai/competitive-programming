l, r = map(int, input().split())
print(sum('0' not in str(i) and len(set(str(i)))==6 and all(i%int(d)==0 for d in str(i)) for i in range(l, r+1)))
