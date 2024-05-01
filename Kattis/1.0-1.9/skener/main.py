h, w, r, c = map(int, input().split())
for _ in range(h):
    print(*[''.join(x*c for x in input())]*r,sep='\n')
