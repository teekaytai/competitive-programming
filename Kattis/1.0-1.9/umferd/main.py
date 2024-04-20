n=int(input())
m=int(input())
print(sum(c=='.'for _ in range(m)for c in input())/n/m)
